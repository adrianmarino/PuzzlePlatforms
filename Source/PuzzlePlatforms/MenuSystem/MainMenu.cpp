#include "MainMenu.h"
#include "../Utils.h"

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void UMainMenu::StartHostGameButtonOnClicked() {
    this->Close();
    MenuInterface->StartHostGameAction();
}

void UMainMenu::JoinToHostGameButtonOnClicked(){
    this->Close();
    MenuInterface->JoinToHostGameAction();
}

bool UMainMenu::Initialize() {
    bool Success = Super::Initialize();
    if(!Success) return false;
 
    StartHostGameButton->OnClicked.AddDynamic(this, &UMainMenu::StartHostGameButtonOnClicked);
    JoinToHostGameButton->OnClicked.AddDynamic(this, &UMainMenu::JoinToHostGameButtonOnClicked);
    return true;
}

void UMainMenu::Setup(IMenuInterface* menuInterface) {
    if(Assert::NotNull(menuInterface, "MenuInterface")) return;
    MenuInterface = menuInterface;

    this->AddToViewport();

    FInputModeUIOnly InputModeData;
    InputModeData.SetWidgetToFocus(this->TakeWidget());
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

    UWorld* World = GetWorld();
    if(Assert::NotNull(World, "World"))  return;

    APlayerController* PlayerController = World->GetFirstPlayerController(); 
    if(Assert::NotNull(PlayerController, "PlayerController"))  return;

    PlayerController->SetInputMode(InputModeData);
    PlayerController->bShowMouseCursor = true;
}

void UMainMenu::Close() {
    this->RemoveFromViewport();

    UWorld* World = GetWorld();
    if(Assert::NotNull(World, "World"))  return;

    APlayerController* PlayerController = World->GetFirstPlayerController(); 
    if(Assert::NotNull(PlayerController, "PlayerController"))  return;

	FInputModeGameOnly InputModeData;
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = false;
}

void UMainMenu::Show(
    UWorld* World,
    UClass* WidgetClass,
    IMenuInterface* menuInterface
) {
    if(Assert::NotNull(World, "World"))  return;
    if(Assert::NotNull(WidgetClass, "MainMenuWidgetClass")) return;
    if(Assert::NotNull(menuInterface, "MenuInterface")) return;

    APlayerController* PlayerController = World->GetFirstPlayerController(); 
    if(Assert::NotNull(PlayerController, "PlayerController"))  return;

    UMainMenu* MainMenu = CreateWidget<UMainMenu>(PlayerController, WidgetClass);
    if(Assert::NotNull(MainMenu, "MainMenuWidget")) return;

    MainMenu->Setup(menuInterface);
}

#include "MainMenu.h"
#include "../Utils.h"

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void UMainMenu::StartHostGameButtonOnClicked() {
    if(Assert::NotNull(MenuInterface, "MenuInterface")) return;
    MenuInterface->StartHostGameAction();
}

void UMainMenu::JoinToHostGameButtonOnClicked(){
    if(Assert::NotNull(MenuInterface, "MenuInterface")) return;
    MenuInterface->JoinToHostGameAction();
}

void UMainMenu::SetMenuInterface(IMenuInterface* menuInterface) { this->MenuInterface = menuInterface; }

bool UMainMenu::Initialize() {
    bool Success = Super::Initialize();
    if(!Success) return false;
 
    StartHostGameButton->OnClicked.AddDynamic(this, &UMainMenu::StartHostGameButtonOnClicked);
    JoinGameButton->OnClicked.AddDynamic(this, &UMainMenu::JoinToHostGameButtonOnClicked);
    return true;
}

UMainMenu* UMainMenu::CreateAndShow(
    APlayerController* PlayerController, 
    UClass* WidgetClass,
    IMenuInterface* MenuInterface
) {
    if(Assert::NotNull(PlayerController, "PlayerController"))  return nullptr;
    if(Assert::NotNull(WidgetClass, "MainMenuWidgetClass")) return nullptr;

    UMainMenu* MainMenu = CreateWidget<UMainMenu>(PlayerController, WidgetClass);
    if(Assert::NotNull(MainMenu, "MainMenuWidget")) return nullptr;
    MainMenu->AddToViewport();

    if(Assert::NotNull(MenuInterface, "MenuInterface")) return nullptr;
    MainMenu->SetMenuInterface(MenuInterface);

    FInputModeUIOnly InputModeData;
    InputModeData.SetWidgetToFocus(MainMenu->TakeWidget());
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    PlayerController->SetInputMode(InputModeData);
    PlayerController->bShowMouseCursor = true;

    return MainMenu;
}

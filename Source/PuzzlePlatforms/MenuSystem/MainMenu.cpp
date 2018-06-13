#include "MainMenu.h"

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------
bool UMainMenu::Initialize() {
    bool Success = Super::Initialize();
    if(!Success) return false;

    StartHostGameButton->OnClicked.AddDynamic(this, &UMainMenu::StartHostGameButtonOnClicked);
    JoinToHostGameButton->OnClicked.AddDynamic(this, &UMainMenu::JoinToHostGameButtonOnClicked);
    JoinBackButton->OnClicked.AddDynamic(this, &UMainMenu::JoinBackButtonOnClicked);
    JoinButton->OnClicked.AddDynamic(this, &UMainMenu::JoinButtonOnClicked);
    QuitButton->OnClicked.AddDynamic(this, &UMainMenu::QuitButtonOnClicked);
    return true;
}

void UMainMenu::StartHostGameButtonOnClicked() {
    this->Close();
    Controller->StartHostGameAction();
}
void UMainMenu::JoinButtonOnClicked() {
    FString IPAddress = IPAddressTextBox->Text.ToString();
    if(IPAddress.IsEmpty()) return;
    this->Close();
    Controller->JoinToHostGameAction(IPAddress);
}

void UMainMenu::JoinToHostGameButtonOnClicked() { MenuSwitcher->SetActiveWidget(JoinMenu); }
void UMainMenu::JoinBackButtonOnClicked() { MenuSwitcher->SetActiveWidget(MainMenu); }

void UMainMenu::QuitButtonOnClicked() { Controller->QuitAction(); }

void UMainMenu::Show(UWorld* World, UClass* WidgetClass, IMenuInterface* Controller) {
    if(Assert::NotNull(World, "World"))  return;
    if(Assert::NotNull(WidgetClass, "MainMenuClass")) return;
    if(Assert::NotNull(Controller, "MainMenuController")) return;

    UE_LOG(LogTemp, Warning, TEXT("Found Class: %s"), *WidgetClass->GetName());
    UMainMenu* Widget = CreateWidget<UMainMenu>(World, WidgetClass);
    if(Assert::NotNull(Widget, WidgetClass->GetName())) return;

    Widget->AddToViewport();

    FInputModeUIOnly InputModeData;
    InputModeData.SetWidgetToFocus(Widget->TakeWidget());
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

    APlayerController* PlayerController = World->GetFirstPlayerController(); 
    if(Assert::NotNull(PlayerController, "PlayerController"))  return;

    PlayerController->SetInputMode(InputModeData);
    PlayerController->bShowMouseCursor = true;

    Widget->SetController(Controller);
}

void UMainMenu::SetController(IMenuInterface* controller) { this->Controller = controller; }
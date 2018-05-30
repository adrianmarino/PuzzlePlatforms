#include "ScreenMenu.h"

bool UScreenMenu::Initialize() {
    bool Success = Super::Initialize();
    if(!Success) return false;

    CancelButton->OnClicked.AddDynamic(this, &UScreenMenu::CancelButtonOnClicked);
    LeaveGameButton->OnClicked.AddDynamic(this, &UScreenMenu::LeaveGameButtonOnClicked);
    return true;
}

void UScreenMenu::CancelButtonOnClicked() {
    this->Close();
    Controller->CancelAction();
}

void UScreenMenu::LeaveGameButtonOnClicked() {
    this->Close();
    Controller->LeaveGameAction();
}

void UScreenMenu::Show(UWorld* World, UClass* WidgetClass, IScreenMenuInterface* Controller) {
    if(Assert::NotNull(World, "World"))  return;
    if(Assert::NotNull(WidgetClass, "ScreenMenuClass")) return;
    if(Assert::NotNull(Controller, "IScreenMenuInterface")) return;

    UScreenMenu* Widget = CreateWidget<UScreenMenu>(World, WidgetClass);
    if(Assert::NotNull(Widget, "UScreenMenu")) return;

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

void UScreenMenu::SetController(IScreenMenuInterface* controller) {
    this->Controller = controller;
}
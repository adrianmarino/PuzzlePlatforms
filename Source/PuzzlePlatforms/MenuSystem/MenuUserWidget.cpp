#include "MenuUserWidget.h"

void UMenuUserWidget::Close() {
    this->RemoveFromViewport();

    UWorld* World = GetWorld();
    if(Assert::NotNull(World, "World"))  return;

    APlayerController* PlayerController = World->GetFirstPlayerController(); 
    if(Assert::NotNull(PlayerController, "PlayerController"))  return;

	FInputModeGameOnly InputModeData;
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = false;
}
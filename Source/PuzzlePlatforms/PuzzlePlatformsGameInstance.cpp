#include "PuzzlePlatformsGameInstance.h"

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance() {
    BlueprintUtils::WidgetClassFrom(
        MAIN_MENU_BP_PATH, 
        [&](UClass* Class) { MainMenuClass = Class; }
    );
    UE_LOG(LogTemp, Warning, TEXT("Construct Game Instance!"));
}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void UPuzzlePlatformsGameInstance::Init() {
    UE_LOG(LogTemp, Warning, TEXT("Initialize Game Instance!"));    
}

void UPuzzlePlatformsGameInstance::LoadMainMenu() {
    UMainMenu::Show(GetWorld(), MainMenuClass, this);
}

void UPuzzlePlatformsGameInstance::StartHostGameAction() { GameCommand::StartHostGame(GetWorld()); };

void UPuzzlePlatformsGameInstance::JoinToHostGameAction(FString& IPAddress) {
    GameCommand::JoinToHostGame(GetFirstLocalPlayerController(), IPAddress);
}

void UPuzzlePlatformsGameInstance::StartHostGame() { GameCommand::StartHostGame(GetWorld()); }

void UPuzzlePlatformsGameInstance::JoinToHostGame(FString& IPAddress) { 
    GameCommand::JoinToHostGame(GetFirstLocalPlayerController(), IPAddress);
}
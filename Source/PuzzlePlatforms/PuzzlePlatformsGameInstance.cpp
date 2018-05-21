#include "PuzzlePlatformsGameInstance.h"

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance() {
    BlueprintUtils::WidgetClassFrom(MAIN_MENU_BP_PATH, [&](UClass* Class) { MenuClass = Class; });
    UE_LOG(LogTemp, Warning, TEXT("Construct Game Instance!"));
}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void UPuzzlePlatformsGameInstance::Init() {
    UE_LOG(LogTemp, Warning, TEXT("Found Class: %s"), *MenuClass->GetName());
    UE_LOG(LogTemp, Warning, TEXT("Initialize Game Instance!"));
    
}

void UPuzzlePlatformsGameInstance::LoadMainMenu() { 
    GameCommand::LoadMainMenu(GetFirstLocalPlayerController(), *MenuClass);
}

void UPuzzlePlatformsGameInstance::StartHostGame() { GameCommand::StartHostGame(GetWorld()); }

void UPuzzlePlatformsGameInstance::JoinToHostGame(FString Address) { 
    GameCommand::JoinToHostGame(GetFirstLocalPlayerController(), Address);
}
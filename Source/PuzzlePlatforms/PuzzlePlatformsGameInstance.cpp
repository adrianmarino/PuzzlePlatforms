#include "PuzzlePlatformsGameInstance.h"

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance() {
    UE_LOG(LogTemp, Warning, TEXT("Construct Game Instance!"));
}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void UPuzzlePlatformsGameInstance::Init() { UE_LOG(LogTemp, Warning, TEXT("Initialize Game Instance!")); }

void UPuzzlePlatformsGameInstance::StartHostGame() { GameCommand::StartHostGame(GetWorld()); }

void UPuzzlePlatformsGameInstance::JoinToHostGame(FString Address) { 
    GameCommand::JoinToHostGame(GetFirstLocalPlayerController(), Address);
}
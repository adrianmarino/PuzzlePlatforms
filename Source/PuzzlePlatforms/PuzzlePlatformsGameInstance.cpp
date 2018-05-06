#include "PuzzlePlatformsGameInstance.h"

void UPuzzlePlatformsGameInstance::StartHostGame() { 
    GameCommand::StartHostGame(GetWorld());
}

void UPuzzlePlatformsGameInstance::JoinToHostGame(FString Address) { 
    GameCommand::JoinToHostGame(GetWorld(), Address);
}

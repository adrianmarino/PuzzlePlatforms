#include "PuzzlePlatformsPlayerController.h"

void APuzzlePlatformsPlayerController::BeginPlay() { Screen::Info(TEXT("Start Player!")); };

void APuzzlePlatformsPlayerController::Players() {  GameCommand::Players(GetWorld()); }
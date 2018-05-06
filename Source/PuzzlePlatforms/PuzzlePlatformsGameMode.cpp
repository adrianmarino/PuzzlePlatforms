#include "PuzzlePlatformsGameMode.h"

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

APuzzlePlatformsGameMode::APuzzlePlatformsGameMode() {
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL) {
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	//tell your custom game mode to use your custom player controller
    PlayerControllerClass = APuzzlePlatformsPlayerController::StaticClass();

    // GameStateClass = ACustomGameState::StaticClass();
    // HUDClass = ACustomGameHUD::StaticClass();
    // ReplaySpectatorPlayerControllerClass = ACustomReplaySpectatorPlayerController::StaticClass();
    // SpectatorClass = ACustomSpectatorClass::StaticClass();
}

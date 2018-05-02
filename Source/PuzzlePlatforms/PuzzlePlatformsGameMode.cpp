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
}
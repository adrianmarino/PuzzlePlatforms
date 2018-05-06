#pragma once

#include "PuzzlePlatforms.h"
#include "GameFramework/GameModeBase.h"
#include "PuzzlePlatformsCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "PuzzlePlatformsPlayerController.h"
#include "PuzzlePlatformsGameMode.generated.h"

UCLASS(minimalapi)
class APuzzlePlatformsGameMode : public AGameModeBase
{
	GENERATED_BODY()

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

public:
	APuzzlePlatformsGameMode();
};




#pragma once

#include "PuzzlePlatforms.h"
#include "PuzzlePlatformsPlayerController.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API APuzzlePlatformsPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void Players();

    virtual void BeginPlay() override;
};

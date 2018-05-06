#pragma once

#include "PuzzlePlatforms.h"
#include "PuzzlePlatformsGameInstance.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void StartHostGame();

	UFUNCTION(Exec)
	void JoinToHostGame(FString Address);
};

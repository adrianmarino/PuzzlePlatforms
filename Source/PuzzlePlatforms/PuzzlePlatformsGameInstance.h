#pragma once

#include "PuzzlePlatforms.h"
#include "Engine/Engine.h"
#include "PuzzlePlatformsGameInstance.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPuzzlePlatformsGameInstance();

	virtual void Init() override;

	UFUNCTION(Exec)
	void StartHostGame();

	UFUNCTION(Exec)
	void JoinToHostGame(FString Address);
};

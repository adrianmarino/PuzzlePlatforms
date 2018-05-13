#pragma once

#include "PuzzlePlatforms.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "PuzzlePlatformsGameInstance.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance
{
	GENERATED_BODY()

//-----------------------------------------------------------------------------
// Constants
//-----------------------------------------------------------------------------

private:
	const TCHAR* MAIN_MENU_BP = TEXT("/Game/PuzzlePlatforms/BP/BP_PlatformTrigger");

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

public:
	UPuzzlePlatformsGameInstance();

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

public:
	virtual void Init() override;

	UFUNCTION(Exec)
	void StartHostGame();

	UFUNCTION(Exec)
	void JoinToHostGame(FString Address);
};

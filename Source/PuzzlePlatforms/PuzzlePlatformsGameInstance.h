#pragma once

#include "PuzzlePlatforms.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "PuzzlePlatformsGameInstance.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance
{
	GENERATED_BODY()

//-----------------------------------------------------------------------------
// Constants
//-----------------------------------------------------------------------------
private:
	const TCHAR* MAIN_MENU_BP = TEXT("/Game/MenuSystem/WBP_MainMenu");

//-----------------------------------------------------------------------------
// Attributes
//-----------------------------------------------------------------------------
private:
	TSubclassOf<UUserWidget> MenuClass;

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

#pragma once

#include "PuzzlePlatforms.h"
#include "Engine/Engine.h"

#include "MenuSystem/MenuInterface.h"
#include "MenuSystem/MainMenu.h"
#include "MenuSystem/ScreenMenuInterface.h"
#include "MenuSystem/ScreenMenu.h"

#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "PuzzlePlatformsGameInstance.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : 	public UGameInstance, 
															public IMenuInterface,
															public IScreenMenuInterface
{
	GENERATED_BODY()

//-----------------------------------------------------------------------------
// Constants
//-----------------------------------------------------------------------------
private:
	const TCHAR* MAIN_MENU_BP_PATH = TEXT("/Game/MenuSystem/WBP_MainMenu");

	const TCHAR* SCREEN_MENU_BP_PATH = TEXT("/Game/MenuSystem/WBP_ScreenMenu");

//-----------------------------------------------------------------------------
// Attributes
//-----------------------------------------------------------------------------
private:
	TSubclassOf<class UUserWidget> MainMenuClass;

	TSubclassOf<class UUserWidget> ScreenMenuClass;

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

	UFUNCTION(BluePrintCallable)
	void LoadMainMenu();

	UFUNCTION(BlueprintCallable)
	void LoadScreenMenu();

	UFUNCTION(Exec)
	void StartHostGame();

	UFUNCTION(Exec)
	void JoinToHostGame(FString& IPAddress);

	virtual void StartHostGameAction() override;

	virtual void JoinToHostGameAction(FString& IPAddress) override;

	virtual void CancelAction() override;

	virtual void LeaveGameAction() override;
};

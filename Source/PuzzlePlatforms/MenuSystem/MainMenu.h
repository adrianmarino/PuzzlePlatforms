#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

//-----------------------------------------------------------------------------
// Attributes
//-----------------------------------------------------------------------------
private:
	IMenuInterface* MenuInterface;

protected:
	UPROPERTY(meta = (BindWidget))
	UButton* StartHostGameButton;

	UPROPERTY(meta = (BindWidget))
	UButton* JoinGameButton;

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------
public:
	void SetMenuInterface(IMenuInterface* menuInterface);

	static UMainMenu* CreateAndShow(
		APlayerController* PlayerController, 
		UClass* WidgetClass,
		IMenuInterface* MenuInterface
	);

protected:
	virtual bool Initialize();

	UFUNCTION()
	void StartHostGameButtonOnClicked();

	UFUNCTION()
	void JoinToHostGameButtonOnClicked();
};
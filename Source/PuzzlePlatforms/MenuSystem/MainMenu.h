#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"
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
	UButton* JoinToHostGameButton;

	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	UButton* JoinBackButton;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* IPAddressTextBox;

	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	UWidget* MainMenu;

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------
public:
	void Close();

	static void Show(
		UWorld* World,
		UClass* WidgetClass,
		IMenuInterface* menuInterface
	);

protected:
	void Setup(IMenuInterface* menuInterface);

	virtual bool Initialize();

	UFUNCTION()
	void StartHostGameButtonOnClicked();

	UFUNCTION()
	void JoinToHostGameButtonOnClicked();

	UFUNCTION()
	void JoinBackButtonOnClicked();

	UFUNCTION()
	void JoinButtonOnClicked();
};
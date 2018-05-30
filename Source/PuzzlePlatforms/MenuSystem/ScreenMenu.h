#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "ScreenMenuInterface.h"
#include "MenuUserWidget.h"
#include "ScreenMenu.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API UScreenMenu : public UMenuUserWidget
{
	GENERATED_BODY()

//-----------------------------------------------------------------------------
// Attributes
//-----------------------------------------------------------------------------
private:
	IScreenMenuInterface* Controller;

protected:
	UPROPERTY(meta = (BindWidget))
	UButton* CancelButton;

	UPROPERTY(meta = (BindWidget))
	UButton* LeaveGameButton;

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------
public:
	void SetController(IScreenMenuInterface* controller);

	static void Show(UWorld* World, UClass* WidgetClass, IScreenMenuInterface* Controller);

protected:
	virtual bool Initialize();

	UFUNCTION()
	void CancelButtonOnClicked();

	UFUNCTION()
	void LeaveGameButtonOnClicked();
};

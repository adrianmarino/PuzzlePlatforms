#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../Utils.h"
#include "MenuUserWidget.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API UMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------
public:
	void Close();
};

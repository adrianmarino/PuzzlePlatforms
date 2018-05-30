#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ScreenMenuInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UScreenMenuInterface : public UInterface { GENERATED_BODY() };

class PUZZLEPLATFORMS_API IScreenMenuInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void CancelAction() = 0;

	virtual void LeaveGameAction() = 0;
};

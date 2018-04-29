#pragma once

#include "CoreMinimal.h"

class Screen
{
	private:
		Screen();

	//-----------------------------------------------------------------------------
	// Methods
	//-----------------------------------------------------------------------------

	public:

		static void Message(const FString& message) {
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, message);
		}
};
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

		static void Info(FString Msg) { 
			Message(TEXT("INFO: ") + Msg, FColor::White, 5);
		}

		static void Warn(FString Msg) { 
			Message(TEXT("WARN: ") + Msg, FColor::Yellow, 5);
		}

		static void Error(FString Msg) { 
			Message(TEXT("ERROR: ") + Msg, FColor::Red, 5);
		}

		static void Message(const FString Msg, FColor Color, float Delay) { 
			GEngine->AddOnScreenDebugMessage(-1, Delay, Color, Msg);
		}

		static void Error(const FString Fmt, void* Arg) {
			GEngine->AddOnScreenDebugMessage(
				-1, 
				5, 
				FColor::Red,  
				TEXT("ERROR: ") + FString::Printf(*Fmt, Arg)
			);
		}

		static void Error(const FString Fmt, void* Arg1, void* Arg2) {
			GEngine->AddOnScreenDebugMessage(
				-1, 
				5, 
				FColor::Red, 
				TEXT("ERROR: ") + FString::Printf(*Fmt, Arg1, Arg2)
			);
		}

		static void Info(const FString Fmt, void* Arg) {
			GEngine->AddOnScreenDebugMessage(
				-1, 
				5,
				FColor::White, 
				TEXT("INFO: ") + FString::Printf(*Fmt, Arg)
			);
		}

		static void Info(const FString Fmt, void* Arg1, void* Arg2) {
			GEngine->AddOnScreenDebugMessage(
				-1, 
				5, 
				FColor::White, 
				TEXT("INFO: ") + FString::Printf(*Fmt, Arg1, Arg2)
			);
		}

		static void Warn(const FString Fmt, void* Arg) {
			GEngine->AddOnScreenDebugMessage(
				-1, 
				5,
				FColor::White,
				TEXT("WARN: ") + FString::Printf(*Fmt, Arg)
			);
		}

		static void Warn(const FString Fmt, void* Arg1, void* Arg2) {
			GEngine->AddOnScreenDebugMessage(
				-1, 
				5, 
				FColor::White, 
				TEXT("WARN: ") + FString::Printf(*Fmt, Arg1, Arg2)
			);
		}
};
#pragma once

#include "CoreMinimal.h"
#include "Utils.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

class GameCommand {

    public:
        static void Players(UWorld* World);
        static void StartHostGame(UWorld* World);
        static void JoinToHostGame(APlayerController* PlayerController, FString& Address);
        static void LeaveGame(APlayerController* PlayerController);

    private:
        GameCommand() {}
};
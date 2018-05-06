#pragma one

#include "Screen.h"
#include "StringUtils.h"
#include "Engine/World.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"

class GameCommand {

public:
    static void Players(UWorld* World) {
        if(Assert::NotNull(World, "World")) return;
        AGameStateBase* GameState = World->GetGameState<AGameStateBase>();        
        if(Assert::NotNull(GameState, "GameState")) return;

        FString Output = FString("Connected Players\n");
        for(APlayerState* Player: GameState->PlayerArray)
            Output += FString::Printf(
                TEXT(" => Id: %s - Name: %s"),
                *FString::FromInt(Player->PlayerId),
                *Str::Try(Player->GetPlayerName(), "Unknow")
            );
        Screen::Message(Output, FColor::Blue, 10);
    }
};
#pragma one

#include "Screen.h"
#include "StringUtils.h"
#include "Engine/World.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/PlayerState.h"

class GameCommand {
private:
    GameCommand() {}

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

    static void StartHostGame(UWorld* World) {
        if(Assert::NotNull(World, "World")) return;
        Screen::Info(TEXT("Start Host Game!"));
        World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
    }

    static void JoinToHostGame(APlayerController* PlayerController, FString Address) {
        if(Assert::NotNull(PlayerController, "PlayerController")) return;
        Screen::Info(FString::Printf(TEXT("Join to Game in %s adress"), *Address));
        PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
    }
};
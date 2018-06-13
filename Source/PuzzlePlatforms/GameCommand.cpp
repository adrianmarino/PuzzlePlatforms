#include "GameCommand.h"

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void GameCommand::Players(UWorld* World) {
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

void GameCommand::StartHostGame(UWorld* World) {
    if(Assert::NotNull(World, "World")) return;

    Screen::Info(TEXT("Start Host Game!"));
    World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void GameCommand::LeaveGame(APlayerController* PlayerController) {
    if(Assert::NotNull(PlayerController, "PlayerController")) return; 

    Screen::Info(TEXT("Leave Game!"));
    PlayerController->ClientTravel("/Game/MenuSystem/MainMenu", ETravelType::TRAVEL_Absolute);
}

void GameCommand::JoinToHostGame(APlayerController* PlayerController, FString& IPAddress) {
    if(Assert::NotNull(PlayerController, "PlayerController")) return; 

    Screen::Info(FString::Printf(TEXT("Join to Game in %s adress"), *IPAddress));
    PlayerController->ClientTravel(IPAddress, ETravelType::TRAVEL_Absolute);
}
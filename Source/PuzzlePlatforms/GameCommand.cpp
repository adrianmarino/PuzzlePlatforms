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

void GameCommand::JoinToHostGame(APlayerController* PlayerController, FString Address) {
    if(Assert::NotNull(PlayerController, "PlayerController")) return; 

    Screen::Info(FString::Printf(TEXT("Join to Game in %s adress"), *Address));
    PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

void GameCommand::LoadMainMenu(APlayerController* PlayerController, UClass* WidgetClass) {
    if(Assert::NotNull(PlayerController, "PlayerController")) return;
    if(Assert::NotNull(WidgetClass, "MainMenuWidgetClass")) return;

    UUserWidget* MainMenu = CreateWidget<UUserWidget>(PlayerController, WidgetClass);
    if(Assert::NotNull(MainMenu, "MainMenuWidget")) return;
    MainMenu->AddToViewport();

    FInputModeUIOnly InputModeData;
    InputModeData.SetWidgetToFocus(MainMenu->TakeWidget());
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    PlayerController->SetInputMode(InputModeData);
    PlayerController->bShowMouseCursor = true;
}
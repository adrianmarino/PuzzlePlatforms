#include "PuzzlePlatformsGameInstance.h"

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance() {
    static ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
    if(Assert::NotNull(*MenuBPClass.Class, "MenuBPClass")) return;
	MenuClass = MenuBPClass.Class;
    UE_LOG(LogTemp, Warning, TEXT("Construct Game Instance!"));
}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void UPuzzlePlatformsGameInstance::Init() {
    UE_LOG(LogTemp, Warning, TEXT("Found Class: %s"), *MenuClass->GetName());
    UE_LOG(LogTemp, Warning, TEXT("Initialize Game Instance!"));
}

void UPuzzlePlatformsGameInstance::StartHostGame() { GameCommand::StartHostGame(GetWorld()); }

void UPuzzlePlatformsGameInstance::JoinToHostGame(FString Address) { 
    GameCommand::JoinToHostGame(GetFirstLocalPlayerController(), Address);
}
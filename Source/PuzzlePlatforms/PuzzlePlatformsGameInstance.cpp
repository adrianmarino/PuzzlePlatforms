#include "PuzzlePlatformsGameInstance.h"
#include "PlatformTrigger.h"

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance() {
	static ConstructorHelpers::FClassFinder<APlatformTrigger> PlatformTriggerBPClassFinder(MAIN_MENU_BP);
    Assert::NotNull(&PlatformTriggerBPClassFinder);

    FString* prueba = nullptr;
    
    Assert::NotNull(prueba);
 
    UE_LOG(LogTemp, Warning, TEXT("Found %s class"), *PlatformTriggerBPClassFinder.Class->GetName());
}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void UPuzzlePlatformsGameInstance::Init() { UE_LOG(LogTemp, Warning, TEXT("Initialize Game Instance!")); }

void UPuzzlePlatformsGameInstance::StartHostGame() { GameCommand::StartHostGame(GetWorld()); }

void UPuzzlePlatformsGameInstance::JoinToHostGame(FString Address) { 
    GameCommand::JoinToHostGame(GetFirstLocalPlayerController(), Address);
}
#pragma once

#include "PuzzlePlatforms.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MovingPlatform.h"
#include "PlatformTrigger.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API APlatformTrigger : public AActor
{
	GENERATED_BODY()

//-----------------------------------------------------------------------------
// Attributes
//-----------------------------------------------------------------------------

private:
	UPROPERTY(
		VisibleAnywhere,
		BlueprintReadWrite,
		Category = "Platform Trigger", 
		meta = (AllowPrivateAccess = true)
	)
	UBoxComponent* TriggerVolume;

	UPROPERTY(
		VisibleAnywhere, 
		BlueprintReadWrite,
		Category = "Platform Trigger",
		meta = (AllowPrivateAccess = true)
	)
	UStaticMeshComponent* Mesh;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "Platform Trigger", 
		meta = (AllowPrivateAccess = true)
	)
	TArray<AMovingPlatform*> Platforms;

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

public:
	APlatformTrigger();

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

private:
	UFUNCTION()
	void OnOverlapBegin(
		class UPrimitiveComponent* OverlappedComp, 
		class AActor* OtherActor, 
		class UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, 
		bool bFromSweep, 
		const FHitResult& SweepResult
	);

	UFUNCTION()
	void OnOverlapEnd(
		UPrimitiveComponent* OverlappedComp, 
		AActor* OtherActor, 
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex
	);
};

#pragma once

#include "PuzzlePlatforms.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MovingPlatform.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

//-----------------------------------------------------------------------------
// Attributes
//-----------------------------------------------------------------------------

private:
	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "Moving Platform", 
		meta = (AllowPrivateAccess = true, MakeEditWidget = true)
	)
	FVector LocalInicial;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "Moving Platform", 
		meta = (AllowPrivateAccess = true, MakeEditWidget = true)
	)
	FVector LocalTarget;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "Moving Platform", 
		meta = (AllowPrivateAccess = true)
	)
	float Speed = 200;

	UPROPERTY(
		VisibleAnywhere, 
		BlueprintReadWrite,
		Category = "Moving Platform",
		meta = (AllowPrivateAccess = true)
	)
	UStaticMeshComponent* Mesh;

	UPROPERTY(
		VisibleAnywhere,
		BlueprintReadWrite,
		Category = "Moving Platform", 
		meta = (AllowPrivateAccess = true)
	)
	UBoxComponent* Collider;

	TrackWalker* ActorTrack;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "Moving Platform", 
		meta = (AllowPrivateAccess = true)
	)
	int Activations = 1;

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

public:
	AMovingPlatform();

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

public:
	virtual void Tick(float DeltaTime) override;

	void AddActivation();

	void RemoveActivation();

	bool IsActive();

protected:
	virtual void BeginPlay() override;

private:
	UBoxComponent* InitializeCollider(USceneComponent* Parent);

	UStaticMeshComponent* InitializeMesh(UBoxComponent* Parent);

	UFUNCTION()
	void OnOverlapBegin(
		class UPrimitiveComponent* OverlappedComp, 
		class AActor* OtherActor, 
		class UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, 
		bool bFromSweep,
		const FHitResult& SweepResult
	);
};

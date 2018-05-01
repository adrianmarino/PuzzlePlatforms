#pragma once

#include "PuzzlePlatforms.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MovingPlatform.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

public:

	AMovingPlatform();

	UBoxComponent* InitializeCollider(USceneComponent* Parent);

	UStaticMeshComponent* InitializeMesh(UBoxComponent* Parent);

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(
		class UPrimitiveComponent* OverlappedComp, 
		class AActor* OtherActor, 
		class UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, 
		bool bFromSweep,
		const FHitResult& SweepResult
	);

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
		EditAnywhere, 
		BlueprintReadWrite,
		Category = "Moving Platform",
		meta = (AllowPrivateAccess = true)
	)
	UStaticMeshComponent* Mesh;

	UPROPERTY(
		EditAnywhere,
		BlueprintReadWrite,
		Category = "Moving Platform", 
		meta = (AllowPrivateAccess = true)
	)
	UBoxComponent* Collider;

	TrackWalker* ActorTrack;
};

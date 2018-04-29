#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform() {
    PrimaryActorTick.bCanEverTick= true;
    
    BoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("MovingPlatformCollider"));
    BoxCollider->SetCollisionProfileName(TEXT("MovingPlatformCollider"));
    BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AMovingPlatform::OnOverlapBegin);

    BoxCollider->SetupAttachment(RootComponent);
    RootComponent = BoxCollider; 

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MovingPlatformMesh"));
    Mesh->SetupAttachment(BoxCollider);
}

void AMovingPlatform::OnOverlapBegin(
	class UPrimitiveComponent* OverlappedComp, 
	class AActor* OtherActor, 
	class UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& SweepResult
) {
    Screen::Message(TEXT("Algo!"));
    
    AActor* Actor = Cast<AActor>(OtherActor);
	if(Actor == nullptr) return;

    Screen::Message(TEXT("Collision: " + Actor->GetName()));
    Speed *= -1;
}

void AMovingPlatform::BeginPlay() {
    Super::BeginPlay();
    if(HasAuthority()) {
        SetReplicates(true);
        SetReplicateMovement(true);
    }
}

void AMovingPlatform::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
     if(HasAuthority())
        SetActorLocation(GetActorLocation() + (FVector::ForwardVector * Speed * DeltaTime));
}

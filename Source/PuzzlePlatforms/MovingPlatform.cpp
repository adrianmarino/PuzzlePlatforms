#include "MovingPlatform.h"

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

AMovingPlatform::AMovingPlatform() {
    PrimaryActorTick.bCanEverTick= true;
    Collider = this->InitializeCollider(RootComponent);
    Mesh = this->InitializeMesh(Collider);
}

//-----------------------------------------------------------------------------
// Intializers
//-----------------------------------------------------------------------------

UBoxComponent* AMovingPlatform::InitializeCollider(USceneComponent* Parent) {        
    UBoxComponent* collider = CreateDefaultSubobject<UBoxComponent>(TEXT("MovingPlatformCollider"));
    collider->SetCollisionProfileName(TEXT("MovingPlatformCollider"));
 
    // Detect overlaing with other objects...
    collider->OnComponentBeginOverlap.AddDynamic(this, &AMovingPlatform::OnOverlapBegin);
 
    // Nest to actor...
    collider->SetupAttachment(Parent);
    Parent = collider; 

    return collider;
}

UStaticMeshComponent* AMovingPlatform::InitializeMesh(UBoxComponent* Parent) {
    UStaticMeshComponent* mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MovingPlatformMesh"));
    mesh->SetupAttachment(Parent);
    return mesh;
}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void AMovingPlatform::BeginPlay() {
    Super::BeginPlay();
    ActorTrack = new TrackWalker(this, LocalInicial, LocalTarget, Speed);
    if(HasAuthority()) {
        SetReplicates(true);
        SetReplicateMovement(true);
    }
}

void AMovingPlatform::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);
    if(HasAuthority() && IsActive()) ActorTrack->Update(DeltaTime);
}

void AMovingPlatform::OnOverlapBegin(
	class UPrimitiveComponent* OverlappedComp, 
	class AActor* OtherActor, 
	class UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& SweepResult
) {
    AActor* Actor = Cast<AActor>(OtherActor);
	if(Actor == nullptr) return;

    // Screen::Info(TEXT("Plaforform Collision! Invert direction."));
    ActorTrack->InvertDirection();
}

bool AMovingPlatform::IsActive() { return Activations > 0; }

void AMovingPlatform::AddActivation() { Activations += 1; }

void AMovingPlatform::RemoveActivation() { if(IsActive()) Activations -= 1; }

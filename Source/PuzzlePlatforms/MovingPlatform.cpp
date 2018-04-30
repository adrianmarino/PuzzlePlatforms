#include "MovingPlatform.h"

//-----------------------------------------------------------------------------
// Constructors / Destructor
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

void AMovingPlatform::OnOverlapBegin(
	class UPrimitiveComponent* OverlappedComp, 
	class AActor* OtherActor, 
	class UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& SweepResult
) {
    Screen::Message(OtherActor->GetName());

    AActor* Actor = Cast<AActor>(OtherActor);
	if(Actor == nullptr) return;

    Screen::Message(TEXT("Collision!"));
    Speed = Speed * -1; 
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
    if(HasAuthority()) {
        FVector Traget = GetTransform().TransformPosition(TargetLocation);
        FVector Direction = VectorUtils::Direction(GetActorLocation(), Traget);
        FVector Increment = Direction * Speed * DeltaTime;
        SetActorLocation(GetActorLocation() + Increment);
    }
}
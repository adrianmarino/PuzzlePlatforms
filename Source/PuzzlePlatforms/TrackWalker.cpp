#include "TrackWalker.h"

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

TrackWalker::TrackWalker(
    AActor* actor, 
    FVector localInitialLocation,
    FVector localTargetLocation, 
    float speed
) {
    this->GlobalInitialLocation =  actor->GetTransform().TransformPosition(localInitialLocation);
    this->GlobalEndLocation = actor->GetTransform().TransformPosition(localTargetLocation);
    this->Actor = actor;
    this->Speed = speed;
}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void TrackWalker::Update(float deltaTime) { 
    if(LimitReached()) {
        Screen::Message(TEXT("Limit reached! Invert direction!"));
        InvertDirection();
    }
    ActorLocation(ActorLocation() + Step(deltaTime));
}

FVector TrackWalker::Step(float deltaTime) { return Speed * deltaTime * Direction(); }

void TrackWalker::ActorLocation(FVector location) { Actor->SetActorLocation(location); }

FVector TrackWalker::ActorLocation() { return Actor->GetActorLocation(); }

FVector TrackWalker::Direction() { 
    return VectorUtils::Direction(GlobalInitialLocation, GlobalEndLocation);
}

bool TrackWalker::LimitReached() {
    return FVector::Dist(ActorLocation(), GlobalInitialLocation) <= 5 ||
    FVector::Dist(ActorLocation(), GlobalEndLocation) <= 5;
}

void TrackWalker::InvertDirection() {
    FVector Inicial = GlobalInitialLocation;
    GlobalInitialLocation = GlobalEndLocation;
    GlobalEndLocation = Inicial;
}
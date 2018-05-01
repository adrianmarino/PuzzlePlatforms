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

bool TrackWalker::LimitReached() { return TrackTravelled() >= TrackLenght(); }

float TrackWalker::TrackTravelled() { return FVector::Dist(ActorLocation(), GlobalInitialLocation); }

float TrackWalker::TrackLenght() { return FVector::Dist(GlobalEndLocation, GlobalInitialLocation);}

void TrackWalker::InvertDirection() {
    FVector Swap = GlobalInitialLocation;
    GlobalInitialLocation = GlobalEndLocation;
    GlobalEndLocation = Swap;
}
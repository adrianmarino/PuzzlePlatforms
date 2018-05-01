#pragma once

#include "PuzzlePlatforms.h"
#include "GameFramework/Actor.h"

class TrackWalker {

//-----------------------------------------------------------------------------
// Attributes
//-----------------------------------------------------------------------------

private:

    FVector GlobalInitialLocation;

    FVector GlobalEndLocation;

    AActor* Actor;

    float Speed;

//-----------------------------------------------------------------------------
// Constructors
//-----------------------------------------------------------------------------

public:
    TrackWalker(
        AActor* actor, 
        FVector localInicialLocation, 
        FVector localTargetLocation, 
        float speed
    );

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

public:
    void Update(float deltaTime);

    FVector Direction();

    void InvertDirection(); 

    bool LimitReached();

    float TrackTravelled();

    float TrackLenght();

private:

    void ActorLocation(FVector location);

    FVector ActorLocation();

    FVector Step(float deltaTime);
};
#include "CoreMinimal.h"
#include <stdlib.h>

class VectorUtils {
public:
    static FVector Direction(FVector VectorA, FVector VectorB) { 
        return (VectorB - VectorA).GetSafeNormal();
    }
};
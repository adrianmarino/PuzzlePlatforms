#pragma one

#include "CoreMinimal.h"
#include "Screen.h"

class Assert {
public:
    static bool NotNull(void* Reference, FString ClassName) {
        if(Reference != nullptr) return false;
        Screen::Error(TEXT("Error: Null %s reference!"), &ClassName);
        return true;
    }

private:
    Assert() {}
};
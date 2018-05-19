#pragma one

#include "Screen.h"
#include <sstream>
#include <string>
#include <exception>

#include "CoreMinimal.h"
#include "Screen.h"

class Assert {
private:
    Assert() {}

public:
    static bool NotNull(void* Reference, FString ClassName) {
        if(Reference != nullptr) return false;
        Screen::Error(TEXT("Error: Null %s reference!"), &ClassName);
        return true;
    }
};
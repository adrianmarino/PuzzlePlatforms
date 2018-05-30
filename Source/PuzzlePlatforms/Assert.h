#pragma one

#include "CoreMinimal.h"
#include "Screen.h"

class Assert {
public:
    static bool NotNull(void* Reference, FString ClassName) {
        if(Reference != nullptr) return false;
        FString Message = FString::Printf(TEXT("Null %s reference!"), *ClassName);
        Screen::Error(Message);
        UE_LOG(LogTemp, Error, TEXT("%s"), *Message); 
        return true;
    }

private:
    Assert() {}
};
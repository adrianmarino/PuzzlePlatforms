#pragma one

#include "Containers/UnrealString.h"

class Str {
private:
    Str() {}

public:
    static FString Try(FString Value, FString Fallback) { return Value.IsEmpty() ? Fallback : Value; }
};
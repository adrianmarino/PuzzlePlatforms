#pragma one

#include "NullPointerException.h"
#include "Screen.h"

class Assert {
private:
    Assert() {}

public:
    template<typename T>
    static void NotNull(T* Reference) {
        if(Reference == nullptr) {
            throw(NullPointerException<T>(Reference));
            Screen::Error("Null reference!");
        }
    }
};
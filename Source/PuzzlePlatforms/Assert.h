#pragma one

class Assert {
private:
    Assert() {}

public:
    static bool NotNull(void* Object, FString name) {
        if(Object == nullptr) {
            Screen::Error(TEXT("%s is null!"), &name);
            return true;
        }
        return false;
    }
};
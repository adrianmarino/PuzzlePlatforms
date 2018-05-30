#pragma one

#include "CoreMinimal.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "functional"

class BlueprintUtils {

public:
    static void WidgetClassFrom(
        FString Path, 
        std::function<void(UClass*)> Handler
    ) {
        static ConstructorHelpers::FClassFinder<UUserWidget> ClassFinder(*Path);
        if(ClassFinder.Class == nullptr) {
            Screen::Error(TEXT("Not Found Widget class for %s"), &Path);
            return;
        }
        UE_LOG(LogTemp, Warning, TEXT("Found Class: %s"), *ClassFinder.Class->GetName());
        Handler(ClassFinder.Class);
    }
};
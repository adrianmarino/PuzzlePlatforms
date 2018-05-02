#include "PlatformTrigger.h"

APlatformTrigger::APlatformTrigger() {
 	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));
	TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapBegin);
	TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapEnd);

	RootComponent = TriggerVolume;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TriggerMesh"));
    Mesh->SetupAttachment(RootComponent);
}

void APlatformTrigger::OnOverlapBegin(
	class UPrimitiveComponent* OverlappedComp, 
	class AActor* OtherActor, 
	class UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& SweepResult
) {
	// Screen::Message(TEXT("Pressing Button!"));
	for(auto Platform : Platforms) Platform->AddActivation();
}

void APlatformTrigger::OnOverlapEnd(
	UPrimitiveComponent* OverlappedComp, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex
) {
	// Screen::Message(TEXT("Stop press Button!"));
	for(auto Platform: Platforms) Platform->RemoveActivation();
}


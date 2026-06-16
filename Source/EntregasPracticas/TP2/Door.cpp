#include "Door.h"
#include "Kismet/GameplayStatics.h"
#include "Altar.h"
#include "ActivatableComponent.h"
#include "Engine/Engine.h"

// IMPLEMENTACIÓN 1: 
ADoor::ADoor()
{
	PrimaryActorTick.bCanEverTick = false;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	RootComponent = DoorMesh;

	AltersActivated = 0;
}

// IMPLEMENTACIÓN 2: BeginPlay
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundAlters;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAltar::StaticClass(), FoundAlters);

	for (AActor* Actor : FoundAlters)
	{
		AAltar* Altar = Cast<AAltar>(Actor);
		if (Altar && Altar->ActivatableComponent)
		{
			Altar->ActivatableComponent->OnActivatableCompleted.AddDynamic(this, &ADoor::CheckAlters);
		}
	}
}

void ADoor::CheckAlters()
{
	AltersActivated++;

	FString Msg;
	FColor ColorMsg = FColor::Cyan;

	switch (AltersActivated)
	{
	case 1:
		Msg = TEXT("MECANISMO: Pilar [1/3] Detectado.");
		break;
	 case 2:
		Msg = TEXT("MECANISMO: Pilar [2/3] Detectado.");
		break;
	case 3:
		Msg = TEXT("MECANISMO: [3/3] ¡SISTEMA ONLINE!");
		ColorMsg = FColor::Green;
		AbrirPuerta(); // Llamamos a la función
		break;
	}}

	//if(GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(1, 5.f, ColorMsg, Msg);
	//};


// IMPLEMENTACIÓN 3: AbrirPuerta
void ADoor::AbrirPuerta()
{
//	UE_LOG(LogTemp, Warning, TEXT("Puerta abierta con éxito."));
//	Destroy(); 
}
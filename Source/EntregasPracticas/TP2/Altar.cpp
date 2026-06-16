#include "Altar.h"

#include "ActivatableComponent.h" 

AAltar::AAltar()
{
	PrimaryActorTick.bCanEverTick = false;

	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	
	ActivatableComponent = CreateDefaultSubobject<UActivatableComponent>(TEXT("ActivatableComponent"));
}

void AAltar::BeginPlay()
{
	Super::BeginPlay();
}


void AAltar::Interact_Implementation(AActor* Interactor)
{
	if (ActivatableComponent)
	{
		
		ActivatableComponent->StartActivation();
		
		//UE_LOG(LogTemp, Warning, TEXT("El Altar recibio la interaccion."));
	}
}

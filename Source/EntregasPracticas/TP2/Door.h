#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class ENTREGASPRACTICAS_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// DECLARACIÓN 1: El Constructor
	ADoor();

protected:
	// DECLARACIÓN 2: BeginPlay
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* DoorMesh;

	int32 AltersActivated;

	// Función para recibir la señal del altar
	UFUNCTION()
	void CheckAlters();

	// DECLARACIÓN 3: AbrirPuerta
	void AbrirPuerta();
};
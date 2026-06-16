#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActivatableComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActivatableCompleted);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ENTREGASPRACTICAS_API UActivatableComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UActivatableComponent();

	// Evento para la puerta
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnActivatableCompleted OnActivatableCompleted;

	// Variables para el tiempo
	UPROPERTY(EditAnywhere, Category = "Config")
	float ActivationTime = 3.0f;

	FTimerHandle ActivationTimerHandle;

	// Funciones que el .cpp reclamaba
	void StartActivation();
	void FinishActivation();

protected:
	virtual void BeginPlay() override;
};
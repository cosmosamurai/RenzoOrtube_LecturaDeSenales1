#include "ActivatableComponent.h"
#include "TimerManager.h"
#include "Engine/Engine.h" 

UActivatableComponent::UActivatableComponent()
{
	
	PrimaryComponentTick.bCanEverTick = false;
}

void UActivatableComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UActivatableComponent::StartActivation()
{

	if (GEngine)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Activando mecanismo... Mantenete cerca."));
	}

	// Iniciamos el timer de 3 segundos
	GetWorld()->GetTimerManager().SetTimer(ActivationTimerHandle, this, &UActivatableComponent::FinishActivation, ActivationTime, false);
}

void UActivatableComponent::FinishActivation()
{
	// Cuando termina el tiempo, avisamos a la puerta
	OnActivatableCompleted.Broadcast();
	
	if (GEngine)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Orange, TEXT("¡Pilar Cargado!"));
	}
}
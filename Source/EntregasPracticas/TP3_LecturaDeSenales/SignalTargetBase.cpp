#include "SignalTargetBase.h"

ASignalTargetBase::ASignalTargetBase()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsActive = true; // Activo por defecto, listo para ser detectado
}

void ASignalTargetBase::BeginPlay()
{
	Super::BeginPlay();
}

FSignalObjectData ASignalTargetBase::GetSignalData_Implementation() const
{
	return TargetData;
}

bool ASignalTargetBase::IsActiveSignal_Implementation() const
{
	return bIsActive;
}

void ASignalTargetBase::OnDetected_Implementation()
{
	bIsActive = false; // Se marca como inactivo tras ser escaneado (Punto 7)

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("Objeto procesado y desactivado."));
}
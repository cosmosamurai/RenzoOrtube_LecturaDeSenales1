#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SignalInteractable.h"
#include "SignalTargetBase.generated.h"

UCLASS()
class ENTREGASPRACTICAS_API ASignalTargetBase : public AActor, public ISignalInteractable
{
	GENERATED_BODY()

public:
	ASignalTargetBase();

protected:
	virtual void BeginPlay() override;

	// Datos configurables de este objeto (Punto 5)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Signal Configuration")
	FSignalObjectData TargetData;

	// Estado interno obligatorio (Punto 7)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Signal State")
	bool bIsActive;

public:
	// Implementación de la Interfaz
	virtual FSignalObjectData GetSignalData_Implementation() const override;
	virtual bool IsActiveSignal_Implementation() const override;
	virtual void OnDetected_Implementation() override;
};
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SignalInteractable.h"
#include "SignalScannerComponent.generated.h"

// Delegado para notificar cuando se escanea un objeto (Punto 6)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnObjectScanned, const FSignalObjectData&, ScannedData);

// Delegado para notificar la fuerza del pulso (0 a 1) cada frame (Punto 6)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSignalPulse, float, PulseStrength);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ENTREGASPRACTICAS_API USignalScannerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USignalScannerComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Función para disparar el escaneo mediante LineTrace (Punto 4)
	UFUNCTION(BlueprintCallable, Category="Scanner")
	void ScanForSignal();

	// Códice de objetos escaneados (Punto 8)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Scanner|Codex")
	TArray<FSignalObjectData> ScannedCodex;

	// Evento al detectar/escanear un objeto (Punto 6)
	UPROPERTY(BlueprintAssignable, Category="Scanner|Events")
	FOnObjectScanned OnObjectScanned;

	// Evento de pulso de proximidad, se dispara cada frame con la intensidad actual (Punto 6)
	UPROPERTY(BlueprintAssignable, Category="Scanner|Events")
	FOnSignalPulse OnSignalPulse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Scanner")
	float ScanRange = 1500.0f;

	// Última intensidad de pulso calculada (0 = nada, 1 = muy cerca). Útil para HUD.
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Scanner")
	float CurrentPulseStrength = 0.0f;

private:
	// Recorre todos los objetos con la interfaz y devuelve la intensidad del más cercano
	float CalculateClosestSignalPulse();
};
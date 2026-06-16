#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SignalInteractable.generated.h"

// Estructura de Datos Obligatoria (Punto 5)
USTRUCT(BlueprintType)
struct FSignalObjectData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Signal")
	FString ObjectName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Signal")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Signal")
	float SignalRadius = 1000.0f; // Radio donde empieza a detectarse el pulso
};

UINTERFACE(MinimalAPI, BlueprintType)
class USignalInteractable : public UInterface
{
	GENERATED_BODY()
};

// Interfaz Obligatoria (Punto 3)
class ISignalInteractable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category = "Signal")
	FSignalObjectData GetSignalData() const;

	UFUNCTION(BlueprintNativeEvent, Category = "Signal")
	bool IsActiveSignal() const;

	UFUNCTION(BlueprintNativeEvent, Category = "Signal")
	void OnDetected();
};
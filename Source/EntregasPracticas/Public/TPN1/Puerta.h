// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puerta.generated.h"

class UStaticMeshComponent;
class USceneComponent;


UCLASS()
class ENTREGASPRACTICAS_API APuerta : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuerta();
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere);
	TObjectPtr<UStaticMeshComponent> HojaIzquierda;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere);
	TObjectPtr<UStaticMeshComponent> HojaDerecha;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere);
	TObjectPtr<USceneComponent> Root;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere);
	bool  bAbierta;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};

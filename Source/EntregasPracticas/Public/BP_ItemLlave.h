// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BP_ItemLlave.generated.h"


class UStaticMeshComponent;

UCLASS()
class ENTREGASPRACTICAS_API ABP_ItemLlave : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABP_ItemLlave();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int CantidadDeFragmentosTotales;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int CantidadDeFragmentosRecolectados;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bActivo;
	
	UFUNCTION(BlueprintCallable)
	void ActivarLlave();
	
	UFUNCTION(BlueprintCallable)
	void DesactivarLlave();
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
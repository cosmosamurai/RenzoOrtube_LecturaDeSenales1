// Fill out your copyright notice in the Description page of Project Settings.


#include "BPC_ComponenteDeFragmentos.h"

// Sets default values for this component's properties
UBPC_ComponenteDeFragmentos::UBPC_ComponenteDeFragmentos()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UBPC_ComponenteDeFragmentos::SumarFragmentos()
{
	CantidadDeFragmentos++;
	
	GEngine->AddOnScreenDebugMessage(
	-1,
	2.0f,
	FColor::Green,
	FString::Printf(TEXT("Fragmentos %d"), CantidadDeFragmentos)
);
}

// Called when the game starts
void UBPC_ComponenteDeFragmentos::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}



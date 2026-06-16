// Fill out your copyright notice in the Description page of Project Settings.


#include "TPN1/Puerta.h"

// Sets default values
APuerta::APuerta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	HojaIzquierda = CreateDefaultSubobject<UStaticMeshComponent>("Hoja Izquierda");
	HojaDerecha = CreateDefaultSubobject<UStaticMeshComponent>("Hoja Derecha");
    Root = CreateDefaultSubobject<USceneComponent>("Root");
	
	
	SetRootComponent(Root);
	HojaIzquierda->SetupAttachment(Root);
	HojaDerecha->SetupAttachment(Root);
	
}

// Called when the game starts or when spawned
void APuerta::BeginPlay()
{
	Super::BeginPlay();
	
}



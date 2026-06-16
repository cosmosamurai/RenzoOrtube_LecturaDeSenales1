// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_ItemLlave.h"

// Sets default values
ABP_ItemLlave::ABP_ItemLlave()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	RootComponent = Mesh;
	
}

void ABP_ItemLlave::ActivarLlave()
{
	if (bActivo) return;
	bActivo = true;
	
	SetActorEnableCollision(true);	
	SetActorHiddenInGame(false);
}

void ABP_ItemLlave::DesactivarLlave()
{
	//if (!bActivo) return;
	//bActivo = false;
	
	SetActorEnableCollision(false);	
	SetActorHiddenInGame(true);
}

// Called when the game starts or when spawned
void ABP_ItemLlave::BeginPlay()
{
	Super::BeginPlay();
	DesactivarLlave();
	
}




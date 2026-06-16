// Copyright Epic Games, Inc. All Rights Reserved.

#include "EntregasPracticasGameMode.h"
#include "EntregasPracticasCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEntregasPracticasGameMode::AEntregasPracticasGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

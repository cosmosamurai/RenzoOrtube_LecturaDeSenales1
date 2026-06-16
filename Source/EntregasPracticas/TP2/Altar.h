#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
// Incluimos nuestra interfaz
#include "InteractInterface.h" 
#include "Altar.generated.h"


class UActivatableComponent; 
class UStaticMeshComponent;


UCLASS()
class ENTREGASPRACTICAS_API AAltar : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	AAltar();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComponent;

	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UActivatableComponent* ActivatableComponent;

	
	virtual void Interact_Implementation(AActor* Interactor) override;

protected:
	virtual void BeginPlay() override;
};
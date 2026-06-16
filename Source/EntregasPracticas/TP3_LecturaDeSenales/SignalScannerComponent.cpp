#include "SignalScannerComponent.h"
#include "DrawDebugHelpers.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

USignalScannerComponent::USignalScannerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void USignalScannerComponent::BeginPlay()
{
    Super::BeginPlay();
}

void USignalScannerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // Calculamos la intensidad del pulso según el objeto activo más cercano
    CurrentPulseStrength = CalculateClosestSignalPulse();

    // Notificamos al HUD / Blueprint cada frame (para mover una aguja, cambiar un sonido, etc)
    OnSignalPulse.Broadcast(CurrentPulseStrength);
}

float USignalScannerComponent::CalculateClosestSignalPulse()
{
    AActor* Owner = GetOwner();
    if (!Owner) return 0.0f;

    FVector OwnerLocation = Owner->GetActorLocation();

    // Buscamos todos los actores en el nivel (simple y suficiente para 5 objetos)
    TArray<AActor*> AllActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), AllActors);

    float BestStrength = 0.0f;

    for (AActor* Actor : AllActors)
    {
        if (!Actor || !Actor->GetClass()->ImplementsInterface(USignalInteractable::StaticClass()))
            continue;

        bool bActive = ISignalInteractable::Execute_IsActiveSignal(Actor);
        if (!bActive)
            continue; // Los ya detectados no emiten pulso

        FSignalObjectData Data = ISignalInteractable::Execute_GetSignalData(Actor);

        float Distance = FVector::Dist(OwnerLocation, Actor->GetActorLocation());

        if (Distance <= Data.SignalRadius)
        {
            // Cuanto más cerca, más fuerte: 1 = encima del objeto, 0 = en el borde del radio
            float Strength = 1.0f - (Distance / Data.SignalRadius);

            if (Strength > BestStrength)
            {
                BestStrength = Strength;
            }
        }
    }

    return FMath::Clamp(BestStrength, 0.0f, 1.0f);
}

void USignalScannerComponent::ScanForSignal()
{
    AActor* Owner = GetOwner();
    if (!Owner) return;

    FVector StartLocation;
    FVector ForwardVector;

    if (ACharacter* CharOwner = Cast<ACharacter>(Owner))
    {
        StartLocation = CharOwner->GetActorLocation();
        ForwardVector = CharOwner->GetActorForwardVector();
    }
    else
    {
        StartLocation = Owner->GetActorLocation();
        ForwardVector = Owner->GetActorForwardVector();
    }

    FVector EndLocation = StartLocation + (ForwardVector * ScanRange);
    FHitResult HitResult;
    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(Owner);

    // LineTrace Obligatorio (Punto 4)
    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, QueryParams);

    // Feedback Visual / Debug (Punto 10)
    DrawDebugLine(GetWorld(), StartLocation, EndLocation, bHit ? FColor::Green : FColor::Red, false, 2.0f, 0, 2.0f);

    if (bHit && HitResult.GetActor())
    {
        AActor* HitActor = HitResult.GetActor();

        // Comunicación mediante Interfaz, sin casteo a clase concreta (Punto 3)
        if (HitActor->GetClass()->ImplementsInterface(USignalInteractable::StaticClass()))
        {
            bool bActive = ISignalInteractable::Execute_IsActiveSignal(HitActor);

            if (bActive)
            {
                FSignalObjectData Data = ISignalInteractable::Execute_GetSignalData(HitActor);

                // Registro en el Códice (Punto 8)
                ScannedCodex.Add(Data);

                // Disparamos el evento (Punto 6)
                OnObjectScanned.Broadcast(Data);

                // Cambiamos el estado interno del objeto (Punto 7)
                ISignalInteractable::Execute_OnDetected(HitActor);

                if (GEngine)
                    GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, FString::Printf(TEXT("Detectado: %s"), *Data.ObjectName));
            }
            else
            {
                if (GEngine)
                    GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Silver, TEXT("Este objeto ya fue escaneado."));
            }
        }
    }
}


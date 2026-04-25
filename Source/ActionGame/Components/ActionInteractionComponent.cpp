// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionInteractionComponent.h"

#include "ActionGame/ActionEngineTypes.h"
#include "ActionGame/Interfaces/ActionInteractable.h"
#include "Kismet/GameplayStatics.h"


UActionInteractionComponent::UActionInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UActionInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	TraceForInteract();
}

void UActionInteractionComponent::TraceForInteract()
{
	if (!IsValid(GEngine) || !IsValid(GEngine->GameViewport)) return;
	FVector2D ViewportSize;
	GEngine->GameViewport->GetViewportSize(ViewportSize);
	const FVector2D ViewportCenter = ViewportSize / 2.f;
	FVector TraceStart;
	FVector Forward;

	APawn* PawnOwner = Cast<APawn>(GetOwner());
	APlayerController* OwnerPC = Cast<APlayerController>(PawnOwner->Controller);
	if (!UGameplayStatics::DeprojectScreenToWorld(OwnerPC, ViewportCenter, TraceStart, Forward)) return;

	ECollisionChannel CollisionChannel = COLLISION_INTERACTION;
	
	const FVector TraceEnd = TraceStart + Forward * InteractionLength;
	FHitResult Hit;

	FCollisionShape Shape;
	Shape.SetSphere(30.f);
	
	GetWorld()->SweepSingleByChannel(Hit, TraceStart, TraceEnd, FQuat::Identity, CollisionChannel, Shape);
	SelectedActor = Hit.GetActor();

	if (SelectedActor.IsValid())
	{
		DrawDebugBox(GetWorld(), SelectedActor->GetActorLocation(), FVector(60.f), FColor::Green);
	}
}

void UActionInteractionComponent::Interact()
{
	if (SelectedActor.Get() && SelectedActor->Implements<UActionInteractable>())
	{
		IActionInteractable::Execute_Interact(SelectedActor.Get(), GetOwner());
	}
}

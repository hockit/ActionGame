// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActionInteractionComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ACTIONGAME_API UActionInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UActionInteractionComponent();
	void Interact();
	
protected:
	UPROPERTY(EditDefaultsOnly, Category="Interaction")
	float InteractionLength{500.f};

private:
	void TraceForInteract();

	UPROPERTY()
	TWeakObjectPtr<AActor> SelectedActor;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;
};

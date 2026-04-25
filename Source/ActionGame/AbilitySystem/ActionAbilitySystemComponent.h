// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActionAbilitySystemComponent.generated.h"


struct FActionAttributeSet
{
	FActionAttributeSet()
		: Health(100.f) {}
	
	float Health;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ACTIONGAME_API UActionAbilitySystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ApplyHealthChange(float InValueChange);

protected:
	FActionAttributeSet Attributes;

public:
	UActionAbilitySystemComponent();

};

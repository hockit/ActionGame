// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActionAbilitySystemComponent.generated.h"

USTRUCT(BlueprintType)
struct FActionAttributeSet
{
	GENERATED_BODY()
	
	FActionAttributeSet()
		: Health(100.f)
		, Mana(100.f) {}

	UPROPERTY(BlueprintReadOnly)
	float Health;
	
	UPROPERTY(BlueprintReadOnly)
	float Mana;
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, float, NewHealth, float, OldHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnManaChanged, float, NewMana, float, OldMana);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ACTIONGAME_API UActionAbilitySystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ApplyHealthChange(float InValueChange);

	UFUNCTION(BlueprintCallable)
	void ApplyManaChange(float InValueChange);

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnManaChanged OnManaChanged;

protected:
	UPROPERTY(BlueprintReadOnly, Category="Attribute")
	FActionAttributeSet Attributes;

public:
	UActionAbilitySystemComponent();

};

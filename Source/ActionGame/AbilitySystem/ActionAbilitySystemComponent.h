// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActionAbilitySystemComponent.generated.h"

class UActionAbility;

USTRUCT(BlueprintType)
struct FActionAttributeSet
{
	GENERATED_BODY()
	
	FActionAttributeSet()
		: Health(100.f)
		, Mana(100.f)
		, Stamina(100.f){}

	UPROPERTY(BlueprintReadOnly)
	float Health;
	
	UPROPERTY(BlueprintReadOnly)
	float Mana;

	UPROPERTY(BlueprintReadOnly)
	float Stamina;
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, float, NewHealth, float, OldHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnManaChanged, float, NewMana, float, OldMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStaminaChanged, float, NewStamina, float, OldStamina);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ACTIONGAME_API UActionAbilitySystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	void StartAbility(FName InAbilityName);
	
	void StopAbility(FName InAbilityName);
	
	UFUNCTION(BlueprintCallable)
	void ApplyHealthChange(float InValueChange);

	UFUNCTION(BlueprintCallable)
	void ApplyManaChange(float InValueChange);

	UFUNCTION(BlueprintCallable)
	void ApplyStaminaChange(float InValueChange);

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FOnManaChanged OnManaChanged;

	UPROPERTY(BlueprintAssignable)
	FOnStaminaChanged OnStaminaChanged;

protected:
	UPROPERTY(BlueprintReadOnly, Category="Attribute")
	FActionAttributeSet Attributes;

	UPROPERTY()
	TArray<TObjectPtr<UActionAbility>> Abilities;

	UPROPERTY(EditAnywhere, Category="Abilities")
	TArray<TSubclassOf<UActionAbility>> DefaultAbilities;

public:
	UActionAbilitySystemComponent();

	virtual void InitializeComponent() override;

	void GrantAbility(TSubclassOf<UActionAbility>& NewAbilityClass);
};

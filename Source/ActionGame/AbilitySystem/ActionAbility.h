// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ActionAbility.generated.h"

class UActionAbilitySystemComponent;
/**
 * 
 */
UCLASS(Blueprintable, Abstract)
class ACTIONGAME_API UActionAbility : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Abilities")
	FName AbilityName;

	UPROPERTY(EditDefaultsOnly, Category="Abilities")
	float CooldownTime = 0.f;

public:

	UFUNCTION(BlueprintCallable)
	UActionAbilitySystemComponent* GetOwningComponent() const;

	bool CanStart() const;

	bool IsRunning() const { return bIsRunning; }

	UFUNCTION(BlueprintNativeEvent, Category="Abilities")
	void StartAbility();

	UFUNCTION(BlueprintNativeEvent, Category="Abilities")
	void StopAbility();

	float GetCooldownTimeRemaining() const;
	
	FName GetAbilityName() const { return AbilityName; }

protected:

	UPROPERTY(Transient)
	bool bIsRunning = false;

	UPROPERTY(Transient)
	float CooldownUntil = 0.f;
};

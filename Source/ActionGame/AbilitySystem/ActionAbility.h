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

public:

	UFUNCTION(BlueprintCallable)
	UActionAbilitySystemComponent* GetOwningComponent() const;

	UFUNCTION(BlueprintNativeEvent, Category="Abilities")
	void StartAbility();

	UFUNCTION(BlueprintNativeEvent, Category="Abilities")
	void StopAbility();
	
	FName GetAbilityName() const { return AbilityName; }
};

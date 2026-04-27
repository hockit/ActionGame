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
	FName AbilityName = FName("Dash");

public:
	virtual void StartAbility();

	UActionAbilitySystemComponent* GetOwningComponent() const;
	
	FName GetAbilityName() const { return AbilityName; }	
};

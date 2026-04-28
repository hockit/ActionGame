// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionGame/AbilitySystem/ActionAbility.h"
#include "ActionAbility_Dash.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class ACTIONGAME_API UActionAbility_Dash : public UActionAbility
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Category="Dash")
	float DashIntensity = 2500.f;

public:
	virtual void StartAbility_Implementation() override;
};

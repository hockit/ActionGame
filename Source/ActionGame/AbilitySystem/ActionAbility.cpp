// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionAbility.h"

#include "ActionAbilitySystemComponent.h"

void UActionAbility::StartAbility_Implementation()
{
	float GameTime = GetWorld()->TimeSeconds;
	UE_LOGFMT(LogTemp, Log, "Started Ability {AbilityName} - {WorldTime}",
		("AbilityName", AbilityName),
		("WorldTime", GameTime));
}

UActionAbilitySystemComponent* UActionAbility::GetOwningComponent() const
{
	return Cast<UActionAbilitySystemComponent>(GetOuter());
}

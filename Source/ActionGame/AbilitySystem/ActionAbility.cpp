// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionAbility.h"

#include "ActionAbilitySystemComponent.h"

void UActionAbility::StartAbility_Implementation()
{
	bIsRunning = true;
	
	float GameTime = GetWorld()->TimeSeconds;
	UE_LOGFMT(LogTemp, Log, "Started Ability {AbilityName} - {WorldTime}",
		("AbilityName", AbilityName),
		("WorldTime", GameTime));
}

void UActionAbility::StopAbility_Implementation()
{
	bIsRunning = false;
	
	float GameTime = GetWorld()->TimeSeconds;
	UE_LOGFMT(LogTemp, Log, "Stopped Ability {AbilityName} - {WorldTime}",
		("AbilityName", AbilityName),
		("WorldTime", GameTime));

	CooldownUntil = GetWorld()->TimeSeconds + CooldownTime;
}

UActionAbilitySystemComponent* UActionAbility::GetOwningComponent() const
{
	return Cast<UActionAbilitySystemComponent>(GetOuter());
}

bool UActionAbility::CanStart() const
{
	if (IsRunning())
		return false;

	if (GetCooldownTimeRemaining() > 0.f)
	{
		UE_LOG(LogTemp, Log, TEXT("Cooldown remaining %f"), GetCooldownTimeRemaining());
		return false;
	}

	return true;
}

float UActionAbility::GetCooldownTimeRemaining() const
{
	return FMath::Max(0.f, CooldownUntil - GetWorld()->TimeSeconds);
}

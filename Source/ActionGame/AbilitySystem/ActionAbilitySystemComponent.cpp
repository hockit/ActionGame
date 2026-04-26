// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionAbilitySystemComponent.h"


UActionAbilitySystemComponent::UActionAbilitySystemComponent()
{
}

void UActionAbilitySystemComponent::ApplyHealthChange(float InValueChange)
{
	float OldHealth = Attributes.Health;
	
	Attributes.Health += InValueChange;

	OnHealthChanged.Broadcast(Attributes.Health, OldHealth);

}

void UActionAbilitySystemComponent::ApplyManaChange(float InValueChange)
{
	float OldMana = Attributes.Mana;
	
	Attributes.Mana += InValueChange;

	OnManaChanged.Broadcast(Attributes.Mana, OldMana);
}

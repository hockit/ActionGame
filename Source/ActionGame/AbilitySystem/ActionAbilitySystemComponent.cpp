// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionAbilitySystemComponent.h"

#include "ActionAbility.h"


UActionAbilitySystemComponent::UActionAbilitySystemComponent()
{
	bWantsInitializeComponent = true;
}

void UActionAbilitySystemComponent::InitializeComponent()
{
	Super::InitializeComponent();

	for (TSubclassOf<UActionAbility> AbilityClass : DefaultAbilities)
	{
		if (ensure(AbilityClass))
		{
			GrantAbility(AbilityClass);	
		}
	}
}

void UActionAbilitySystemComponent::GrantAbility(TSubclassOf<UActionAbility>& NewAbilityClass)
{
	UActionAbility* NewAbility = NewObject<UActionAbility>(this, NewAbilityClass);
	Abilities.Add(NewAbility);
}

void UActionAbilitySystemComponent::StartAbility(FName InAbilityName)
{
	for (UActionAbility* Ability : Abilities)
	{
		if (Ability->GetAbilityName() == InAbilityName)
		{
			Ability->StartAbility();
			return;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("No ability found with name %s"), *InAbilityName.ToString());
}

void UActionAbilitySystemComponent::StopAbility(FName InAbilityName)
{
	for (UActionAbility* Ability : Abilities)
	{
		if (Ability->GetAbilityName() == InAbilityName)
		{
			Ability->StopAbility();
			return;
		}
	}
	
	UE_LOG(LogTemp, Warning, TEXT("No ability found with name %s"), *InAbilityName.ToString());
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

void UActionAbilitySystemComponent::ApplyStaminaChange(float InValueChange)
{
	float OldStamina = Attributes.Stamina;
	
	Attributes.Stamina += InValueChange;

	OnStaminaChanged.Broadcast(Attributes.Stamina, OldStamina);
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionAbility_Dash.h"

#include "ActionGame/AbilitySystem/ActionAbilitySystemComponent.h"
#include "GameFramework/Character.h"

void UActionAbility_Dash::StartAbility_Implementation()
{
	Super::StartAbility_Implementation();

	UActionAbilitySystemComponent* AbilityComp = GetOwningComponent();
	ACharacter* Character = CastChecked<ACharacter>(AbilityComp->GetOwner());

	FVector DashDir = Character->GetVelocity().GetSafeNormal();
	if (DashDir.IsNearlyZero())
	{
		DashDir = Character->GetActorForwardVector();
	}

	AbilityComp->ApplyStaminaChange(-10.f);
	Character->LaunchCharacter(DashDir * DashIntensity, true, true);
}

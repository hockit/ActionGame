// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionAbility_Dash.h"

#include "ActionGame/AbilitySystem/ActionAbilitySystemComponent.h"
#include "GameFramework/Character.h"

void UActionAbility_Dash::StartAbility()
{
	Super::StartAbility();

	UActionAbilitySystemComponent* AbilityComp = GetOwningComponent();
	ACharacter* Character = CastChecked<ACharacter>(AbilityComp->GetOwner());

	FVector DashDir = Character->GetVelocity().GetSafeNormal();
	if (DashDir.IsNearlyZero())
	{
		DashDir = Character->GetActorForwardVector();
	}
	
	Character->LaunchCharacter(DashDir * DashIntensity, true, true);
}

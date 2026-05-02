// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionWeaponManagerComponent.h"

#include "ActionGame/Weapons/ActionWeaponBase.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


UActionWeaponManagerComponent::UActionWeaponManagerComponent()
{
}

void UActionWeaponManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());
}

void UActionWeaponManagerComponent::EquipWeapon(TSubclassOf<AActionWeaponBase> WeaponClass)
{
	check(OwnerCharacter);
	
	if (IsValid(EquippedWeapon))
	{
		if (EquippedWeapon->GetClass() == WeaponClass)
		{
			UnEquipWeapon();
			return;
		}
		UnEquipWeapon();
	}
	EquippedWeapon = GetWorld()->SpawnActor<AActionWeaponBase>(WeaponClass);
	EquippedWeapon->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, EquippedWeapon->GetWeaponConfig().EquippedSocketName);
	OwnerCharacter->GetMesh()->SetAnimInstanceClass(EquippedWeapon->GetWeaponConfig().AnimClass);

	OwnerCharacter->GetCharacterMovement()->MaxWalkSpeed = EquippedWeapon->GetWeaponConfig().MovementSettings.MaxWalkSpeed;
	OwnerCharacter->GetCharacterMovement()->bOrientRotationToMovement = EquippedWeapon->GetWeaponConfig().MovementSettings.OrientRotationToMovement;
	OwnerCharacter->GetCharacterMovement()->bUseControllerDesiredRotation = EquippedWeapon->GetWeaponConfig().MovementSettings.UseControllerDesireRotation;
}

void UActionWeaponManagerComponent::UnEquipWeapon()
{
	if (IsValid(EquippedWeapon))
	{
		EquippedWeapon->Destroy();
		EquippedWeapon = nullptr;

		OwnerCharacter->GetMesh()->SetAnimInstanceClass(UnarmedWeaponConfig.AnimClass);

		OwnerCharacter->GetCharacterMovement()->MaxWalkSpeed = UnarmedWeaponConfig.MovementSettings.MaxWalkSpeed;
		OwnerCharacter->GetCharacterMovement()->bOrientRotationToMovement = UnarmedWeaponConfig.MovementSettings.OrientRotationToMovement;
		OwnerCharacter->GetCharacterMovement()->bUseControllerDesiredRotation = UnarmedWeaponConfig.MovementSettings.UseControllerDesireRotation;
	}
}
#pragma once

#include "CoreMinimal.h"
#include "Data_WeaponProperties.generated.h"

class UActionAbility;

USTRUCT(BlueprintType)
struct FMovementSettings
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	float MaxWalkSpeed;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	bool OrientRotationToMovement;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	bool UseControllerDesireRotation;
};

USTRUCT(BlueprintType)
struct FWeaponConfig
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	TArray<TSubclassOf<UActionAbility>> AbilitiesToGrant;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	FName EquippedSocketName;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	TSubclassOf<UAnimInstance> AnimClass;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	FMovementSettings MovementSettings;
};
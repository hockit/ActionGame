// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionGame/Weapons/Data/Data_WeaponProperties.h"
#include "Components/ActorComponent.h"
#include "ActionWeaponManagerComponent.generated.h"


class AActionWeaponBase;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ACTIONGAME_API UActionWeaponManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UActionWeaponManagerComponent();

	UFUNCTION(BlueprintCallable)
	void EquipWeapon(TSubclassOf<AActionWeaponBase> WeaponClass);

	UFUNCTION(BlueprintCallable)
	void UnEquipWeapon();

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<AActionWeaponBase> EquippedWeapon;

	UPROPERTY()
	TObjectPtr<ACharacter> OwnerCharacter;

	UPROPERTY(EditDefaultsOnly)
	FWeaponConfig UnarmedWeaponConfig;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/Data_WeaponProperties.h"
#include "GameFramework/Actor.h"
#include "ActionWeaponBase.generated.h"

class UActionAbility;
class UStaticMeshComponent;


UCLASS(Abstract)
class ACTIONGAME_API AActionWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	AActionWeaponBase();

	FWeaponConfig GetWeaponConfig() const { return WeaponConfig; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Weapon")
	TObjectPtr<UStaticMeshComponent> WeaponMesh;

	UPROPERTY(BlueprintReadWrite, Category="Weapon")
	FWeaponConfig WeaponConfig;

public:
	virtual void Tick(float DeltaTime) override;
};

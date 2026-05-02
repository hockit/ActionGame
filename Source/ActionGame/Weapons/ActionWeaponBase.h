// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActionWeaponBase.generated.h"

class UActionAbility;
class UStaticMeshComponent;



USTRUCT(BlueprintType)
struct FWeaponConfig
{
	GENERATED_BODY()

	FWeaponConfig() {}

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	TArray<TSubclassOf<UActionAbility>> AbilitiesToGrant;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	FName EquippedSocketName;

	UPROPERTY(EditDefaultsOnly, Category="Weapon")
	TSubclassOf<UAnimInstance> AnimClass;
};



UCLASS()
class ACTIONGAME_API AActionWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	AActionWeaponBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Weapon")
	TObjectPtr<UStaticMeshComponent> WeaponMesh;

	UPROPERTY(BlueprintReadWrite, Category="Weapon")
	FWeaponConfig WeaponConfig;

public:
	virtual void Tick(float DeltaTime) override;
};

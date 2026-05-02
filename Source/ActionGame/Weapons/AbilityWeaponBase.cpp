// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityWeaponBase.h"


// Sets default values
AAbilityWeaponBase::AAbilityWeaponBase()
{
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	//WeaponMesh->SetupAttachment(GetRootComponent());
	WeaponMesh->SetCollisionProfileName("NoCollision");
}

void AAbilityWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAbilityWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


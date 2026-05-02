// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionWeaponBase.h"


// Sets default values
AActionWeaponBase::AActionWeaponBase()
{
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	//WeaponMesh->SetupAttachment(GetRootComponent());
	WeaponMesh->SetCollisionProfileName("NoCollision");
}

void AActionWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AActionWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


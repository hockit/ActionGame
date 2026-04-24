// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionPlayerCharacter.h"

#include "DataAsset_InputConfig.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AActionPlayerCharacter::AActionPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->SocketOffset = FVector(0.f, 0.f, 60.f);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 0.f, 630.f);
	GetCharacterMovement()->BrakingDecelerationWalking = 1024.f;
	
}

void AActionPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AActionPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActionPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	auto* InputComp = Cast<UEnhancedInputComponent>(InputComponent);

	InputComp->BindAction(InputConfig->Input_Move, ETriggerEvent::Triggered, this, &ThisClass::Move);
	InputComp->BindAction(InputConfig->Input_Look, ETriggerEvent::Triggered, this, &ThisClass::Look);

}

void AActionPlayerCharacter::Move(const FInputActionValue& InValue)
{
	FVector2D InputValue = InValue.Get<FVector2D>();
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.f;
	AddMovementInput(ControlRot.Vector(), InputValue.X);

	FVector RightDirection = ControlRot.RotateVector(FVector::RightVector);
	AddMovementInput(RightDirection, InputValue.Y);
}

void AActionPlayerCharacter::Look(const FInputActionInstance& InValue)
{
	FVector2D InputValue = InValue.GetValue().Get<FVector2D>();
	
	AddControllerPitchInput(InputValue.Y);
	AddControllerYawInput(InputValue.X);
}



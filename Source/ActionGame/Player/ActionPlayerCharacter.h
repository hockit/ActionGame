// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ActionPlayerCharacter.generated.h"

class UActionWeaponManagerComponent;
struct FGameplayTag;
class UActionAbilitySystemComponent;
class UActionInteractionComponent;
struct FInputActionInstance;
struct FInputActionValue;
class UDataAsset_InputConfig;
class UCameraComponent;
class USpringArmComponent;

UCLASS()
class ACTIONGAME_API AActionPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AActionPlayerCharacter();
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category="Components")
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(VisibleAnywhere, Category="Components")
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(VisibleAnywhere, Category="Components")
	TObjectPtr<UActionInteractionComponent> InteractionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UActionAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	TObjectPtr<UActionWeaponManagerComponent> WeaponManagerComponent;

	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UDataAsset_InputConfig> InputConfig;


	void Move(const FInputActionValue& InValue);
	void Look(const FInputActionInstance& InValue);
	void Interact();

	void StartAbility(FGameplayTag InAbilityName);
	void StopAbility(FGameplayTag InAbilityName);

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

};

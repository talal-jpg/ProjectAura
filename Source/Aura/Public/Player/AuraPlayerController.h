// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"


class UAuraAbilitySystemComponent;
struct FGameplayTag;
class UAuraInputConfig;
class IAuraEnemyCursorHitInterface;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
	public:
	virtual void SetupInputComponent() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,Category="Input")
	UInputMappingContext*  PlayerInputMappingContext;

	UPROPERTY(EditAnywhere,Category="Input")
	UInputAction* IA_Move;

	UPROPERTY(EditAnywhere,Category="Input")
	const UAuraInputConfig* InputConfig;

	void InputPressed(FGameplayTag InputTag);
	void InputReleased(FGameplayTag InputTag);
	void InputHeld(FGameplayTag InputTag);

	void Move(const FInputActionValue& InputActionValue);

	void MoveToLocation(const FVector& Location);

	void CursorTrace();

	IAuraEnemyCursorHitInterface* ThisActor;

	IAuraEnemyCursorHitInterface* LastActor;

	UAuraAbilitySystemComponent* GetAuraAbilitySystemComponent();

	UPROPERTY()
	UAuraAbilitySystemComponent* AuraAbilitySystemComponent;
};


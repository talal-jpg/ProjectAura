// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AuraAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnGameplayEffectAppliedBroadcastAssetTagsDelegateSignature,FGameplayTagContainer);


/**
 * 
 */
UCLASS()
class AURA_API UAuraAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

	UAuraAbilitySystemComponent();

	public:

	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,const FGameplayEffectSpec& GameplayEffectSpec,FActiveGameplayEffectHandle ActiveGameplayEffectHandle);

	FOnGameplayEffectAppliedBroadcastAssetTagsDelegateSignature	OnGameplayEffectAppliedBroadcastAssetTagsDelegate;

	void InputTagHeld(FGameplayTag InputTag);

	void InputTagReleased(FGameplayTag InputTag);
	
};

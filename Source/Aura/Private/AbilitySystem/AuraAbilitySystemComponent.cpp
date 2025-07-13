// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAbilitySystemComponent.h"

UAuraAbilitySystemComponent::UAuraAbilitySystemComponent()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this,&ThisClass::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& GameplayEffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	FGameplayTagContainer GameplayTags;
	GameplayEffectSpec.GetAllAssetTags(GameplayTags);
	OnGameplayEffectAppliedBroadcastAssetTagsDelegate.Broadcast(GameplayTags);
}

void UAuraAbilitySystemComponent::InputTagHeld(FGameplayTag InputTag)
{
	for (auto AbilitySpec:GetActivatableAbilities())
	{
		AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag);
		
		if (!AbilitySpec.IsActive())
		{
			AbilitySpecInputPressed(AbilitySpec);
			TryActivateAbility(AbilitySpec.Handle);
		}
	}
}

void UAuraAbilitySystemComponent::InputTagReleased(FGameplayTag InputTag)
{
	for (auto AbilitySpec:GetActivatableAbilities())
	{
		AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag);
		if (AbilitySpec.IsActive())
		{
			AbilitySpecInputReleased(AbilitySpec);
		}
		
	}

}


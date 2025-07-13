// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/OverlayWidgetController.h"

#include "GameplayTagsManager.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/AuraGameplayTags.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	/**
	*BroadCastInitialVals
	*/

	UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(AttributeSet);
	OnHealthChangeDelegate.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChangeDelegate.Broadcast(AuraAttributeSet->GetMaxHealth());
	OnManaChangeDelegate.Broadcast(AuraAttributeSet->GetMana());
	OnMaxManaChangeDelegate.Broadcast(AuraAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	/**
	*BindingFuncsToAttribValueChangeDelegates
	*/
	
	UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(AttributeSet);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute()).AddUObject(this,&ThisClass::OnHealthChange);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxHealthAttribute()).AddUObject(this,&ThisClass::OnMaxHealthChange);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetManaAttribute()).AddUObject(this,&ThisClass::OnManaChange);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxManaAttribute()).AddUObject(this,&ThisClass::OnMaxManaChange);
	
	/**
	*BindingFuncsToGameplayEffectAppliedDelegates
	*/

	//only one func or lambda can be applied to a non multicast delegate
//	AbilitySystemComponent->OnGameplayEffectAppliedDelegateToSelf.AddLambda(
//		[this](UAbilitySystemComponent* AbilitySystemComponent,const FGameplayEffectSpec& GameplaySpec,FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
//		{
//			FGameplayTagContainer GameplayTags;
//			GameplaySpec.GetAllAssetTags(GameplayTags);
//			for (FGameplayTag GameplayTag : GameplayTags)
//			{
//				FGameplayTag MessageTag= FGameplayTag::RequestGameplayTag(FName("Message"));
//				if (GameplayTag.MatchesTag(MessageTag))
//				{
//					FPopUpWidget* PopUpWidgetRow=DT_PopUpWidget->FindRow<FPopUpWidget>(GameplayTag.GetTagName(),TEXT(""));
//					if (PopUpWidgetRow)
//					{
//						OnGameplayEffectAppliedDelegate.Broadcast(*PopUpWidgetRow);
//					}
//					
//				}
//			}
//			
//		}
//		);

	
	Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->OnGameplayEffectAppliedBroadcastAssetTagsDelegate.AddLambda(
	[this](FGameplayTagContainer GameplayTags)
	{
		for (FGameplayTag GameplayTag : GameplayTags)
		{
			 FGameplayTag MessageTag=FGameplayTag::RequestGameplayTag(FName("Message"));
			if (GameplayTag.MatchesTag(MessageTag))
			{
				GEngine->AddOnScreenDebugMessage(-1,10,FColor::Black,GameplayTag.GetTagName().ToString());
				FPopUpWidget* PopUpWidget= DT_PopUpWidget->FindRow<FPopUpWidget>(FName("Message.HealthPotion"),TEXT(""));
				if (PopUpWidget)
				{
					OnGameplayEffectAppliedDelegate.Broadcast(*PopUpWidget);
				}
				else
				{
					GEngine->AddOnScreenDebugMessage(-1,10,FColor::Black,FString("RowNotFound"));
				}
			}
		}
	}
	);
}


void UOverlayWidgetController::OnHealthChange(const FOnAttributeChangeData& Data)
{
	float NewValue=Data.NewValue;
	OnHealthChangeDelegate.Broadcast(NewValue);
}

void UOverlayWidgetController::OnMaxHealthChange(const FOnAttributeChangeData& Data)
{
	float NewValue=Data.NewValue;
	OnMaxHealthChangeDelegate.Broadcast(NewValue);
}

void UOverlayWidgetController::OnManaChange(const FOnAttributeChangeData& Data)
{
	float NewValue=Data.NewValue;
	OnManaChangeDelegate.Broadcast(NewValue);
}

void UOverlayWidgetController::OnMaxManaChange(const FOnAttributeChangeData& Data)
{
	float NewValue=Data.NewValue;
	OnMaxManaChangeDelegate.Broadcast(NewValue);
}

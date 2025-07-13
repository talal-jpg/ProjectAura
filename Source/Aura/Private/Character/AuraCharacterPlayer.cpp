// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacterPlayer.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/AuraGameplayAbility.h"
#include "Player/AuraPlayerState.h"
#include "UI/AuraHUD.h"
#include "UI/AuraWidgetController.h"

void AAuraCharacterPlayer::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityActorInfo();
	GiveStartupAbilities();
}

void AAuraCharacterPlayer::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilityActorInfo();
}

void AAuraCharacterPlayer::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState= GetPlayerState<AAuraPlayerState>();
	AbilitySystemComponent=AuraPlayerState->AbilitySystemComponent;
	AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState,this);
	AttributeSet=AuraPlayerState->AttributeSet;
	APlayerController* PlayerController=GetController<APlayerController>();
	AAuraHUD* AuraHUD=Cast<AAuraHUD>(PlayerController->GetHUD());
	FWidgetControllerParams WidgetControllerParams(PlayerController,AuraPlayerState,AbilitySystemComponent,AttributeSet);
	AuraHUD->InitOverlay(WidgetControllerParams);
}

void AAuraCharacterPlayer::GiveStartupAbilities()
{
	for (auto AbilityClass : StartupGameplayAbilities)
	{
		FGameplayAbilitySpec AbilitySpec=AbilitySystemComponent->BuildAbilitySpecFromClass(AbilityClass);
		if (const UAuraGameplayAbility* AuraAbility= Cast<UAuraGameplayAbility>(AbilitySpec.Ability))
		{
			AbilitySpec.GetDynamicSpecSourceTags().AddTag(AuraAbility->StartupInputTag);
		}
		//AbilitySystemComponent->GiveAbility(AbilitySpec);
		AbilitySystemComponent->GiveAbility(AbilitySpec);
	}
}

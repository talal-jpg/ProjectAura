// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAbilitySystemFunctionLibrary.h"
#include "UI/AuraHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Player/AuraPlayerState.h"
#include "UI/AttributeMenuWidgetController.h"
#include "UI/AuraWidgetController.h"
#include "UI/OverlayWidgetController.h"

UOverlayWidgetController* UAuraAbilitySystemFunctionLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	APlayerController* PC= UGameplayStatics::GetPlayerController(WorldContextObject,0);
	if (PC)
	{
		AAuraHUD* AuraHUD=Cast<AAuraHUD>(PC->GetHUD());
		AAuraPlayerState* PS= PC->GetPlayerState<AAuraPlayerState>();
		UAbilitySystemComponent* ASC=PS->GetAbilitySystemComponent();
		UAttributeSet* AS=PS->GetAttributeSet();
		
		FWidgetControllerParams WcParams;
		WcParams.PlayerController=PC;
		WcParams.PlayerState=PS;
		WcParams.AbilitySystemComponent=ASC;
		WcParams.AttributeSet=AS;
		return Cast<UOverlayWidgetController>(AuraHUD->GetOverlayWidgetController(WcParams));
	}
	return nullptr;
}

UAttributeMenuWidgetController* UAuraAbilitySystemFunctionLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
	APlayerController* PC=UGameplayStatics::GetPlayerController(WorldContextObject,0);
	if (PC)
	{
		AAuraHUD* AuraHUD=Cast<AAuraHUD>(PC->GetHUD());
		AAuraPlayerState* PS= PC->GetPlayerState<AAuraPlayerState>();
		UAbilitySystemComponent* ASC=PS->GetAbilitySystemComponent();
		UAttributeSet* AS=PS->GetAttributeSet();
		
		FWidgetControllerParams WcParams(PC,PS,ASC,AS);
		
		return Cast<UAttributeMenuWidgetController>(AuraHUD->GetAttributeMenuWidgetController(WcParams));
	}
	return nullptr;
}

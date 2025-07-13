// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AttributeMenuWidgetController.h"

#include "AbilitySystem/Data/AuraAttributeInfo.h"

void UAttributeMenuWidgetController::PrintDebugInfo()
{

	FGameplayTag HealthTag=FGameplayTag::RequestGameplayTag(TEXT("Attributes.Primary.Health"));
	
	FAttributeInfo AuraAttributeInfo=DT_AttributeInfoList->GetAttributeInfoByGameplayTag(HealthTag);
	FString String=AuraAttributeInfo.AttributeDescription.ToString();
	GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,String);
}

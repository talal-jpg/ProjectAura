// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AuraWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
/**
 * 
 */
USTRUCT()
struct FWidgetControllerParams
{
	GENERATED_BODY()
	FWidgetControllerParams() {}
	FWidgetControllerParams(APlayerController* PC,APlayerState* PS,UAbilitySystemComponent* ASC,UAttributeSet* AS): PlayerController(PC),PlayerState(PS),AbilitySystemComponent(ASC),AttributeSet(AS)
	{}
		UPROPERTY()
		APlayerController* PlayerController = nullptr;
		UPROPERTY()
		APlayerState* PlayerState = nullptr;
		UPROPERTY()
		UAbilitySystemComponent* AbilitySystemComponent = nullptr;
		UPROPERTY()
		UAttributeSet* AttributeSet = nullptr;

};
UCLASS()
class AURA_API UAuraWidgetController : public UObject
{
	GENERATED_BODY()
	virtual void BroadcastInitialValues();
	virtual void BindCallbacksToDependencies();

	public:
	
	UPROPERTY()
	APlayerController* PlayerController;

	UPROPERTY()
	APlayerState* PlayerState;
	
	UPROPERTY()
	UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	UAttributeSet* AttributeSet;

	void SetWidgetControllerParams(FWidgetControllerParams& InWidgetControllerParams);
};

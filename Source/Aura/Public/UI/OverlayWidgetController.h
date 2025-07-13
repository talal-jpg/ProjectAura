// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UI/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

struct FOnAttributeChangeData;

USTRUCT(BlueprintType,Blueprintable)
struct FPopUpWidget : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	FGameplayTag GameplayTag;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	FText Message;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	TSubclassOf<UUserWidget> WidgetClass;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UTexture2D* Image;
};
/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangeDelegateSignature,float,Health);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangeDelegateSignature,float,MaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangeDelegateSignature,float,Mana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangeDelegateSignature,float,MaxMana);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGameplayEffectAppliedDelegateSignature,FPopUpWidget,PopUpWidget);


UCLASS(BlueprintType,Blueprintable)
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()
	public:
	virtual void BroadcastInitialValues() override;

	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChangeDelegateSignature OnHealthChangeDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnMaxHealthChangeDelegateSignature OnMaxHealthChangeDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnManaChangeDelegateSignature OnManaChangeDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnMaxManaChangeDelegateSignature OnMaxManaChangeDelegate;

	void OnHealthChange(const FOnAttributeChangeData& Data);
	void OnMaxHealthChange(const FOnAttributeChangeData& Data);
	void OnManaChange(const FOnAttributeChangeData& Data);
	void OnMaxManaChange(const FOnAttributeChangeData& Data);

	UPROPERTY(BlueprintAssignable)
	FOnGameplayEffectAppliedDelegateSignature OnGameplayEffectAppliedDelegate;

	UPROPERTY(EditAnywhere)
	UDataTable* DT_PopUpWidget;
	
	
	
};

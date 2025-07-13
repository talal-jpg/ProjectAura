// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/AuraWidgetController.h"
#include "AttributeMenuWidgetController.generated.h"

class UAuraAttributeInfo;
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class AURA_API UAttributeMenuWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

	public:
	UFUNCTION(BlueprintCallable)
	void PrintDebugInfo();

	UPROPERTY(EditAnywhere)
	UAuraAttributeInfo* DT_AttributeInfoList;
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

class UAuraWidgetController;
/**
 * 
 */
UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()

	public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UAuraWidgetController> WidgetController;

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UAuraWidgetController* InWidgetController);

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
	
};

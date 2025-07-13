// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAuraUserWidget;
struct FWidgetControllerParams;
class UAttributeSet;
class UAbilitySystemComponent;
class UAuraWidgetController;
/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

	public:
	void InitOverlay(FWidgetControllerParams& WcParams);

	UAuraWidgetController* GetOverlayWidgetController(FWidgetControllerParams& WcParams);

	UAuraWidgetController* GetAttributeMenuWidgetController(FWidgetControllerParams& WcParams);

	UPROPERTY()
	UAuraWidgetController* OverlayWidgetController;

	UPROPERTY()
	UAuraWidgetController* AttributeMenuWidgetController;

	UPROPERTY()
	UAuraUserWidget* OverlayUserWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraWidgetController> OverlayWidgetControllerClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraWidgetController> AttributeMenuWidgetControllerClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayUserWidgetClass;
};

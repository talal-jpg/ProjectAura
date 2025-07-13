// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AuraHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/AuraUserWidget.h"
#include "UI/AuraWidgetController.h"
#include "UI/OverlayWidgetController.h"

UAuraWidgetController* AAuraHUD::GetOverlayWidgetController(FWidgetControllerParams& WcParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController=NewObject<UOverlayWidgetController>(this,OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WcParams);
	}
	return OverlayWidgetController;
	
}

UAuraWidgetController* AAuraHUD::GetAttributeMenuWidgetController(FWidgetControllerParams& WcParams)
{
	if (AttributeMenuWidgetController == nullptr)
	{
		AttributeMenuWidgetController=NewObject<UAuraWidgetController>(this,AttributeMenuWidgetControllerClass);
		AttributeMenuWidgetController->SetWidgetControllerParams(WcParams);
	}
	return AttributeMenuWidgetController;
}

void AAuraHUD::InitOverlay(FWidgetControllerParams& WcParams)
{
	OverlayUserWidget=CreateWidget<UAuraUserWidget>(GetWorld(),OverlayUserWidgetClass);
	OverlayWidgetController= GetOverlayWidgetController(WcParams);
	OverlayUserWidget->SetWidgetController(OverlayWidgetController);
	OverlayUserWidget->AddToViewport();
	Cast<UOverlayWidgetController>(OverlayWidgetController)->BindCallbacksToDependencies();
	Cast<UOverlayWidgetController>(OverlayWidgetController)->BroadcastInitialValues();
	
}


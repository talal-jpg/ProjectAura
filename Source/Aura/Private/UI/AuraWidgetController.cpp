// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/AuraWidgetController.h"

void UAuraWidgetController::BroadcastInitialValues()
{
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
}

void UAuraWidgetController::SetWidgetControllerParams(FWidgetControllerParams& InWidgetControllerParams)
{
	PlayerController=InWidgetControllerParams.PlayerController;
	PlayerState=InWidgetControllerParams.PlayerState;
	AbilitySystemComponent=InWidgetControllerParams.AbilitySystemComponent;
	AttributeSet=InWidgetControllerParams.AttributeSet;
}

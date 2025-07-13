// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacterEnemy.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Character/AuraCharacterBase.h"

AAuraCharacterEnemy::AAuraCharacterEnemy()
{
	AbilitySystemComponent= CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AttributeSet= CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraCharacterEnemy::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this,this);
}

void AAuraCharacterEnemy::Highlight()
{
	bIsHighlighted = true;
}

void AAuraCharacterEnemy::UnHighlight()
{
	bIsHighlighted = false;
}

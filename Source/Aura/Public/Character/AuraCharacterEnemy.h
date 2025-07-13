// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraEnemyCursorHitInterface.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacterEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacterEnemy : public AAuraCharacterBase, public IAuraEnemyCursorHitInterface
{
	GENERATED_BODY()
	public:
	AAuraCharacterEnemy();

	virtual void BeginPlay() override;

	virtual void Highlight() override;
	virtual void UnHighlight() override;

	UPROPERTY(BlueprintReadOnly)
	bool bIsHighlighted = false;
};

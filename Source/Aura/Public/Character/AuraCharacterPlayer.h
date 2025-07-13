// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacterPlayer.generated.h"

class UGameplayAbility;
class UAuraGameplayAbility;
/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacterPlayer : public AAuraCharacterBase
{
	GENERATED_BODY()

	public:
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	void InitAbilityActorInfo();

	void GiveStartupAbilities();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TSubclassOf<UGameplayAbility>> StartupGameplayAbilities;
	
};

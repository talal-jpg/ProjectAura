// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "AuraAttributeInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FAttributeInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FGameplayTag Tag;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FText AttributeName;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	FText AttributeDescription;

	UPROPERTY(BlueprintReadOnly)
	float AttributeValue;
};


UCLASS()
class AURA_API UAuraAttributeInfo : public UDataAsset
{
	GENERATED_BODY()


	public:
	FAttributeInfo GetAttributeInfoByGameplayTag(FGameplayTag Tag,bool bLogNotFound=false);

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	TArray<FAttributeInfo> AttributeInfoList;
	
};

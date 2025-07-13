// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Data/AuraAttributeInfo.h"

FAttributeInfo UAuraAttributeInfo::GetAttributeInfoByGameplayTag(FGameplayTag Tag,bool bLogNotFound)
{
	for (auto AttributeInfo : AttributeInfoList)
	{
		if (AttributeInfo.Tag== Tag)
		{
			return AttributeInfo;
		}
	}
	if (bLogNotFound)
	{
		GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,FString::Printf(TEXT("AttribInfo Not Found for Tag %s in %s"),*Tag.GetTagName().ToString(),*GetNameSafe(this)));
	}
	return FAttributeInfo();
}

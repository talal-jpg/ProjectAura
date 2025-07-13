// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraAssetManager.h"
#include "AbilitySystem/AuraGameplayTags.h"

UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine);
	return *Cast<UAuraAssetManager>(GEngine->AssetManager.Get());
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FAuraGameplayTags::Get().InitializeGameplayTags();
}

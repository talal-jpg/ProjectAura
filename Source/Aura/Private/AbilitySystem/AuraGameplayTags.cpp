// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraGameplayTags.h"

#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeGameplayTags()
{
	/**
	 *AttributeTags
	 */
	GameplayTags.Attributes_Secondary_Vigor=UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Vigor"),FString("Increases Blablabla"));
	GameplayTags.Attributes_Primary_Health= UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Health"),FString("Health"));
	GameplayTags.Attributes_Primary_MaxHealth=UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.MaxHealth"),FString("MaxHealth"));
	GameplayTags.Attributes_Primary_Mana=UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Mana"),FString("Mana"));
	GameplayTags.Attributes_Primary_MaxMana=UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.MaxMana"),FString("MaxMana"));

	/**
	 *MessageTags
	 */
	GameplayTags.Message_HealthPotion=UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Message.HealthPotion"),FString("HealthPotion"));
	GameplayTags.Message_HealthPotion= UGameplayTagsManager::Get().RequestGameplayTag(FName("Message.HealthPotion"));
	GameplayTags.Message_ManaPotion=UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Message.ManaPotion"),FString("ManaPotion"));
	GameplayTags.Message_ManaPotion=UGameplayTagsManager::Get().RequestGameplayTag(FName("Message.ManaPotion"));
	GameplayTags.Message_HealthCrystal=UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Message.HealthCrystal"),FString("HealthCrystal"));
	GameplayTags.Message_HealthCrystal=UGameplayTagsManager::Get().RequestGameplayTag(FName("Message.HealthCrystal"));
	GameplayTags.Message_ManaCrystal=UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Message.ManaCrystal"),FString("ManaCrystal"));
	GameplayTags.Message_ManaCrystal=UGameplayTagsManager::Get().RequestGameplayTag(FName("Message.ManaCrystal"));

	/**
	 *InputTags
	 */
	GameplayTags.Input_LMB=UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.LMB"),FString("Tag for when LMB is pressed"));
	GameplayTags.Input_LMB= UGameplayTagsManager::Get().RequestGameplayTag(FName("Input.LMB"));
}

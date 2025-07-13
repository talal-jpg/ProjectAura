// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * 
 */
struct FAuraGameplayTags
{
	public:
	
	static FAuraGameplayTags& Get(){return GameplayTags;};

	static void InitializeGameplayTags();

	/**
	 * Attribute Tags
	 */
	FGameplayTag Attributes_Secondary_Vigor;
	FGameplayTag Attributes_Primary_Health;
	FGameplayTag Attributes_Primary_MaxHealth;
	FGameplayTag Attributes_Primary_Mana;
	FGameplayTag Attributes_Primary_MaxMana;

	/**
	 * Message Tags
	 */
	FGameplayTag Message_HealthPotion;
	FGameplayTag Message_ManaPotion;
	FGameplayTag Message_HealthCrystal;
	FGameplayTag Message_ManaCrystal;

	/**
	 * Input Tags
	 */

	FGameplayTag Input_LMB;
	FGameplayTag Input_RMB;
	FGameplayTag Input_1;
	FGameplayTag Input_2;
	FGameplayTag Input_3;
	
	private:

	protected:

	static FAuraGameplayTags GameplayTags;
	
};
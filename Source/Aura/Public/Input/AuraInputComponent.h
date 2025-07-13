// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraInputConfig.h"
#include "EnhancedInputComponent.h"
#include "AuraInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

	public:
	template<class UserClass,typename PressedFuncType, typename ReleasedFuncType,typename HeldFuncType>
	void BindAbilityActions(const UAuraInputConfig* InputConfig,UserClass Object,PressedFuncType PressedFunc,ReleasedFuncType ReleasedFunc,HeldFuncType HeldFunc);
	
};

template <class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
void UAuraInputComponent::BindAbilityActions(const UAuraInputConfig* InputConfig, UserClass Object,PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, HeldFuncType HeldFunc)
{
	for (auto InputConf:InputConfig->InputConfs)
	{
		if (InputConf.InputTag.IsValid() && InputConf.InputAction)
		{
			if (PressedFunc)
			{
				BindAction(InputConf.InputAction,ETriggerEvent::Started,Object,PressedFunc,InputConf.InputTag);
			}
			if (ReleasedFunc)
			{
				BindAction(InputConf.InputAction,ETriggerEvent::Completed,Object,ReleasedFunc,InputConf.InputTag);
			}
			if (HeldFunc)
			{
				BindAction(InputConf.InputAction,ETriggerEvent::Started,Object,HeldFunc,InputConf.InputTag);
			}
		}
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/AuraEffectActor.h"

#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"

// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(SceneComp);

}

// Called when the game starts or when spawned
void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAuraEffectActor::ApplyEffect(AActor* OtherActor)
{
	IAbilitySystemInterface* TargetAsAblillitySysInterface=Cast<IAbilitySystemInterface>(OtherActor);
	if (!TargetAsAblillitySysInterface)return;
	UAbilitySystemComponent* TargetASC=TargetAsAblillitySysInterface->GetAbilitySystemComponent();
	FGameplayEffectContextHandle EffectContextHandle=TargetASC->MakeEffectContext();
	EffectContextHandle.AddInstigator(this,this);
	FGameplayEffectSpecHandle EffectSpecHandle=TargetASC->MakeOutgoingSpec(GameplayEffectClass,1,EffectContextHandle);
	FActiveGameplayEffectHandle ActiveEffectHandle=TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	
	bool bIsInfinite= EffectSpecHandle.Data.Get()->Def.Get()->DurationPolicy==EGameplayEffectDurationType::Infinite;
	if (bIsInfinite)
	{
		ActiveEffectSpecs.Add(ActiveEffectHandle,TargetASC );
	}
}

void AAuraEffectActor::RemoveEffect(AActor* OtherActor)
{
	UAbilitySystemComponent* TargetASC=Cast<IAbilitySystemInterface>(OtherActor)->GetAbilitySystemComponent();
	if (!TargetASC)return;
	TArray<FActiveGameplayEffectHandle> HandlesToRemove;
	for (auto ActiveEffectSpec : ActiveEffectSpecs)
	{
		if (TargetASC==ActiveEffectSpec.Value)
		{
			ActiveEffectSpec.Value->RemoveActiveGameplayEffect(ActiveEffectSpec.Key);
			HandlesToRemove.Add(ActiveEffectSpec.Key);
		}
		for (FActiveGameplayEffectHandle HandleToRemove : HandlesToRemove)
		{
			ActiveEffectSpecs.FindAndRemoveChecked(HandleToRemove);
		}
	}
}

void AAuraEffectActor::OnOverlap(AActor* OtherActor)
{
	if (EffectApplicationPolicy==EEffectApplicationPolicy::EEffectApplicationPolicy_ApplyOnOverlap)
	{
		ApplyEffect(OtherActor);
	}
	if (EffectRemovalPolicy==EEffectRemovalPolicy::EEffectRemovalPolicy_RemoveOnOverlap)
	{
		
	}
}

void AAuraEffectActor::OnEndOverlap(AActor* OtherActor)
{
	RemoveEffect(OtherActor);
}


// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class UAbilitySystemComponent;
struct FGameplayEffectSpecHandle;
class UGameplayEffect;

UENUM()
enum class EEffectApplicationPolicy
{
	EEffectApplicationPolicy_ApplyOnOverlap,
	EEffectApplicationPolicy_ApplyOnEndOverlap,
	EEffectApplicationPolicy_DoNotApply
};

UENUM()
enum class EEffectRemovalPolicy
{
	EEffectRemovalPolicy_RemoveOnOverlap,
	EEffectRemovalPolicy_RemoveOnEndOverlap
};

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAuraEffectActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere)
	EEffectApplicationPolicy EffectApplicationPolicy=EEffectApplicationPolicy::EEffectApplicationPolicy_ApplyOnEndOverlap;

	UPROPERTY(EditAnywhere)
	EEffectRemovalPolicy EffectRemovalPolicy=EEffectRemovalPolicy::EEffectRemovalPolicy_RemoveOnEndOverlap;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USceneComponent> SceneComp;

	void ApplyEffect(AActor* OtherActor);

	void RemoveEffect(AActor* OtherActor);

	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* OtherActor);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* OtherActor);
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UGameplayEffect> GameplayEffectClass;

	UPROPERTY()
	TMap<FActiveGameplayEffectHandle,UAbilitySystemComponent* > ActiveEffectSpecs;
};

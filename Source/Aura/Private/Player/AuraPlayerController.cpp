// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"

#include "AuraEnemyCursorHitInterface.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraGameplayTags.h"
#include "Components/SplineComponent.h"
#include "Input/AuraInputComponent.h"
#include "Player/AuraPlayerState.h"

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputLocalPlayerSubsystem* EnhancedInputLocalPlayerSubsystem=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	EnhancedInputLocalPlayerSubsystem->AddMappingContext(PlayerInputMappingContext,1);
	
	UAuraInputComponent* AuraInputComponent= Cast<UAuraInputComponent>(InputComponent);
	AuraInputComponent->BindAction(IA_Move,ETriggerEvent::Triggered,this,&AAuraPlayerController::Move);
	AuraInputComponent->BindAbilityActions(InputConfig,this,&ThisClass::InputPressed,&ThisClass::InputReleased,&ThisClass::InputHeld);

	bShowMouseCursor=true;
	DefaultMouseCursor=EMouseCursor::Default;
}

void AAuraPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CursorTrace();
	if (bAutoRunning)
	{
		if (APawn* ControlledPawn= GetPawn())
		{
			FVector MoveDir= (CachedDestination- ControlledPawn->GetActorLocation()).GetSafeNormal();
			ControlledPawn->AddMovementInput(MoveDir);
		}
		
	}
	FString Debug_HeldTime= FString::Printf(TEXT("heldTime=%f"),HeldTime);
	GEngine->AddOnScreenDebugMessage(1,10,FColor::Black,Debug_HeldTime);
}

UAuraAbilitySystemComponent* AAuraPlayerController::GetAuraAbilitySystemComponent()
{
	if (!AuraAbilitySystemComponent)
	{
	AuraAbilitySystemComponent=Cast<UAuraAbilitySystemComponent>(GetPlayerState<AAuraPlayerState>()->AbilitySystemComponent);
	}
	return AuraAbilitySystemComponent;
}

void AAuraPlayerController::InputPressed(FGameplayTag InputTag)
{
	if (InputTag.MatchesTag(FAuraGameplayTags::Get().Input_LMB))
	{
		bTargeting= ThisActor ? true : false;
		bAutoRunning= false;
		HeldTime=0.f;
	}
}

void AAuraPlayerController::InputReleased(FGameplayTag InputTag)
{
	if (!InputTag.MatchesTagExact(FAuraGameplayTags::Get().Input_LMB))
	{
		GetAuraAbilitySystemComponent()->InputTagHeld(InputTag);
	}
	if (bTargeting)
	{
		GetAuraAbilitySystemComponent()->InputTagHeld(InputTag);
	}
	else
	{
		if (HeldTime<=ShortPressThreshold)
		{
			if (APawn* ControlledPawn= GetPawn())
			{
//				UNavigationPath* NavPath=UNavigationSystemV1::FindPathToLocationSynchronously(this,CachedDestination,ControlledPawn->GetActorLocation());
//				for (auto Point:NavPath->PathPoints)
//				{
//					Spline->AddSplinePoint(Point,ESplineCoordinateSpace::World);
//				}
				bAutoRunning=true;
			}
		}
		FHitResult HitResult;
		GetHitResultUnderCursor(ECC_Visibility,true,HitResult);
		if (!HitResult.bBlockingHit)return;
		if (APawn* ControlledPawn= GetPawn())
		{
			CachedDestination= HitResult.ImpactPoint;
			FVector MoveDir= (CachedDestination- ControlledPawn->GetActorLocation()).GetSafeNormal();
			ControlledPawn->AddMovementInput(MoveDir);
		}
	}
	
}

void AAuraPlayerController::InputHeld(FGameplayTag InputTag)
{
	if (!InputTag.MatchesTagExact(FAuraGameplayTags::Get().Input_LMB))
	{
		GetAuraAbilitySystemComponent()->InputTagHeld(InputTag);
	}
	if (bTargeting)
	{
		GetAuraAbilitySystemComponent()->InputTagHeld(InputTag);
	}
	else
	{
		HeldTime+= GetWorld()->GetDeltaSeconds();
		
		FHitResult HitResult;
		GetHitResultUnderCursor(ECC_Visibility,true,HitResult);
		if (!HitResult.bBlockingHit)return;
		if (APawn* ControlledPawn= GetPawn())
		{
			CachedDestination= HitResult.ImpactPoint;
			FVector MoveDir= (CachedDestination- ControlledPawn->GetActorLocation()).GetSafeNormal();
			ControlledPawn->AddMovementInput(MoveDir);
		}
	}
	
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	FVector2D Val= InputActionValue.Get<FVector2D>();
	FRotator Rot=GetControlRotation();
	FRotationMatrix RotMatrix=FRotationMatrix(Rot);
	FVector Forward= RotMatrix.GetUnitAxis(EAxis::X);
	FVector Right= RotMatrix.GetUnitAxis(EAxis::Y);
	GetPawn()->AddMovementInput(Forward,Val.X);
	GetPawn()->AddMovementInput(Right,Val.Y);
}


void AAuraPlayerController::CursorTrace()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility,false,HitResult);
	if (!HitResult.bBlockingHit)return;
	
	LastActor=ThisActor;
	ThisActor=Cast<IAuraEnemyCursorHitInterface>(HitResult.GetActor());
	if (ThisActor && ThisActor!=LastActor)
	{
		ThisActor->Highlight();
	}
	if (LastActor && ThisActor!=LastActor)
	{
		LastActor->UnHighlight();
	}
}

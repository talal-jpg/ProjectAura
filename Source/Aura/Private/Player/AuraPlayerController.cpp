// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"

#include "AuraEnemyCursorHitInterface.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
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
	GEngine->AddOnScreenDebugMessage(1,.1,FColor::Red,TEXT("InputPressed"));
	GEngine->AddOnScreenDebugMessage(1,.1,FColor::Red,InputTag.ToString());
}

void AAuraPlayerController::InputReleased(FGameplayTag InputTag)
{
	GEngine->AddOnScreenDebugMessage(2,.1,FColor::Blue,TEXT("InputReleased"));
	GEngine->AddOnScreenDebugMessage(1,.1,FColor::Blue,InputTag.ToString());
}

void AAuraPlayerController::InputHeld(FGameplayTag InputTag)
{
	GEngine->AddOnScreenDebugMessage(3,.1,FColor::Green,TEXT("InputHeld"));
	GEngine->AddOnScreenDebugMessage(1,.1,FColor::Green,InputTag.ToString());
	GetAuraAbilitySystemComponent()->InputTagHeld(InputTag);
	
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

void AAuraPlayerController::MoveToLocation(const FVector& Location)
{
	
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

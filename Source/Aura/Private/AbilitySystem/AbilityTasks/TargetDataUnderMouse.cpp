// Copyright Luca Palermo


#include "AbilitySystem/AbilityTasks/TargetDataUnderMouse.h"

UTargetDataUnderMouse* UTargetDataUnderMouse::CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility)
{
	UTargetDataUnderMouse* MyObj = NewAbilityTask<UTargetDataUnderMouse>(OwningAbility);
	return MyObj;
}

void UTargetDataUnderMouse::Activate()
{
	const FGameplayAbilityActorInfo* ActorInfo = Ability->GetCurrentActorInfo();
	if (!ActorInfo || !ActorInfo->PlayerController.IsValid())
	{
		return;
	}
	FHitResult HitResult;
	ActorInfo->PlayerController->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
	
	if (!HitResult.bBlockingHit) return;
	ValidData.Broadcast(HitResult.Location);
}

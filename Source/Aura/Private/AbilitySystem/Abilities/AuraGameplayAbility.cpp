// Copyright Luca Palermo


#include "AbilitySystem/Abilities/AuraGameplayAbility.h"

#include "Kismet/KismetSystemLibrary.h"

void UAuraGameplayAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                           const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	UKismetSystemLibrary::PrintString(this, FString("Activate ability C++"), true, true, FLinearColor::Yellow, 3.f);
}

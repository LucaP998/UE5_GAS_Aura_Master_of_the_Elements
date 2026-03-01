// Copyright Luca Palermo


#include "AbilitySystem/AuraAbilitySystemComponent.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec,
	FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	for (const FGameplayTag& Tag : TagContainer)
	{
		//TODO: broadcast tag to widget controller
		const FString Msg = FString::Printf(TEXT("Applied tag: %s"), *Tag.ToString());
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Msg);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, Msg);
	}
}

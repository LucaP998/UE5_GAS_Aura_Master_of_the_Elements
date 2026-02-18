// Copyright Luca Palermo


#include "Player/AuraPlayerState.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	// EGameplayEffectReplicationMode should be set to Mixed for players and Minimal for enemies
	// It decides what should be replicated on clients. 
	// Mixed means Gameplay effects are replicated on the owning client only.
	// Minimal means that it doesn't replicate, which is not needed for AI controlled enemies. 
	// Full should basically never be used in multiplayer games. 
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
	// This is updated for online play 100 times a second (if the server can manage it)
	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

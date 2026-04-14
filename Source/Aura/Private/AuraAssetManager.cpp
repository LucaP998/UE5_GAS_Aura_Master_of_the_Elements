// Copyright Luca Palermo


#include "AuraAssetManager.h"

#include "AbilitySystemGlobals.h"
#include "AuraGameplayTags.h"

// I had to add AssetManagerClassName=/Script/Aura.AuraAssetManager to DefaultEngine.ini in the config folder
// under /Script/Engine.Engine for this to be set as the default asset manager

// Tags can be added with a DataTable, defined in the DefaultGameplayTags.ini file, or natively in the AuraGameplayTags struct

UAuraAssetManager& UAuraAssetManager::Get()
{
	check(GEngine);
	UAuraAssetManager* AuraAssetManager = Cast<UAuraAssetManager>(GEngine->AssetManager);
	return *AuraAssetManager;
}

void UAuraAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FAuraGameplayTags::InitializeNativeGameplayTags();
	// This is required to use Target Data
	UAbilitySystemGlobals::Get().InitGlobalTags();
}

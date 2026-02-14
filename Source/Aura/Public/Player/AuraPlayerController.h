// Copyright Luca Palermo

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

// If I don't need to use the class but only delcare it, 
// it's better to forward declare it so I don't have to include the header
class UInputMappingContext;


UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAuraPlayerController();
	
protected:
	virtual void BeginPlay() override;
	
private:
	//To make this work I had to add it to Aura.Build.cs 
	//and also enable index plugins in rider
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> AuraContext;
	
};

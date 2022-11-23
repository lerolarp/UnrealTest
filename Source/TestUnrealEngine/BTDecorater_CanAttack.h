// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorater_CanAttack.generated.h"

/**
 * 
 */
UCLASS()
class TESTUNREALENGINE_API UBTDecorater_CanAttack : public UBTDecorator
{
	GENERATED_BODY()

public:

	UBTDecorater_CanAttack();

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};

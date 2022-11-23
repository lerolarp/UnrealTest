// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorater_CanAttack.h"
#include "MyAIController.h"
#include "MyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"


UBTDecorater_CanAttack::UBTDecorater_CanAttack()
{
	NodeName = TEXT("CanAttack");
}


bool UBTDecorater_CanAttack::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	auto CurrentPawn = OwnerComp.GetAIOwner()->GetPawn();

	if (CurrentPawn == nullptr)
		return false;

	auto Target = Cast<AMyCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(TEXT("Target"))));
	if (Target == nullptr)
		return false;

	return bResult && Target->GetDistanceTo(CurrentPawn) <= 200.f;
}

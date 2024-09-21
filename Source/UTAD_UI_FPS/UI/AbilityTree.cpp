// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityTree.h"
#include "TreeNode.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/TextBlock.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "Kismet/GameplayStatics.h"

void UAbilityTree::NativeConstruct()
{
	Player = Cast<AUTAD_UI_FPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if(Player)
	{
		Player->OnPointsChanged.BindUObject(this, &UAbilityTree::UpdatePointsText);
		UpdatePointsText(Player->Points);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player instance not found in UAbilityTree"));
	}
}

bool UAbilityTree::CheckIfPreviousNodeIsUnlocked(UTreeNode* Node)
{
	switch (Node->AbilityType)
	{
	case ABILITY_TYPE::MOVEMENT:
		return Node->AbilityLevel == movementAbilityLevel;
	case ABILITY_TYPE::HEALTH:
		return Node->AbilityLevel == healthAbilityLevel;
	case ABILITY_TYPE::DAMAGE:
		return Node->AbilityLevel == damageAbilityLevel;
	default:
		return false;
	}
}

bool UAbilityTree::EnoughPointsToUnlock(int Cost)
{
	return Cost <= Player->Points;
}

void UAbilityTree::UpdateLevels(UTreeNode* UnlockedNode)
{
	switch (UnlockedNode->AbilityType)
	{
	case ABILITY_TYPE::MOVEMENT:
		++movementAbilityLevel;
		break;
	case ABILITY_TYPE::HEALTH:
		++healthAbilityLevel;
		break;
	case ABILITY_TYPE::DAMAGE:
		++damageAbilityLevel;
		break;
	}
}

void UAbilityTree::UpdatePointsText(int NewPoints)
{
	PointsText->SetText(FText::FromString(FString::FromInt(NewPoints)));
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TreeNode.h"

#include "AbilityTree.generated.h"

class UTreeNode;

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UAbilityTree : public UUserWidget
{
	GENERATED_BODY()

private:

	int movementAbilityLevel = 1;

	int healthAbilityLevel = 1;

	int damageAbilityLevel = 1;

	class AUTAD_UI_FPSCharacter* Player;

protected:

	virtual void NativeConstruct() override;

public:

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UCanvasPanel* Canvas;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UTextBlock* PointsText;

	bool CheckIfPreviousNodeIsUnlocked(UTreeNode* Node);

	bool EnoughPointsToUnlock(int Cost);

	void UpdateLevels(UTreeNode* UnlockedNode);

	void UpdatePointsText(int NewPoints);
	
};

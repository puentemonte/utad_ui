// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "TreeNode.generated.h"

UENUM(BlueprintType)
enum class ABILITY_TYPE
{
	MOVEMENT = 0, HEALTH, DAMAGE
};

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UTreeNode : public UUserWidget
{
	GENERATED_BODY()

private:

	bool bIsButtonDown = false;

	bool bPrevAbilityUnlocked = false;

	float fLastClickTime = 0.0f;

	float fNecessaryClickTime = 0.5f;

	bool CanUnlock();

	class UAbilityTree* AbilityTreeInstance;

	class AUTAD_UI_FPSCharacter* Player;

protected:

	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

public:

	UPROPERTY(EditAnywhere, Category = UI)
	bool bUnlocked = false;

	UPROPERTY(EditAnywhere, Category = UI)
	int UnlockCost = 100;

	UPROPERTY(EditAnywhere, Category = UI)
	ABILITY_TYPE AbilityType;

	UPROPERTY(EditAnywhere, Category = UI)
	int AbilityLevel = 0;

	UPROPERTY(EditAnywhere, Category = UI, meta = (BindWidget))
	class UImage* Icon;

	UPROPERTY(EditAnywhere, Category = UI, meta = (BindWidget))
	class UProgressBar* UnlockingProgressBar;

	UPROPERTY(EditAnywhere, Category = UI, meta = (BindWidget))
	class UButton* Button;


	void MouseDown();

	void MouseUp();

	
};

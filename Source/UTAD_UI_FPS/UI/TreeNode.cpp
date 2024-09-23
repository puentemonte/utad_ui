// Fill out your copyright notice in the Description page of Project Settings.


#include "TreeNode.h"
#include "AbilityTree.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "Kismet/GameplayStatics.h"

void UTreeNode::NativeConstruct()
{
    Player = Cast<AUTAD_UI_FPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
    if (!Player)
    {
        UE_LOG(LogTemp, Error, TEXT("Player instance not found in UAbilityTree"));
    }

    FProgressBarStyle Style = UnlockingProgressBar->GetWidgetStyle();

    if (bUnlocked)
    {
        Style.FillImage.TintColor = FLinearColor(0, 1, 0, 0.25);
        UnlockingProgressBar->SetPercent(1);
        bPrevAbilityUnlocked = true;
    }
    else
	{
        Style.FillImage.TintColor = FLinearColor(0.33, 0.33, 0.33, 0.25);
		UnlockingProgressBar->SetPercent(0);
	}

    UnlockingProgressBar->SetWidgetStyle(Style);

    Button->OnClicked.AddDynamic(this, &UTreeNode::MouseDown);
    Button->OnReleased.AddDynamic(this, &UTreeNode::MouseUp);

    // Parent: Canvas -> Overlay -> UAbilityTree
    AbilityTreeInstance = Cast<UAbilityTree>(GetParent()->GetOuter()->GetOuter());
    if(!AbilityTreeInstance)
	{
		UE_LOG(LogTemp, Error, TEXT("AbilityTree not found in UTreeNode::NativeConstruct()"))
	}
}

void UTreeNode::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);

    if (bIsButtonDown)
    {
        if (fLastClickTime < fNecessaryClickTime)
        {
            fLastClickTime += InDeltaTime;

            float Percent = (float)fLastClickTime / (float)fNecessaryClickTime;
            UnlockingProgressBar->SetPercent(Percent); // Need to multiply by delta time??

            if (fLastClickTime >= fNecessaryClickTime)
			{
                bUnlocked = true;
                FProgressBarStyle Style = UnlockingProgressBar->GetWidgetStyle();
                Style.FillImage.TintColor = FLinearColor(0, 1, 0, 0.25);
                UnlockingProgressBar->SetWidgetStyle(Style);
                UnlockingProgressBar->SetPercent(1);

                Player->RemovePoints(UnlockCost);

                if (AbilityTreeInstance)
				{
					AbilityTreeInstance->UpdateLevels(this);
				}
			}
        }
    }
}
bool UTreeNode::CanUnlock()
{
    return AbilityTreeInstance->EnoughPointsToUnlock(UnlockCost)     // Enough points
        && !bUnlocked                                                // Not yet unlocked
        && AbilityTreeInstance->CheckIfPreviousNodeIsUnlocked(this); // Previous node is unlocked
}


void UTreeNode::MouseDown()
{
    if (CanUnlock())
    {
        bIsButtonDown = true;
        fLastClickTime = 0.f;
    }
}

void UTreeNode::MouseUp()
{
    bIsButtonDown = false;
}

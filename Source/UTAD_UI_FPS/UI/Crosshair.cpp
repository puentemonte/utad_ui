// Fill out your copyright notice in the Description page of Project Settings.


#include "Crosshair.h"

#include "Components/Image.h"

void UCrosshair::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UCrosshair::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UCrosshair::ShootingAnim()
{
	fShootingAnimProgress = 0.f;
	bShooting = true;
}

void UCrosshair::SetColor(bool bAimingAtEnemy)
{
	if (bAimingAtEnemy)
	{
		Crosshair->SetBrushTintColor(FLinearColor::Yellow);
	}
	else
	{
		Crosshair->SetBrushTintColor(FLinearColor::Black);
	}
}

void UCrosshair::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
		Super::NativeTick(MyGeometry, InDeltaTime);

		if (fShootingAnimProgress < fShootingAnimDuration)
		{
			fShootingAnimProgress += InDeltaTime;

			if (fShootingAnimProgress >= fShootingAnimDuration)
			{
				bShooting = false;
			}
		}

		if (bShooting)
		{
			Crosshair->SetDesiredSizeOverride(vDesiredSize);
		}
		else
		{
			Crosshair->SetDesiredSizeOverride(vNormalSize);
		}
}
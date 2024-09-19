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
	// Need to reset the time
	fShootingAnimTime = fShootingAnimDuration;

	CrosshairImage->SetDesiredSizeOverride(vDesiredSize);
}

void UCrosshair::SetColor(bool bAimingAtEnemy)
{
	if (bAimingAtEnemy)
	{
		CrosshairImage->SetBrushTintColor(FLinearColor::Yellow);
	}
	else
	{
		CrosshairImage->SetBrushTintColor(FLinearColor::Black);
	}
}

void UCrosshair::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
		Super::NativeTick(MyGeometry, InDeltaTime);

		if (fShootingAnimTime > 0.f)
		{
			fShootingAnimTime -= InDeltaTime;
		}
		else
		{
			CrosshairImage->SetDesiredSizeOverride(FVector2D::ZeroVector); // Needed?
		}
}

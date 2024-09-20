// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerDamageSign.h"

void UPlayerDamageOverlay::Show()
{
	SetVisibility(ESlateVisibility::Visible);
	fFadeOutProgress = 0.f;
}

void UPlayerDamageOverlay::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UPlayerDamageOverlay::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (fFadeOutProgress < fFadeOutTime)
	{
		fFadeOutProgress += InDeltaTime;
		if (fFadeOutProgress >= fFadeOutTime)
		{
			SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

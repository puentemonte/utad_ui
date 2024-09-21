// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHealthBar.h"
#include "Kismet/GameplayStatics.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "Components/ProgressBar.h"
#include "Math/Color.h"
#include "Styling/SlateColor.h"

#define BLINK_ANIMATION_TIME 1.f
#define BLINK_THRESHOLD 0.25f

void UPlayerHealthBar::NativeConstruct()
{
	Super::NativeConstruct();

	if (AUTAD_UI_FPSCharacter* PlayerCharacter = Cast<AUTAD_UI_FPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)))
	{
		PlayerCharacter->OnHealthChanged.BindUObject(this, &UPlayerHealthBar::UpdatePlayerHealthBar);
	}
}

void UPlayerHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	LowHealthBlink(InDeltaTime);
}

void UPlayerHealthBar::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UPlayerHealthBar::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UPlayerHealthBar::UpdatePlayerHealthBar(int NewHealth, int MaxHealth)
{
	float Percentage = (float)NewHealth / (float)MaxHealth;
	PlayerHealthBar->SetPercent(Percentage);
	bIsLowHealth = Percentage <= BLINK_THRESHOLD;
}

void UPlayerHealthBar::LowHealthBlink(float InDeltaTime)
{
	FProgressBarStyle Style = PlayerHealthBar->GetWidgetStyle();
	if (bIsLowHealth)
	{
		BlinkTimer += InDeltaTime;

		if (BlinkTimer >= BLINK_ANIMATION_TIME)
		{
			BlinkTimer = 0.f;
			bBlinkTurningRed = !bBlinkTurningRed;
		}

		// Oscillate between red and green if low health
		if (bBlinkTurningRed)
		{
			Style.FillImage.TintColor = FSlateColor(FLinearColor::Red);
		}
		else
		{
			Style.FillImage.TintColor = FSlateColor(FLinearColor::Green);
		}
	}
	else
	{
		Style.FillImage.TintColor = FSlateColor(FLinearColor::Green);
	}
	PlayerHealthBar->SetWidgetStyle(Style);
}

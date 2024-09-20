// Fill out your copyright notice in the Description page of Project Settings.


#include "SplashScreen.h"

#include "Kismet/GameplayStatics.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "PlayerHUD.h"

void USplashScreen::NativeConstruct()
{
	Super::NativeConstruct();

	PlayerCharacter = Cast<AUTAD_UI_FPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (PlayerCharacter)
	{
		PlayerCharacter->GetPlayerHUDInstance()->Hide();
		PlayerCharacter->DisableInput(nullptr);
	}
}

void USplashScreen::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if (fSplashScreenProgress < fSplashScreenDuration)
	{
		fSplashScreenProgress += InDeltaTime;
	}
	else
	{
		PlayerCharacter->EnableInput(nullptr);
		PlayerCharacter->GetPlayerHUDInstance()->ShowNoWeapon();
		RemoveFromParent();
	}
}

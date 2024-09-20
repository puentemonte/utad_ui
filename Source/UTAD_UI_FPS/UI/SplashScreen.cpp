// Fill out your copyright notice in the Description page of Project Settings.


#include "SplashScreen.h"

void USplashScreen::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if (fSplashScreenProgress < fSplashScreenDuration)
	{
		fSplashScreenProgress += InDeltaTime;
	}
	else
	{
		RemoveFromParent();
	}
}

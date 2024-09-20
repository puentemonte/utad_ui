// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "SplashScreen.generated.h"

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API USplashScreen : public UUserWidget
{
	GENERATED_BODY()
	
private:
	float fSplashScreenProgress = 0.f;

	class AUTAD_UI_FPSCharacter* PlayerCharacter;

public:
	UPROPERTY(EditAnywhere, Category = UI)
	float fSplashScreenDuration = 3.f;


protected:
	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};

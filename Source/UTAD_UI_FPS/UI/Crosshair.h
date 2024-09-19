// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Crosshair.generated.h"

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UCrosshair : public UUserWidget
{
	GENERATED_BODY()

private:
	float fShootingAnimTime = 0.f;

	FVector2D vDesiredSize = FVector2D(200.f, 200.f);
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI | Crosshair")
	float fShootingAnimDuration = 1.f;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* CrosshairImage;

	void ShootingAnim();

	void SetColor(bool bAimingAtEnemy);

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

};

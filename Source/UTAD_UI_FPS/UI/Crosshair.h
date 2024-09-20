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
	float fShootingAnimProgress = 0.f;

	bool bShooting = true;
	
public:

	UPROPERTY(EditAnywhere, Category = "UI | Crosshair")
	FVector2D vNormalSize = FVector2D(100.f, 100.f);

	UPROPERTY(EditAnywhere, Category = "UI | Crosshair")
	FVector2D vDesiredSize = FVector2D(150.f, 150.f);

	UPROPERTY(EditAnywhere, Category = "UI | Crosshair")
	float fShootingAnimDuration = 0.5f;
	
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* Crosshair;

	void ShootingAnim();

	void SetColor(bool bAimingAtEnemy);

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

};

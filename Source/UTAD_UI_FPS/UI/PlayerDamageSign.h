// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "PlayerDamageSign.generated.h"

/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API UPlayerDamageOverlay : public UUserWidget
{
	GENERATED_BODY()

private:
	float fFadeOutProgress = 0.f;

public:
	UPROPERTY(EditAnywhere, Category = UI)
	float fFadeOutTime = 0.1f;

	void Show();

	void Hide();


protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};

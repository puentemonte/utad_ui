// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "Crosshair.h"
#include "AmmoCounter.h"
#include "PlayerHealthBar.h"
#include "ReloadBar.h"

void UPlayerHUD::ShowNoWeapon()
{
	CrosshairWidget->Hide();
	PlayerHealthBarWidget->Show();
}

void UPlayerHUD::ShowAll()
{
	CrosshairWidget->Show();
	PlayerHealthBarWidget->Show();
}

void UPlayerHUD::Hide()
{
	CrosshairWidget->Hide();
	PlayerHealthBarWidget->Hide();
}

# UTAD-UI-FPS-Public

## HUD

### Health bar

- PlayerHealthBar with Health and MaxHealth params
- Progress bar has to show the value of Health
- If Player receives damage, Progress bar has to decrease
- If Health param is @ 25% of MaxHealth, the Progress bar has to oscillate between original color and red indifinitely

### Dynamic crosshair

- Already existing crosshair
- Animate crosshair when shooting
- If Player is aiming @ Enemy it has to change color

To animate the crosshair when shooting, we need to override the Tick function of the UserWidget. Overriding normal Tick and Construct will not work in cpp, Native prefix is needed. We need an animation duration, and a "normal" and "desired" crosshair size. 

```cpp
void UMyWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);
    

    // Code...
}
```

We need to call the ShootingAnim from the Crosshair class in the WeaponComponent when the Weapon is shot.

```cpp

Character->GetPlayerHUDInstance()->Crosshair->ShootingAnim();
```

To make it work, in the Crosshair Image of the WB_Crosshair, check sizeToContent.

For changing the color of the Crosshair when aiming at an Enemy, we need the actual image of the crosshair. To change it, just call the SetColor method from the Tick function of the character. 

```cpp
void AUTAD_UI_FPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bHasRifle)
	{
		FVector Start = FirstPersonCameraComponent->GetComponentLocation();
		FVector End = Start + FirstPersonCameraComponent->GetForwardVector() * 10000.f;

		FHitResult HitResult;

		if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Visibility))
		{
			if(AUTAD_UI_FPS_Enemy* Enemy = Cast<AUTAD_UI_FPS_Enemy>(HitResult.GetActor()))
			{
				PlayerHUDInstance->Crosshair->SetColor(true);
			}
			else
			{
				PlayerHUDInstance->Crosshair->SetColor(false);
			}
		}
		else
		{
			PlayerHUDInstance->Crosshair->SetColor(false);
		}
	}
}
```

Check if there's an Enemy in front.

### Damage sign

- When Player is damaged by Enemy, Health decreases
- Implement new PlayerHitMarker showing damage received

## Screens

### Splash screen

- When Game is started, show Splash Screen, after a few seconds, disappears

### Ability tree

- Menu accesible from Game
- 3 Branches: movement speed, health, damage
- Each Branch has 2 Nodes
- Unlocking abilities requires unlocking previous ability from the same Branch
- Select ability and confirm unlocking
- Give Player points to unlock new abilities (either give them at the start or killing enemies gives points)

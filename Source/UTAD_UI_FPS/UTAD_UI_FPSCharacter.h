// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UTAD_UI_FPSCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class UAnimMontage;
class USoundBase;
class UTP_WeaponComponent;
struct FInputActionValue;

class UPlayerHUD;
class USplashScreen;
class UPlayerDamageOverlay;
class UAbilityTree;

DECLARE_DELEGATE_TwoParams(FOnHealthChanged, int /* New Health*/, int /* Max Health*/)
DECLARE_DELEGATE_OneParam(FOnPointsChanged, int /* New Points */)

UCLASS(config=Game)
class AUTAD_UI_FPSCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	/** Weapon component that is attached */
	UPROPERTY(VisibleDefaultsOnly, Category = Weapon)
	UTP_WeaponComponent* AttachedWeaponComponent;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/* UI */

	bool AbilityTreeOpen = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* OpenAbilityTreeAction;

	
public:
	AUTAD_UI_FPSCharacter();

protected:
	virtual void BeginPlay();

	virtual void Tick(float DeltaTime) override;

public:
		
	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	/** Current Health */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stats)
	int Health = 100;

	/** Max Health */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Stats)
	int MaxHealth = 100;

	/** Counter for bullets in player (not in weapon) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon)
	int TotalBullets = 100;

	/** Bool for AnimBP to switch to another animation set */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Weapon)
	bool bHasRifle;

	/** Setter to set the int */
	UFUNCTION(BlueprintCallable, Category = Stats)
	void SetHealth(int NewHealth);

	/** Getter for the int */
	UFUNCTION(BlueprintCallable, Category = Stats)
	int GetHealth();

	/** Setter to set the int */
	UFUNCTION(BlueprintCallable, Category = Stats)
	void SetMaxHealth(int NewMaxHealth);

	/** Getter for the int */
	UFUNCTION(BlueprintCallable, Category = Stats)
	int GetMaxHealth();

	/** Setter to set the bool */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void SetHasRifle(bool bNewHasRifle);

	/** Getter for the bool */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	bool GetHasRifle();

	/** Setter to set the int */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void SetTotalBullets(int NewTotalBullets);

	/** Getter for the int */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	int GetTotalBullets();

	/** Function to add an amount of bullets to TotalBullets */
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void AddBullets(int Bullets);

	void SetAttachedWeaponComponent(UTP_WeaponComponent* WeaponComponent);

	void RemovePoints(int InPoints);

	/****************************************************/
	/************************ UI ************************/
	/****************************************************/

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = UI)
	int Points = 5000;

	/** Widget Blueprints that will be used to create the instances */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI)
	TSubclassOf<UPlayerHUD> PlayerHUDWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI)
	TSubclassOf<USplashScreen> SplashScreenWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI)
	TSubclassOf<UPlayerDamageOverlay> PlayerDamageSignWidget;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = UI)
	TSubclassOf<UAbilityTree> AbilityTreeWidget;

	FOnHealthChanged OnHealthChanged;
	FOnPointsChanged OnPointsChanged;

protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void OpenAbilityTree(const FInputActionValue& Value);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
	/** Returns AttachedWeaponComponent subobject **/
	UTP_WeaponComponent* GetAttachedWeaponComponent() const { return AttachedWeaponComponent; }

	UPlayerHUD* GetPlayerHUDInstance() const { return PlayerHUDInstance; };
	
	UPlayerDamageOverlay* GetPlayerDamageOverlayInstance() const { return PlayerDamageOverlayInstance; };

private:

	/****************************************************/
	/************************ UI ************************/
	/****************************************************/

	/** Instances that will be created and showed on viewport */
	UPlayerHUD* PlayerHUDInstance;

	USplashScreen* SplashScreenInstance;

	UPlayerDamageOverlay* PlayerDamageOverlayInstance;

	UAbilityTree* AbilityTreeInstance;
};


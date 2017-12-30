// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) {  return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this, OutLaunchVelocity,
		StartLocation, HitLocation,
		LaunchSpeed, false, 0, 0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	// Calculate the outlaunch velocity.
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		auto Name = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%f: %s Aim solution found."), Time, *Name);
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		auto Name = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%f: %s No aim solution found."),Time, *Name);
	}
	
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// work out distance between current barrel position and aim direction
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	Barrel->Elevate(DeltaRotator.Pitch); // TODO Remove magic number.
}


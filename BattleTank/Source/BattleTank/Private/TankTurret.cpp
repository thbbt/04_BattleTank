// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	// Adjust Turret and Barrel to match AimDirection relative to the position of the tank.
	// Move the barrel the right amount this frame
	// Given Max elevation speed
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, Rotation, 0));
}




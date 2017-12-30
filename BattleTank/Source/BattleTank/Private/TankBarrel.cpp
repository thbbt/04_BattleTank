// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// Adjust Turret and Barrel to match AimDirection relative to the position of the tank.
	// Move the barrel the right amount this frame
	// Given Max elevation speed
	UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate called at speed %f"), DegreesPerSecond);
}
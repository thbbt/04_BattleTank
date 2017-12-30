// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController could not find a player tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found plaery tank: %s"), *(PlayerTank->GetName()));
	}
	//UE_LOG(LogTemp, Warning, TEXT("AICotroller Begin Play"));
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerPawn);
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetPlayerTank())
	{
		// TODO move towards the player
		// Start aiming towards the palyer
		// fire if ready

		//AimTowardsPlayer();
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}	
	//UE_LOG(LogTemp, Warning, TEXT("PlayerContoler Tick()."));
}

void ATankAIController::AimTowardsPlayer()
{
	if (!GetControlledTank()) { return; }
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}


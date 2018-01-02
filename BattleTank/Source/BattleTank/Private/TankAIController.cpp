// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();	
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	auto* ControlledTank = Cast<ATank>(GetPawn());
	auto* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank)
	{
		// TODO move towards the player
		// Start aiming towards the palyer
		//AimTowardsPlayer();
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		ControlledTank->Fire(); // TODO limit firing rate
	}		
}

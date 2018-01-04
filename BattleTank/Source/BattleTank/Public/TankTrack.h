// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force and to apply forces to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category=Input)
	void SetThrottle(float Throttle);

	// Max force per tank track
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000; // assume tank 40 tonne 1g of accelleration
	
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlattform.h"

// Sets default values
AMovingPlattform::AMovingPlattform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlattform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlattform::Tick(float DeltaTime)
{
	MovePlattform(DeltaTime);
	RotatePlattform(DeltaTime);
}

void AMovingPlattform::MovePlattform(float DeltaTime)
{
	FVector newLocation = GetActorLocation();
	Super::Tick(DeltaTime);
	newLocation += moveSpeed * Direction * DeltaTime;
	float distance = FVector::Dist(StartLocation, newLocation);
	if (distance > MaxDistance)
	{
		FVector normalizedDir = Direction;
		normalizedDir.Normalize();
		newLocation = StartLocation + normalizedDir * MaxDistance;
		Direction *= -1;
		StartLocation = newLocation;
	}

	SetActorLocation(newLocation);
}

void AMovingPlattform::RotatePlattform(float DeltaTime)
{
	FRotator newRotation = GetActorRotation();
	newRotation += rotateSpeed * RotateDirection * DeltaTime;
	SetActorRotation(newRotation);
}


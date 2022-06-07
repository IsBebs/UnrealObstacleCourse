// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlattform.generated.h"

UCLASS()
class UNREALLEARNINGKIT_API AMovingPlattform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlattform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, Category="Temp")
	FVector MyVector = FVector(1,2,3);
	UPROPERTY(EditAnywhere, Category="Plattform")
	float moveSpeed = 5.0f;
	UPROPERTY(EditAnywhere, Category = "Plattform")
	float rotateSpeed = 5.0f;
private:
	FVector StartLocation;
	UPROPERTY(EditAnywhere, Category = "Plattform")
	FVector Direction =FVector(0,0,1);
	UPROPERTY(EditAnywhere, Category = "Plattform")
	FRotator RotateDirection = FRotator(0, 0, 0);
	UPROPERTY(EditAnywhere, Category = "Plattform")
	float MaxDistance = 5000;
	void MovePlattform(float DeltaTime);
	void RotatePlattform(float DeltaTime);
};

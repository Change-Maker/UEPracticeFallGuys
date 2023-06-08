// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstacle.generated.h"

UCLASS()
class PRACTICEFALLGUYS_API AObstacle : public AActor
{
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  AObstacle();

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
  bool bReciprocating = true;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
  float MovingDistance = 0.0f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
  FVector MovingVelocity = FVector::ZeroVector;

private:
  UPROPERTY()
  FVector StartLocation = FVector::ZeroVector;

  UPROPERTY()
  FVector TargetLocation = FVector::ZeroVector;

  UPROPERTY()
  FVector TempLocation = FVector::ZeroVector;
};

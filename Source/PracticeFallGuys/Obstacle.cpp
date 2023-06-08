// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"

// Sets default values
AObstacle::AObstacle()
{
   // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
  Super::BeginPlay();

  StartLocation = GetActorLocation();
  TargetLocation = StartLocation + (MovingVelocity / MovingVelocity.Size()) * MovingDistance;
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);

  TempLocation = GetActorLocation() + (MovingVelocity * DeltaTime);

  if (FVector::Dist(StartLocation, TempLocation) < MovingDistance) {
    SetActorLocation(TempLocation);
  } else {
    SetActorLocation(TargetLocation);
    if (bReciprocating) {
      Swap<FVector>(StartLocation, TargetLocation);
      MovingVelocity = -MovingVelocity;
    }
  }
}

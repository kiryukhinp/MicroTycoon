// Fill out your copyright notice in the Description page of Project Settings.


#include "GroundPlane.h"


// Sets default values
AGroundPlane::AGroundPlane()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PlaneMesh = CreateDefaultSubobject<UStaticMeshComponent>("Found");
	RootComponent=PlaneMesh;
}

// Called when the game starts or when spawned
void AGroundPlane::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGroundPlane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


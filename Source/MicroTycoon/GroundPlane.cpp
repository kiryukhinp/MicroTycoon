// Fill out your copyright notice in the Description page of Project Settings.


#include "GroundPlane.h"



// Sets default values
AGroundPlane::AGroundPlane()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PlaneMesh = CreateDefaultSubobject<UStaticMeshComponent>("Found");
	RootComponent=PlaneMesh;
	GridOrigin = FVector2D(0);
}

// Called when the game starts or when spawned
void AGroundPlane::BeginPlay()
{
	Super::BeginPlay();
		
}
#if WITH_EDITOR
void AGroundPlane::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	CalculateGrid();
	
}
#endif

// Called every frame
void AGroundPlane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

TArray<FVector2D> AGroundPlane::CalculateGrid()
{
	GridPoints.Empty();
	for (int i = 0; i<GridX;i++)
	{
		for (int j= 0; j < GridY; j++) GridPoints.Add(FVector2D(GridOrigin.X+ GridStep*i,GridOrigin.Y+ GridStep*j));
	}
	return GridPoints;
}






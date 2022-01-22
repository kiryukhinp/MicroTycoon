// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseBuilding.h"


// Sets default values
ABaseBuilding::ABaseBuilding()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
	Mesh->SetCollisionObjectType(ECC_WorldStatic);
	TimerTick = 1;
	ResMax = 100;
	ResAmount = 0;
	ResPerf = 10;
	BuildingTimeStep = 0.5;
	PerfTimerDelegate = FTimerDelegate::CreateUObject(this,&ABaseBuilding::AddRes_Internal);
	BuildingTimerDelegate = FTimerDelegate::CreateUObject(this,&ABaseBuilding::OnBuild_Internal);
	BuildingProgress = 0;
	BuildingStep = 1;
	BuildingMax = 10;
}

// Called when the game starts or when spawned
void ABaseBuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseBuilding::AddRes_Internal()
{
	if (ResAmount<ResMax)
	{
		ResAmount = ResAmount+ResPerf;	
		UE_LOG(LogTemp,Warning,TEXT("%d"),ResAmount );
		AddRes();
	}
}

// Called every frame
void ABaseBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseBuilding::StartBuilding()
{
	GetWorldTimerManager().SetTimer(BuildingTimerHandle,BuildingTimerDelegate,BuildingTimeStep,true);
	
}

void ABaseBuilding::OnFinishBuild_Internal()
{
	UE_LOG(LogTemp,Warning,TEXT("builded"))
	GetWorldTimerManager().SetTimer(PerfTimerHandle,PerfTimerDelegate,TimerTick,true);
	OnFinishBuild();	
}


void ABaseBuilding::OnBuild_Internal()
{
	UE_LOG(LogTemp,Warning,TEXT("%d"),BuildingProgress );
	if (BuildingProgress<BuildingMax)
	{
		BuildingProgress = BuildingProgress + BuildingStep;
		OnBuild();
	}
		
	else
	{
		GetWorldTimerManager().ClearTimer(BuildingTimerHandle);
		OnFinishBuild_Internal();		
	}	
}

void ABaseBuilding::BeginDestroy()
{
	Super::BeginDestroy();
	PerfTimerHandle.Invalidate();
	BuildingTimerHandle.Invalidate();
}

void ABaseBuilding::StartPlacing()
{
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ABaseBuilding::EndPlacing_Implementation()
{
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}









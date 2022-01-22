// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingSocket.h"


// Sets default values
ABuildingSocket::ABuildingSocket()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");	
	RootComponent = Mesh;
	Mesh->SetCollisionObjectType(ECC_WorldStatic);
	bEmpty = true;
}

// Called when the game starts or when spawned
void ABuildingSocket::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABuildingSocket::BuildHere()
{
	bEmpty =false;
	Mesh->SetVisibility(false);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called every frame
void ABuildingSocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


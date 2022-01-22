// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "BuildingSocket.generated.h"

UCLASS()
class MICROTYCOON_API ABuildingSocket : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABuildingSocket();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION()
	void BuildHere();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)		
	UStaticMeshComponent* Mesh;
	UPROPERTY(BlueprintReadOnly)
	bool bEmpty;
	
	
};

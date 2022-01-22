// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GroundPlane.generated.h"

UCLASS()
class MICROTYCOON_API AGroundPlane : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGroundPlane();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	TArray<FVector2D> CalculateGrid();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PlaneMesh;
	UPROPERTY(BlueprintReadOnly,Category=Grid)
	TArray<FVector2D> GridPoints;
	UPROPERTY(EditAnywhere,Category=Grid)
	int GridX;
	UPROPERTY(EditAnywhere,Category=Grid)
	int GridY;
	UPROPERTY(EditAnywhere,Category=Grid)
	float GridStep;
	UPROPERTY(EditAnywhere,Category=Grid)
	FVector2D GridOrigin;
};

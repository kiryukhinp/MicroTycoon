// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseBuilding.generated.h"

UCLASS()
class MICROTYCOON_API ABaseBuilding : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABaseBuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void BeginDestroy() override;

	void AddRes_Internal();
	UFUNCTION(BlueprintImplementableEvent)
	void AddRes();
	UFUNCTION(BlueprintCallable)
	void StartPlacing();
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void EndPlacing();
	UFUNCTION(BlueprintCallable)
	void StartBuilding();
	
	UFUNCTION()
	void OnFinishBuild_Internal();
	UFUNCTION(BlueprintImplementableEvent)
	void OnFinishBuild();
	
	void OnBuild_Internal();
	UFUNCTION(BlueprintImplementableEvent)
	void OnBuild();
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent*Mesh;
	UPROPERTY(EditAnywhere)
	float TimerTick;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,category = Resource)
	int ResPerf;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,category = Resource)
	int ResAmount;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, category = Resource)
	int ResMax;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, category = BuildingProcess)
	float BuildingTimeStep;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, category = BuildingProcess)
	int BuildingStep;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, category = BuildingProcess)
	int BuildingProgress;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, category = BuildingProcess)
	int BuildingMax;
	
	FTimerHandle PerfTimerHandle;
	FTimerDelegate PerfTimerDelegate;
	FTimerHandle BuildingTimerHandle;
	FTimerDelegate BuildingTimerDelegate;
};

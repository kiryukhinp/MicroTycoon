// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseBuilding.h"
#include "BuildingSocket.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "TycoonPawn.generated.h"

UCLASS()
class MICROTYCOON_API ATycoonPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATycoonPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
	void OnBuildingLocatingStart(FTransform SocketTransform, TSubclassOf<ABaseBuilding> CurBuilding);
	UFUNCTION(BlueprintImplementableEvent)
	void OnBuildingLocatingProcessing(FTransform SocketTransform);
	UFUNCTION(BlueprintNativeEvent)
	void OnBuildingLocationFinished(FTransform SocketTransform);
	void PressOnScene();

	
	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;
	UPROPERTY()
	APlayerController* PlayerController;
	UPROPERTY()
	ABuildingSocket *LastSocket;
	UPROPERTY(BlueprintReadWrite)
	ABaseBuilding *LastBuilding;
	float TraceLength;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bBuildingInProcess;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool bCanBuild;
	FHitResult LastHitResult;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Building)
	TSubclassOf<ABaseBuilding> BuildingType;
};

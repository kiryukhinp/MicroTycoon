// Fill out your copyright notice in the Description page of Project Settings.


#include "TycoonPawn.h"

#include "BuildingSocket.h"
#include "DrawDebugHelpers.h"

// Sets default values
ATycoonPawn::ATycoonPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	RootComponent = Camera;
	TraceLength = 2000;
	LastBuilding = nullptr;
	BuildingType = ABaseBuilding::StaticClass();
	bBuildingInProcess = false;
}

// Called when the game starts or when spawned
void ATycoonPawn::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = Cast<APlayerController>(Controller); 
	if (PlayerController) PlayerController->SetShowMouseCursor(true);
}

// Called every frame
void ATycoonPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bBuildingInProcess)
	{
		if (PlayerController) PlayerController->GetHitResultUnderCursor(ECC_WorldStatic,false,LastHitResult);
		LastSocket = Cast<ABuildingSocket>(LastHitResult.Actor);
		if (LastSocket)	OnBuildingLocatingProcessing(LastSocket->GetActorTransform());
	}
}

// Called to bind functionality to input
void ATycoonPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("OnMouseLeftPress",IE_Pressed,this, &ATycoonPawn::PressOnScene);
}

void ATycoonPawn::OnBuildingLocatingStart_Implementation(FTransform SocketTransform,
	TSubclassOf<ABaseBuilding> CurBuilding)
{
    if (!bBuildingInProcess)
    {
        UE_LOG(LogTemp,Warning,TEXT("BuildingStarted"));
    	bCanBuild = true;
    	bBuildingInProcess = true;
    	OnBuildingLocatingStart(SocketTransform,CurBuilding);
    }   
    
 }

void ATycoonPawn::OnBuildingLocationFinished_Implementation(FTransform SocketTransform)
{
	bCanBuild = false;
	bBuildingInProcess = false;
	UE_LOG(LogTemp,Warning,TEXT("BuildingFinished"));
	OnBuildingLocationFinished(SocketTransform);
}

void ATycoonPawn::PressOnScene()
{
	UE_LOG(LogTemp,Warning,TEXT("click"));	
	PlayerController->GetHitResultUnderCursor(ECC_WorldStatic,false,LastHitResult);
	LastSocket = Cast<ABuildingSocket>(LastHitResult.Actor);
	if (LastSocket&&bBuildingInProcess)
	{
		bBuildingInProcess = false;
		LastSocket->BuildHere();		
		OnBuildingLocationFinished_Implementation(LastSocket->GetActorTransform());
		
	}
	//DrawDebugSphere(GetWorld(), LastHitResult.Location, 5.0f, 6.0f, FColor::Red, false, 5, 0U, 1);
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, LastHitResult.Actor.IsValid() ? FString(LastHitResult.Actor->GetName())
	//	:"none");    
}




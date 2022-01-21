// Fill out your copyright notice in the Description page of Project Settings.


#include "TycoonPawn.h"

#include "DrawDebugHelpers.h"

// Sets default values
ATycoonPawn::ATycoonPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	RootComponent = Camera;
	TraceLength = 2000;
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

}

// Called to bind functionality to input
void ATycoonPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("OnMouseLeftPress",IE_Pressed,this, &ATycoonPawn::PressOnScene);

}

void ATycoonPawn::PressOnScene()
{
	UE_LOG(LogTemp,Warning,TEXT("click"));
	FVector MousePosition;
	FVector MouseDirection;
	FHitResult HitResult;
	PlayerController->GetHitResultUnderCursor(ECollisionChannel::ECC_WorldStatic,false,HitResult);
	DrawDebugSphere(GetWorld(), HitResult.Location, 5.0f, 6.0f, FColor(255, 0, 0), false, 5, 0U, 1);
	PlayerController->DeprojectMousePositionToWorld(MousePosition,MouseDirection);
	UE_LOG(LogTemp,Warning,TEXT("%f %f %f"),MousePosition.X,MousePosition.Y,MousePosition.Z);
	//PerformRayCast(MousePosition);
}




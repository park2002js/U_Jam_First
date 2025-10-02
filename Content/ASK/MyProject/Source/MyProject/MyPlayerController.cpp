// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "GameFramework/Pawn.h"

AMyPlayerController::AMyPlayerController()
{
    bShowMouseCursor = true;
}

void AMyPlayerController::BeginPlay()
{
    Super::BeginPlay();
}

void AMyPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAxis("Turn", this, &AMyPlayerController::Turn);
    InputComponent->BindAxis("LookUp", this, &AMyPlayerController::LookUp);
}

void AMyPlayerController::Turn(float Value)
{
    if (GetPawn())
    {
        GetPawn()->AddControllerYawInput(Value);
    }
}

void AMyPlayerController::LookUp(float Value)
{
    if (GetPawn())
    {
        GetPawn()->AddControllerPitchInput(Value);
    }
}
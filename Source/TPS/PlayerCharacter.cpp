// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	Camera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Jump);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("TurnCamera"), this, &APlayerCharacter::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APlayerCharacter::LookUp);

}
void APlayerCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void APlayerCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void APlayerCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void APlayerCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}
void APlayerCharacter::MoveForward(float Value)
{
    MoveForwardValue = Value;
    AddMovementInput(GetActorForwardVector(), Value);
}

void APlayerCharacter::MoveRight(float Value)
{
    MoveRightValue = Value;
    AddMovementInput(GetActorRightVector(), Value);
}
void APlayerCharacter::HandleDeath()
{
    // 이미 죽은 상태라면 중복 처리 방지
    if (CurrentHealth <= 0.0f)
    {
        return;
    }

    // 1. 게임 멈춤 (시간 흐름 정지)
    UGameplayStatics::SetGamePaused(GetWorld(), true);

    // 2. 플레이어 입력을 UI 전용으로 변경하고 마우스 커서 표시
    APlayerController* PC = Cast<APlayerController>(GetController());
    if (PC)
    {
        PC->SetInputMode(FInputModeUIOnly());
        PC->bShowMouseCursor = true;
    }

    // 3. 게임 오버 UI 표시 (블루프린트 위젯 생성 및 뷰포트에 추가)
    if (GameOverWidgetClass) // 미리 Blueprint에서 설정된 Widget Class 변수
    {
        UUserWidget* GameOverWidget = CreateWidget<UUserWidget>(GetWorld(), GameOverWidgetClass);
        if (GameOverWidget)
        {
            GameOverWidget->AddToViewport();
        }
    }
}
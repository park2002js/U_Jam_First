// Fill out your copyright notice in the Description page of Project Settings.


#include "JSP/EnemyCharacter.h"

#include "EnemyAIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // 캐릭터의 기본 설정 (이동 및 회전)
    GetCapsuleComponent()->SetCapsuleHalfHeight(90.0f);
    GetCapsuleComponent()->SetCapsuleRadius(30.0f);

    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);

    // 스켈레탈 메시를 찾아서 할당
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_MANNEQUIN(TEXT("/Game/Characters/Mannequins/Meshes/SKM_Manny_Simple"));
    if (SK_MANNEQUIN.Succeeded())
    {
        GetMesh()->SetSkeletalMesh(SK_MANNEQUIN.Object);
    }

    // 메시 위치 및 회전 조정
    GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

    // AI 컨트롤러 클래스 지정
    AIControllerClass = AEnemyAIController::StaticClass();
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    TeamId = FGenericTeamId(1); // 적은 1번 팀
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


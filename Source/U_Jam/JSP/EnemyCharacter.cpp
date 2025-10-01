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

    // ĳ������ �⺻ ���� (�̵� �� ȸ��)
    GetCapsuleComponent()->SetCapsuleHalfHeight(90.0f);
    GetCapsuleComponent()->SetCapsuleRadius(30.0f);

    bUseControllerRotationPitch = false;
    bUseControllerRotationYaw = false;
    bUseControllerRotationRoll = false;

    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);

    // ���̷�Ż �޽ø� ã�Ƽ� �Ҵ�
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_MANNEQUIN(TEXT("/Game/Characters/Mannequins/Meshes/SKM_Manny_Simple"));
    if (SK_MANNEQUIN.Succeeded())
    {
        GetMesh()->SetSkeletalMesh(SK_MANNEQUIN.Object);
    }

    // �޽� ��ġ �� ȸ�� ����
    GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
    GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

    // AI ��Ʈ�ѷ� Ŭ���� ����
    AIControllerClass = AEnemyAIController::StaticClass();
    AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

    TeamId = FGenericTeamId(1); // ���� 1�� ��
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


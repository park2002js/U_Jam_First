#include "MyPawn.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"
#include "MyPlayerController.h"

AMyPawn::AMyPawn()
{
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArmComponent->SetupAttachment(RootComponent);
    SpringArmComponent->TargetArmLength = 300.f;
    SpringArmComponent->bUsePawnControlRotation = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);

    BaseTurnRate = 45.f;
    BaseLookUpRate = 45.f;
}

void AMyPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    // ���콺 ��Ŭ�� �Է� ���ε��� Fire() �Լ��� ����
    PlayerInputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &AMyPawn::Fire);

    // ī�޶� ȸ�� �Է� ���ε�
    PlayerInputComponent->BindAxis("Turn", this, &AMyPawn::Turn);
    PlayerInputComponent->BindAxis("LookUp", this, &AMyPawn::LookUp);
}

// �� �߻� �Լ� ����
void AMyPawn::Fire()
{
    FVector StartLocation = CameraComponent->GetComponentLocation();
    FRotator Direction = CameraComponent->GetComponentRotation();
    FVector EndLocation = StartLocation + Direction.Vector() * 10000.f; // 10000 ���� �Ÿ����� ���� Ʈ���̽�

    FHitResult HitResult;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this); // �߻� �� �ڱ� �ڽ��� ����

    if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility, Params))
    {
        // ���𰡿� �¾��� ���
        UE_LOG(LogTemp, Warning, TEXT("target: %s"), *HitResult.GetActor()->GetName());

        // ���� ��ġ�� ����� ���� �׸��� (���� �������� ����)
        DrawDebugLine(GetWorld(), StartLocation, HitResult.Location, FColor::Red, false, 2.f);
        DrawDebugPoint(GetWorld(), HitResult.Location, 20.f, FColor::Red, false, 2.f);
    }
    else
    {
        // �ƹ��͵� ���� �ʾ��� ���
        UE_LOG(LogTemp, Warning, TEXT("missed"));

        // ����� �߻�� ����� ���� �׸���
        DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, 2.f);
    }
}

void AMyPawn::OnLeftMouseClick()
{
    ClickCount++;
    UE_LOG(LogTemp, Waring, TEXT("click: %d"), ClickCount);
}

void AMyPawn::Turn(float Value)
{
    AddControllerYawInput(Value * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMyPawn::LookUp(float Value)
{
    AddControllerPitchInput(Value * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}
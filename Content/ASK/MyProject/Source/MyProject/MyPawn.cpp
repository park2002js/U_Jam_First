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

    // 마우스 좌클릭 입력 바인딩을 Fire() 함수와 연결
    PlayerInputComponent->BindAction("LeftMouseClick", IE_Pressed, this, &AMyPawn::Fire);

    // 카메라 회전 입력 바인딩
    PlayerInputComponent->BindAxis("Turn", this, &AMyPawn::Turn);
    PlayerInputComponent->BindAxis("LookUp", this, &AMyPawn::LookUp);
}

// 총 발사 함수 구현
void AMyPawn::Fire()
{
    FVector StartLocation = CameraComponent->GetComponentLocation();
    FRotator Direction = CameraComponent->GetComponentRotation();
    FVector EndLocation = StartLocation + Direction.Vector() * 10000.f; // 10000 유닛 거리까지 라인 트레이스

    FHitResult HitResult;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this); // 발사 시 자기 자신은 무시

    if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility, Params))
    {
        // 무언가에 맞았을 경우
        UE_LOG(LogTemp, Warning, TEXT("target: %s"), *HitResult.GetActor()->GetName());

        // 맞은 위치에 디버그 라인 그리기 (게임 내에서만 보임)
        DrawDebugLine(GetWorld(), StartLocation, HitResult.Location, FColor::Red, false, 2.f);
        DrawDebugPoint(GetWorld(), HitResult.Location, 20.f, FColor::Red, false, 2.f);
    }
    else
    {
        // 아무것도 맞지 않았을 경우
        UE_LOG(LogTemp, Warning, TEXT("missed"));

        // 허공에 발사된 디버그 라인 그리기
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
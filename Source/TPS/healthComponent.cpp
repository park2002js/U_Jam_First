#include "HealthComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h" 

UHealthComponent::UHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UHealthComponent::BeginPlay()
{
    Super::BeginPlay();

    CurrentHealth = MaxHealth;

    AActor* Owner = GetOwner();
    if (Owner)
    {
        Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleDamage); 
    }
}

void UHealthComponent::HandleDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    // 대미지가 0이거나 이미 체력이 0이면 처리하지 않음
    if (Damage <= 0.0f || CurrentHealth <= 0.0f)
    {
        return;
    }

    CurrentHealth -= Damage;

    CurrentHealth = FMath::Max(0.0f, CurrentHealth);

    OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);

    // 체력이 0이 되었는지 확인
    if (CurrentHealth <= 0.0f)
    {
        // 체력 고갈 델리게이트 실행 (게임 오버 트리거)
        OnHealthDepleted.Broadcast();
    }
}

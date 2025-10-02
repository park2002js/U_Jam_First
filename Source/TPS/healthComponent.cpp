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
    // ������� 0�̰ų� �̹� ü���� 0�̸� ó������ ����
    if (Damage <= 0.0f || CurrentHealth <= 0.0f)
    {
        return;
    }

    CurrentHealth -= Damage;

    CurrentHealth = FMath::Max(0.0f, CurrentHealth);

    OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);

    // ü���� 0�� �Ǿ����� Ȯ��
    if (CurrentHealth <= 0.0f)
    {
        // ü�� �� ��������Ʈ ���� (���� ���� Ʈ����)
        OnHealthDepleted.Broadcast();
    }
}

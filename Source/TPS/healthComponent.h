#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h" 
#include "HealthComponent.generated.h" 


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TPS_API UHealthComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UHealthComponent();

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, float, NewHealth, float, MaxHealth);
    UPROPERTY(BlueprintAssignable, Category = "Health")
    FOnHealthChanged OnHealthChanged;

    // ü���� 0�� �Ǿ����� �˸��� ��������Ʈ (���� ���� ó����)
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthDepleted);
    UPROPERTY(BlueprintAssignable, Category = "Health")
    FOnHealthDepleted OnHealthDepleted;

    // ���� ü�°� �ִ� ü�� ����
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
    float MaxHealth = 100.0f;

private:
    float CurrentHealth;

public:
    UFUNCTION(BlueprintCallable, Category = "Health")
    void ApplyDamage(float DamageAmount);


    UFUNCTION()
    void HandleDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);


    // Get �Լ���
    UFUNCTION(BlueprintPure, Category = "Health")
    float GetCurrentHealth() const { return CurrentHealth; }

    UFUNCTION(BlueprintPure, Category = "Health")
    float GetHealthPercentage() const { return CurrentHealth / MaxHealth; }
};
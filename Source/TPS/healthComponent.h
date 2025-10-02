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

    // 체력이 0이 되었음을 알리는 델리게이트 (게임 오버 처리용)
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthDepleted);
    UPROPERTY(BlueprintAssignable, Category = "Health")
    FOnHealthDepleted OnHealthDepleted;

    // 현재 체력과 최대 체력 변수
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
    float MaxHealth = 100.0f;

private:
    float CurrentHealth;

public:
    UFUNCTION(BlueprintCallable, Category = "Health")
    void ApplyDamage(float DamageAmount);


    UFUNCTION()
    void HandleDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);


    // Get 함수들
    UFUNCTION(BlueprintPure, Category = "Health")
    float GetCurrentHealth() const { return CurrentHealth; }

    UFUNCTION(BlueprintPure, Category = "Health")
    float GetHealthPercentage() const { return CurrentHealth / MaxHealth; }
};
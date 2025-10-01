#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h" // FAIStimulus ������ �ʿ�
#include "EnemyAIController.generated.h"

class UBehaviorTreeComponent;
class UBlackboardComponent;
class UAIPerceptionComponent;

UCLASS()
class U_JAM_API AEnemyAIController :  public AAIController
{
    GENERATED_BODY()

public:
    AEnemyAIController();

protected:
    // ��Ʈ�ѷ��� ���� ����(Possess)�� �� ȣ��˴ϴ�.
    virtual void OnPossess(APawn* InPawn) override;

private:
    // AI Perception�� ������Ʈ �� �� ȣ��� �Լ��Դϴ�.
    UFUNCTION()
    void OnTargetDetected(AActor* Actor, FAIStimulus Stimulus);

    // -- ������Ʈ�� --
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UBlackboardComponent> BlackboardComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UAIPerceptionComponent> AIPerceptionComponent;

    // -- ���� ���� --
    // �������Ʈ���� ������ �����̺�� Ʈ�� �����Դϴ�.
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
    TObjectPtr<class UBehaviorTree> BehaviorTreeAsset;
};
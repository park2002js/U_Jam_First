#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h" // FAIStimulus 때문에 필요
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
    // 컨트롤러가 폰에 빙의(Possess)될 때 호출됩니다.
    virtual void OnPossess(APawn* InPawn) override;

private:
    // AI Perception이 업데이트 될 때 호출될 함수입니다.
    UFUNCTION()
    void OnTargetDetected(AActor* Actor, FAIStimulus Stimulus);

    // -- 컴포넌트들 --
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UBlackboardComponent> BlackboardComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
    TObjectPtr<UAIPerceptionComponent> AIPerceptionComponent;

    // -- 에셋 참조 --
    // 블루프린트에서 설정할 비헤이비어 트리 에셋입니다.
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AI", meta = (AllowPrivateAccess = "true"))
    TObjectPtr<class UBehaviorTree> BehaviorTreeAsset;
};
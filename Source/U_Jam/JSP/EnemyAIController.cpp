// Fill out your copyright notice in the Description page of Project Settings.

#include "JSP/EnemyAIController.h" // ���� ������Ʈ ��ο� �°� ����
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "JSP/EnemyCharacter.h" // ���� ������Ʈ ��ο� �°� ����

AEnemyAIController::AEnemyAIController()
{
    // 1. ������Ʈ ����
    BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
    BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
    AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));

    // 2. �þ�(Sight) ���� ����
    UAISenseConfig_Sight* SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
    SightConfig->SightRadius = 2000.0f;
    SightConfig->LoseSightRadius = 2500.0f;
    SightConfig->PeripheralVisionAngleDegrees = 90.0f;
    SightConfig->SetMaxAge(5.0f); // 5�ʰ� ���
    SightConfig->DetectionByAffiliation.bDetectEnemies = true;
    SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
    SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

    // 3. ������ ������ �ۼ��� ������Ʈ�� �Ҵ�
    AIPerceptionComponent->ConfigureSense(*SightConfig);
    AIPerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    // C++�� ���� ĳ���Ͱ� �ƴϸ� �ߴ�
    AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(InPawn);
    if (!EnemyCharacter) return;

    // �����̺�� Ʈ�� ������ �Ҵ�Ǿ� �ִٸ�, �����带 �ʱ�ȭ�ϰ� �����̺�� Ʈ���� ����
    if (BehaviorTreeAsset)
    {
        BlackboardComponent->InitializeBlackboard(*(BehaviorTreeAsset->BlackboardAsset));
        BehaviorTreeComponent->StartTree(*(BehaviorTreeAsset));
    }

    // �ۼ��� ������Ʈ �̺�Ʈ�� C++ �Լ��� ���ε�(����)
    AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIController::OnTargetDetected);
}

void AEnemyAIController::OnTargetDetected(AActor* Actor, FAIStimulus Stimulus)
{
    // ������ �����ߴٸ� (�þ߿� ���Դٸ�)
    if (Stimulus.WasSuccessfullySensed())
    {
        // �������� TargetActor Ű�� ������ ���͸� ���
        BlackboardComponent->SetValueAsObject(TEXT("TargetActor"), Actor);
    }
    else // ������ �����ߴٸ� (�þ߿��� ����ٸ�)
    {
        // �������� TargetActor Ű�� ���
        BlackboardComponent->ClearValue(TEXT("TargetActor"));
    }
}

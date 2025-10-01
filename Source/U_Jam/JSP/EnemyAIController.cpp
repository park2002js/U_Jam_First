// Fill out your copyright notice in the Description page of Project Settings.

#include "JSP/EnemyAIController.h" // 본인 프로젝트 경로에 맞게 수정
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "JSP/EnemyCharacter.h" // 본인 프로젝트 경로에 맞게 수정
#include "JSP/TeamAttitudeFunctionLibrary.h" // 프로젝트 경로에 맞게 수정
#include "GenericTeamAgentInterface.h"

AEnemyAIController::AEnemyAIController()
{
    // 1. 컴포넌트 생성
    BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
    BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
    AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));

    // 2. 시야(Sight) 감각 설정
    UAISenseConfig_Sight* SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
    SightConfig->SightRadius = 2000.0f;
    SightConfig->LoseSightRadius = 5000.0f;
    SightConfig->PeripheralVisionAngleDegrees = 90.0f;
    SightConfig->SetMaxAge(5.0f); // 5초간 기억
    SightConfig->DetectionByAffiliation.bDetectEnemies = true; // Enemies로 분류된 오브젝트만 인식하도록 설정
    SightConfig->DetectionByAffiliation.bDetectFriendlies = false;
    SightConfig->DetectionByAffiliation.bDetectNeutrals = false;

    // 3. 설정된 감각을 퍼셉션 컴포넌트에 할당
    AIPerceptionComponent->ConfigureSense(*SightConfig);
    AIPerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    // C++로 만든 캐릭터가 아니면 중단
    AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(InPawn);
    if (!EnemyCharacter) return;

    // 비헤이비어 트리 에셋이 할당되어 있다면, 블랙보드를 초기화하고 비헤이비어 트리를 실행
    if (BehaviorTreeAsset)
    {
        BlackboardComponent->InitializeBlackboard(*(BehaviorTreeAsset->BlackboardAsset));
        BehaviorTreeComponent->StartTree(*(BehaviorTreeAsset));
    }

    // 퍼셉션 업데이트 이벤트에 C++ 함수를 바인딩(연결)
    AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIController::OnTargetDetected);
}

void AEnemyAIController::OnTargetDetected(AActor* Actor, FAIStimulus Stimulus)
{
    // 감지에 성공했다면 (시야에 들어왔다면)
    if (Stimulus.WasSuccessfullySensed())
    {
        // 블랙보드의 TargetActor 키에 감지된 액터를 기록
        BlackboardComponent->SetValueAsObject(TEXT("TargetActor"), Actor);
    }
    else // 감지에 실패했다면 (시야에서 벗어났다면)
    {
        // 블랙보드의 TargetActor 키를 비움
        BlackboardComponent->ClearValue(TEXT("TargetActor"));
    }
}
ETeamAttitude::Type AEnemyAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
    // AI 컨트롤러가 조종하는 Pawn(자신)과 상대방(Other)을
    // 중앙 관리 시스템에 전달하여 관계를 물어봅니다.
    return UTeamAttitudeFunctionLibrary::GetTeamAttitude(GetPawn(), &Other);
}
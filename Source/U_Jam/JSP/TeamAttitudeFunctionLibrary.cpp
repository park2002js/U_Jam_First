#include "JSP/TeamAttitudeFunctionLibrary.h"// 프로젝트 경로에 맞게 수정
#include "Logging/LogMacros.h" 

// 이 함수를 새로 추가합니다.
// 액터나 그 컨트롤러로부터 팀 인터페이스를 가져오는 헬퍼(Helper) 함수입니다.
static const IGenericTeamAgentInterface* GetTeamAgent(const AActor* InActor)
{
    if (InActor == nullptr)
    {
        return nullptr;
    }

    // 1. 먼저 액터 본인이 인터페이스를 가지고 있는지 확인합니다.
    const IGenericTeamAgentInterface* TeamAgent = Cast<IGenericTeamAgentInterface>(InActor);
    if (TeamAgent)
    {
        return TeamAgent;
    }

    // 2. 액터가 없다면, 액터를 조종하는 컨트롤러가 인터페이스를 가지고 있는지 확인합니다.
    AController* Controller = InActor->GetInstigatorController();
    TeamAgent = Cast<IGenericTeamAgentInterface>(Controller);
    if (TeamAgent)
    {
        return TeamAgent;
    }

    // 둘 다 없으면 null을 반환합니다.
    return nullptr;
}


ETeamAttitude::Type UTeamAttitudeFunctionLibrary::GetTeamAttitude(const AActor* ActorA, const AActor* ActorB)
{
    if (!ActorA || !ActorB)
    {
        UE_LOG(LogTemp, Error, TEXT("GetAttitude FAILED: One of the actors is NULL."));
        return ETeamAttitude::Neutral;
    }

    // 위에서 만든 헬퍼 함수를 사용하여 팀 정보를 가져옵니다.
    const IGenericTeamAgentInterface* TeamAgentA = GetTeamAgent(ActorA);
    const IGenericTeamAgentInterface* TeamAgentB = GetTeamAgent(ActorB);

    if (!TeamAgentA || !TeamAgentB)
    {
        UE_LOG(LogTemp, Warning, TEXT("GetAttitude WARNING: Team Interface cast failed. ActorA TeamAgent: %s, ActorB TeamAgent: %s"),
            TeamAgentA ? TEXT("Success") : TEXT("FAILED"),
            TeamAgentB ? TEXT("Success") : TEXT("FAILED"));
        return ETeamAttitude::Neutral;
    }

    FGenericTeamId TeamIdA = TeamAgentA->GetGenericTeamId();
    FGenericTeamId TeamIdB = TeamAgentB->GetGenericTeamId();

    UE_LOG(LogTemp, Log, TEXT("Comparing Teams -> ActorA: %d vs ActorB: %d"), TeamIdA.GetId(), TeamIdB.GetId());

    if (TeamIdA == TeamIdB)
    {
        return ETeamAttitude::Friendly;
    }
    else
    {
        return ETeamAttitude::Hostile;
    }
}
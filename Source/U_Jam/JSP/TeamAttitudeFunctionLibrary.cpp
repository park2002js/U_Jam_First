#include "JSP/TeamAttitudeFunctionLibrary.h"// ������Ʈ ��ο� �°� ����
#include "Logging/LogMacros.h" 

// �� �Լ��� ���� �߰��մϴ�.
// ���ͳ� �� ��Ʈ�ѷ��κ��� �� �������̽��� �������� ����(Helper) �Լ��Դϴ�.
static const IGenericTeamAgentInterface* GetTeamAgent(const AActor* InActor)
{
    if (InActor == nullptr)
    {
        return nullptr;
    }

    // 1. ���� ���� ������ �������̽��� ������ �ִ��� Ȯ���մϴ�.
    const IGenericTeamAgentInterface* TeamAgent = Cast<IGenericTeamAgentInterface>(InActor);
    if (TeamAgent)
    {
        return TeamAgent;
    }

    // 2. ���Ͱ� ���ٸ�, ���͸� �����ϴ� ��Ʈ�ѷ��� �������̽��� ������ �ִ��� Ȯ���մϴ�.
    AController* Controller = InActor->GetInstigatorController();
    TeamAgent = Cast<IGenericTeamAgentInterface>(Controller);
    if (TeamAgent)
    {
        return TeamAgent;
    }

    // �� �� ������ null�� ��ȯ�մϴ�.
    return nullptr;
}


ETeamAttitude::Type UTeamAttitudeFunctionLibrary::GetTeamAttitude(const AActor* ActorA, const AActor* ActorB)
{
    if (!ActorA || !ActorB)
    {
        UE_LOG(LogTemp, Error, TEXT("GetAttitude FAILED: One of the actors is NULL."));
        return ETeamAttitude::Neutral;
    }

    // ������ ���� ���� �Լ��� ����Ͽ� �� ������ �����ɴϴ�.
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
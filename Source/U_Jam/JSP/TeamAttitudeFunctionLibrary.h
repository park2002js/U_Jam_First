// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GenericTeamAgentInterface.h" // ETeamAttitude::Type�� ����ϱ� ���� �ʿ�
#include "TeamAttitudeFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class U_JAM_API UTeamAttitudeFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	// �� ������ �� ���踦 �Ǵ��Ͽ� ��ȯ�ϴ� ���� �Լ�
	UFUNCTION(BlueprintPure, Category = "AI | Team")
	static ETeamAttitude::Type GetTeamAttitude(const AActor* ActorA, const AActor* ActorB);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GenericTeamAgentInterface.h" // ETeamAttitude::Type을 사용하기 위해 필요
#include "TeamAttitudeFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class U_JAM_API UTeamAttitudeFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	// 두 액터의 팀 관계를 판단하여 반환하는 전역 함수
	UFUNCTION(BlueprintPure, Category = "AI | Team")
	static ETeamAttitude::Type GetTeamAttitude(const AActor* ActorA, const AActor* ActorB);
};

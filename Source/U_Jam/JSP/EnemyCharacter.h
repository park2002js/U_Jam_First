// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "EnemyCharacter.generated.h"

class AEnemyAIController;

UCLASS()
class U_JAM_API AEnemyCharacter : public ACharacter, public IGenericTeamAgentInterface // <-- 2. �������̽� ���
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

	// 3. �� ID�� �����ϰ� �������� �Լ� ����
	virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }
	virtual void SetGenericTeamId(const FGenericTeamId& InTeamId) { TeamId = InTeamId; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// 4. �� ID�� ������ ���� ����
	UPROPERTY(EditAnywhere, Category = "AI")
	FGenericTeamId TeamId;

};

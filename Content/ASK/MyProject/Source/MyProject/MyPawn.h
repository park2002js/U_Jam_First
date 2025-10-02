#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MyPawn.generated.h"

UCLASS()
class MYPROJECT_API AMyPawn : public APawn
{
    GENERATED_BODY()

public:
    AMyPawn();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
    int32 ClickCount = 0;

    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void Turn(float Value);
    void LookUp(float Value);

protected:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
    float BaseTurnRate;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
    float BaseLookUpRate;

private:
    void Fire(); // ÃÑ ¹ß»ç ÇÔ¼ö

private:
    void OnLeftMouseClick();
};
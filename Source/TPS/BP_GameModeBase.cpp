// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeBase.h" 
#include "ConstructorHelpers.h" 
#include "Character/PlayerCharacter.h" 

ABP_GameModeBase::ABP_GameModeBase()
{
 
    static ConstructorHelpers::FClassFinder<ACharacter> BP_PlayerPawnClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C"));
    if (BP_PlayerPawnClass.Succeeded())
    {
        // 3. DefaultPawnClass¿¡ ÇÒ´ç
        DefaultPawnClass = BP_PlayerPawnClass.Class;
    }

}

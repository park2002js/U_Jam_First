// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyPlayerController.h"

#ifdef MYPROJECT_MyPlayerController_generated_h
#error "MyPlayerController.generated.h already included, missing '#pragma once' in MyPlayerController.h"
#endif
#define MYPROJECT_MyPlayerController_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AMyPlayerController ******************************************************
MYPROJECT_API UClass* Z_Construct_UClass_AMyPlayerController_NoRegister();

#define FID_Unreal_Projects_MyProject_Source_MyProject_MyPlayerController_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyPlayerController(); \
	friend struct Z_Construct_UClass_AMyPlayerController_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* Z_Construct_UClass_AMyPlayerController_NoRegister(); \
public: \
	DECLARE_CLASS2(AMyPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_AMyPlayerController_NoRegister) \
	DECLARE_SERIALIZER(AMyPlayerController)


#define FID_Unreal_Projects_MyProject_Source_MyProject_MyPlayerController_h_12_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AMyPlayerController(AMyPlayerController&&) = delete; \
	AMyPlayerController(const AMyPlayerController&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyPlayerController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyPlayerController) \
	NO_API virtual ~AMyPlayerController();


#define FID_Unreal_Projects_MyProject_Source_MyProject_MyPlayerController_h_9_PROLOG
#define FID_Unreal_Projects_MyProject_Source_MyProject_MyPlayerController_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_MyProject_Source_MyProject_MyPlayerController_h_12_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_MyProject_Source_MyProject_MyPlayerController_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AMyPlayerController;

// ********** End Class AMyPlayerController ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_MyProject_Source_MyProject_MyPlayerController_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

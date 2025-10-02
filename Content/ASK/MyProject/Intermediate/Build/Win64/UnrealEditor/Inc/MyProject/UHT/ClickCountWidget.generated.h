// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ClickCountWidget.h"

#ifdef MYPROJECT_ClickCountWidget_generated_h
#error "ClickCountWidget.generated.h already included, missing '#pragma once' in ClickCountWidget.h"
#endif
#define MYPROJECT_ClickCountWidget_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UClickCountWidget ********************************************************
MYPROJECT_API UClass* Z_Construct_UClass_UClickCountWidget_NoRegister();

#define FID_Unreal_Projects_MyProject_Source_MyProject_ClickCountWidget_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUClickCountWidget(); \
	friend struct Z_Construct_UClass_UClickCountWidget_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend MYPROJECT_API UClass* Z_Construct_UClass_UClickCountWidget_NoRegister(); \
public: \
	DECLARE_CLASS2(UClickCountWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MyProject"), Z_Construct_UClass_UClickCountWidget_NoRegister) \
	DECLARE_SERIALIZER(UClickCountWidget)


#define FID_Unreal_Projects_MyProject_Source_MyProject_ClickCountWidget_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UClickCountWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UClickCountWidget(UClickCountWidget&&) = delete; \
	UClickCountWidget(const UClickCountWidget&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UClickCountWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UClickCountWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UClickCountWidget) \
	NO_API virtual ~UClickCountWidget();


#define FID_Unreal_Projects_MyProject_Source_MyProject_ClickCountWidget_h_13_PROLOG
#define FID_Unreal_Projects_MyProject_Source_MyProject_ClickCountWidget_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Unreal_Projects_MyProject_Source_MyProject_ClickCountWidget_h_16_INCLASS_NO_PURE_DECLS \
	FID_Unreal_Projects_MyProject_Source_MyProject_ClickCountWidget_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UClickCountWidget;

// ********** End Class UClickCountWidget **********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Unreal_Projects_MyProject_Source_MyProject_ClickCountWidget_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS

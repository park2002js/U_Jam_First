// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MyProject/ClickCountWidget.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeClickCountWidget() {}

// ********** Begin Cross Module References ********************************************************
MYPROJECT_API UClass* Z_Construct_UClass_UClickCountWidget();
MYPROJECT_API UClass* Z_Construct_UClass_UClickCountWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_MyProject();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UClickCountWidget ********************************************************
void UClickCountWidget::StaticRegisterNativesUClickCountWidget()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_UClickCountWidget;
UClass* UClickCountWidget::GetPrivateStaticClass()
{
	using TClass = UClickCountWidget;
	if (!Z_Registration_Info_UClass_UClickCountWidget.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("ClickCountWidget"),
			Z_Registration_Info_UClass_UClickCountWidget.InnerSingleton,
			StaticRegisterNativesUClickCountWidget,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UClickCountWidget.InnerSingleton;
}
UClass* Z_Construct_UClass_UClickCountWidget_NoRegister()
{
	return UClickCountWidget::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UClickCountWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "ClickCountWidget.h" },
		{ "ModuleRelativePath", "ClickCountWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClickCountText_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ClickCountWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ClickCountText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UClickCountWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UClickCountWidget_Statics::NewProp_ClickCountText = { "ClickCountText", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UClickCountWidget, ClickCountText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClickCountText_MetaData), NewProp_ClickCountText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UClickCountWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UClickCountWidget_Statics::NewProp_ClickCountText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UClickCountWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UClickCountWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_MyProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UClickCountWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UClickCountWidget_Statics::ClassParams = {
	&UClickCountWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UClickCountWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UClickCountWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UClickCountWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UClickCountWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UClickCountWidget()
{
	if (!Z_Registration_Info_UClass_UClickCountWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UClickCountWidget.OuterSingleton, Z_Construct_UClass_UClickCountWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UClickCountWidget.OuterSingleton;
}
UClickCountWidget::UClickCountWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UClickCountWidget);
UClickCountWidget::~UClickCountWidget() {}
// ********** End Class UClickCountWidget **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Unreal_Projects_MyProject_Source_MyProject_ClickCountWidget_h__Script_MyProject_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UClickCountWidget, UClickCountWidget::StaticClass, TEXT("UClickCountWidget"), &Z_Registration_Info_UClass_UClickCountWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UClickCountWidget), 441242326U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Projects_MyProject_Source_MyProject_ClickCountWidget_h__Script_MyProject_3618921650(TEXT("/Script/MyProject"),
	Z_CompiledInDeferFile_FID_Unreal_Projects_MyProject_Source_MyProject_ClickCountWidget_h__Script_MyProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Projects_MyProject_Source_MyProject_ClickCountWidget_h__Script_MyProject_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS

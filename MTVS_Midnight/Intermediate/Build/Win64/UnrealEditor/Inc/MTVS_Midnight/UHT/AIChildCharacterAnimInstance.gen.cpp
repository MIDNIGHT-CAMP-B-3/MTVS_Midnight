// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MTVS_Midnight/Public/AIChildCharacterAnimInstance.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAIChildCharacterAnimInstance() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UAnimInstance();
MTVS_MIDNIGHT_API UClass* Z_Construct_UClass_UAIChildCharacterAnimInstance();
MTVS_MIDNIGHT_API UClass* Z_Construct_UClass_UAIChildCharacterAnimInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_MTVS_Midnight();
// End Cross Module References

// Begin Class UAIChildCharacterAnimInstance
void UAIChildCharacterAnimInstance::StaticRegisterNativesUAIChildCharacterAnimInstance()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAIChildCharacterAnimInstance);
UClass* Z_Construct_UClass_UAIChildCharacterAnimInstance_NoRegister()
{
	return UAIChildCharacterAnimInstance::StaticClass();
}
struct Z_Construct_UClass_UAIChildCharacterAnimInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "AnimInstance" },
		{ "IncludePath", "AIChildCharacterAnimInstance.h" },
		{ "ModuleRelativePath", "Public/AIChildCharacterAnimInstance.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAIChildCharacterAnimInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UAIChildCharacterAnimInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_MTVS_Midnight,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAIChildCharacterAnimInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAIChildCharacterAnimInstance_Statics::ClassParams = {
	&UAIChildCharacterAnimInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAIChildCharacterAnimInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UAIChildCharacterAnimInstance_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAIChildCharacterAnimInstance()
{
	if (!Z_Registration_Info_UClass_UAIChildCharacterAnimInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAIChildCharacterAnimInstance.OuterSingleton, Z_Construct_UClass_UAIChildCharacterAnimInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAIChildCharacterAnimInstance.OuterSingleton;
}
template<> MTVS_MIDNIGHT_API UClass* StaticClass<UAIChildCharacterAnimInstance>()
{
	return UAIChildCharacterAnimInstance::StaticClass();
}
UAIChildCharacterAnimInstance::UAIChildCharacterAnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAIChildCharacterAnimInstance);
UAIChildCharacterAnimInstance::~UAIChildCharacterAnimInstance() {}
// End Class UAIChildCharacterAnimInstance

// Begin Registration
struct Z_CompiledInDeferFile_FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacterAnimInstance_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAIChildCharacterAnimInstance, UAIChildCharacterAnimInstance::StaticClass, TEXT("UAIChildCharacterAnimInstance"), &Z_Registration_Info_UClass_UAIChildCharacterAnimInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAIChildCharacterAnimInstance), 3194729543U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacterAnimInstance_h_2953906479(TEXT("/Script/MTVS_Midnight"),
	Z_CompiledInDeferFile_FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacterAnimInstance_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacterAnimInstance_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS

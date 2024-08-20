// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MTVS_Midnight/HSW_Player.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHSW_Player() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
MTVS_MIDNIGHT_API UClass* Z_Construct_UClass_AHSW_Player();
MTVS_MIDNIGHT_API UClass* Z_Construct_UClass_AHSW_Player_NoRegister();
UPackage* Z_Construct_UPackage__Script_MTVS_Midnight();
// End Cross Module References

// Begin Class AHSW_Player
void AHSW_Player::StaticRegisterNativesAHSW_Player()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AHSW_Player);
UClass* Z_Construct_UClass_AHSW_Player_NoRegister()
{
	return AHSW_Player::StaticClass();
}
struct Z_Construct_UClass_AHSW_Player_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "HSW_Player.h" },
		{ "ModuleRelativePath", "HSW_Player.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHSW_Player>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AHSW_Player_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_MTVS_Midnight,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AHSW_Player_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AHSW_Player_Statics::ClassParams = {
	&AHSW_Player::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AHSW_Player_Statics::Class_MetaDataParams), Z_Construct_UClass_AHSW_Player_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AHSW_Player()
{
	if (!Z_Registration_Info_UClass_AHSW_Player.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AHSW_Player.OuterSingleton, Z_Construct_UClass_AHSW_Player_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AHSW_Player.OuterSingleton;
}
template<> MTVS_MIDNIGHT_API UClass* StaticClass<AHSW_Player>()
{
	return AHSW_Player::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AHSW_Player);
AHSW_Player::~AHSW_Player() {}
// End Class AHSW_Player

// Begin Registration
struct Z_CompiledInDeferFile_FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_HSW_Player_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AHSW_Player, AHSW_Player::StaticClass, TEXT("AHSW_Player"), &Z_Registration_Info_UClass_AHSW_Player, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AHSW_Player), 301775061U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_HSW_Player_h_2715035701(TEXT("/Script/MTVS_Midnight"),
	Z_CompiledInDeferFile_FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_HSW_Player_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_HSW_Player_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS

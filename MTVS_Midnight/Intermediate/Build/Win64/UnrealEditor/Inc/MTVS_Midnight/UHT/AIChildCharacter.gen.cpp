// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MTVS_Midnight/Public/AIChildCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAIChildCharacter() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
MTVS_MIDNIGHT_API UClass* Z_Construct_UClass_AAIChildCharacter();
MTVS_MIDNIGHT_API UClass* Z_Construct_UClass_AAIChildCharacter_NoRegister();
MTVS_MIDNIGHT_API UEnum* Z_Construct_UEnum_MTVS_Midnight_EAIChildCharacterState();
UPackage* Z_Construct_UPackage__Script_MTVS_Midnight();
// End Cross Module References

// Begin Enum EAIChildCharacterState
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAIChildCharacterState;
static UEnum* EAIChildCharacterState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAIChildCharacterState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAIChildCharacterState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_MTVS_Midnight_EAIChildCharacterState, (UObject*)Z_Construct_UPackage__Script_MTVS_Midnight(), TEXT("EAIChildCharacterState"));
	}
	return Z_Registration_Info_UEnum_EAIChildCharacterState.OuterSingleton;
}
template<> MTVS_MIDNIGHT_API UEnum* StaticEnum<EAIChildCharacterState>()
{
	return EAIChildCharacterState_StaticEnum();
}
struct Z_Construct_UEnum_MTVS_Midnight_EAIChildCharacterState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Complete.Name", "EAIChildCharacterState::Complete" },
		{ "Die.Name", "EAIChildCharacterState::Die" },
		{ "ModuleRelativePath", "Public/AIChildCharacter.h" },
		{ "MOVE.Name", "EAIChildCharacterState::MOVE" },
		{ "STOP.Name", "EAIChildCharacterState::STOP" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAIChildCharacterState::STOP", (int64)EAIChildCharacterState::STOP },
		{ "EAIChildCharacterState::MOVE", (int64)EAIChildCharacterState::MOVE },
		{ "EAIChildCharacterState::Complete", (int64)EAIChildCharacterState::Complete },
		{ "EAIChildCharacterState::Die", (int64)EAIChildCharacterState::Die },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_MTVS_Midnight_EAIChildCharacterState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_MTVS_Midnight,
	nullptr,
	"EAIChildCharacterState",
	"EAIChildCharacterState",
	Z_Construct_UEnum_MTVS_Midnight_EAIChildCharacterState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_MTVS_Midnight_EAIChildCharacterState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_MTVS_Midnight_EAIChildCharacterState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_MTVS_Midnight_EAIChildCharacterState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_MTVS_Midnight_EAIChildCharacterState()
{
	if (!Z_Registration_Info_UEnum_EAIChildCharacterState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAIChildCharacterState.InnerSingleton, Z_Construct_UEnum_MTVS_Midnight_EAIChildCharacterState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAIChildCharacterState.InnerSingleton;
}
// End Enum EAIChildCharacterState

// Begin Class AAIChildCharacter
void AAIChildCharacter::StaticRegisterNativesAAIChildCharacter()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AAIChildCharacter);
UClass* Z_Construct_UClass_AAIChildCharacter_NoRegister()
{
	return AAIChildCharacter::StaticClass();
}
struct Z_Construct_UClass_AAIChildCharacter_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AIChildCharacter.h" },
		{ "ModuleRelativePath", "Public/AIChildCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "ModuleRelativePath", "Public/AIChildCharacter.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_goalDistance_MetaData[] = {
		{ "Category", "ChildCharacter" },
		{ "ModuleRelativePath", "Public/AIChildCharacter.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_goalDistance;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAIChildCharacter>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AAIChildCharacter_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AAIChildCharacter_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAIChildCharacter, State), Z_Construct_UEnum_MTVS_Midnight_EAIChildCharacterState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 4221130068
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAIChildCharacter_Statics::NewProp_goalDistance = { "goalDistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AAIChildCharacter, goalDistance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_goalDistance_MetaData), NewProp_goalDistance_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAIChildCharacter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAIChildCharacter_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAIChildCharacter_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAIChildCharacter_Statics::NewProp_goalDistance,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAIChildCharacter_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AAIChildCharacter_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_MTVS_Midnight,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AAIChildCharacter_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AAIChildCharacter_Statics::ClassParams = {
	&AAIChildCharacter::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AAIChildCharacter_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AAIChildCharacter_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AAIChildCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AAIChildCharacter_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AAIChildCharacter()
{
	if (!Z_Registration_Info_UClass_AAIChildCharacter.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AAIChildCharacter.OuterSingleton, Z_Construct_UClass_AAIChildCharacter_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AAIChildCharacter.OuterSingleton;
}
template<> MTVS_MIDNIGHT_API UClass* StaticClass<AAIChildCharacter>()
{
	return AAIChildCharacter::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AAIChildCharacter);
AAIChildCharacter::~AAIChildCharacter() {}
// End Class AAIChildCharacter

// Begin Registration
struct Z_CompiledInDeferFile_FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacter_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EAIChildCharacterState_StaticEnum, TEXT("EAIChildCharacterState"), &Z_Registration_Info_UEnum_EAIChildCharacterState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 4221130068U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AAIChildCharacter, AAIChildCharacter::StaticClass, TEXT("AAIChildCharacter"), &Z_Registration_Info_UClass_AAIChildCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AAIChildCharacter), 3182773562U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacter_h_4141079972(TEXT("/Script/MTVS_Midnight"),
	Z_CompiledInDeferFile_FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacter_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacter_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacter_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS

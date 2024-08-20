// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AIChildCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MTVS_MIDNIGHT_AIChildCharacter_generated_h
#error "AIChildCharacter.generated.h already included, missing '#pragma once' in AIChildCharacter.h"
#endif
#define MTVS_MIDNIGHT_AIChildCharacter_generated_h

#define FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacter_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAIChildCharacter(); \
	friend struct Z_Construct_UClass_AAIChildCharacter_Statics; \
public: \
	DECLARE_CLASS(AAIChildCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/MTVS_Midnight"), NO_API) \
	DECLARE_SERIALIZER(AAIChildCharacter)


#define FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AAIChildCharacter(AAIChildCharacter&&); \
	AAIChildCharacter(const AAIChildCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAIChildCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAIChildCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAIChildCharacter) \
	NO_API virtual ~AAIChildCharacter();


#define FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacter_h_17_PROLOG
#define FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacter_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacter_h_20_INCLASS_NO_PURE_DECLS \
	FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MTVS_MIDNIGHT_API UClass* StaticClass<class AAIChildCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_Public_AIChildCharacter_h


#define FOREACH_ENUM_EAICHILDCHARACTERSTATE(op) \
	op(EAIChildCharacterState::STOP) \
	op(EAIChildCharacterState::MOVE) \
	op(EAIChildCharacterState::Complete) \
	op(EAIChildCharacterState::Die) 

enum class EAIChildCharacterState : uint8;
template<> struct TIsUEnumClass<EAIChildCharacterState> { enum { Value = true }; };
template<> MTVS_MIDNIGHT_API UEnum* StaticEnum<EAIChildCharacterState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS

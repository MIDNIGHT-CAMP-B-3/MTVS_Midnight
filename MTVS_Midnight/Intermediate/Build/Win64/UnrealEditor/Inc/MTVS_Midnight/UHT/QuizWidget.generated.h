// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "QuizWidget.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MTVS_MIDNIGHT_QuizWidget_generated_h
#error "QuizWidget.generated.h already included, missing '#pragma once' in QuizWidget.h"
#endif
#define MTVS_MIDNIGHT_QuizWidget_generated_h

#define FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_QuizWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnAnswerButton2Clicked); \
	DECLARE_FUNCTION(execOnAnswerButton1Clicked);


#define FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_QuizWidget_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuizWidget(); \
	friend struct Z_Construct_UClass_UQuizWidget_Statics; \
public: \
	DECLARE_CLASS(UQuizWidget, UUserWidget, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/MTVS_Midnight"), NO_API) \
	DECLARE_SERIALIZER(UQuizWidget)


#define FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_QuizWidget_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuizWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UQuizWidget(UQuizWidget&&); \
	UQuizWidget(const UQuizWidget&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuizWidget); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuizWidget); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuizWidget) \
	NO_API virtual ~UQuizWidget();


#define FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_QuizWidget_h_12_PROLOG
#define FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_QuizWidget_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_QuizWidget_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_QuizWidget_h_15_INCLASS_NO_PURE_DECLS \
	FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_QuizWidget_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MTVS_MIDNIGHT_API UClass* StaticClass<class UQuizWidget>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_QuizWidget_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

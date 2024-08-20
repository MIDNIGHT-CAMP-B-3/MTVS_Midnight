// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MTVS_Midnight/QuizWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuizWidget() {}

// Begin Cross Module References
MTVS_MIDNIGHT_API UClass* Z_Construct_UClass_UQuizWidget();
MTVS_MIDNIGHT_API UClass* Z_Construct_UClass_UQuizWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_MTVS_Midnight();
// End Cross Module References

// Begin Class UQuizWidget Function OnAnswerButton1Clicked
struct Z_Construct_UFunction_UQuizWidget_OnAnswerButton1Clicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc6\xb0\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc5\xac\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcc\xba\xef\xbf\xbd\xc6\xae \xc3\xb3\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd4\xbc\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "QuizWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xc6\xb0\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xc5\xac\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xcc\xba\xef\xbf\xbd\xc6\xae \xc3\xb3\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd4\xbc\xef\xbf\xbd" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuizWidget_OnAnswerButton1Clicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuizWidget, nullptr, "OnAnswerButton1Clicked", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuizWidget_OnAnswerButton1Clicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuizWidget_OnAnswerButton1Clicked_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UQuizWidget_OnAnswerButton1Clicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuizWidget_OnAnswerButton1Clicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuizWidget::execOnAnswerButton1Clicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAnswerButton1Clicked();
	P_NATIVE_END;
}
// End Class UQuizWidget Function OnAnswerButton1Clicked

// Begin Class UQuizWidget Function OnAnswerButton2Clicked
struct Z_Construct_UFunction_UQuizWidget_OnAnswerButton2Clicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "QuizWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuizWidget_OnAnswerButton2Clicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuizWidget, nullptr, "OnAnswerButton2Clicked", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuizWidget_OnAnswerButton2Clicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuizWidget_OnAnswerButton2Clicked_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UQuizWidget_OnAnswerButton2Clicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuizWidget_OnAnswerButton2Clicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuizWidget::execOnAnswerButton2Clicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnAnswerButton2Clicked();
	P_NATIVE_END;
}
// End Class UQuizWidget Function OnAnswerButton2Clicked

// Begin Class UQuizWidget
void UQuizWidget::StaticRegisterNativesUQuizWidget()
{
	UClass* Class = UQuizWidget::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnAnswerButton1Clicked", &UQuizWidget::execOnAnswerButton1Clicked },
		{ "OnAnswerButton2Clicked", &UQuizWidget::execOnAnswerButton2Clicked },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UQuizWidget);
UClass* Z_Construct_UClass_UQuizWidget_NoRegister()
{
	return UQuizWidget::StaticClass();
}
struct Z_Construct_UClass_UQuizWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "QuizWidget.h" },
		{ "ModuleRelativePath", "QuizWidget.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Score_MetaData[] = {
		{ "Category", "Quiz" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "QuizWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CorrectAnswer_MetaData[] = {
		{ "Category", "Quiz" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xda\xbf\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "QuizWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xda\xbf\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_QuestionText_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd8\xbd\xef\xbf\xbd\xc6\xae\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "QuizWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd8\xbd\xef\xbf\xbd\xc6\xae" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScoreText_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd8\xbd\xef\xbf\xbd\xc6\xae\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "QuizWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd8\xbd\xef\xbf\xbd\xc6\xae" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FeedbackText_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd/\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc7\xb5\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd8\xbd\xef\xbf\xbd\xc6\xae\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "QuizWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd/\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xc7\xb5\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd8\xbd\xef\xbf\xbd\xc6\xae" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnswerButton1_MetaData[] = {
		{ "BindWidget", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xe4\xba\xaf \xef\xbf\xbd\xef\xbf\xbd\xc6\xb0\xef\xbf\xbd\xef\xbf\xbd\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "QuizWidget.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xe4\xba\xaf \xef\xbf\xbd\xef\xbf\xbd\xc6\xb0\xef\xbf\xbd\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AnswerButton2_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "QuizWidget.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Score;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CorrectAnswer;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_QuestionText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ScoreText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FeedbackText;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AnswerButton1;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AnswerButton2;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuizWidget_OnAnswerButton1Clicked, "OnAnswerButton1Clicked" }, // 3353824488
		{ &Z_Construct_UFunction_UQuizWidget_OnAnswerButton2Clicked, "OnAnswerButton2Clicked" }, // 2393426039
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuizWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UQuizWidget_Statics::NewProp_Score = { "Score", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuizWidget, Score), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Score_MetaData), NewProp_Score_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UQuizWidget_Statics::NewProp_CorrectAnswer = { "CorrectAnswer", nullptr, (EPropertyFlags)0x0020080000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuizWidget, CorrectAnswer), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CorrectAnswer_MetaData), NewProp_CorrectAnswer_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuizWidget_Statics::NewProp_QuestionText = { "QuestionText", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuizWidget, QuestionText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_QuestionText_MetaData), NewProp_QuestionText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuizWidget_Statics::NewProp_ScoreText = { "ScoreText", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuizWidget, ScoreText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScoreText_MetaData), NewProp_ScoreText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuizWidget_Statics::NewProp_FeedbackText = { "FeedbackText", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuizWidget, FeedbackText), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FeedbackText_MetaData), NewProp_FeedbackText_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuizWidget_Statics::NewProp_AnswerButton1 = { "AnswerButton1", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuizWidget, AnswerButton1), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnswerButton1_MetaData), NewProp_AnswerButton1_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuizWidget_Statics::NewProp_AnswerButton2 = { "AnswerButton2", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuizWidget, AnswerButton2), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AnswerButton2_MetaData), NewProp_AnswerButton2_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuizWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuizWidget_Statics::NewProp_Score,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuizWidget_Statics::NewProp_CorrectAnswer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuizWidget_Statics::NewProp_QuestionText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuizWidget_Statics::NewProp_ScoreText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuizWidget_Statics::NewProp_FeedbackText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuizWidget_Statics::NewProp_AnswerButton1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuizWidget_Statics::NewProp_AnswerButton2,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuizWidget_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UQuizWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_MTVS_Midnight,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuizWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuizWidget_Statics::ClassParams = {
	&UQuizWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UQuizWidget_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UQuizWidget_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuizWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuizWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UQuizWidget()
{
	if (!Z_Registration_Info_UClass_UQuizWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuizWidget.OuterSingleton, Z_Construct_UClass_UQuizWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UQuizWidget.OuterSingleton;
}
template<> MTVS_MIDNIGHT_API UClass* StaticClass<UQuizWidget>()
{
	return UQuizWidget::StaticClass();
}
UQuizWidget::UQuizWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UQuizWidget);
UQuizWidget::~UQuizWidget() {}
// End Class UQuizWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_QuizWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UQuizWidget, UQuizWidget::StaticClass, TEXT("UQuizWidget"), &Z_Registration_Info_UClass_UQuizWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuizWidget), 1207527869U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_QuizWidget_h_1946393237(TEXT("/Script/MTVS_Midnight"),
	Z_CompiledInDeferFile_FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_QuizWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Unreal_MTVS_Midnight_Unreal_MTVS_Midnight_Source_MTVS_Midnight_QuizWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS

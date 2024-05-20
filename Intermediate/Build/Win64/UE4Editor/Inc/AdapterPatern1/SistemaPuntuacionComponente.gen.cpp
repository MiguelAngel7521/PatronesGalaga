// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/SistemaPuntuacionComponente.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSistemaPuntuacionComponente() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_USistemaPuntuacionComponente_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_USistemaPuntuacionComponente();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
// End Cross Module References
	DEFINE_FUNCTION(USistemaPuntuacionComponente::execObtenerPuntaje)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->ObtenerPuntaje();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USistemaPuntuacionComponente::execSumarPuntaje)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_Puntos);
		P_GET_PROPERTY(FStrProperty,Z_Param__nombre);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SumarPuntaje(Z_Param_Puntos,Z_Param__nombre);
		P_NATIVE_END;
	}
	void USistemaPuntuacionComponente::StaticRegisterNativesUSistemaPuntuacionComponente()
	{
		UClass* Class = USistemaPuntuacionComponente::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ObtenerPuntaje", &USistemaPuntuacionComponente::execObtenerPuntaje },
			{ "SumarPuntaje", &USistemaPuntuacionComponente::execSumarPuntaje },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USistemaPuntuacionComponente_ObtenerPuntaje_Statics
	{
		struct SistemaPuntuacionComponente_eventObtenerPuntaje_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_USistemaPuntuacionComponente_ObtenerPuntaje_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SistemaPuntuacionComponente_eventObtenerPuntaje_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USistemaPuntuacionComponente_ObtenerPuntaje_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USistemaPuntuacionComponente_ObtenerPuntaje_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USistemaPuntuacionComponente_ObtenerPuntaje_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SistemaPuntuacionComponente.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USistemaPuntuacionComponente_ObtenerPuntaje_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USistemaPuntuacionComponente, nullptr, "ObtenerPuntaje", nullptr, nullptr, sizeof(SistemaPuntuacionComponente_eventObtenerPuntaje_Parms), Z_Construct_UFunction_USistemaPuntuacionComponente_ObtenerPuntaje_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USistemaPuntuacionComponente_ObtenerPuntaje_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USistemaPuntuacionComponente_ObtenerPuntaje_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USistemaPuntuacionComponente_ObtenerPuntaje_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USistemaPuntuacionComponente_ObtenerPuntaje()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USistemaPuntuacionComponente_ObtenerPuntaje_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USistemaPuntuacionComponente_SumarPuntaje_Statics
	{
		struct SistemaPuntuacionComponente_eventSumarPuntaje_Parms
		{
			int32 Puntos;
			FString _nombre;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Puntos;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp__nombre;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_USistemaPuntuacionComponente_SumarPuntaje_Statics::NewProp_Puntos = { "Puntos", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SistemaPuntuacionComponente_eventSumarPuntaje_Parms, Puntos), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USistemaPuntuacionComponente_SumarPuntaje_Statics::NewProp__nombre = { "_nombre", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SistemaPuntuacionComponente_eventSumarPuntaje_Parms, _nombre), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USistemaPuntuacionComponente_SumarPuntaje_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USistemaPuntuacionComponente_SumarPuntaje_Statics::NewProp_Puntos,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USistemaPuntuacionComponente_SumarPuntaje_Statics::NewProp__nombre,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USistemaPuntuacionComponente_SumarPuntaje_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "SistemaPuntuacionComponente.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USistemaPuntuacionComponente_SumarPuntaje_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USistemaPuntuacionComponente, nullptr, "SumarPuntaje", nullptr, nullptr, sizeof(SistemaPuntuacionComponente_eventSumarPuntaje_Parms), Z_Construct_UFunction_USistemaPuntuacionComponente_SumarPuntaje_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USistemaPuntuacionComponente_SumarPuntaje_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USistemaPuntuacionComponente_SumarPuntaje_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USistemaPuntuacionComponente_SumarPuntaje_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USistemaPuntuacionComponente_SumarPuntaje()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USistemaPuntuacionComponente_SumarPuntaje_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USistemaPuntuacionComponente_NoRegister()
	{
		return USistemaPuntuacionComponente::StaticClass();
	}
	struct Z_Construct_UClass_USistemaPuntuacionComponente_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USistemaPuntuacionComponente_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USistemaPuntuacionComponente_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USistemaPuntuacionComponente_ObtenerPuntaje, "ObtenerPuntaje" }, // 3456704243
		{ &Z_Construct_UFunction_USistemaPuntuacionComponente_SumarPuntaje, "SumarPuntaje" }, // 1584793371
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USistemaPuntuacionComponente_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "SistemaPuntuacionComponente.h" },
		{ "ModuleRelativePath", "SistemaPuntuacionComponente.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USistemaPuntuacionComponente_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USistemaPuntuacionComponente>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USistemaPuntuacionComponente_Statics::ClassParams = {
		&USistemaPuntuacionComponente::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USistemaPuntuacionComponente_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USistemaPuntuacionComponente_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USistemaPuntuacionComponente()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USistemaPuntuacionComponente_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USistemaPuntuacionComponente, 4195539531);
	template<> ADAPTERPATERN1_API UClass* StaticClass<USistemaPuntuacionComponente>()
	{
		return USistemaPuntuacionComponente::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USistemaPuntuacionComponente(Z_Construct_UClass_USistemaPuntuacionComponente, &USistemaPuntuacionComponente::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("USistemaPuntuacionComponente"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USistemaPuntuacionComponente);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

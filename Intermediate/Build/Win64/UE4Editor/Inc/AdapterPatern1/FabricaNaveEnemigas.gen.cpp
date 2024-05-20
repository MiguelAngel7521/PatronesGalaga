// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/FabricaNaveEnemigas.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFabricaNaveEnemigas() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AFabricaNaveEnemigas_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AFabricaNaveEnemigas();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ANaveEnemiga_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AFabricaNaveEnemigas::execFabricarNave)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_TipoNave);
		P_GET_OBJECT(UObject,Z_Param_Outer);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(ANaveEnemiga**)Z_Param__Result=AFabricaNaveEnemigas::FabricarNave(Z_Param_TipoNave,Z_Param_Outer);
		P_NATIVE_END;
	}
	void AFabricaNaveEnemigas::StaticRegisterNativesAFabricaNaveEnemigas()
	{
		UClass* Class = AFabricaNaveEnemigas::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FabricarNave", &AFabricaNaveEnemigas::execFabricarNave },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave_Statics
	{
		struct FabricaNaveEnemigas_eventFabricarNave_Parms
		{
			FString TipoNave;
			UObject* Outer;
			ANaveEnemiga* ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_TipoNave;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Outer;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave_Statics::NewProp_TipoNave = { "TipoNave", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FabricaNaveEnemigas_eventFabricarNave_Parms, TipoNave), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave_Statics::NewProp_Outer = { "Outer", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FabricaNaveEnemigas_eventFabricarNave_Parms, Outer), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FabricaNaveEnemigas_eventFabricarNave_Parms, ReturnValue), Z_Construct_UClass_ANaveEnemiga_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave_Statics::NewProp_TipoNave,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave_Statics::NewProp_Outer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave_Statics::Function_MetaDataParams[] = {
		{ "Category", "Factory" },
		{ "ModuleRelativePath", "FabricaNaveEnemigas.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFabricaNaveEnemigas, nullptr, "FabricarNave", nullptr, nullptr, sizeof(FabricaNaveEnemigas_eventFabricarNave_Parms), Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AFabricaNaveEnemigas_NoRegister()
	{
		return AFabricaNaveEnemigas::StaticClass();
	}
	struct Z_Construct_UClass_AFabricaNaveEnemigas_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFabricaNaveEnemigas_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AFabricaNaveEnemigas_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFabricaNaveEnemigas_FabricarNave, "FabricarNave" }, // 2036609441
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFabricaNaveEnemigas_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FabricaNaveEnemigas.h" },
		{ "ModuleRelativePath", "FabricaNaveEnemigas.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFabricaNaveEnemigas_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFabricaNaveEnemigas>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFabricaNaveEnemigas_Statics::ClassParams = {
		&AFabricaNaveEnemigas::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFabricaNaveEnemigas_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFabricaNaveEnemigas_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFabricaNaveEnemigas()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFabricaNaveEnemigas_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFabricaNaveEnemigas, 1422986742);
	template<> ADAPTERPATERN1_API UClass* StaticClass<AFabricaNaveEnemigas>()
	{
		return AFabricaNaveEnemigas::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFabricaNaveEnemigas(Z_Construct_UClass_AFabricaNaveEnemigas, &AFabricaNaveEnemigas::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("AFabricaNaveEnemigas"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFabricaNaveEnemigas);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

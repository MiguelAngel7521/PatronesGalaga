// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/FabricaObstaculos.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFabricaObstaculos() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AFabricaObstaculos_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AFabricaObstaculos();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AObstaculo_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AFabricaObstaculos::execGenerarObstaculos)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_CantidadObstaculos);
		P_GET_STRUCT(FVector,Z_Param_MinSpawnLocation);
		P_GET_STRUCT(FVector,Z_Param_MaxSpawnLocation);
		P_GET_PROPERTY(FFloatProperty,Z_Param_MinMoveSpeed);
		P_GET_PROPERTY(FFloatProperty,Z_Param_MaxMoveSpeed);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->GenerarObstaculos(Z_Param_CantidadObstaculos,Z_Param_MinSpawnLocation,Z_Param_MaxSpawnLocation,Z_Param_MinMoveSpeed,Z_Param_MaxMoveSpeed);
		P_NATIVE_END;
	}
	void AFabricaObstaculos::StaticRegisterNativesAFabricaObstaculos()
	{
		UClass* Class = AFabricaObstaculos::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GenerarObstaculos", &AFabricaObstaculos::execGenerarObstaculos },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics
	{
		struct FabricaObstaculos_eventGenerarObstaculos_Parms
		{
			int32 CantidadObstaculos;
			FVector MinSpawnLocation;
			FVector MaxSpawnLocation;
			float MinMoveSpeed;
			float MaxMoveSpeed;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CantidadObstaculos;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_MinSpawnLocation;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_MaxSpawnLocation;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MinMoveSpeed;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxMoveSpeed;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::NewProp_CantidadObstaculos = { "CantidadObstaculos", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FabricaObstaculos_eventGenerarObstaculos_Parms, CantidadObstaculos), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::NewProp_MinSpawnLocation = { "MinSpawnLocation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FabricaObstaculos_eventGenerarObstaculos_Parms, MinSpawnLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::NewProp_MaxSpawnLocation = { "MaxSpawnLocation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FabricaObstaculos_eventGenerarObstaculos_Parms, MaxSpawnLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::NewProp_MinMoveSpeed = { "MinMoveSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FabricaObstaculos_eventGenerarObstaculos_Parms, MinMoveSpeed), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::NewProp_MaxMoveSpeed = { "MaxMoveSpeed", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FabricaObstaculos_eventGenerarObstaculos_Parms, MaxMoveSpeed), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::NewProp_CantidadObstaculos,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::NewProp_MinSpawnLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::NewProp_MaxSpawnLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::NewProp_MinMoveSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::NewProp_MaxMoveSpeed,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "FabricaObstaculos.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AFabricaObstaculos, nullptr, "GenerarObstaculos", nullptr, nullptr, sizeof(FabricaObstaculos_eventGenerarObstaculos_Parms), Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AFabricaObstaculos_NoRegister()
	{
		return AFabricaObstaculos::StaticClass();
	}
	struct Z_Construct_UClass_AFabricaObstaculos_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ObstaculoClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ObstaculoClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFabricaObstaculos_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AFabricaObstaculos_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AFabricaObstaculos_GenerarObstaculos, "GenerarObstaculos" }, // 2173681973
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFabricaObstaculos_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FabricaObstaculos.h" },
		{ "ModuleRelativePath", "FabricaObstaculos.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFabricaObstaculos_Statics::NewProp_ObstaculoClass_MetaData[] = {
		{ "Category", "Obstaculo" },
		{ "ModuleRelativePath", "FabricaObstaculos.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AFabricaObstaculos_Statics::NewProp_ObstaculoClass = { "ObstaculoClass", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFabricaObstaculos, ObstaculoClass), Z_Construct_UClass_AObstaculo_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AFabricaObstaculos_Statics::NewProp_ObstaculoClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFabricaObstaculos_Statics::NewProp_ObstaculoClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFabricaObstaculos_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFabricaObstaculos_Statics::NewProp_ObstaculoClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFabricaObstaculos_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFabricaObstaculos>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFabricaObstaculos_Statics::ClassParams = {
		&AFabricaObstaculos::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AFabricaObstaculos_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AFabricaObstaculos_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFabricaObstaculos_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFabricaObstaculos_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFabricaObstaculos()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFabricaObstaculos_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFabricaObstaculos, 3735671244);
	template<> ADAPTERPATERN1_API UClass* StaticClass<AFabricaObstaculos>()
	{
		return AFabricaObstaculos::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFabricaObstaculos(Z_Construct_UClass_AFabricaObstaculos, &AFabricaObstaculos::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("AFabricaObstaculos"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFabricaObstaculos);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

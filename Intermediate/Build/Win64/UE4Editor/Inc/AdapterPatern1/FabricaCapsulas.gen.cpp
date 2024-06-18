// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/FabricaCapsulas.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFabricaCapsulas() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AFabricaCapsulas_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AFabricaCapsulas();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
// End Cross Module References
	void AFabricaCapsulas::StaticRegisterNativesAFabricaCapsulas()
	{
	}
	UClass* Z_Construct_UClass_AFabricaCapsulas_NoRegister()
	{
		return AFabricaCapsulas::StaticClass();
	}
	struct Z_Construct_UClass_AFabricaCapsulas_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RangoSpawnX_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RangoSpawnX;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RangoSpawnY_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RangoSpawnY;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFabricaCapsulas_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFabricaCapsulas_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "FabricaCapsulas.h" },
		{ "ModuleRelativePath", "FabricaCapsulas.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFabricaCapsulas_Statics::NewProp_RangoSpawnX_MetaData[] = {
		{ "Category", "Spawn Range" },
		{ "ModuleRelativePath", "FabricaCapsulas.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFabricaCapsulas_Statics::NewProp_RangoSpawnX = { "RangoSpawnX", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFabricaCapsulas, RangoSpawnX), METADATA_PARAMS(Z_Construct_UClass_AFabricaCapsulas_Statics::NewProp_RangoSpawnX_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFabricaCapsulas_Statics::NewProp_RangoSpawnX_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFabricaCapsulas_Statics::NewProp_RangoSpawnY_MetaData[] = {
		{ "Category", "Spawn Range" },
		{ "ModuleRelativePath", "FabricaCapsulas.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AFabricaCapsulas_Statics::NewProp_RangoSpawnY = { "RangoSpawnY", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AFabricaCapsulas, RangoSpawnY), METADATA_PARAMS(Z_Construct_UClass_AFabricaCapsulas_Statics::NewProp_RangoSpawnY_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AFabricaCapsulas_Statics::NewProp_RangoSpawnY_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AFabricaCapsulas_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFabricaCapsulas_Statics::NewProp_RangoSpawnX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AFabricaCapsulas_Statics::NewProp_RangoSpawnY,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFabricaCapsulas_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFabricaCapsulas>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFabricaCapsulas_Statics::ClassParams = {
		&AFabricaCapsulas::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AFabricaCapsulas_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AFabricaCapsulas_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AFabricaCapsulas_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFabricaCapsulas_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFabricaCapsulas()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFabricaCapsulas_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFabricaCapsulas, 972504549);
	template<> ADAPTERPATERN1_API UClass* StaticClass<AFabricaCapsulas>()
	{
		return AFabricaCapsulas::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFabricaCapsulas(Z_Construct_UClass_AFabricaCapsulas, &AFabricaCapsulas::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("AFabricaCapsulas"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFabricaCapsulas);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

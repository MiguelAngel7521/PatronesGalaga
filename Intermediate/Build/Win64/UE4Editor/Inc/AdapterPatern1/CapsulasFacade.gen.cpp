// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/CapsulasFacade.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCapsulasFacade() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ACapsulasFacade_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ACapsulasFacade();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ANivel_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ACapsulasTipoFacade_NoRegister();
// End Cross Module References
	void ACapsulasFacade::StaticRegisterNativesACapsulasFacade()
	{
	}
	UClass* Z_Construct_UClass_ACapsulasFacade_NoRegister()
	{
		return ACapsulasFacade::StaticClass();
	}
	struct Z_Construct_UClass_ACapsulasFacade_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NivelActual_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NivelActual;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Nivel_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Nivel_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Nivel;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_OrdenCapsulas_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OrdenCapsulas_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OrdenCapsulas;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACapsulasFacade_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACapsulasFacade_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CapsulasFacade.h" },
		{ "ModuleRelativePath", "CapsulasFacade.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_NivelActual_MetaData[] = {
		{ "ModuleRelativePath", "CapsulasFacade.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_NivelActual = { "NivelActual", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACapsulasFacade, NivelActual), Z_Construct_UClass_ANivel_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_NivelActual_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_NivelActual_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_Nivel_Inner = { "Nivel", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_ACapsulasTipoFacade_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_Nivel_MetaData[] = {
		{ "ModuleRelativePath", "CapsulasFacade.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_Nivel = { "Nivel", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACapsulasFacade, Nivel), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_Nivel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_Nivel_MetaData)) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_OrdenCapsulas_Inner = { "OrdenCapsulas", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_OrdenCapsulas_MetaData[] = {
		{ "ModuleRelativePath", "CapsulasFacade.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_OrdenCapsulas = { "OrdenCapsulas", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACapsulasFacade, OrdenCapsulas), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_OrdenCapsulas_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_OrdenCapsulas_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACapsulasFacade_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_NivelActual,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_Nivel_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_Nivel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_OrdenCapsulas_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACapsulasFacade_Statics::NewProp_OrdenCapsulas,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACapsulasFacade_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACapsulasFacade>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACapsulasFacade_Statics::ClassParams = {
		&ACapsulasFacade::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACapsulasFacade_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulasFacade_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACapsulasFacade_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulasFacade_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACapsulasFacade()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACapsulasFacade_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACapsulasFacade, 2732350697);
	template<> ADAPTERPATERN1_API UClass* StaticClass<ACapsulasFacade>()
	{
		return ACapsulasFacade::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACapsulasFacade(Z_Construct_UClass_ACapsulasFacade, &ACapsulasFacade::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("ACapsulasFacade"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACapsulasFacade);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

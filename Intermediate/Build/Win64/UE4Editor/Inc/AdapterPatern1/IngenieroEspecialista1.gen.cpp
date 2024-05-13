// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/IngenieroEspecialista1.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIngenieroEspecialista1() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AIngenieroEspecialista1_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AIngenieroEspecialista1();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UIngenieroGeneral_NoRegister();
// End Cross Module References
	void AIngenieroEspecialista1::StaticRegisterNativesAIngenieroEspecialista1()
	{
	}
	UClass* Z_Construct_UClass_AIngenieroEspecialista1_NoRegister()
	{
		return AIngenieroEspecialista1::StaticClass();
	}
	struct Z_Construct_UClass_AIngenieroEspecialista1_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AIngenieroEspecialista1_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AIngenieroEspecialista1_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "IngenieroEspecialista1.h" },
		{ "ModuleRelativePath", "IngenieroEspecialista1.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AIngenieroEspecialista1_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UIngenieroGeneral_NoRegister, (int32)VTABLE_OFFSET(AIngenieroEspecialista1, IIngenieroGeneral), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AIngenieroEspecialista1_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AIngenieroEspecialista1>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AIngenieroEspecialista1_Statics::ClassParams = {
		&AIngenieroEspecialista1::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		UE_ARRAY_COUNT(InterfaceParams),
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AIngenieroEspecialista1_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AIngenieroEspecialista1_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AIngenieroEspecialista1()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AIngenieroEspecialista1_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AIngenieroEspecialista1, 1177237853);
	template<> ADAPTERPATERN1_API UClass* StaticClass<AIngenieroEspecialista1>()
	{
		return AIngenieroEspecialista1::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AIngenieroEspecialista1(Z_Construct_UClass_AIngenieroEspecialista1, &AIngenieroEspecialista1::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("AIngenieroEspecialista1"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AIngenieroEspecialista1);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/EstrategiaAtaqueSierra.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstrategiaAtaqueSierra() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AEstrategiaAtaqueSierra_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AEstrategiaAtaqueSierra();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UIEstrategiasAtaquesPawn_NoRegister();
// End Cross Module References
	void AEstrategiaAtaqueSierra::StaticRegisterNativesAEstrategiaAtaqueSierra()
	{
	}
	UClass* Z_Construct_UClass_AEstrategiaAtaqueSierra_NoRegister()
	{
		return AEstrategiaAtaqueSierra::StaticClass();
	}
	struct Z_Construct_UClass_AEstrategiaAtaqueSierra_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEstrategiaAtaqueSierra_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstrategiaAtaqueSierra_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EstrategiaAtaqueSierra.h" },
		{ "ModuleRelativePath", "EstrategiaAtaqueSierra.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AEstrategiaAtaqueSierra_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UIEstrategiasAtaquesPawn_NoRegister, (int32)VTABLE_OFFSET(AEstrategiaAtaqueSierra, IIEstrategiasAtaquesPawn), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEstrategiaAtaqueSierra_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEstrategiaAtaqueSierra>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEstrategiaAtaqueSierra_Statics::ClassParams = {
		&AEstrategiaAtaqueSierra::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEstrategiaAtaqueSierra_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEstrategiaAtaqueSierra_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEstrategiaAtaqueSierra()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEstrategiaAtaqueSierra_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEstrategiaAtaqueSierra, 1641241479);
	template<> ADAPTERPATERN1_API UClass* StaticClass<AEstrategiaAtaqueSierra>()
	{
		return AEstrategiaAtaqueSierra::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEstrategiaAtaqueSierra(Z_Construct_UClass_AEstrategiaAtaqueSierra, &AEstrategiaAtaqueSierra::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("AEstrategiaAtaqueSierra"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEstrategiaAtaqueSierra);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/ConstruirNaveEnemiga.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConstruirNaveEnemiga() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AConstruirNaveEnemiga_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AConstruirNaveEnemiga();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UNaveEnemigaBuilder_NoRegister();
// End Cross Module References
	void AConstruirNaveEnemiga::StaticRegisterNativesAConstruirNaveEnemiga()
	{
	}
	UClass* Z_Construct_UClass_AConstruirNaveEnemiga_NoRegister()
	{
		return AConstruirNaveEnemiga::StaticClass();
	}
	struct Z_Construct_UClass_AConstruirNaveEnemiga_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AConstruirNaveEnemiga_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AConstruirNaveEnemiga_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ConstruirNaveEnemiga.h" },
		{ "ModuleRelativePath", "ConstruirNaveEnemiga.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AConstruirNaveEnemiga_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UNaveEnemigaBuilder_NoRegister, (int32)VTABLE_OFFSET(AConstruirNaveEnemiga, INaveEnemigaBuilder), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AConstruirNaveEnemiga_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AConstruirNaveEnemiga>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AConstruirNaveEnemiga_Statics::ClassParams = {
		&AConstruirNaveEnemiga::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AConstruirNaveEnemiga_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AConstruirNaveEnemiga_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AConstruirNaveEnemiga()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AConstruirNaveEnemiga_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AConstruirNaveEnemiga, 4151876700);
	template<> ADAPTERPATERN1_API UClass* StaticClass<AConstruirNaveEnemiga>()
	{
		return AConstruirNaveEnemiga::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AConstruirNaveEnemiga(Z_Construct_UClass_AConstruirNaveEnemiga, &AConstruirNaveEnemiga::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("AConstruirNaveEnemiga"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AConstruirNaveEnemiga);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

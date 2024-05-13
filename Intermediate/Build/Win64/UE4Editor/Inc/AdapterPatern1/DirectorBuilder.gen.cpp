// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/DirectorBuilder.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDirectorBuilder() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ADirectorBuilder_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ADirectorBuilder();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
// End Cross Module References
	void ADirectorBuilder::StaticRegisterNativesADirectorBuilder()
	{
	}
	UClass* Z_Construct_UClass_ADirectorBuilder_NoRegister()
	{
		return ADirectorBuilder::StaticClass();
	}
	struct Z_Construct_UClass_ADirectorBuilder_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADirectorBuilder_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADirectorBuilder_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DirectorBuilder.h" },
		{ "ModuleRelativePath", "DirectorBuilder.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADirectorBuilder_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADirectorBuilder>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ADirectorBuilder_Statics::ClassParams = {
		&ADirectorBuilder::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ADirectorBuilder_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ADirectorBuilder_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ADirectorBuilder()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ADirectorBuilder_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ADirectorBuilder, 3060372452);
	template<> ADAPTERPATERN1_API UClass* StaticClass<ADirectorBuilder>()
	{
		return ADirectorBuilder::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ADirectorBuilder(Z_Construct_UClass_ADirectorBuilder, &ADirectorBuilder::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("ADirectorBuilder"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADirectorBuilder);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

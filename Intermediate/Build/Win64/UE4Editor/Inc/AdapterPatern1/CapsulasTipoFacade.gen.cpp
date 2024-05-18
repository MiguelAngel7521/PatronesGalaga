// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/CapsulasTipoFacade.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCapsulasTipoFacade() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ACapsulasTipoFacade_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ACapsulasTipoFacade();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
// End Cross Module References
	void ACapsulasTipoFacade::StaticRegisterNativesACapsulasTipoFacade()
	{
	}
	UClass* Z_Construct_UClass_ACapsulasTipoFacade_NoRegister()
	{
		return ACapsulasTipoFacade::StaticClass();
	}
	struct Z_Construct_UClass_ACapsulasTipoFacade_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACapsulasTipoFacade_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACapsulasTipoFacade_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CapsulasTipoFacade.h" },
		{ "ModuleRelativePath", "CapsulasTipoFacade.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACapsulasTipoFacade_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACapsulasTipoFacade>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACapsulasTipoFacade_Statics::ClassParams = {
		&ACapsulasTipoFacade::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ACapsulasTipoFacade_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACapsulasTipoFacade_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACapsulasTipoFacade()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACapsulasTipoFacade_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACapsulasTipoFacade, 2082257696);
	template<> ADAPTERPATERN1_API UClass* StaticClass<ACapsulasTipoFacade>()
	{
		return ACapsulasTipoFacade::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACapsulasTipoFacade(Z_Construct_UClass_ACapsulasTipoFacade, &ACapsulasTipoFacade::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("ACapsulasTipoFacade"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACapsulasTipoFacade);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

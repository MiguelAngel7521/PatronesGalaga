// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/ProxyNaveCompuesta.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProxyNaveCompuesta() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AProxyNaveCompuesta_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AProxyNaveCompuesta();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UNaveEnemigaBuilder_NoRegister();
// End Cross Module References
	void AProxyNaveCompuesta::StaticRegisterNativesAProxyNaveCompuesta()
	{
	}
	UClass* Z_Construct_UClass_AProxyNaveCompuesta_NoRegister()
	{
		return AProxyNaveCompuesta::StaticClass();
	}
	struct Z_Construct_UClass_AProxyNaveCompuesta_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AProxyNaveCompuesta_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProxyNaveCompuesta_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ProxyNaveCompuesta.h" },
		{ "ModuleRelativePath", "ProxyNaveCompuesta.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AProxyNaveCompuesta_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UNaveEnemigaBuilder_NoRegister, (int32)VTABLE_OFFSET(AProxyNaveCompuesta, INaveEnemigaBuilder), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AProxyNaveCompuesta_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProxyNaveCompuesta>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AProxyNaveCompuesta_Statics::ClassParams = {
		&AProxyNaveCompuesta::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AProxyNaveCompuesta_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AProxyNaveCompuesta_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AProxyNaveCompuesta()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AProxyNaveCompuesta_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProxyNaveCompuesta, 2578571631);
	template<> ADAPTERPATERN1_API UClass* StaticClass<AProxyNaveCompuesta>()
	{
		return AProxyNaveCompuesta::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProxyNaveCompuesta(Z_Construct_UClass_AProxyNaveCompuesta, &AProxyNaveCompuesta::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("AProxyNaveCompuesta"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProxyNaveCompuesta);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

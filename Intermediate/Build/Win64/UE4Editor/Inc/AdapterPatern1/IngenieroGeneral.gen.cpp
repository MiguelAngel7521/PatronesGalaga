// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/IngenieroGeneral.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIngenieroGeneral() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UIngenieroGeneral_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UIngenieroGeneral();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
// End Cross Module References
	void UIngenieroGeneral::StaticRegisterNativesUIngenieroGeneral()
	{
	}
	UClass* Z_Construct_UClass_UIngenieroGeneral_NoRegister()
	{
		return UIngenieroGeneral::StaticClass();
	}
	struct Z_Construct_UClass_UIngenieroGeneral_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UIngenieroGeneral_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UIngenieroGeneral_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "IngenieroGeneral.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UIngenieroGeneral_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IIngenieroGeneral>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UIngenieroGeneral_Statics::ClassParams = {
		&UIngenieroGeneral::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000840A1u,
		METADATA_PARAMS(Z_Construct_UClass_UIngenieroGeneral_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UIngenieroGeneral_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UIngenieroGeneral()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UIngenieroGeneral_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UIngenieroGeneral, 1450362354);
	template<> ADAPTERPATERN1_API UClass* StaticClass<UIngenieroGeneral>()
	{
		return UIngenieroGeneral::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UIngenieroGeneral(Z_Construct_UClass_UIngenieroGeneral, &UIngenieroGeneral::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("UIngenieroGeneral"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UIngenieroGeneral);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

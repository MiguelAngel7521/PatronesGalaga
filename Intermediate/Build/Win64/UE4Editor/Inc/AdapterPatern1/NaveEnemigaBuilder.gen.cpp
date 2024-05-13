// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/NaveEnemigaBuilder.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNaveEnemigaBuilder() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UNaveEnemigaBuilder_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UNaveEnemigaBuilder();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
// End Cross Module References
	void UNaveEnemigaBuilder::StaticRegisterNativesUNaveEnemigaBuilder()
	{
	}
	UClass* Z_Construct_UClass_UNaveEnemigaBuilder_NoRegister()
	{
		return UNaveEnemigaBuilder::StaticClass();
	}
	struct Z_Construct_UClass_UNaveEnemigaBuilder_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UNaveEnemigaBuilder_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UNaveEnemigaBuilder_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "NaveEnemigaBuilder.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UNaveEnemigaBuilder_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<INaveEnemigaBuilder>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UNaveEnemigaBuilder_Statics::ClassParams = {
		&UNaveEnemigaBuilder::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UNaveEnemigaBuilder_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UNaveEnemigaBuilder_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UNaveEnemigaBuilder()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UNaveEnemigaBuilder_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UNaveEnemigaBuilder, 3590028781);
	template<> ADAPTERPATERN1_API UClass* StaticClass<UNaveEnemigaBuilder>()
	{
		return UNaveEnemigaBuilder::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UNaveEnemigaBuilder(Z_Construct_UClass_UNaveEnemigaBuilder, &UNaveEnemigaBuilder::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("UNaveEnemigaBuilder"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UNaveEnemigaBuilder);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

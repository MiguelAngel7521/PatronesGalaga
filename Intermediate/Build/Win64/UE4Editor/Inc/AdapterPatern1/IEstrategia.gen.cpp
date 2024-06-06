// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/IEstrategia.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIEstrategia() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UIEstrategia_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UIEstrategia();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
// End Cross Module References
	void UIEstrategia::StaticRegisterNativesUIEstrategia()
	{
	}
	UClass* Z_Construct_UClass_UIEstrategia_NoRegister()
	{
		return UIEstrategia::StaticClass();
	}
	struct Z_Construct_UClass_UIEstrategia_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UIEstrategia_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UIEstrategia_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "IEstrategia.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UIEstrategia_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IIEstrategia>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UIEstrategia_Statics::ClassParams = {
		&UIEstrategia::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UIEstrategia_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UIEstrategia_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UIEstrategia()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UIEstrategia_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UIEstrategia, 2627826576);
	template<> ADAPTERPATERN1_API UClass* StaticClass<UIEstrategia>()
	{
		return UIEstrategia::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UIEstrategia(Z_Construct_UClass_UIEstrategia, &UIEstrategia::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("UIEstrategia"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UIEstrategia);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

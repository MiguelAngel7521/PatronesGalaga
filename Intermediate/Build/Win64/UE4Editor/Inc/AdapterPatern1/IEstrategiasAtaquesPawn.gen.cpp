// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/IEstrategiasAtaquesPawn.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIEstrategiasAtaquesPawn() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UIEstrategiasAtaquesPawn_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UIEstrategiasAtaquesPawn();
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
// End Cross Module References
	void UIEstrategiasAtaquesPawn::StaticRegisterNativesUIEstrategiasAtaquesPawn()
	{
	}
	UClass* Z_Construct_UClass_UIEstrategiasAtaquesPawn_NoRegister()
	{
		return UIEstrategiasAtaquesPawn::StaticClass();
	}
	struct Z_Construct_UClass_UIEstrategiasAtaquesPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UIEstrategiasAtaquesPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UIEstrategiasAtaquesPawn_Statics::Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "IEstrategiasAtaquesPawn.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UIEstrategiasAtaquesPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IIEstrategiasAtaquesPawn>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UIEstrategiasAtaquesPawn_Statics::ClassParams = {
		&UIEstrategiasAtaquesPawn::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UIEstrategiasAtaquesPawn_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UIEstrategiasAtaquesPawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UIEstrategiasAtaquesPawn()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UIEstrategiasAtaquesPawn_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UIEstrategiasAtaquesPawn, 4153248657);
	template<> ADAPTERPATERN1_API UClass* StaticClass<UIEstrategiasAtaquesPawn>()
	{
		return UIEstrategiasAtaquesPawn::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UIEstrategiasAtaquesPawn(Z_Construct_UClass_UIEstrategiasAtaquesPawn, &UIEstrategiasAtaquesPawn::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("UIEstrategiasAtaquesPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UIEstrategiasAtaquesPawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

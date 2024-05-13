// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/IngenieroEspecialista3.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIngenieroEspecialista3() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AIngenieroEspecialista3_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AIngenieroEspecialista3();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UIngenieroGeneral_NoRegister();
// End Cross Module References
	void AIngenieroEspecialista3::StaticRegisterNativesAIngenieroEspecialista3()
	{
	}
	UClass* Z_Construct_UClass_AIngenieroEspecialista3_NoRegister()
	{
		return AIngenieroEspecialista3::StaticClass();
	}
	struct Z_Construct_UClass_AIngenieroEspecialista3_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AIngenieroEspecialista3_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AIngenieroEspecialista3_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "IngenieroEspecialista3.h" },
		{ "ModuleRelativePath", "IngenieroEspecialista3.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AIngenieroEspecialista3_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UIngenieroGeneral_NoRegister, (int32)VTABLE_OFFSET(AIngenieroEspecialista3, IIngenieroGeneral), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AIngenieroEspecialista3_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AIngenieroEspecialista3>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AIngenieroEspecialista3_Statics::ClassParams = {
		&AIngenieroEspecialista3::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AIngenieroEspecialista3_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AIngenieroEspecialista3_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AIngenieroEspecialista3()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AIngenieroEspecialista3_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AIngenieroEspecialista3, 2786267092);
	template<> ADAPTERPATERN1_API UClass* StaticClass<AIngenieroEspecialista3>()
	{
		return AIngenieroEspecialista3::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AIngenieroEspecialista3(Z_Construct_UClass_AIngenieroEspecialista3, &AIngenieroEspecialista3::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("AIngenieroEspecialista3"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AIngenieroEspecialista3);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

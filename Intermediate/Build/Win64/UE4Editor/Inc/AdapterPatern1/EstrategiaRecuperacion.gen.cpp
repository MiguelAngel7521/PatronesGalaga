// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/EstrategiaRecuperacion.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEstrategiaRecuperacion() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AEstrategiaRecuperacion_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AEstrategiaRecuperacion();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UIEstrategia_NoRegister();
// End Cross Module References
	void AEstrategiaRecuperacion::StaticRegisterNativesAEstrategiaRecuperacion()
	{
	}
	UClass* Z_Construct_UClass_AEstrategiaRecuperacion_NoRegister()
	{
		return AEstrategiaRecuperacion::StaticClass();
	}
	struct Z_Construct_UClass_AEstrategiaRecuperacion_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEstrategiaRecuperacion_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEstrategiaRecuperacion_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "EstrategiaRecuperacion.h" },
		{ "ModuleRelativePath", "EstrategiaRecuperacion.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AEstrategiaRecuperacion_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UIEstrategia_NoRegister, (int32)VTABLE_OFFSET(AEstrategiaRecuperacion, IIEstrategia), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEstrategiaRecuperacion_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEstrategiaRecuperacion>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AEstrategiaRecuperacion_Statics::ClassParams = {
		&AEstrategiaRecuperacion::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AEstrategiaRecuperacion_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AEstrategiaRecuperacion_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AEstrategiaRecuperacion()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AEstrategiaRecuperacion_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AEstrategiaRecuperacion, 2519284459);
	template<> ADAPTERPATERN1_API UClass* StaticClass<AEstrategiaRecuperacion>()
	{
		return AEstrategiaRecuperacion::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AEstrategiaRecuperacion(Z_Construct_UClass_AEstrategiaRecuperacion, &AEstrategiaRecuperacion::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("AEstrategiaRecuperacion"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEstrategiaRecuperacion);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

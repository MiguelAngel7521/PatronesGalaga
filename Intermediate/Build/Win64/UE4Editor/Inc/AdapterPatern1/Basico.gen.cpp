// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/Basico.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBasico() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ABasico_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ABasico();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UIEstados_NoRegister();
// End Cross Module References
	void ABasico::StaticRegisterNativesABasico()
	{
	}
	UClass* Z_Construct_UClass_ABasico_NoRegister()
	{
		return ABasico::StaticClass();
	}
	struct Z_Construct_UClass_ABasico_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABasico_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABasico_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Basico.h" },
		{ "ModuleRelativePath", "Basico.h" },
	};
#endif
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ABasico_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UIEstados_NoRegister, (int32)VTABLE_OFFSET(ABasico, IIEstados), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABasico_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABasico>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABasico_Statics::ClassParams = {
		&ABasico::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ABasico_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABasico_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABasico()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABasico_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABasico, 2312313002);
	template<> ADAPTERPATERN1_API UClass* StaticClass<ABasico>()
	{
		return ABasico::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABasico(Z_Construct_UClass_ABasico, &ABasico::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("ABasico"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABasico);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

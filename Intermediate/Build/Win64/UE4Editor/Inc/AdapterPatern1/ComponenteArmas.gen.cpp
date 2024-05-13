// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/ComponenteArmas.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeComponenteArmas() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AComponenteArmas_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AComponenteArmas();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AComponenteArmas::StaticRegisterNativesAComponenteArmas()
	{
	}
	UClass* Z_Construct_UClass_AComponenteArmas_NoRegister()
	{
		return AComponenteArmas::StaticClass();
	}
	struct Z_Construct_UClass_AComponenteArmas_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MallaArmas_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MallaArmas;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AComponenteArmas_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AComponenteArmas_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ComponenteArmas.h" },
		{ "ModuleRelativePath", "ComponenteArmas.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AComponenteArmas_Statics::NewProp_MallaArmas_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Projectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ComponenteArmas.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComponenteArmas_Statics::NewProp_MallaArmas = { "MallaArmas", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AComponenteArmas, MallaArmas), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AComponenteArmas_Statics::NewProp_MallaArmas_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AComponenteArmas_Statics::NewProp_MallaArmas_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AComponenteArmas_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComponenteArmas_Statics::NewProp_MallaArmas,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AComponenteArmas_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AComponenteArmas>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AComponenteArmas_Statics::ClassParams = {
		&AComponenteArmas::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AComponenteArmas_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AComponenteArmas_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AComponenteArmas_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AComponenteArmas_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AComponenteArmas()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AComponenteArmas_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AComponenteArmas, 4122775889);
	template<> ADAPTERPATERN1_API UClass* StaticClass<AComponenteArmas>()
	{
		return AComponenteArmas::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AComponenteArmas(Z_Construct_UClass_AComponenteArmas, &AComponenteArmas::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("AComponenteArmas"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AComponenteArmas);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

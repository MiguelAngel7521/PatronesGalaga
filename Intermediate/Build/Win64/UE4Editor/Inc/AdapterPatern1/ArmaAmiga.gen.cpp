// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/ArmaAmiga.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeArmaAmiga() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AArmaAmiga_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AArmaAmiga();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AProjectileEnemigo_NoRegister();
// End Cross Module References
	void AArmaAmiga::StaticRegisterNativesAArmaAmiga()
	{
	}
	UClass* Z_Construct_UClass_AArmaAmiga_NoRegister()
	{
		return AArmaAmiga::StaticClass();
	}
	struct Z_Construct_UClass_AArmaAmiga_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MallaArmas_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MallaArmas;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProyectilEnemigoClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProyectilEnemigoClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FireRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_FireRate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AArmaAmiga_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AArmaAmiga_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ArmaAmiga.h" },
		{ "ModuleRelativePath", "ArmaAmiga.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AArmaAmiga_Statics::NewProp_MallaArmas_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Projectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ArmaAmiga.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AArmaAmiga_Statics::NewProp_MallaArmas = { "MallaArmas", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AArmaAmiga, MallaArmas), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AArmaAmiga_Statics::NewProp_MallaArmas_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AArmaAmiga_Statics::NewProp_MallaArmas_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AArmaAmiga_Statics::NewProp_ProyectilEnemigoClass_MetaData[] = {
		{ "Category", "Proyectil" },
		{ "ModuleRelativePath", "ArmaAmiga.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AArmaAmiga_Statics::NewProp_ProyectilEnemigoClass = { "ProyectilEnemigoClass", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AArmaAmiga, ProyectilEnemigoClass), Z_Construct_UClass_AProjectileEnemigo_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AArmaAmiga_Statics::NewProp_ProyectilEnemigoClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AArmaAmiga_Statics::NewProp_ProyectilEnemigoClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AArmaAmiga_Statics::NewProp_FireRate_MetaData[] = {
		{ "Category", "Proyectil" },
		{ "ModuleRelativePath", "ArmaAmiga.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AArmaAmiga_Statics::NewProp_FireRate = { "FireRate", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AArmaAmiga, FireRate), METADATA_PARAMS(Z_Construct_UClass_AArmaAmiga_Statics::NewProp_FireRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AArmaAmiga_Statics::NewProp_FireRate_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AArmaAmiga_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AArmaAmiga_Statics::NewProp_MallaArmas,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AArmaAmiga_Statics::NewProp_ProyectilEnemigoClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AArmaAmiga_Statics::NewProp_FireRate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AArmaAmiga_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AArmaAmiga>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AArmaAmiga_Statics::ClassParams = {
		&AArmaAmiga::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AArmaAmiga_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AArmaAmiga_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AArmaAmiga_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AArmaAmiga_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AArmaAmiga()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AArmaAmiga_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AArmaAmiga, 563930474);
	template<> ADAPTERPATERN1_API UClass* StaticClass<AArmaAmiga>()
	{
		return AArmaAmiga::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AArmaAmiga(Z_Construct_UClass_AArmaAmiga, &AArmaAmiga::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("AArmaAmiga"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AArmaAmiga);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

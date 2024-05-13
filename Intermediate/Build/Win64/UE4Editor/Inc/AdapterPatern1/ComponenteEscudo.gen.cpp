// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/ComponenteEscudo.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeComponenteEscudo() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AComponenteEscudo_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AComponenteEscudo();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AComponenteEscudo::StaticRegisterNativesAComponenteEscudo()
	{
	}
	UClass* Z_Construct_UClass_AComponenteEscudo_NoRegister()
	{
		return AComponenteEscudo::StaticClass();
	}
	struct Z_Construct_UClass_AComponenteEscudo_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MallaEscudo_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MallaEscudo;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AComponenteEscudo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AComponenteEscudo_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ComponenteEscudo.h" },
		{ "ModuleRelativePath", "ComponenteEscudo.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AComponenteEscudo_Statics::NewProp_MallaEscudo_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Projectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ComponenteEscudo.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComponenteEscudo_Statics::NewProp_MallaEscudo = { "MallaEscudo", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AComponenteEscudo, MallaEscudo), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AComponenteEscudo_Statics::NewProp_MallaEscudo_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AComponenteEscudo_Statics::NewProp_MallaEscudo_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AComponenteEscudo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComponenteEscudo_Statics::NewProp_MallaEscudo,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AComponenteEscudo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AComponenteEscudo>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AComponenteEscudo_Statics::ClassParams = {
		&AComponenteEscudo::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AComponenteEscudo_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AComponenteEscudo_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AComponenteEscudo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AComponenteEscudo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AComponenteEscudo()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AComponenteEscudo_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AComponenteEscudo, 4224604987);
	template<> ADAPTERPATERN1_API UClass* StaticClass<AComponenteEscudo>()
	{
		return AComponenteEscudo::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AComponenteEscudo(Z_Construct_UClass_AComponenteEscudo, &AComponenteEscudo::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("AComponenteEscudo"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AComponenteEscudo);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

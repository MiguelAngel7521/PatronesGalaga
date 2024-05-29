// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/AdapterPatern1GameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdapterPatern1GameMode() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AAdapterPatern1GameMode_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AAdapterPatern1GameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ACapsulasFacade_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AAdapterPatern1Pawn_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ABallAdapter_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ARadarEnemigo_NoRegister();
// End Cross Module References
	void AAdapterPatern1GameMode::StaticRegisterNativesAAdapterPatern1GameMode()
	{
	}
	UClass* Z_Construct_UClass_AAdapterPatern1GameMode_NoRegister()
	{
		return AAdapterPatern1GameMode::StaticClass();
	}
	struct Z_Construct_UClass_AAdapterPatern1GameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Facade_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Facade;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Jugador_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Jugador;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Adapter_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Adapter;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Radar_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Radar;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAdapterPatern1GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAdapterPatern1GameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "AdapterPatern1GameMode.h" },
		{ "ModuleRelativePath", "AdapterPatern1GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Facade_MetaData[] = {
		{ "Category", "Game mode" },
		{ "Comment", "//Patron Facade \n" },
		{ "ModuleRelativePath", "AdapterPatern1GameMode.h" },
		{ "ToolTip", "Patron Facade" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Facade = { "Facade", nullptr, (EPropertyFlags)0x0020080000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAdapterPatern1GameMode, Facade), Z_Construct_UClass_ACapsulasFacade_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Facade_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Facade_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Jugador_MetaData[] = {
		{ "Category", "Game Mode" },
		{ "ModuleRelativePath", "AdapterPatern1GameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Jugador = { "Jugador", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAdapterPatern1GameMode, Jugador), Z_Construct_UClass_AAdapterPatern1Pawn_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Jugador_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Jugador_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Adapter_MetaData[] = {
		{ "Category", "Game Mode" },
		{ "ModuleRelativePath", "AdapterPatern1GameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Adapter = { "Adapter", nullptr, (EPropertyFlags)0x0010000000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAdapterPatern1GameMode, Adapter), Z_Construct_UClass_ABallAdapter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Adapter_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Adapter_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Radar_MetaData[] = {
		{ "Category", "Game mode" },
		{ "Comment", "//Patron State \n" },
		{ "ModuleRelativePath", "AdapterPatern1GameMode.h" },
		{ "ToolTip", "Patron State" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Radar = { "Radar", nullptr, (EPropertyFlags)0x0040000000020001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAdapterPatern1GameMode, Radar), Z_Construct_UClass_ARadarEnemigo_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Radar_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Radar_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAdapterPatern1GameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Facade,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Jugador,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Adapter,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAdapterPatern1GameMode_Statics::NewProp_Radar,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAdapterPatern1GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAdapterPatern1GameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAdapterPatern1GameMode_Statics::ClassParams = {
		&AAdapterPatern1GameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AAdapterPatern1GameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AAdapterPatern1GameMode_Statics::PropPointers),
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AAdapterPatern1GameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAdapterPatern1GameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAdapterPatern1GameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAdapterPatern1GameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAdapterPatern1GameMode, 288009217);
	template<> ADAPTERPATERN1_API UClass* StaticClass<AAdapterPatern1GameMode>()
	{
		return AAdapterPatern1GameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAdapterPatern1GameMode(Z_Construct_UClass_AAdapterPatern1GameMode, &AAdapterPatern1GameMode::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("AAdapterPatern1GameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAdapterPatern1GameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

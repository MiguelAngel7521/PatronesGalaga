// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/AdapterPatern1Pawn.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAdapterPatern1Pawn() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AAdapterPatern1Pawn_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_AAdapterPatern1Pawn();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UIBounceBall_NoRegister();
// End Cross Module References
	void AAdapterPatern1Pawn::StaticRegisterNativesAAdapterPatern1Pawn()
	{
	}
	UClass* Z_Construct_UClass_AAdapterPatern1Pawn_NoRegister()
	{
		return AAdapterPatern1Pawn::StaticClass();
	}
	struct Z_Construct_UClass_AAdapterPatern1Pawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ShipMeshComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ShipMeshComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GunOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GunOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FireRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_FireRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MoveSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MoveSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FireSound_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FireSound;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAdapterPatern1Pawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAdapterPatern1Pawn_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AdapterPatern1Pawn.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "AdapterPatern1Pawn.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_ShipMeshComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Mesh" },
		{ "Comment", "/* The mesh component */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AdapterPatern1Pawn.h" },
		{ "ToolTip", "The mesh component" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_ShipMeshComponent = { "ShipMeshComponent", nullptr, (EPropertyFlags)0x00400000000b001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAdapterPatern1Pawn, ShipMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_ShipMeshComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_ShipMeshComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_CameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** The camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AdapterPatern1Pawn.h" },
		{ "ToolTip", "The camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_CameraComponent = { "CameraComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAdapterPatern1Pawn, CameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_CameraComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_CameraComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera boom positioning the camera above the character */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AdapterPatern1Pawn.h" },
		{ "ToolTip", "Camera boom positioning the camera above the character" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAdapterPatern1Pawn, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_GunOffset_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/** Offset from the ships location to spawn projectiles */" },
		{ "ModuleRelativePath", "AdapterPatern1Pawn.h" },
		{ "ToolTip", "Offset from the ships location to spawn projectiles" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_GunOffset = { "GunOffset", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAdapterPatern1Pawn, GunOffset), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_GunOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_GunOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_FireRate_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/* How fast the weapon will fire */" },
		{ "ModuleRelativePath", "AdapterPatern1Pawn.h" },
		{ "ToolTip", "How fast the weapon will fire" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_FireRate = { "FireRate", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAdapterPatern1Pawn, FireRate), METADATA_PARAMS(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_FireRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_FireRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_MoveSpeed_MetaData[] = {
		{ "Category", "Gameplay" },
		{ "Comment", "/* The speed our ship moves around the level */" },
		{ "ModuleRelativePath", "AdapterPatern1Pawn.h" },
		{ "ToolTip", "The speed our ship moves around the level" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_MoveSpeed = { "MoveSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAdapterPatern1Pawn, MoveSpeed), METADATA_PARAMS(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_MoveSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_MoveSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_FireSound_MetaData[] = {
		{ "Category", "Audio" },
		{ "Comment", "/** Sound to play each time we fire */" },
		{ "ModuleRelativePath", "AdapterPatern1Pawn.h" },
		{ "ToolTip", "Sound to play each time we fire" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_FireSound = { "FireSound", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAdapterPatern1Pawn, FireSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_FireSound_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_FireSound_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAdapterPatern1Pawn_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_ShipMeshComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_CameraComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_CameraBoom,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_GunOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_FireRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_MoveSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAdapterPatern1Pawn_Statics::NewProp_FireSound,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AAdapterPatern1Pawn_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UIBounceBall_NoRegister, (int32)VTABLE_OFFSET(AAdapterPatern1Pawn, IIBounceBall), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAdapterPatern1Pawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAdapterPatern1Pawn>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAdapterPatern1Pawn_Statics::ClassParams = {
		&AAdapterPatern1Pawn::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AAdapterPatern1Pawn_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAdapterPatern1Pawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAdapterPatern1Pawn()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAdapterPatern1Pawn_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAdapterPatern1Pawn, 1324097594);
	template<> ADAPTERPATERN1_API UClass* StaticClass<AAdapterPatern1Pawn>()
	{
		return AAdapterPatern1Pawn::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAdapterPatern1Pawn(Z_Construct_UClass_AAdapterPatern1Pawn, &AAdapterPatern1Pawn::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("AAdapterPatern1Pawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAdapterPatern1Pawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

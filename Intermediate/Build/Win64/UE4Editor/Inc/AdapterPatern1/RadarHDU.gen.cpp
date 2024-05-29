// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/RadarHDU.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRadarHDU() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ARadarHDU_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ARadarHDU();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_UIObserverRadar_NoRegister();
// End Cross Module References
	void ARadarHDU::StaticRegisterNativesARadarHDU()
	{
	}
	UClass* Z_Construct_UClass_ARadarHDU_NoRegister()
	{
		return ARadarHDU::StaticClass();
	}
	struct Z_Construct_UClass_ARadarHDU_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RadarStartLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_RadarStartLocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RadarRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RadarRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DegreeStep_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DegreeStep;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DrawPixelSize_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DrawPixelSize;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SphereHeight_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SphereHeight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SphereRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SphereRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RadarDistanceScale_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RadarDistanceScale;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARadarHDU_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARadarHDU_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "RadarHDU.h" },
		{ "ModuleRelativePath", "RadarHDU.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARadarHDU_Statics::NewProp_RadarStartLocation_MetaData[] = {
		{ "Category", "Radar" },
		{ "Comment", "/*La ubicaci?n de inicio de nuestro radar*/" },
		{ "ModuleRelativePath", "RadarHDU.h" },
		{ "ToolTip", "La ubicaci?n de inicio de nuestro radar" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ARadarHDU_Statics::NewProp_RadarStartLocation = { "RadarStartLocation", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARadarHDU, RadarStartLocation), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_ARadarHDU_Statics::NewProp_RadarStartLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARadarHDU_Statics::NewProp_RadarStartLocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARadarHDU_Statics::NewProp_RadarRadius_MetaData[] = {
		{ "Category", "Radar" },
		{ "Comment", "/*El radio de nuestro radar*/" },
		{ "ModuleRelativePath", "RadarHDU.h" },
		{ "ToolTip", "El radio de nuestro radar" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARadarHDU_Statics::NewProp_RadarRadius = { "RadarRadius", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARadarHDU, RadarRadius), METADATA_PARAMS(Z_Construct_UClass_ARadarHDU_Statics::NewProp_RadarRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARadarHDU_Statics::NewProp_RadarRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARadarHDU_Statics::NewProp_DegreeStep_MetaData[] = {
		{ "Category", "Radar" },
		{ "ModuleRelativePath", "RadarHDU.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARadarHDU_Statics::NewProp_DegreeStep = { "DegreeStep", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARadarHDU, DegreeStep), METADATA_PARAMS(Z_Construct_UClass_ARadarHDU_Statics::NewProp_DegreeStep_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARadarHDU_Statics::NewProp_DegreeStep_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARadarHDU_Statics::NewProp_DrawPixelSize_MetaData[] = {
		{ "Category", "Radar" },
		{ "Comment", "/*El tama?o de p?xel de los actores de radar dibujables*/" },
		{ "ModuleRelativePath", "RadarHDU.h" },
		{ "ToolTip", "El tama?o de p?xel de los actores de radar dibujables" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARadarHDU_Statics::NewProp_DrawPixelSize = { "DrawPixelSize", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARadarHDU, DrawPixelSize), METADATA_PARAMS(Z_Construct_UClass_ARadarHDU_Statics::NewProp_DrawPixelSize_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARadarHDU_Statics::NewProp_DrawPixelSize_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARadarHDU_Statics::NewProp_SphereHeight_MetaData[] = {
		{ "Category", "Radar" },
		{ "Comment", "/*Altura y radio de la esfera para nuestro raycast*/" },
		{ "ModuleRelativePath", "RadarHDU.h" },
		{ "ToolTip", "Altura y radio de la esfera para nuestro raycast" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARadarHDU_Statics::NewProp_SphereHeight = { "SphereHeight", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARadarHDU, SphereHeight), METADATA_PARAMS(Z_Construct_UClass_ARadarHDU_Statics::NewProp_SphereHeight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARadarHDU_Statics::NewProp_SphereHeight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARadarHDU_Statics::NewProp_SphereRadius_MetaData[] = {
		{ "Category", "Radar" },
		{ "ModuleRelativePath", "RadarHDU.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARadarHDU_Statics::NewProp_SphereRadius = { "SphereRadius", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARadarHDU, SphereRadius), METADATA_PARAMS(Z_Construct_UClass_ARadarHDU_Statics::NewProp_SphereRadius_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARadarHDU_Statics::NewProp_SphereRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARadarHDU_Statics::NewProp_RadarDistanceScale_MetaData[] = {
		{ "Category", "Radar" },
		{ "Comment", "/*La escala de distancia de los actores del radar*/" },
		{ "ModuleRelativePath", "RadarHDU.h" },
		{ "ToolTip", "La escala de distancia de los actores del radar" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ARadarHDU_Statics::NewProp_RadarDistanceScale = { "RadarDistanceScale", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ARadarHDU, RadarDistanceScale), METADATA_PARAMS(Z_Construct_UClass_ARadarHDU_Statics::NewProp_RadarDistanceScale_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ARadarHDU_Statics::NewProp_RadarDistanceScale_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ARadarHDU_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARadarHDU_Statics::NewProp_RadarStartLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARadarHDU_Statics::NewProp_RadarRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARadarHDU_Statics::NewProp_DegreeStep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARadarHDU_Statics::NewProp_DrawPixelSize,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARadarHDU_Statics::NewProp_SphereHeight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARadarHDU_Statics::NewProp_SphereRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ARadarHDU_Statics::NewProp_RadarDistanceScale,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ARadarHDU_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UIObserverRadar_NoRegister, (int32)VTABLE_OFFSET(ARadarHDU, IIObserverRadar), false },
		};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARadarHDU_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARadarHDU>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ARadarHDU_Statics::ClassParams = {
		&ARadarHDU::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ARadarHDU_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ARadarHDU_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ARadarHDU_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ARadarHDU_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ARadarHDU()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ARadarHDU_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ARadarHDU, 3847884438);
	template<> ADAPTERPATERN1_API UClass* StaticClass<ARadarHDU>()
	{
		return ARadarHDU::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ARadarHDU(Z_Construct_UClass_ARadarHDU, &ARadarHDU::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("ARadarHDU"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARadarHDU);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

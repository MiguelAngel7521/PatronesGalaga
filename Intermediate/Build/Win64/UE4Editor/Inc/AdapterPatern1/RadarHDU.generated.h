// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ADAPTERPATERN1_RadarHDU_generated_h
#error "RadarHDU.generated.h already included, missing '#pragma once' in RadarHDU.h"
#endif
#define ADAPTERPATERN1_RadarHDU_generated_h

#define AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_SPARSE_DATA
#define AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_RPC_WRAPPERS
#define AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesARadarHDU(); \
	friend struct Z_Construct_UClass_ARadarHDU_Statics; \
public: \
	DECLARE_CLASS(ARadarHDU, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/AdapterPatern1"), NO_API) \
	DECLARE_SERIALIZER(ARadarHDU) \
	virtual UObject* _getUObject() const override { return const_cast<ARadarHDU*>(this); }


#define AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_INCLASS \
private: \
	static void StaticRegisterNativesARadarHDU(); \
	friend struct Z_Construct_UClass_ARadarHDU_Statics; \
public: \
	DECLARE_CLASS(ARadarHDU, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/AdapterPatern1"), NO_API) \
	DECLARE_SERIALIZER(ARadarHDU) \
	virtual UObject* _getUObject() const override { return const_cast<ARadarHDU*>(this); }


#define AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARadarHDU(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARadarHDU) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARadarHDU); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARadarHDU); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARadarHDU(ARadarHDU&&); \
	NO_API ARadarHDU(const ARadarHDU&); \
public:


#define AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARadarHDU(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ARadarHDU(ARadarHDU&&); \
	NO_API ARadarHDU(const ARadarHDU&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARadarHDU); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARadarHDU); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARadarHDU)


#define AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__RadarStartLocation() { return STRUCT_OFFSET(ARadarHDU, RadarStartLocation); } \
	FORCEINLINE static uint32 __PPO__RadarRadius() { return STRUCT_OFFSET(ARadarHDU, RadarRadius); } \
	FORCEINLINE static uint32 __PPO__DegreeStep() { return STRUCT_OFFSET(ARadarHDU, DegreeStep); } \
	FORCEINLINE static uint32 __PPO__DrawPixelSize() { return STRUCT_OFFSET(ARadarHDU, DrawPixelSize); } \
	FORCEINLINE static uint32 __PPO__SphereHeight() { return STRUCT_OFFSET(ARadarHDU, SphereHeight); } \
	FORCEINLINE static uint32 __PPO__SphereRadius() { return STRUCT_OFFSET(ARadarHDU, SphereRadius); } \
	FORCEINLINE static uint32 __PPO__RadarDistanceScale() { return STRUCT_OFFSET(ARadarHDU, RadarDistanceScale); }


#define AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_12_PROLOG
#define AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_PRIVATE_PROPERTY_OFFSET \
	AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_SPARSE_DATA \
	AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_RPC_WRAPPERS \
	AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_INCLASS \
	AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_PRIVATE_PROPERTY_OFFSET \
	AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_SPARSE_DATA \
	AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_INCLASS_NO_PURE_DECLS \
	AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADAPTERPATERN1_API UClass* StaticClass<class ARadarHDU>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AdapterPatern1_4_27_Source_AdapterPatern1_RadarHDU_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

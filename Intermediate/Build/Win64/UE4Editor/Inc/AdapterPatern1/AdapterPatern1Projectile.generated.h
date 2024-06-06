// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef ADAPTERPATERN1_AdapterPatern1Projectile_generated_h
#error "AdapterPatern1Projectile.generated.h already included, missing '#pragma once' in AdapterPatern1Projectile.h"
#endif
#define ADAPTERPATERN1_AdapterPatern1Projectile_generated_h

#define AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_SPARSE_DATA
#define AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAdapterPatern1Projectile(); \
	friend struct Z_Construct_UClass_AAdapterPatern1Projectile_Statics; \
public: \
	DECLARE_CLASS(AAdapterPatern1Projectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AdapterPatern1"), NO_API) \
	DECLARE_SERIALIZER(AAdapterPatern1Projectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAAdapterPatern1Projectile(); \
	friend struct Z_Construct_UClass_AAdapterPatern1Projectile_Statics; \
public: \
	DECLARE_CLASS(AAdapterPatern1Projectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AdapterPatern1"), NO_API) \
	DECLARE_SERIALIZER(AAdapterPatern1Projectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AAdapterPatern1Projectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AAdapterPatern1Projectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAdapterPatern1Projectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAdapterPatern1Projectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAdapterPatern1Projectile(AAdapterPatern1Projectile&&); \
	NO_API AAdapterPatern1Projectile(const AAdapterPatern1Projectile&); \
public:


#define AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAdapterPatern1Projectile(AAdapterPatern1Projectile&&); \
	NO_API AAdapterPatern1Projectile(const AAdapterPatern1Projectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAdapterPatern1Projectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAdapterPatern1Projectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAdapterPatern1Projectile)


#define AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ProjectileMesh() { return STRUCT_OFFSET(AAdapterPatern1Projectile, ProjectileMesh); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AAdapterPatern1Projectile, ProjectileMovement); }


#define AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_12_PROLOG
#define AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_PRIVATE_PROPERTY_OFFSET \
	AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_SPARSE_DATA \
	AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_RPC_WRAPPERS \
	AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_INCLASS \
	AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_PRIVATE_PROPERTY_OFFSET \
	AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_SPARSE_DATA \
	AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_INCLASS_NO_PURE_DECLS \
	AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADAPTERPATERN1_API UClass* StaticClass<class AAdapterPatern1Projectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AdapterPatern1_Source_AdapterPatern1_AdapterPatern1Projectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

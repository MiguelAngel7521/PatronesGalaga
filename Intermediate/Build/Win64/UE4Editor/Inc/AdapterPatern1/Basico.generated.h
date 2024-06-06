// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ADAPTERPATERN1_Basico_generated_h
#error "Basico.generated.h already included, missing '#pragma once' in Basico.h"
#endif
#define ADAPTERPATERN1_Basico_generated_h

#define AdapterPatern1_Source_AdapterPatern1_Basico_h_13_SPARSE_DATA
#define AdapterPatern1_Source_AdapterPatern1_Basico_h_13_RPC_WRAPPERS
#define AdapterPatern1_Source_AdapterPatern1_Basico_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define AdapterPatern1_Source_AdapterPatern1_Basico_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABasico(); \
	friend struct Z_Construct_UClass_ABasico_Statics; \
public: \
	DECLARE_CLASS(ABasico, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AdapterPatern1"), NO_API) \
	DECLARE_SERIALIZER(ABasico) \
	virtual UObject* _getUObject() const override { return const_cast<ABasico*>(this); }


#define AdapterPatern1_Source_AdapterPatern1_Basico_h_13_INCLASS \
private: \
	static void StaticRegisterNativesABasico(); \
	friend struct Z_Construct_UClass_ABasico_Statics; \
public: \
	DECLARE_CLASS(ABasico, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/AdapterPatern1"), NO_API) \
	DECLARE_SERIALIZER(ABasico) \
	virtual UObject* _getUObject() const override { return const_cast<ABasico*>(this); }


#define AdapterPatern1_Source_AdapterPatern1_Basico_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABasico(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABasico) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABasico); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABasico); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABasico(ABasico&&); \
	NO_API ABasico(const ABasico&); \
public:


#define AdapterPatern1_Source_AdapterPatern1_Basico_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABasico(ABasico&&); \
	NO_API ABasico(const ABasico&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABasico); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABasico); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABasico)


#define AdapterPatern1_Source_AdapterPatern1_Basico_h_13_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Jugador() { return STRUCT_OFFSET(ABasico, Jugador); }


#define AdapterPatern1_Source_AdapterPatern1_Basico_h_10_PROLOG
#define AdapterPatern1_Source_AdapterPatern1_Basico_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AdapterPatern1_Source_AdapterPatern1_Basico_h_13_PRIVATE_PROPERTY_OFFSET \
	AdapterPatern1_Source_AdapterPatern1_Basico_h_13_SPARSE_DATA \
	AdapterPatern1_Source_AdapterPatern1_Basico_h_13_RPC_WRAPPERS \
	AdapterPatern1_Source_AdapterPatern1_Basico_h_13_INCLASS \
	AdapterPatern1_Source_AdapterPatern1_Basico_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AdapterPatern1_Source_AdapterPatern1_Basico_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AdapterPatern1_Source_AdapterPatern1_Basico_h_13_PRIVATE_PROPERTY_OFFSET \
	AdapterPatern1_Source_AdapterPatern1_Basico_h_13_SPARSE_DATA \
	AdapterPatern1_Source_AdapterPatern1_Basico_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	AdapterPatern1_Source_AdapterPatern1_Basico_h_13_INCLASS_NO_PURE_DECLS \
	AdapterPatern1_Source_AdapterPatern1_Basico_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADAPTERPATERN1_API UClass* StaticClass<class ABasico>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AdapterPatern1_Source_AdapterPatern1_Basico_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

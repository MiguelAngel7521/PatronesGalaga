// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ADAPTERPATERN1_INaveEnemigaVisitor_generated_h
#error "INaveEnemigaVisitor.generated.h already included, missing '#pragma once' in INaveEnemigaVisitor.h"
#endif
#define ADAPTERPATERN1_INaveEnemigaVisitor_generated_h

#define AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_SPARSE_DATA
#define AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_RPC_WRAPPERS
#define AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_RPC_WRAPPERS_NO_PURE_DECLS
#define AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADAPTERPATERN1_API UINaveEnemigaVisitor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UINaveEnemigaVisitor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADAPTERPATERN1_API, UINaveEnemigaVisitor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UINaveEnemigaVisitor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADAPTERPATERN1_API UINaveEnemigaVisitor(UINaveEnemigaVisitor&&); \
	ADAPTERPATERN1_API UINaveEnemigaVisitor(const UINaveEnemigaVisitor&); \
public:


#define AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADAPTERPATERN1_API UINaveEnemigaVisitor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADAPTERPATERN1_API UINaveEnemigaVisitor(UINaveEnemigaVisitor&&); \
	ADAPTERPATERN1_API UINaveEnemigaVisitor(const UINaveEnemigaVisitor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADAPTERPATERN1_API, UINaveEnemigaVisitor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UINaveEnemigaVisitor); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UINaveEnemigaVisitor)


#define AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUINaveEnemigaVisitor(); \
	friend struct Z_Construct_UClass_UINaveEnemigaVisitor_Statics; \
public: \
	DECLARE_CLASS(UINaveEnemigaVisitor, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/AdapterPatern1"), ADAPTERPATERN1_API) \
	DECLARE_SERIALIZER(UINaveEnemigaVisitor)


#define AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_GENERATED_UINTERFACE_BODY() \
	AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_GENERATED_UINTERFACE_BODY() \
	AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IINaveEnemigaVisitor() {} \
public: \
	typedef UINaveEnemigaVisitor UClassType; \
	typedef IINaveEnemigaVisitor ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_INCLASS_IINTERFACE \
protected: \
	virtual ~IINaveEnemigaVisitor() {} \
public: \
	typedef UINaveEnemigaVisitor UClassType; \
	typedef IINaveEnemigaVisitor ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_10_PROLOG
#define AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_SPARSE_DATA \
	AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_RPC_WRAPPERS \
	AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_SPARSE_DATA \
	AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h_14_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADAPTERPATERN1_API UClass* StaticClass<class UINaveEnemigaVisitor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AdapterPatern1_Source_AdapterPatern1_INaveEnemigaVisitor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

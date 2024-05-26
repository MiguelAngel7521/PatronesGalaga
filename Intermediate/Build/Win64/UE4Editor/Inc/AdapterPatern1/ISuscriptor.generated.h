// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ADAPTERPATERN1_ISuscriptor_generated_h
#error "ISuscriptor.generated.h already included, missing '#pragma once' in ISuscriptor.h"
#endif
#define ADAPTERPATERN1_ISuscriptor_generated_h

#define AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_SPARSE_DATA
#define AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_RPC_WRAPPERS
#define AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_RPC_WRAPPERS_NO_PURE_DECLS
#define AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADAPTERPATERN1_API UISuscriptor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UISuscriptor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADAPTERPATERN1_API, UISuscriptor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UISuscriptor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADAPTERPATERN1_API UISuscriptor(UISuscriptor&&); \
	ADAPTERPATERN1_API UISuscriptor(const UISuscriptor&); \
public:


#define AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	ADAPTERPATERN1_API UISuscriptor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADAPTERPATERN1_API UISuscriptor(UISuscriptor&&); \
	ADAPTERPATERN1_API UISuscriptor(const UISuscriptor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(ADAPTERPATERN1_API, UISuscriptor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UISuscriptor); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UISuscriptor)


#define AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUISuscriptor(); \
	friend struct Z_Construct_UClass_UISuscriptor_Statics; \
public: \
	DECLARE_CLASS(UISuscriptor, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/AdapterPatern1"), ADAPTERPATERN1_API) \
	DECLARE_SERIALIZER(UISuscriptor)


#define AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_GENERATED_BODY_LEGACY \
		PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_GENERATED_UINTERFACE_BODY() \
	AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_STANDARD_CONSTRUCTORS \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_GENERATED_UINTERFACE_BODY() \
	AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IISuscriptor() {} \
public: \
	typedef UISuscriptor UClassType; \
	typedef IISuscriptor ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_INCLASS_IINTERFACE \
protected: \
	virtual ~IISuscriptor() {} \
public: \
	typedef UISuscriptor UClassType; \
	typedef IISuscriptor ThisClass; \
	virtual UObject* _getUObject() const { check(0 && "Missing required implementation."); return nullptr; }


#define AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_10_PROLOG
#define AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_SPARSE_DATA \
	AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_RPC_WRAPPERS \
	AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_INCLASS_IINTERFACE \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_SPARSE_DATA \
	AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ADAPTERPATERN1_API UClass* StaticClass<class UISuscriptor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AdapterPatern1_Source_AdapterPatern1_ISuscriptor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS

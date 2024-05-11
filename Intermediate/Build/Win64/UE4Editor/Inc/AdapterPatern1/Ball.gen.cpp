// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AdapterPatern1/Ball.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBall() {}
// Cross Module References
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ABall_NoRegister();
	ADAPTERPATERN1_API UClass* Z_Construct_UClass_ABall();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AdapterPatern1();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UProjectileMovementComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ABall::execGetBall)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UStaticMeshComponent**)Z_Param__Result=P_THIS->GetBall();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABall::execEnableCollision)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EnableCollision();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABall::execSetVelocity)
	{
		P_GET_STRUCT_REF(FVector,Z_Param_Out_NewVelocity);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetVelocity(Z_Param_Out_NewVelocity);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABall::execCalculateReflectionVelocity)
	{
		P_GET_STRUCT_REF(FVector,Z_Param_Out_CurrentVelocity);
		P_GET_STRUCT_REF(FVector,Z_Param_Out_SurfaceNormal);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->CalculateReflectionVelocity(Z_Param_Out_CurrentVelocity,Z_Param_Out_SurfaceNormal);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABall::execOnOverlapBegin)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
		P_GET_UBOOL(Z_Param_bFromSweep);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
		P_NATIVE_END;
	}
	void ABall::StaticRegisterNativesABall()
	{
		UClass* Class = ABall::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CalculateReflectionVelocity", &ABall::execCalculateReflectionVelocity },
			{ "EnableCollision", &ABall::execEnableCollision },
			{ "GetBall", &ABall::execGetBall },
			{ "OnOverlapBegin", &ABall::execOnOverlapBegin },
			{ "SetVelocity", &ABall::execSetVelocity },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics
	{
		struct Ball_eventCalculateReflectionVelocity_Parms
		{
			FVector CurrentVelocity;
			FVector SurfaceNormal;
			FVector ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentVelocity_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CurrentVelocity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SurfaceNormal_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SurfaceNormal;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::NewProp_CurrentVelocity_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::NewProp_CurrentVelocity = { "CurrentVelocity", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Ball_eventCalculateReflectionVelocity_Parms, CurrentVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::NewProp_CurrentVelocity_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::NewProp_CurrentVelocity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::NewProp_SurfaceNormal_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::NewProp_SurfaceNormal = { "SurfaceNormal", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Ball_eventCalculateReflectionVelocity_Parms, SurfaceNormal), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::NewProp_SurfaceNormal_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::NewProp_SurfaceNormal_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Ball_eventCalculateReflectionVelocity_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::NewProp_CurrentVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::NewProp_SurfaceNormal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//Cuando colisiona\n" },
		{ "ModuleRelativePath", "Ball.h" },
		{ "ToolTip", "Cuando colisiona" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABall, nullptr, "CalculateReflectionVelocity", nullptr, nullptr, sizeof(Ball_eventCalculateReflectionVelocity_Parms), Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C40401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABall_CalculateReflectionVelocity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABall_CalculateReflectionVelocity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABall_EnableCollision_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABall_EnableCollision_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//Establecer la velocidad\n" },
		{ "ModuleRelativePath", "Ball.h" },
		{ "ToolTip", "Establecer la velocidad" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABall_EnableCollision_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABall, nullptr, "EnableCollision", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABall_EnableCollision_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABall_EnableCollision_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABall_EnableCollision()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABall_EnableCollision_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABall_GetBall_Statics
	{
		struct Ball_eventGetBall_Parms
		{
			UStaticMeshComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABall_GetBall_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABall_GetBall_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Ball_eventGetBall_Parms, ReturnValue), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ABall_GetBall_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABall_GetBall_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABall_GetBall_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABall_GetBall_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABall_GetBall_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Ball.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABall_GetBall_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABall, nullptr, "GetBall", nullptr, nullptr, sizeof(Ball_eventGetBall_Parms), Z_Construct_UFunction_ABall_GetBall_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABall_GetBall_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABall_GetBall_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABall_GetBall_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABall_GetBall()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABall_GetBall_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABall_OnOverlapBegin_Statics
	{
		struct Ball_eventOnOverlapBegin_Parms
		{
			UPrimitiveComponent* OverlappedComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SweepResult;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Ball_eventOnOverlapBegin_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_OverlappedComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_OverlappedComponent_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Ball_eventOnOverlapBegin_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Ball_eventOnOverlapBegin_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Ball_eventOnOverlapBegin_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((Ball_eventOnOverlapBegin_Parms*)Obj)->bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Ball_eventOnOverlapBegin_Parms), &Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Ball_eventOnOverlapBegin_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_OverlappedComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::NewProp_SweepResult,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Ball.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABall, nullptr, "OnOverlapBegin", nullptr, nullptr, sizeof(Ball_eventOnOverlapBegin_Parms), Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABall_OnOverlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABall_OnOverlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABall_SetVelocity_Statics
	{
		struct Ball_eventSetVelocity_Parms
		{
			FVector NewVelocity;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_NewVelocity_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_NewVelocity;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABall_SetVelocity_Statics::NewProp_NewVelocity_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABall_SetVelocity_Statics::NewProp_NewVelocity = { "NewVelocity", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Ball_eventSetVelocity_Parms, NewVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_ABall_SetVelocity_Statics::NewProp_NewVelocity_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABall_SetVelocity_Statics::NewProp_NewVelocity_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABall_SetVelocity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABall_SetVelocity_Statics::NewProp_NewVelocity,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABall_SetVelocity_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//Calculo de la velocidad de rebote\n" },
		{ "ModuleRelativePath", "Ball.h" },
		{ "ToolTip", "Calculo de la velocidad de rebote" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABall_SetVelocity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABall, nullptr, "SetVelocity", nullptr, nullptr, sizeof(Ball_eventSetVelocity_Parms), Z_Construct_UFunction_ABall_SetVelocity_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABall_SetVelocity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C40401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABall_SetVelocity_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABall_SetVelocity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABall_SetVelocity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABall_SetVelocity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ABall_NoRegister()
	{
		return ABall::StaticClass();
	}
	struct Z_Construct_UClass_ABall_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SM_Ball_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SM_Ball;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileMovement_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ProjectileMovement;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CollisionBall_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CollisionBall;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABall_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AdapterPatern1,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABall_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABall_CalculateReflectionVelocity, "CalculateReflectionVelocity" }, // 4138117847
		{ &Z_Construct_UFunction_ABall_EnableCollision, "EnableCollision" }, // 1723362834
		{ &Z_Construct_UFunction_ABall_GetBall, "GetBall" }, // 306564735
		{ &Z_Construct_UFunction_ABall_OnOverlapBegin, "OnOverlapBegin" }, // 787443766
		{ &Z_Construct_UFunction_ABall_SetVelocity, "SetVelocity" }, // 2692329672
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABall_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Ball.h" },
		{ "ModuleRelativePath", "Ball.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABall_Statics::NewProp_SM_Ball_MetaData[] = {
		{ "Category", "Ball" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Ball.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABall_Statics::NewProp_SM_Ball = { "SM_Ball", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABall, SM_Ball), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABall_Statics::NewProp_SM_Ball_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABall_Statics::NewProp_SM_Ball_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABall_Statics::NewProp_ProjectileMovement_MetaData[] = {
		{ "Category", "Ball" },
		{ "Comment", "//Malla\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Ball.h" },
		{ "ToolTip", "Malla" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABall_Statics::NewProp_ProjectileMovement = { "ProjectileMovement", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABall, ProjectileMovement), Z_Construct_UClass_UProjectileMovementComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABall_Statics::NewProp_ProjectileMovement_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABall_Statics::NewProp_ProjectileMovement_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABall_Statics::NewProp_CollisionBall_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Ball" },
		{ "Comment", "//Movimiento del proyectil\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Ball.h" },
		{ "ToolTip", "Movimiento del proyectil" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABall_Statics::NewProp_CollisionBall = { "CollisionBall", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABall, CollisionBall), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABall_Statics::NewProp_CollisionBall_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABall_Statics::NewProp_CollisionBall_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABall_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABall_Statics::NewProp_SM_Ball,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABall_Statics::NewProp_ProjectileMovement,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABall_Statics::NewProp_CollisionBall,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABall_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABall>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABall_Statics::ClassParams = {
		&ABall::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ABall_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ABall_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABall_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABall_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABall()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABall_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABall, 3555787181);
	template<> ADAPTERPATERN1_API UClass* StaticClass<ABall>()
	{
		return ABall::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABall(Z_Construct_UClass_ABall, &ABall::StaticClass, TEXT("/Script/AdapterPatern1"), TEXT("ABall"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABall);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

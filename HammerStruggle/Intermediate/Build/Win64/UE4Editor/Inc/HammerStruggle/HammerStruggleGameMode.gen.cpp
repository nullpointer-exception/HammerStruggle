// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HammerStruggle/HammerStruggleGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHammerStruggleGameMode() {}
// Cross Module References
	HAMMERSTRUGGLE_API UClass* Z_Construct_UClass_AHammerStruggleGameMode_NoRegister();
	HAMMERSTRUGGLE_API UClass* Z_Construct_UClass_AHammerStruggleGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_HammerStruggle();
// End Cross Module References
	void AHammerStruggleGameMode::StaticRegisterNativesAHammerStruggleGameMode()
	{
	}
	UClass* Z_Construct_UClass_AHammerStruggleGameMode_NoRegister()
	{
		return AHammerStruggleGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AHammerStruggleGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHammerStruggleGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HammerStruggle,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHammerStruggleGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "HammerStruggleGameMode.h" },
		{ "ModuleRelativePath", "HammerStruggleGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHammerStruggleGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHammerStruggleGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHammerStruggleGameMode_Statics::ClassParams = {
		&AHammerStruggleGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AHammerStruggleGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AHammerStruggleGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHammerStruggleGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHammerStruggleGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHammerStruggleGameMode, 3693323183);
	template<> HAMMERSTRUGGLE_API UClass* StaticClass<AHammerStruggleGameMode>()
	{
		return AHammerStruggleGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHammerStruggleGameMode(Z_Construct_UClass_AHammerStruggleGameMode, &AHammerStruggleGameMode::StaticClass, TEXT("/Script/HammerStruggle"), TEXT("AHammerStruggleGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHammerStruggleGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

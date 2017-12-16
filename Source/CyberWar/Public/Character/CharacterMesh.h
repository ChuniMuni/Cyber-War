// Студия разработки игр Netlex.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/SkeletalMesh.h"
#include "CharacterMesh.generated.h"

UENUM(BlueprintType)
enum class ETeam : uint8
{
	Team_Red UMETA(DisplayName = "Red"),
	Team_Blue UMETA(DisplayName = "Blue")
};

USTRUCT(BlueprintType)
struct FCharacterMeshes
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
		USkeletalMesh* FirstPersonMesh;

	UPROPERTY(EditDefaultsOnly)
		USkeletalMesh* ThirdPersonMesh;

	UPROPERTY(EditDefaultsOnly)
		USkeletalMesh* LobbyPersonMesh;

	FCharacterMeshes()
	{
		FirstPersonMesh = NULL;
		ThirdPersonMesh = NULL;
		LobbyPersonMesh = NULL;
	}
};

USTRUCT(BlueprintType)
struct FCharacterInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
		FText Name;

	UPROPERTY(EditDefaultsOnly)
		UTexture2D* Icon;

	UPROPERTY(EditDefaultsOnly)
		int Gender;

	UPROPERTY(EditDefaultsOnly)
		FText Description;

	FCharacterInfo()
	{
		Name = FText::GetEmpty();
		Icon = nullptr;
		Gender = 0;
		Description = FText::GetEmpty();
	}
};

/**
 * Базовый класс для персонажей.
 */

UCLASS(Blueprintable)
class CYBERWAR_API UCharacterMesh : public UObject
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
		ETeam Team;
	
	UPROPERTY(EditDefaultsOnly)
		FCharacterMeshes Meshes;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UAnimInstance> AnimInstance;

	UPROPERTY(EditDefaultsOnly)
		FCharacterInfo Info;

};

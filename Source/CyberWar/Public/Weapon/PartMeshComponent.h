// Студия разработки игр Netlex.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PartMesh.h"
#include "PartMeshComponent.generated.h"

struct FDefaultPartMesh
{
	EPartType Type;
	USkeletalMeshComponent* MeshComponent;

	FDefaultPartMesh()
	{
		Type = EPartType::PartType_Body1;
		MeshComponent = NULL;
	}
};

struct FSocketPartMesh
{
	EPartType Type;
	USkeletalMeshComponent* MeshComponent;
	FName Socket;

	FSocketPartMesh()
	{
		Type = EPartType::PartType_Body1;
		MeshComponent = NULL;
		Socket = "None";
	}
};

struct FSelectedPart
{
	EPartType Type;
	int32 Id;

	FSelectedPart()
	{
		Type = EPartType::PartType_Body1;
		Id = 0;
	}
};

UCLASS( ClassGroup=(Weapon), meta=(BlueprintSpawnableComponent) )
class CYBERWAR_API UPartMeshComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UPartMeshComponent();
	void UpdatePartsComponents();
	void UpdateParts(TArray<FSelectedPart> IndexSelectedParts, TArray<TSubclassOf<UPartMesh>> Parts);

	TArray<TSubclassOf<UPartMesh>> PartsInfo;
	TArray<FSelectedPart> SelectedParts;

	bool IsThirdPerson;

protected:
	
	virtual void BeginPlay() override;

	TArray<FDefaultPartMesh> DefaultParts;
	TArray<FSocketPartMesh> SocketParts;


private:


public:	
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};

// Студия разработки игр Netlex.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PartMeshComponent.h"
#include "PartMesh.h"
#include "Weapon.generated.h"

UCLASS()
class CYBERWAR_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AWeapon();

	TArray<FSelectedPart> SelectedParts;

	UPROPERTY(Category = Parts, EditDefaultsOnly)
		TArray<TSubclassOf<UPartMesh>> Parts;

protected:
	
	virtual void BeginPlay() override;

private:

	// UPROPERTY(Category = Parts, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UPartMeshComponent* FirstPersonParts;
		UPartMeshComponent* ThirdPersonParts;

public:	
	
	virtual void Tick(float DeltaTime) override;

	
	
};

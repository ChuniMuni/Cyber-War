// Студия разработки игр Netlex.

#include "PartMeshComponent.h"
#include "PartMesh.h"
#include "Components/SkeletalMeshComponent.h"


UPartMeshComponent::UPartMeshComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	bAutoActivate = true;
}

void UPartMeshComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UPartMeshComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}

void UPartMeshComponent::UpdateParts(TArray<FSelectedPart> IndexSelectedParts, TArray<TSubclassOf<UPartMesh>> Parts)
{
	SelectedParts = IndexSelectedParts;
	PartsInfo = Parts;
	UpdatePartsComponents();
}

void UPartMeshComponent::UpdatePartsComponents()
{
	for (int i = 0; i < PartsInfo.Num(); i++)
	{
		if (PartsInfo[i].GetDefaultObject()->Meshes[SelectedParts[i].Id].Socket == "None")
		{

			if (!DefaultParts[i].MeshComponent)
				DefaultParts[i].MeshComponent = NewObject<USkeletalMeshComponent>(GetOwner());

			if (IsThirdPerson)
				DefaultParts[i].MeshComponent->SetSkeletalMesh(PartsInfo[i].GetDefaultObject()->Meshes[SelectedParts[i].Id].ThirdPersonMesh);
			else
				DefaultParts[i].MeshComponent->SetSkeletalMesh(PartsInfo[i].GetDefaultObject()->Meshes[SelectedParts[i].Id].FirstPersonMesh);

			DefaultParts[i].Type = PartsInfo[i].GetDefaultObject()->PartType;

		}
		else
		{
			if (!SocketParts[i].MeshComponent)
				SocketParts[i].MeshComponent = NewObject<USkeletalMeshComponent>(GetOwner());

			if (IsThirdPerson)
				SocketParts[i].MeshComponent->SetSkeletalMesh(PartsInfo[i].GetDefaultObject()->Meshes[SelectedParts[i].Id].ThirdPersonMesh);
			else
				SocketParts[i].MeshComponent->SetSkeletalMesh(PartsInfo[i].GetDefaultObject()->Meshes[SelectedParts[i].Id].FirstPersonMesh);

			SocketParts[i].Type = PartsInfo[i].GetDefaultObject()->PartType;
		}

	}
}

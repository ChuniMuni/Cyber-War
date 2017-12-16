// Студия разработки игр Netlex.

#include "Weapon.h"
#include "PartMeshComponent.h"


AWeapon::AWeapon()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	FirstPersonParts = CreateDefaultSubobject<UPartMeshComponent>("FirstPersonParts");
	ThirdPersonParts = CreateDefaultSubobject<UPartMeshComponent>("ThirdPersonParts");
	ThirdPersonParts->IsThirdPerson = true;
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


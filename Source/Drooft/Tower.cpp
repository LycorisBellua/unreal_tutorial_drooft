// Lycoris Bellua © All Rights Reserved

#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (InFireRange())
		RotateTurret(Tank->GetActorLocation(), DeltaTime);
}

void ATower::CheckFireCondition()
{
	if (InFireRange())
		Fire();
}

bool ATower::InFireRange()
{
	float Distance;

	if (!Tank)
		return false;

	Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
	return Distance <= FireRange;
}

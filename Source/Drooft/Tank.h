// Lycoris Bellua © All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

UCLASS()
class DROOFT_API ATank : public ABasePawn
{
	GENERATED_BODY()
	
public:
	ATank();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed = 300.f;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate = 45.f;

	UWorld* World = nullptr;
	APlayerController* PlayerControllerRef;

	void Move(float Value);
	void Turn(float Value);
};

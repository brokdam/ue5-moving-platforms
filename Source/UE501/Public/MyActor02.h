#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor02.generated.h"

UCLASS()
class UE501_API AMyActor02 : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActor02();

protected:
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	float RotationSpeed;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};

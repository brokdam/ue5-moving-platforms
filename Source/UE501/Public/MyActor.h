#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class UE501_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActor();

protected:
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	// 이동 관련 변수들 추가
	FVector MoveVelocity;
	float MaxRange;

private: 
	// 왕복 기준점 저장용 변수
	FVector StartLocation;
};

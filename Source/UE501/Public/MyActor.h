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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* StaticMeshComp;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	// 이동 관련 변수들 추가
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Translation")
	FVector MoveVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|Translation")
	float MaxRange;

private: 
	// 왕복 기준점 저장용 변수
	FVector StartLocation;
};

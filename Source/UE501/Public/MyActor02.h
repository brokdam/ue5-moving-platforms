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
	//virtual void BeginPlay() override;
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	//public:	
		//virtual void Tick(float DeltaTime) override;

};

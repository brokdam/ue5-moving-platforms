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
	//virtual void BeginPlay() override;
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	//public:	
		//virtual void Tick(float DeltaTime) override;

};

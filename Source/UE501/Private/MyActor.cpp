#include "MyActor.h"

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Shapes/Shape_Sphere.Shape_Sphere"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Burnished_Steel.M_Metal_Burnished_Steel"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	// 이동 기본값 설정
	MoveVelocity = FVector(200.0f, 0.0f, 0.0f);
	MaxRange = 500.0f;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	FVector NewLocation(0.0f);
	FRotator NewRotation(0.0f);
	SetActorScale3D(FVector(50.0f));

	// 게임 시작 시점의 현재 위치를 이동 기준점으로 저장
	StartLocation = GetActorLocation();
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 매 프레임 이동 로직 적용
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (MoveVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);

	// 시작 위치로부터 얼마나 멀어졌는지 계산
	float DistanceMoved = FVector::Distance(StartLocation, CurrentLocation);

	// 설정한 한계치 넘어가면 방향을 반전시킴
	if (DistanceMoved >= MaxRange)
	{
		MoveVelocity = -MoveVelocity; 

		// 정확한 왕복을 위해 시작 위치 갱신
		FVector MoveDirection = MoveVelocity.GetSafeNormal();
		StartLocation = StartLocation + (-MoveDirection * MaxRange);
	}
}

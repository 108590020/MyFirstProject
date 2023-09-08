// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorLevel.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
AActorLevel::AActorLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyScene = CreateDefaultSubobject<USceneComponent>(TEXT("MyScene"));
	/*RootComponent: 每個 Actor 都有一個默認的 RootComponent; 它用來儲存物體的基礎信息。
	它可以被改變。這是 AActor 的一個成員，用於保存 AActor 組件樹中的頂級組件*/
	RootComponent = MyScene;

	//添加靜態網格體，用來顯示物體的形狀
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->SetupAttachment(MyScene);

	/*添加粒子組件
	MyParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MyParticle"));
	MyParticle->SetupAttachment(MyMesh);*/

	//添加聲音組件
	MyAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("MyAudio"));
	MyAudio->SetupAttachment(MyMesh);

	//添加盒體組件，做碰撞檢測
	MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBoxComponent"));
	MyBoxComponent->SetupAttachment(MyMesh);
}

// Called when the game starts or when spawned
void AActorLevel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActorLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


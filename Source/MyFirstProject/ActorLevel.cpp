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
	/*RootComponent: �C�� Actor �����@���q�{�� RootComponent; ���Ψ��x�s���骺��¦�H���C
	���i�H�Q���ܡC�o�O AActor ���@�Ӧ����A�Ω�O�s AActor �ե�𤤪����Ųե�*/
	RootComponent = MyScene;

	//�K�[�R�A������A�Ψ���ܪ��骺�Ϊ�
	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->SetupAttachment(MyScene);

	/*�K�[�ɤl�ե�
	MyParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MyParticle"));
	MyParticle->SetupAttachment(MyMesh);*/

	//�K�[�n���ե�
	MyAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("MyAudio"));
	MyAudio->SetupAttachment(MyMesh);

	//�K�[����ե�A���I���˴�
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


/*
�H A �}�Y�����O�i�H��m�b���������A�H U �}�Y�����O�ե�u��̪����L�ե󤣯��W��m�������
Actor �M �ե� �����Y: �ե�i�H����� Actor ���W�A���O����W�ߥX�{�b�������C

*/
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorLevel.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class UAudioComponent;
class UBoxComponent;


UCLASS()
class MYFIRSTPROJECT_API AActorLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*SceneComponents �O�֦��ܴ��� ActorComponents�C�ܴ��O����������m�A�Ѧ�m�B����B�M�Y��w�q�C
	SceneComponent ��H�h�Ū��覡�ۤ����[�C Actor ����m�B����B�M�Y����ۦ��h�Ůڳ��� SceneComponent�C*/
	USceneComponent* MyScene;

	UPROPERTY(EditAnywhere, Category = "MyMesh")
	UStaticMeshComponent* MyMesh;

	/*UPROPERTY(EditAnywhere, Category = "MyMesh")
	UParticleSystemComponent* MyParticle;*/

	UPROPERTY(EditAnywhere, Category = "MyAudio")
	UAudioComponent* MyAudio;

	UPROPERTY(EditAnywhere, Category = "Box")
	UBoxComponent* MyBoxComponent;
};

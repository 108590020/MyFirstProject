/*
以 A 開頭的都是可以放置在場景中的，以 U 開頭的都是組件只能依附於其他組件不能單獨放置到場景中
Actor 和 組件 的關係: 組件可以附件到 Actor 身上，但是不能獨立出現在場景中。

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

	/*SceneComponents 是擁有變換的 ActorComponents。變換是場景中的位置，由位置、旋轉、和縮放定義。
	SceneComponent 能以層級的方式相互附加。 Actor 的位置、旋轉、和縮放取自位於層級根部的 SceneComponent。*/
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

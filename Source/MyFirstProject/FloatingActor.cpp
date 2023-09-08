/*Super::
���եΤ�������ơA�A�եΦۨ������
�եΤ������Ѽƪ��c�y��k�A�]������b�l�����c�y��k (������k���i�H) �̭��A
�åB�u���b�c�y��k�����y�C �䤤x,y,z�O���P���������ѳy��k���ѼƼƾ������۹������l�������Ѽ�
*/


#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//�Ыث��V�Ӳե󪺫��w
	//�ЫإX�Ӳե�åB��a�}���ȵ��ڭ̪����w
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//�R�A��������[��ڲե�W
	VisualMesh->SetupAttachment(RootComponent);

	//ConstructorHelpers �O ObjectBase.h ���w�q���S��R�W�Ŷ� �Ҧp���귽�����M��ޥΡB�H�γЫبôM��ե󪺧U��ҪO�C
	//�R�A�����]�t�@���n���ҪO���c��

	//�h�귽��󧨤U�d��@�Ӹ귽�[��
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//�����e�����m
	FVector NewLocation = GetActorLocation();
	//�����e�������
	FRotator NewRotation = GetActorRotation();
	//�����e����B��ɶ�
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
	float DeltaRotation = DeltaTime * 20.0f;    //Rotate by 20 degrees per second
	NewRotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewLocation, NewRotation);
}


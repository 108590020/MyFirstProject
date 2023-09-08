/*Super::
先調用父類的函數，再調用自身的函數
調用父類有參數的構造方法，也必須放在子類的構造方法 (成員方法不可以) 裡面，
並且只能放在構造方法的首句。 其中x,y,z是指與父類此有參造方法中參數數據類型相對應的子類中的參數
*/


#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//創建指向該組件的指針
	//創建出來組件並且把地址附值給我們的指針
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//靜態網格體附加到根組件上
	VisualMesh->SetupAttachment(RootComponent);

	//ConstructorHelpers 是 ObjectBase.h 中定義的特殊命名空間 例如為資源或類尋找引用、以及創建並尋找組件的助手模板。
	//靜態類中包含一個聲明模板結構體

	//去資源文件夾下查找一個資源加載
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

	//獲取當前物體位置
	FVector NewLocation = GetActorLocation();
	//獲取當前物體旋轉
	FRotator NewRotation = GetActorRotation();
	//獲取當前物體運行時間
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
	float DeltaRotation = DeltaTime * 20.0f;    //Rotate by 20 degrees per second
	NewRotation.Yaw += DeltaRotation;
	SetActorLocationAndRotation(NewLocation, NewRotation);
}


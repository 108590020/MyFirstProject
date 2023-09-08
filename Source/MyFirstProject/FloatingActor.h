/*
1.#include "CoreMinimal.h"
CoreMinimal 頭文件包含一套來自於 UE 核心編程環境的普遍存在類型(包括 FString、FName、TArray等)
CoreMinimal 頭文件原本包含所有編程所需要的頭文件，為減輕負擔分為 stdio.h(輸入、輸出)、stdlib.h(記憶體相關)
CoreMinimal 頭文件類似 C++ 的 iostream

2.#include "GameFramework/Actor.h"
創建 C++ class 時選擇以 Actor 為父類，因為是基於 Actor 生成的源代碼，所以默認包含 Actor 頭文件

3.#include "FloatingActor.generated.h"
UE 將生成所有反射數據並放入該文件中。
必須將該文件作為聲明類型的標頭文件中的最後一個包含語句，將其包含進去。它必須在最下方。

UE 反射機制:
反射是指在運行狀態下，任意一個實體類都能夠知道這個類的所有屬性和方法;
對於任意一個對象，都能夠調用它的任何方法和屬性，這種動態獲取信息以及動態調用對象方法的功能稱為語言的反射

4.UCLASS()
標示符，標記為類，以便於 UE 編程系統所識別

5.class MYFIRSTPROJECT_API AFloatingActor : public AActor
語法 => (class ProjectName_API derived-class: access-specifier base-class)
MYFIRSTPROJECT_API 為命名空間

6.GENERATED_BODY()
生成此項目時 UE 幫忙生成許多代碼，編譯時會將 GENERATED_BODY() 替換為 UE 為我們生成的代碼，類似 C++ 的 macro

7.
*/

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class MYFIRSTPROJECT_API AFloatingActor : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	//默認構造函數
	AFloatingActor();

	//將變量公開到編輯器或藍圖
	//VisibleAnywhere 修飾符設置該屬性為在任何地方都可見
	UPROPERTY(VisibleAnywhere)
	// UStaticMeshComponent 靜態網格體組件，用來顯示物體
	UStaticMeshComponent* VisualMesh;

protected:
	// Called when the game starts or when spawned
	//遊戲一開始調用函數
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//每幀調用
	virtual void Tick(float DeltaTime) override;

};

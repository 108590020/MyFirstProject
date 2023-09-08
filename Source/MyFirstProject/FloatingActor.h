/*
1.#include "CoreMinimal.h"
CoreMinimal �Y���]�t�@�M�Ӧ۩� UE �֤߽s�{���Ҫ����M�s�b����(�]�A FString�BFName�BTArray��)
CoreMinimal �Y���쥻�]�t�Ҧ��s�{�һݭn���Y���A����t����� stdio.h(��J�B��X)�Bstdlib.h(�O�������)
CoreMinimal �Y������� C++ �� iostream

2.#include "GameFramework/Actor.h"
�Ы� C++ class �ɿ�ܥH Actor �������A�]���O��� Actor �ͦ������N�X�A�ҥH�q�{�]�t Actor �Y���

3.#include "FloatingActor.generated.h"
UE �N�ͦ��Ҧ��Ϯg�ƾڨé�J�Ӥ�󤤡C
�����N�Ӥ��@���n�����������Y��󤤪��̫�@�ӥ]�t�y�y�A�N��]�t�i�h�C�������b�̤U��C

UE �Ϯg����:
�Ϯg�O���b�B�檬�A�U�A���N�@�ӹ�������������D�o�������Ҧ��ݩʩM��k;
�����N�@�ӹ�H�A������եΥ��������k�M�ݩʡA�o�ذʺA����H���H�ΰʺA�եι�H��k���\��٬��y�����Ϯg

4.UCLASS()
�ХܲšA�аO�����A�H�K�� UE �s�{�t�Ω��ѧO

5.class MYFIRSTPROJECT_API AFloatingActor : public AActor
�y�k => (class ProjectName_API derived-class: access-specifier base-class)
MYFIRSTPROJECT_API ���R�W�Ŷ�

6.GENERATED_BODY()
�ͦ������خ� UE �����ͦ��\�h�N�X�A�sĶ�ɷ|�N GENERATED_BODY() ������ UE ���ڭ̥ͦ����N�X�A���� C++ �� macro

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
	//�q�{�c�y���
	AFloatingActor();

	//�N�ܶq���}��s�边���Ź�
	//VisibleAnywhere �׹��ų]�m���ݩʬ��b����a�賣�i��
	UPROPERTY(VisibleAnywhere)
	// UStaticMeshComponent �R�A������ե�A�Ψ���ܪ���
	UStaticMeshComponent* VisualMesh;

protected:
	// Called when the game starts or when spawned
	//�C���@�}�l�եΨ��
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//�C�V�ե�
	virtual void Tick(float DeltaTime) override;

};

//˳���ľ�̬�洢
#include<stdio.h>
#include"malloc.h"
#include<stdlib.h>
#define _CRT_SECURE_NO_DEPRECATE
#define N 1
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType array[N];//�������鳤��
	size_t size;//��Ч���ݵĸ���
}SeqList;


//˳���Ķ�̬����
//typedef struct SeqList
//{
//	SLDataType* array;//ָ��̬���ٵ�����
//	size_t size;//��Ч���ݸ���
//	size_t capacity;//�����ռ�Ĵ�С
//}SeqList;
//˳���ĳ�ʼ��

void SeqListInit(SeqList* ps1)
{
	ps1 = (SeqList*)malloc(sizeof(SeqList));
	ps1->size = 0;
	for (int i = 0; i <N; i++)
	{
		ps1->array[i] = 0;//��ʼ��˳����е�ֵ����ֵΪ0
	}

}
//����һ��˳���
void CreateSeqList(SeqList* ps1)
{
	int i;
	printf("�����������뼸�����֣�");
	scanf_s("%d", &i);
	if (i<1 ||i>N)
	{
		printf("��������");

	}
	else
	{
		for (int j = 0; j<i; j++)
		{
			int num;
			printf("������һ�����֣�");
			scanf_s("%d", &num);
			ps1->array[j] = num;
			ps1->size++;
		}
	}
}
int main()
{

	SeqList *ps1=0;
	SeqListInit(ps1);
	 CreateSeqList(ps1);
};

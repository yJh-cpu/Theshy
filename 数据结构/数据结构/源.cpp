//顺序表的静态存储
#include<stdio.h>
#include"malloc.h"
#include<stdlib.h>
#define _CRT_SECURE_NO_DEPRECATE
#define N 1
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType array[N];//定义数组长度
	size_t size;//有效数据的个数
}SeqList;


//顺序表的动态储存
//typedef struct SeqList
//{
//	SLDataType* array;//指向动态开辟的数组
//	size_t size;//有效数据个数
//	size_t capacity;//容量空间的大小
//}SeqList;
//顺序表的初始化

void SeqListInit(SeqList* ps1)
{
	ps1 = (SeqList*)malloc(sizeof(SeqList));
	ps1->size = 0;
	for (int i = 0; i <N; i++)
	{
		ps1->array[i] = 0;//初始化顺序表中的值，赋值为0
	}

}
//创建一个顺序表
void CreateSeqList(SeqList* ps1)
{
	int i;
	printf("请问您想输入几个数字：");
	scanf_s("%d", &i);
	if (i<1 ||i>N)
	{
		printf("输入有误");

	}
	else
	{
		for (int j = 0; j<i; j++)
		{
			int num;
			printf("请输入一个数字：");
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

#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char arr[100];
	int lean = sizeof(arr) / sizeof(arr[0]);
	scanf("%s", &arr);
	char cunchu[1000];
	for (int i = 0; i < lean - 1; i++)
	{
		cunchu[i] = arr[lean - 1];
		lean = lean - 1; 
		//printf("%s", cunchu[i]);
	}
	printf("%s",cunchu);
	system("pause");
	return 0;
}
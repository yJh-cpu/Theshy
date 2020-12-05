#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10];
		for (int i = 0; i <10; i++)
		{
			scanf_s("%d", &a[i]);
		}
		int max = a[0];
		for (int i = 1; i <10; i++)
		{
			 max=max>a[i] ? max : a[i];
		}
		printf("%d", max);
		system("pause");
		return 0;
}
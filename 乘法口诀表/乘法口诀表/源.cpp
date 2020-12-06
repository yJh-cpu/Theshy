#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a;
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j <=i; j++)
		{
			a = i*j;
			printf("%d*%d=%d\t", i, j, a);
		}
		printf("\n");
	}
	system("pause");

	return 0;

}
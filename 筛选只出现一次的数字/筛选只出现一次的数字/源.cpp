#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
int main()b 
{
	int arry[10] = {4,1,4,6};
	/*for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arry[i]);
	}*/
	int ret = 0;
	for (int i = 0; i < 10; i++)
	{
		ret ^= arry[i];
	}
	int n = 1;
	while ((ret&n) == 0)
	{
		n << 1 == 1;
	}
	int a = 0;
	int b = 0;
	for (int i = 0; i < 10; i++)
	{
		if ((arry[i] & n) == 0)
		{
			a ^= arry[i];
		}
		else
		{
			b ^= arry[i];
		}
	}
	printf("%d%d", a, b);
	system("pause");
	return 0;
}
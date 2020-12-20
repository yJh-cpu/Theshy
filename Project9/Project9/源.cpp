#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 1;
for (; i <= 100; i++)
{
	if (i % 3 == 0)
	{
		printf("%d\n", i);

	}
}
	system("pause");

}
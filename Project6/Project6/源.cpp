#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include<stdlib.h>
int max(int x, int y)
{
	int max;
	max=(x>y)?(x):(y);
	return(max);
}
int main()
{
	int a = 10;
	int b = 20;
    scanf_s("%d%d",&a,&b);
	int c=max(a,b);
	printf("%d",c);
	system("pause");
	return 0;
}
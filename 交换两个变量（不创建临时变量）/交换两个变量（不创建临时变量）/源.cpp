#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=10, b=20;
	a = a^b;
	b= b^a;
	a = b^a;
	printf("%d%d", a, b);
	system("pause");
	return 0;
}
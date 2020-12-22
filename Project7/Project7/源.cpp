#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
int max(int x, int y)
{
	int max;
	return(max)=x ? y : x, y;
}
int min(int x, int y)
{
	int min;
	return(min) = x < y; x, y;
}
int main()
{
	    int a = 3,
		int b = 4; 
	     int c = 5;
		int d;
		int e;
	    int g;
	scanf_s("%d%d%d", a, b,c);
	g = min(a, b);
	d = max(a, b);
	e=max(d, c);
	system ("pause");
	printf("%d%d%d", e, d, g);
}
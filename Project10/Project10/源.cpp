#include <stdio.h>
#include<stdlib.h>
int main()
{
	int a=6;
	int b=10;
	int c;
	c = (a > b) ? b : a;  
	while (c > 0)
	{
		if (a%c != 0 || b%c != 0)
		{
		c--;
	    }
		else
		{
			break;
		}
}
	printf("最大公约数是：%d\n", c);
	system("pause");
	return 0;
 }
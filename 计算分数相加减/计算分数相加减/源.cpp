#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i, temp, a, sum = 0;
	for (i = 1; i <= 100; i++)
	{
		temp = pow(-1.0, i + 1);
		sum = sum + (1 / i)*(temp);
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}
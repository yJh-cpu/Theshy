#include<stdio.h>

#include<stdlib.h>

int main()

{

	int i;

	for (i = 1; i <= 100; i++)

	{

		if (i % 10 == 9 || i / 10 == 9)

		{

			printf("%d\n", i);

		}

		else

			continue;

	}

	system("pause");

	return 0;

}
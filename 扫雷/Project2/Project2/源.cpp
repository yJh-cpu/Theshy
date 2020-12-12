#include <stdio.h>
int main()
{
	int arr[] = { 1, 2, (3, 4), 5 };
	printf("%d\n", sizeof(arr));
	return 0;
}
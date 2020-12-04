#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int key=7;
	int mid;
	while (left <= right){
	 mid = (left + right) / 2;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
			break;
	}
	if (left <= right)
	{
		printf("%d\n", mid);
	}
	else
		printf("Ã»ÕÒµ½\n");
	system("pause");
	return 0;
}
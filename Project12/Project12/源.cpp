#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int lean;
	char arr[6] = {"hello"};
	char arr1[5] = { 'h','e','l','l','o' };
	lean=strlen(arr);
	printf("%d", lean);
	printf("%d", sizeof(arr));
	printf("%d", sizeof(arr1));
	system("pause");
	return 0;
}
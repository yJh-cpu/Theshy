#include<stdio.h>
#include<stdlib.h>
int main()
{
	char arr1[] = "bit";
	char arr2[4] = { 'b', 'i', 't' };
	char arr3[] = { 'b', 'i' ,'t', '\0' };
	char c[] = { 'I', ' ', 'a', 'm', ' ', 'h', 'a', 'p', 'p', 'y', '\0'};
	printf("%s\n", c);
	printf("%s\n", arr1);
	printf("%s\n", arr2);
	printf("%s\n", arr3);
	system("pause");
	return 0;
}

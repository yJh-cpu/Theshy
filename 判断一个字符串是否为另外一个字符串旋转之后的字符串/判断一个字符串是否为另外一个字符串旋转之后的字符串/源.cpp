#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
int strRoundStr(char* src, char* a){
	char tmp[256] = { 0 };
	strcpy(tmp, src);
	strcat(tmp, src);
	return strstr(tmp, a) != NULL;
}
int main()
{
	char src[] = "ABCDEFG";
	char a[] = "GA";
	printf("%d\n", strRoundStr(src, a));
	char a1[] = "GAa";
	printf("%d\n", strRoundStr(src,a1));
	system("pause");
	return 0;
}
#include<stdio.h>
#include<string.h>

int substr(char* , char*);
int main()
{
	printf("Enter a string\n");
	char s[100];
	char sub[100];
	scanf("%[^\n]s",s);
	fflush(stdin);
	printf("Enter the substring\n");
	scanf("%[^\n]s",sub);
	fflush(stdin);
	if(substr(s,sub))
		printf("substring found\n");
	else
		printf("substring not found\n");
	return 0;
}

int substr(char* str, char* sub)
{
	int lenstr = strlen(str);
	int lensub = strlen(sub);

	if(lensub>lenstr)
		return 0;

	else if(strncmp(str,sub,lensub)==0)
		return 1;

	else
		return substr(str+1,sub);
}
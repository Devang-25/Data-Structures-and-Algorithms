#include<stdio.h>
int main(void)
{
	char a[]={'A','B','C','D'};
	char *ppp=&a[0];
	*ppp++;
	printf("%c %c " ,*++ppp,--*ppp);
	return 0;
}

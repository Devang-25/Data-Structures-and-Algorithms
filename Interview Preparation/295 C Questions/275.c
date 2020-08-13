#include<stdio.h>
#include<stdlib.h>
main()
{
	struct test
	{
		double c;
		int y;
	} t1;
	int x;
	char y;
	printf("int=%d    char = %d \n",sizeof(x),sizeof(y));
	printf("%d %d\n",sizeof(t1), sizeof(t1.c));
}
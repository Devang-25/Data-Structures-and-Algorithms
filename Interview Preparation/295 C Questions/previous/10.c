#include<stdio.h>
//# include <conio.h>
int i=	2;
main()
{
	void add();
//	clrscr();
	add(i++,--i);
    printf("\ni=%d \n",i);
}
void add(int a ,int b)
{
	printf("\na=%d b=%d",a,b);
}

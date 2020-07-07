#include<stdio.h>
#define DEF
#define YES 1
#define NO 0
main()
{
int j;
#ifdef DEF
	j=YES;
#else
	j=NO;
#endif
printf("j=%d",j);
}

#include<stdio.h>
static struct s
{
	unsigned a:1;
	unsigned b:1;
	unsigned c:1;
	unsigned d:1;
}v={3,2,3,4};
main()
{
	printf("%u\n%u\n%u\n%u\n",v.a,v.b,v.c,v.d);
	printf("size of v = %d",sizeof(v));
}
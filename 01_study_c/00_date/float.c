/********
介绍c语言浮点型变量
********/

#include <stdio.h>

int main(int argc, char **argv)
{
	int a;
	int b;
	double c;
	
	a = 12;
	b = 23;
	c = 3.1415926785123584;
	//printf("c= %d\n",c);
	printf("c= %.18f\n",c);
	return 0;
}
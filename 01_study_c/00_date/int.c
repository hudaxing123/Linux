/********
介绍c语言整形变量
********/

#include <stdio.h>

int main(int argc, char **argv)
{
	int a;
	int b;
	float c;
	
	a = 12;
	b = 23;
	c = b/a;
	//printf("c= %d\n",c);
	printf("c= %.2f\n",c);
	return 0;
}
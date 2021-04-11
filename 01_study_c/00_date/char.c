/********
介绍c语言字符型型变量
********/

#include <stdio.h>

int main(int argc, char **argv)
{
	char d = 'A';
	printf("d = %d, d= %c\n",d,d);
	
	d = d+5;
	printf("d = %d, d= %c\n",d,d);
	
	return 0;
}
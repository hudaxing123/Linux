/********
说明：介绍C语言的程序结构
作者：小柠檬
时间：2021-04-21
作用：实现选择结构和循环结构
功能：实现从1+2……100
********/

#include <stdio.h>

int main(int argc, char **argv)
{
	int a, sum; 
	a = 1;
	sum = 0;
	
	for(a=1; a<100; a++)
	{
		sum = sum + a;	
	}
	printf("sum = %d\r\n",sum);	
	
	return 0;
}
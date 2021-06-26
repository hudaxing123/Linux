/********
说明：介绍C语言的程序结构
作者：小柠檬
时间：2021-06-26
作用：实现选择结构和循环结构
功能：0-100的奇数和
********/

#include <stdio.h>

int main(int argc, char **argv)
{
	int i,sum = 0;
		
	for(i=1; i<100; i+=2)
	{
		sum = sum + i;
		printf("i = %d\r\n",i);	
	
	}

	printf("sum = %d\r\n",sum);	
	
	return 0;
}
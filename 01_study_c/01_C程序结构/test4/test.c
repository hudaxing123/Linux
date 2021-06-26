/********
说明：介绍C语言的程序结构
作者：小柠檬
时间：2021-06-26
作用：实现选择结构和循环结构，采用while的方式来实现
功能：100以内的奇数和
********/

#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 1, value = 1;
		
	do
	{
		printf("i = %d\r\n",i);
		i += 2;
		value += i;     //更加普遍的写法
		//printf("i = %c\r\n",i);	   //打印出对应的ASCII表	
	}while(i<101);

	printf("value = %d\r\n",value);	
	
	return 0;
}
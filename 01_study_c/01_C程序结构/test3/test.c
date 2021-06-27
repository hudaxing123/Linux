/********
说明：介绍C语言的程序结构
作者：小柠檬
时间：2021-06-26
作用：实现选择结构和循环结构
功能：1-10的阶乘（1*2*3……*10）
********/

#include <stdio.h>

int main(int argc, char **argv)
{
	int i,value = 1;
		
	for(i=1; i<11; i++)
	{
		value *= i;     //更加普遍的写法
		printf("i = %d\r\n",i);
		//printf("i = %c\r\n",i);	   //打印出对应的ASCII表	
	}

	printf("value = %d\r\n",value);	
	
	return 0;
}
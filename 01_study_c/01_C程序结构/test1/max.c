/********
说明：介绍C语言的程序结构
作者：小柠檬
时间：2021-06-26
作用：实现选择结构和循环结构
功能：实现从三个数中输出最大的,暂未考虑数值相等的情况
********/

#include <stdio.h>

int main(int argc, char **argv)
{
	int a,b,c,max; 
	a = 1;
	b = 123;
	c = 23;
	
	if(a > b)
	{
		if(a > c)
		{
			max = a;  //a最大
		}
		else
		{
			max = c;  //c最大
		}
	}
	else
	{
		if(b > c)
		{
			max = b;  //b最大
		}
		else
		{
			max = c; //c最大
		}
				
	}
	
	printf("max = %d\r\n",max);	
	
	return 0;
}
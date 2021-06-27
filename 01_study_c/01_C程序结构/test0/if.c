/********
说明：介绍C语言的程序结构
作者：小柠檬
时间：2021-04-11
作用：实现选择结构和循环结构
********/

#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b, max;    //需要考虑大于、小于以及等于的情况
	
	a = 123;
	b = 123;
	
	if(a > b)   //如果布尔型返回1，执行代码1，否则执行代码2
	{
		max = a; //执行代码1
		printf("max = %d\r\n", max);
	}
	else if (a == b)
	{
		max = a;
		printf("max = %d\r\n", max);
		printf("a 等于 b\r\n");
	}
	else
	{
		max = b;  //执行代码2
		printf("max = %d\r\n", max);
	}
		
	return 0;
}
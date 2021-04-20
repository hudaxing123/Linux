/********
说明：介绍C语言的++和--
作者：小柠檬
时间：2021-04-11
作用：实现自增和自减
********/

#include <stdio.h>

int main(int argc, char **argv)
{
	int a, b;
	
	a = 2;
	++a;
	printf("a= %d\n", a);
	
	a = 2;
	a += 1;
	printf("a= %d\n", a);	//a=3 
	
	a = 2;
	b = a++;     //先赋值在++,
	printf("b= %d\n", b);   //b=2
	printf("a= %d\n", a);   //a=3
	
	a = 2;
	b = ++a;    //先执行++，在赋值
	printf("b= %d\n", b);	//b=3 
	printf("a= %d\n", a);   //a=3
	return 0;
}
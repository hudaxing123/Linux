#include <stdio.h>  
#include <stdarg.h>  

//方式一
#define DBG_PRINT (printf("%s:%u %s:%s:\t", __FILE__, __LINE__, __DATE__, __TIME__), printf) 

//方式二
void MyPrintf(const char *cmd, ...)  
{  
    printf("%s %s ", __DATE__, __TIME__);  
    va_list args;       //定义一个va_list类型的变量，用来储存单个参数  
    va_start(args,cmd); //使args指向可变参数的第一个参数  
    vprintf(cmd,args);  //必须用vprintf等带V的  
    va_end(args);       //结束可变参数的获取
    printf("\n");  
}  

int main()
{
    MyPrintf("%s", "hello world");
    MyPrintf("hello world");
    MyPrintf("%d %f", 15, 16.3);

    DBG_PRINT("%s", "hello world");
    DBG_PRINT("hello world");
    DBG_PRINT ("%d %f", 15, 16.3);
    return 0;
}
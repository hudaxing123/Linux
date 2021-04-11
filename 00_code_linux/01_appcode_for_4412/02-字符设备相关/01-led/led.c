//标准输入输出头文件
#include <stdio.h>

//文件操作函数头文件
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//定义led的数量
#define LED_NUM 2

//LED灯的状态
#define LED_C 2

//cmd 为0则灭，为1则亮
//IO为0则是靠近蜂鸣器，为1则靠近独立按键的小灯

int main (int argc,char *argv[])
{
	int fd,led_num,led_c;
	char *leds = "/dev/leds";
	
	led_num = LED_NUM;
	led_c = LED_C;
	//输入提示，第一个参数只能输入0，1
	printf("argv1 is cmd; argv2 is IO");
	if(atoi(argv[1]) >= led_c)
	{
		printf("argv1 is 0 or 1\n");
		exit(1);
	}
	if(atoi(argv[2]) >= led_num)
	{
		printf("argv2 is 0 or 1\n");
		exit(1);
	}
	//打开LED文件
	if((fd = open(leds,O_RDWR|O_NOCTTY|O_NDELAY))<0)
	{
		printf("Open %s failed!\n",leds);
	}
	else
	{
		ioctl(fd,atoi(argv[1]),atoi(argv[2]));
		printf("ioctl %s success\n",leds);
	}
	close(fd);
	
	return 0;
}




//定义寄存器的宏
#define GPX20CON   0X11000C40
#define GPX20DAT   0X11000C44

//定义访问寄存器

#define rGPX20CON  (*(volatile unsigned int *)GPX20CON)
#define rGPX20DAT  (*(volatile unsigned int *)GPX20DAT)


//初始化按键
void key_init(void)
{
	//配置GPX2的寄存器为输入模式
	//将bit0-3全部设置成0即可,左移4位取反
	rGPX20CON &= ~(0xf0<<4);	
}

void key_polling(void)
{
	//依次读取GPIO的 状态是0还是1
	while(1)   //轮询的读取led的状态
	{
	
		if(rGPX20DAT & (1<<0))    //1左移0位，判断bit0是不是1
		{
			//为1，说明没有按键
			led_off();
		}
		else
		{
			//为0，说明有按键
			led1();		
		}
	}
}

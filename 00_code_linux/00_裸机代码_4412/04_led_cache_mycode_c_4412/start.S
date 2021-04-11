/***
*	说明：基于itop 4412开发板实现裸机的led功能
*      	  参考朱老师的视频来操作
*	作者：胡大星
*   时间：2021-03-04
*   功能：开关icache来测试led灯的效果
*	说明：汇编语言中实现icache的开关
*   预期结果：打开icache后运行速度会加快，关闭后运行变慢
*
****/


#define WTCON  0x10060000

//用宏定义实现寄存器的控制
.global _start      //把_start链接属性改为外部，消除链接时的警告
_start:
		
	ldr r0, =WTCON   //关闭看门狗,WTCON bit5写0
	ldr r1, =0x0
	str r1, [r0]    //完成关看门狗
	
	ldr	sp, =0x02050000   //设置SVC栈
	
	//开&关icache 
	mrc p15,0,r0,c1,c0,0   //读出cp15寄存器的c1到r0中
	
	//bic	r0, r0, #0x00001000    //bit 12置0 关icache
	//bic	r0, r0, #(1<<12)   //效果等同与上面
	
	
	//orr	r0, r0, #0x00001000   //bit 12置1 开icache
	orr	r0, r0, #(1<<12)
	mcr	p15, 0, r0, c1, c0, 0
	
	//从这之后就可以调用c程序了
	
	
 bl led_blink    //要调用的c程序

 b .      //汇编最后的死循环不能丢

	
	

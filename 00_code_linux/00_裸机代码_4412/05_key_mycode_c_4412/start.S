/***
*	说明：基于itop 4412开发板实现裸机的key功能
*      	  参考朱老师的视频来操作
*	作者：胡大星
*   时间：2021-03-03
*   功能：在led的基础上实现，按键点亮led的功能
*	说明：汇编语言启动c语言的过程
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
	
	//从这之后就可以调用c程序了
	
	
 // bl led_blink    //要调用的c程序
 bl key_init
 bl key_polling

 b .      //汇编最后的死循环不能丢

	
	

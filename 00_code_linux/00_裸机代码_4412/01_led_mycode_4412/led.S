/***
*	说明：基于itop 4412开发板实现裸机的led功能
*      	  参考朱老师的视频来操作
*	作者：胡大星
*   时间：2021-02-21
*   功能：实现LED灯的闪烁
*
****/
#define GPL2CON  0x11000100
#define GPL2DAT  0x11000104

#define GPK1CON  0x11000060
#define GPK1DAT  0x11000064

//用宏定义实现寄存器的控制
.global _start      //把_start链接属性改为外部，消除链接时的警告
_start:

	
	//LED2控制寄存器操作
	//控制GPL2_0为输出，把相应的寄存器写入对应的值，r1为寄存器地址，r0为写入的数据
	ldr r0, =0x00000001
	ldr r1, =GPL2CON
	str  r0, [r1]            //将r0中的值写入到r1中区去
	
	//LED3控制寄存器操作
	
	//控制GPIO为输出，把相应的寄存器写入对应的值，GPK1_1
	ldr r0, =0x00000010		  //配置为输出模式
	ldr r1, =GPK1CON		  //GPK1CON基地址
	str  r0, [r1]             //将r0中的值写入到r1中区去

flash:                     //该语句与后面的b. flash 搭配实现while(1)的循环效果
	
	//写对用的数据寄存器，控制哪个LED灯亮

	ldr r0, =0x1             //可以点亮LED
	ldr r1, =GPL2DAT
	str  r0, [r1]
	
	//以上实现了LED点亮
	bl delay               //延时
	
	ldr r0, =0x10000000            //熄灭LED
	ldr r1, =GPL2DAT
	str  r0, [r1]
	
	//以上实现了LED灭
	bl delay               //延时

	
	//写对用的数据寄存器，控制哪个LED3灯亮
	//ldr r0, =0x2              //对应的二进制：00000010 转换成16进制0x20
							  //升级一下，使用位运算的方式来实现
	ldr r0, =1<<1
	ldr r1, =GPK1DAT
	str  r0, [r1]
	
	bl delay 
	
	ldr r0, =0<<1
	ldr r1, =GPK1DAT
	str  r0, [r1]
	
	bl delay 
	
bl  flash        //最后一句的b.可以去掉了
//	b .                //.代表当前只一句指令的地址，与下面两条指令效果一致
//flag:
//	b flag   		   //b跳转指令，跳转到flag,形成死循环
	
//汇编指令结束后都要来一段，类似于死循环，防止程序跑飞，仅仅是死循环，不等于while(1)

//延时函数的实现，用一些没有目的代码来实现延时
delay:
	ldr r2, =0x2000000      //直接写成数据延时函数不生效，要加0x。原因待确认
	ldr r3, =0x0
	
delay_loop:
	sub r2, r2, #1                    //r2 = r2 -1
	cmp r2, r3                        //cmp会影响z标志位，如果r2等r3则z=1,下一句eq就会成，程序就不会执行
									  //下一行代码，直接跳到下下一行去执行。
	bne delay_loop								  
	mov pc, lr                        //函数调用返回
	
	
	
	
	
	
	
	
	

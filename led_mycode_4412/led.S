/***
*	说明：基于itop 4412开发板实现裸机的led功能
*      	  参考朱老师的视频来操作
*	作者：胡大星
*   时间：2021-02-21
*
*
****/
#define GPL2CON  0x11000100
#define GPL2DAT  0x11000104

#define GPK1CON  0x11000060
#define GPK1DAT  0x11000064

//用宏定义实现寄存器的控制
.global _start      //把_start链接属性改为外部，消除链接时的警告
_start:

	//控制GPL2_0为输出，把相应的寄存器写入对应的值，r1为寄存器地址，r0为写入的数据
	ldr r0, =0x00000001
	ldr r1, =GPL2CON
	str  r0, [r1]            //将r0中的值写入到r1中区去
	
	//写对用的数据寄存器，控制哪个LED灯亮
	//ldr r0, =0x10000000     //不可以点亮LED	
	ldr r0, =0x1             //可以点亮LED
	ldr r1, =GPL2DAT
	str  r0, [r1]
	
	
	//控制GPIO为输出，把相应的寄存器写入对应的值，GPK1_1
	ldr r0, =0x00000010		  //配置为输出模式
	ldr r1, =GPK1CON		  //GPK1CON基地址
	str  r0, [r1]             //将r0中的值写入到r1中区去
	
	//写对用的数据寄存器，控制哪个LED灯亮
	//ldr r0, =0x2              //对应的二进制：00000010 转换成16进制0x20
							  //升级一下，使用位运算的方式来实现
	ldr r0, =1<<1
	ldr r1, =GPK1DAT
	str  r0, [r1]
	
	b .                //.代表当前只一句指令的地址
//flag:
//	b flag   //b跳转指令，跳转到flag,形成死循环
	
//汇编指令结束后都要来一段，类似于死循环，反防止程序跑飞
	

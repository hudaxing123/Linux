/***
*	说明：基于itop 4412开发板实现裸机的led功能
*      	  参考朱老师的视频来操作
*	作者：胡大星
*
*
****/

_start:

	//控制GPIO为输出，把相应的寄存器写入对应的值，GPL2
	ldr r0, =0x10000000
	ldr r1, =0x21000000
	str  r0, [r1]            //将r0中的值写入到r1中区去
	
	//写对用的数据寄存器，控制哪个LED灯亮
	ldr r0, =0x10000000
	ldr r1, =0x11104000
	str  r0, [r1]
	
	
	//控制GPIO为输出，把相应的寄存器写入对应的值，GPK1
	ldr r0, =0x10000000
	ldr r1, =0x11600000
	str  r0, [r1]            //将r0中的值写入到r1中区去
	
	//写对用的数据寄存器，控制哪个LED灯亮
	ldr r0, =0x10000000
	ldr r1, =0x11640000
	str  r0, [r1]
	
	
flag:
	b flag   //b跳转指令，跳转到flag,形成死循环
	
//汇编指令结束后都要来一段，类似于死循环，反防止程序跑飞
	

////#define CONFIG_SYS_ICACHE_OFF  
//.global _start

//_start:
	////disable watch dog
	//ldr	r0, =0x10060000
      	//mov	r1, #0
      	//str	r1, [r0]

	////turn on icache
	//mrc	p15, 0, r0, c1, c0, 0
	////bic	r0, r0, #0x00002300	/* clear bits 13, 9:8 (--V- --RS) */
	////bic	r0, r0, #0x00000087	/* clear bits 7, 2:0 (B--- -CAM) */
	////orr	r0, r0, #0x00000002	/* set bit 2 (A) Align */
	////orr	r0, r0, #0x00001000	/* set bit 12 (I) I-Cache */
	
//#ifdef CONFIG_SYS_ICACHE_OFF
    	//// clear bit 12 (I) I-cache
    	//bic	r0, r0, #0x00001000
//#else
    	//// set bit 12 (I) I-cache
    	//orr	r0, r0, #0x00001000
//#endif
       //	mcr	p15, 0, r0, c1, c0, 0
	////mcr p15, 0, r0, c7, c5, 0	@ invalidate icache

	////set stack
	//ldr	sp, =0x02050000

	//bl	led_blink

//halt:
	//b halt


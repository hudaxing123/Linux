#define         GPL2CON         (*(volatile unsigned long *) 0x11000100)
#define         GPL2DAT         (*(volatile unsigned long *) 0x11000104)

#define 	GPK1CON 	(*(volatile unsigned long *) 0x11000060)
#define 	GPK1DAT		(*(volatile unsigned long *) 0x11000064)

//GPL2_0, GPK1_1

void delay(int r0)
{
    volatile int count = r0;
    while (count--)
        ;
}

void led_blink()
{
	GPL2CON = 0x00000001;
	GPK1CON = 0x00000010;
	
	while(1)							
	{
		GPL2DAT = 1;
		GPK1DAT = 0;
		delay(0x80000);
		GPL2DAT = 0;
		GPK1DAT = 0x2;
		delay(0x80000);
	}
}


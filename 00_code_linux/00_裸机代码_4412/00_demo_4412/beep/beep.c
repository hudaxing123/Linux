#define GPD0CON		(*(volatile unsigned long *) 0x114000A0)
#define GPD0DAT		(*(volatile unsigned long *) 0x114000A4)


void delay(int r0)
{
    volatile int count = r0;

    while (count--)
        ;
}

void main()
{
	GPD0CON = 0x00000001;
	
	while(1)							
	{
		GPD0DAT = 1;
		delay(0x80000);
		GPD0DAT = 0;
		delay(0x80000);
	}
}

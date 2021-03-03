beep.bin: start.o beep.o
	arm-none-linux-gnueabi-ld -Ttext 0x0 -o beep.elf $^
	arm-none-linux-gnueabi-objcopy -O binary beep.elf beep.bin
	arm-none-linux-gnueabi-objdump -D beep.elf > beep_elf.dis


%.o : %.S
	arm-none-linux-gnueabi-gcc -o $@ $< -c -nostdlib

%.o : %.c
	arm-none-linux-gnueabi-gcc -o $@ $< -c -nostdlib

clean:
	rm *.o *.elf *.bin *.dis  -f

key.bin: start.o key.o led.o
	arm-none-linux-gnueabi-ld -Ttext 0x0 -o key.elf $^
	arm-none-linux-gnueabi-objcopy -O binary key.elf key.bin
	arm-none-linux-gnueabi-objdump -D key.elf >key_elf.dis


%.o : %.S
	arm-none-linux-gnueabi-gcc -o $@ $< -c -nostdlib

%.o : %.c
	arm-none-linux-gnueabi-gcc -o $@ $< -c -nostdlib

clean:
	rm *.o *.elf *.bin *.dis  -f

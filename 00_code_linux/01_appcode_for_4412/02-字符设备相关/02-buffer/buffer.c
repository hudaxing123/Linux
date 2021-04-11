#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUZZER_C 2

int main(int argc,char *argv[])
{
	int fd,ret,buzzer_c;
	char *buzzer_ctl = "/dev/buzzer_ctl";
	buzzer_c = BUZZER_C;
	
	printf("start test buzzer\n");
	if(atoi(argv[1]) >= buzzer_c)
	{
		printf("argv[1] is 0 or 1\n");
		exit(1);
	}
	if((fd = open(buzzer_ctl, O_RDWR|O_NOCTTY|O_NDELAY))<0)
	{
		printf("open %s failed\n",buzzer_ctl); 
		exit(1);
	}
	ret = ioctl(fd,atoi(argv[1]),atoi(argv[2]));
	close(fd);
	
	return 0;
	
}
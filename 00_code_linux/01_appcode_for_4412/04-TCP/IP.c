#include <arpa/inet.h>
#include <stdio.h>

#define MYIP  "192.168.1.10"

int main (void)
{
	int ret = 0;
	struct in_addr_t addr = 0;
	
	//addr = inet_addr(MYIP);
	ret = inet_pton(AF_INET,MYIP,&in_addr_t);
	
	if(ret != 1)
	{
		printf("addr turn fail!\r\n");
		return -1;
	}
	printf("addr = 0x%x\r\n",addr.s_addr);

	return 0;
}
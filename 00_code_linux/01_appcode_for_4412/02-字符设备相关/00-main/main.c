#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
	int i,j;
	i = atoi(argv[1]);
	j = atoi(argv[2]);
	
	printf("the Program name is %s\n",argv[0]);
	
	printf("the command line has %d argument\n",argc);
	
	printf("%d,%d\n",i,j);
	
	return 0;
}
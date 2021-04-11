
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>     //write 函数头文件
#include <string.h>

#define MAX_SIZE 1000

void main ()
{
	int fd,fd1;    //定义句柄
	char *leds = "/dev/leds";  //定义文件，在绝对路径下面
	char *test1 = "bin/test1"; //路径下没有此文件，也可以直接新建
	char *test2 = "bin/test2"; //同上
	char *test3 = "bin/test3"; //同上
	char *testwrite = "bin/testwrite";	
	char buffer_write[] = "Hello Write Function!";
	char buffer_read[MAX_SIZE];
	ssize_t length_w,length_r = MAX_SIZE,ret;

	
	if((fd = open(leds,O_RDWR|O_NOCTTY|O_NDELAY))<0) //标准的语句,第一个参数：句柄。
	                                                 //第二个参数：文件操作
	{
		printf("open %s failed!\n",leds);		
	}
		printf("\n%s fd is %d\n",leds,fd);
	
	if((fd = open(test1,O_RDWR,0777))<0)
	{
		printf("open %s failed!\n",test1);		
	}
		printf("%s fd is %d\n",test1,fd);
	
	if((fd = open(test2,O_RDWR|O_CREAT,0777))<0)    //0_CREAT OPEN的时候不存在就新建
	{
		printf("open %s failed!\n",test2);		
	}
		printf("%s fd is %d\n",test2,fd);
		
	fd = creat(test3,0777);
	if(fd == -1)
	{	
		printf ("%s fd %d",test3,fd);
	}
	else
	{
		printf ("creat %s is OK! fd is %d\r\n",test3,fd);
	}
	
	if((fd1 = open(testwrite,O_RDWR|O_CREAT,0777))<0)
	{
		printf("open %s failed!\n",testwrite);		
	}
	length_w = write(fd1,buffer_write,strlen(buffer_write));
	if(length_w == -1)
	{
		perror ("write");
	}
		
	else{
		printf("Write Function OK!\n");
	}
	close(fd1);	
	
	if((fd1 = open(testwrite,O_RDWR|O_CREAT,0777))<0)
	{
		printf("open %s failed!\n",testwrite);
	}
	if(ret = read(fd1,buffer_read,length_r))
	{
		perror("read");
	}
	printf("Files Content is %s \n",buffer_read);
	close(fd1);

/*	
	if((fd1 = open(testwrite, O_RDWR|O_CREAT,0777))<0)
	{
		printf("open %s failed\n",testwrite); 
	}
	
	//将buffer写入fd文件
	length_w = write(fd1,buffer_write,strlen(buffer_write));
	if(length_w == -1)
	{
		perror("write");
	}
	else{
		printf("Write Function OK!\n");
	}
	close(fd1);
	*/
	printf("Hello World!\r\n");
		
}





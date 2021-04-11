/* ****Socket 编程*********************/
/*
 客户端编程
 1、建立Socket  socket(int domain, int type, int protocol)
 2、连接服务器      
 int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
 3、数据发送
 send(int sockfd, const void *buf, size_t len, int flags);
 4、数据接收
recv(int sockfd, void *buf, size_t len, int flags);

 
 注：该代码仅仅实现了基础的功能函数，并没有对函数的健壮性做相关的扩展。

*/

#include <stdio.h>
#include <sys/types.h>        
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

//#define Server_IP     "121.41.12.44"   //服务器开放的IP地址和端口号
//<<<<<<< HEAD
//#define Server_IP     "10.66.82.108"   //服务器开放的IP地址和端口号
#define Server_Port   6800     //定义服务器端口号
//=======
#define Server_IP     "10.77.50.10"   //服务器开放的IP地址和端口号
//#define Server_Port   6900     //定义服务器端口号
//>>>>>>> 40fd8c73ea7bdbc1c923b9c543d9d81f76ea9761

char tcp_send_buffer[100];


int main(void)
{
	int socket_tcp = 0;
	int connect_tcp = 0;
	int send_tcp = 0;

	
	struct sockaddr_in seraddr = {0};
	struct sockaddr_in cliaddr = {0};
	//Socket 创建Socket
	socket_tcp = socket( AF_INET, SOCK_STREAM , 0);  //IPV4、TCP
	if(-1 == socket_tcp)
	{
		perror ("socket_tcp");
		return -1;
	}
	printf("socket_tcp = %d\r\n",socket_tcp);
	
	//connect 连接服务器
	seraddr.sin_family = AF_INET;      //设置为IPV4
	seraddr.sin_port = htons(Server_Port);   //端口号，转成大端模式
	seraddr.sin_addr.s_addr = inet_addr(Server_IP);  //设置IP地址
	
	connect_tcp = connect(socket_tcp,(const struct sockaddr *)&seraddr,sizeof(seraddr));
	if(-1 == connect_tcp)
	{
		perror ("connect_tcp");
		return -1;
	}
	printf("connect_tcp Success! connect_tcp=%d\r\n",connect_tcp);
	
	//数据单次发送
	/*
	strcpy(tcp_send_buffer,"Hello TCP!");    //给发送缓冲区填写相关的数据   
	send_tcp = send(socket_tcp, tcp_send_buffer, strlen(tcp_send_buffer), 0);   //不能用sizeof(),不然后面的0都发出去了。
	if(-1 == send_tcp)
	{
		perror ("send_tcp");
		return -1;
	}
	printf("send_tcp byte num is: %d\r\n",send_tcp);
	*/
	
	//实现输入发送
	while(1)
	{
		printf("send tcp date:");
		scanf("%s\r\n",tcp_send_buffer);
		send_tcp = send(socket_tcp, tcp_send_buffer, strlen(tcp_send_buffer), 0);   //不能用sizeof(),不然后面的0都发出去了。
		if(-1 == send_tcp)
		{
			perror ("send_tcp");
			return -1;
		}
		printf("send_tcp byte num is: %d\r\n",send_tcp);		
	}
	
	
		
	
	return 0;
	
}
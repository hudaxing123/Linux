/* ****Socket 编程*********************/
/*
 服务端编程
 1、建立Socket  socket(int domain, int type, int protocol)
 2、绑定当前电脑的IP地址和端口号 
    bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
 3、listen 监听端口  
    int listen(int sockfd, int backlog);
 4、accept 阻塞等待客户端连接接入 
    int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

 5、

*/

#include <stdio.h>
#include <sys/types.h>        
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define Server_Port   6800     //定义服务器端口号
#define Server_IP     "10.66.82.108"   //定义服务器IP地址
#define listen_num    100             //等待的数量

char tcp_recive_buffer[100];

int main(void)
{
	int socket_tcp = 0;
	int bind_tcp = 0;
	int listen_tcp = 0;
	int accept_tcp = 0;
	int recvie_tcp = 0;
	socklen_t len = 0;
	
	struct sockaddr_in seraddr = {0};
	struct sockaddr_in cliaddr = {0};
	//Socket 创建Socket
	socket_tcp = socket( AF_INET, SOCK_STREAM , 0);  //IPV4、TCP
	if(-1 == socket_tcp)
	{
		perror ("socket_tcp");
		return -1;
	}
	printf("Socket_tcp = %d\r\n",socket_tcp);
	
	//bind  绑定IP地址和端口号	
	seraddr.sin_family = AF_INET;      //设置为IPV4
	seraddr.sin_port = htons(Server_Port);   //端口号，转成大端模式
	seraddr.sin_addr.s_addr = inet_addr(Server_IP);  //设置IP地址
	bind_tcp = bind(socket_tcp, (const struct sockaddr *)&seraddr, sizeof(seraddr));
	
	if(-1 == bind_tcp)
	{
		perror ("bind_tcp");
		return -1;
	}
	printf("bind_tcp Success!\r\n");
	
	//Listen 监听
	listen_tcp = listen(socket_tcp, listen_num);     //监听端口
	if(-1 == listen_tcp)
	{
		perror ("listen_tcp");
		return -1;
	}	
	printf("Listen_tcp Success! listen_tcp =%d\r\n",listen_tcp);
	
	//accept 阻塞等待客户端接入
	accept_tcp = accept(socket_tcp, (struct sockaddr *)&cliaddr, &len);
	if(-1 == accept_tcp)
	{
		perror ("accept_tcp");
		return -1;
	}	
	printf("accept_tcp Success!\r\n");
	
	//实现数据的单次接收
/*	recvie_tcp = recv(accept_tcp, tcp_recive_buffer, sizeof(tcp_recive_buffer),0);
	if(-1 == recvie_tcp)
	{
		perror ("recvie_tcp");
		return -1;
	}	
	printf("recvie_tcp Success is %s!\r\n",tcp_recive_buffer);
*/	
	while(1)
	{
		recvie_tcp = recv(accept_tcp, tcp_recive_buffer, sizeof(tcp_recive_buffer),0);
		memset(tcp_recive_buffer,0,sizeof(tcp_recive_buffer));
		if(-1 == recvie_tcp)
		{
			perror ("recvie_tcp");
			return -1;
		}	
		printf("recvie_tcp Success is %s!\r\n",tcp_recive_buffer);
	}	
	
	return 0;
	
}
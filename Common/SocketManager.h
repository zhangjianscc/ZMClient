#ifndef SOCKETMANGER_H
#define SOCKETMANGER_H
#include <winsock2.h>

#include <iostream>
#include <string>
#include "connection.h"
using namespace std;

#ifndef INVALID_SOCKET
#define INVALID_SOCKET (SOCKET)(~0)
#endif
#ifndef SOCKET_ERROR
#define SOCKET_ERROR -1
#endif
#ifndef SD_RECEIVE
#define SD_RECEIVE 0x00
#define SD_SEND 0x01
#define SD_BOTH 0x02
#endif

//user pre-compile identifiers
#define WSVERS MAKEWORD(2, 0)	 //winsock version 2.0
//#pragma comment(lib, "ws2_32.lib")

//这个类把Socket通信封装，connection.h是网上的代码，基本没有错误了
//这个类负责发送和接受
class SocketManager
{
private:
	WSADATA wsadata;
	string server;
	string port;
	SOCKET socket;

public:	
    SocketManager()
    {

    }
	~SocketManager(){
		try{
			shutdown(socket, SD_BOTH);
			closesocket(socket);
			WSACleanup();                            /* 卸载某版本的DLL */ 
		}catch(ConnException e){
			cout<<e.msg<<" 错误号 "<<e.err<<endl;
		}
	}
    //lianjiefuwuqi
    bool connetService(string server, string port);
	//发送数据
	bool sendMessage(const char* message);
	//接收数据，在buf数据结尾自动加上/0，注意buf的大小要比len大1以上
	int receive(char * buf, int len);
    Connection cn;
};
#endif // SOCKETMANGER_H

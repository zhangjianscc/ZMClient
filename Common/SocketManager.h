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

//������Socketͨ�ŷ�װ��connection.h�����ϵĴ��룬����û�д�����
//����ฺ���ͺͽ���
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
			WSACleanup();                            /* ж��ĳ�汾��DLL */ 
		}catch(ConnException e){
			cout<<e.msg<<" ����� "<<e.err<<endl;
		}
	}
    //lianjiefuwuqi
    bool connetService(string server, string port);
	//��������
	bool sendMessage(const char* message);
	//�������ݣ���buf���ݽ�β�Զ�����/0��ע��buf�Ĵ�СҪ��len��1����
	int receive(char * buf, int len);
    Connection cn;
};
#endif // SOCKETMANGER_H

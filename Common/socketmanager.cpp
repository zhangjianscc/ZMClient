#include "Common/SocketManager.h"

bool SocketManager::connetService(string server, string port)
{
    this->server = server;
    this->port = port;
    socket=INVALID_SOCKET;
    try{
        if (WSAStartup(WSVERS, &wsadata) != 0){   //启动某版本的DLL
            return false;
        }
        cn.makeConnect(server, port, "tcp");
        socket=cn.getSocket();
    }catch(ConnException e){
        cout<<e.msg<<" 错误号 "<<e.err<<endl;
        return false;
    }
    return true;
}
bool SocketManager::sendMessage(const char* message)
{
    /*try{
        if (WSAStartup(WSVERS, &wsadata) != 0){   //启动某版本的DLL
            return false;
        }
        cn.makeConnect(server, port, "tcp");
        socket=cn.getSocket();
        if(send(socket, message, (int)strlen(message), 0)==SOCKET_ERROR){
            return false;
        }
        return true;
    }catch(ConnException e){
        cout<<e.msg<<" 错误号 "<<e.err<<endl;
        return false;
    }*/
    if(send(socket, message, (int)strlen(message), 0)==SOCKET_ERROR){
        return false;
    }
    return true;
}


int SocketManager::receive(char * buf, int len){
    try{
        int charCount;			//recv character count	缓冲区200KB
        if(socket == INVALID_SOCKET || socket == SOCKET_ERROR)
            return -1;

        //recieve messages
        charCount = recv(socket, buf, len, 0);
        if( charCount != SOCKET_ERROR && charCount > 0) {
            buf[charCount] = '\0';		/* ensure null-termination	*/
        }
        return charCount;
    }catch(ConnException e){
        cout<<"error in receive.."<<endl;
        return -1;
    }
}

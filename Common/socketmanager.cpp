﻿#pragma once
#include "Common/SocketManager.h"

bool SocketManager::connetService(string server, string port)
{
        this->server = server;
        this->port = port;
        socket=INVALID_SOCKET;
        return true;
}
bool SocketManager::sendMessage(const char* message)
{
    try{
        if (WSAStartup(WSVERS, &wsadata) != 0){   /* 启动某版本的DLL */
            return false;
        }
        cn.makeConnect(server, port, "tcp");
        socket=cn.getSocket();
        if(send(socket, message, strlen(message), 0)==SOCKET_ERROR){
            return false;
        }
        return true;
    }catch(ConnException e){
        cout<<e.msg<<" 错误号 "<<e.err<<endl;
        return false;
    }
}


int SocketManager::receive(char * buf, int len){
    try{
        int	charCount;			/* recv character count		*/
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

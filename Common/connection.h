#ifndef CONNETION_H
#define CONNETION_H
#include <cstdlib>
#include <winsock2.h>
#include <string>

#include "conn_exception.h"

using std::string;

#ifndef	INADDR_NONE
#define	INADDR_NONE	0xffffffff
#endif	/* INADDR_NONE */

#ifndef SD_RECEIVE
#define SD_RECEIVE 0x00
#define SD_SEND 0x01
#define SD_BOTH 0x02
#endif

#define CONN_EXCEPTION 1

#define PASSIVE_SOCK 1
#define CONNECT_SOCK 2

#define DEFAULT_QLEN 50

typedef int SOCKET_TYPE;

//class connection
class Connection
{
public:
	Connection(){
		sock=INVALID_SOCKET;
		sock_type=0;
		qlen=DEFAULT_QLEN;
		host="localhost";
		service="service";
		protocal_type="tcp";
		portbase = 0;
	}

	~Connection(){
		shutdown(sock, SD_BOTH);
		closesocket(sock);
	}

	//make connect-socket
    bool makeConnect(const string &host, const string &service, const string &protocal);
    bool makeConnect(){
		return makeConnect(host, service, protocal_type);
	}
	//make passive-socket
    bool makePassive(const string &service, const string &transport, const int qlen);
    bool makePassive(){
		return makePassive(service, protocal_type, qlen);
	}

	//get protocal
    string getProtocal(){ return protocal_type; }

	//get socket type
    SOCKET_TYPE getSocketType(){ return sock_type; }

	//get socket
    SOCKET getSocket(){	return sock; }

    string getHost(){ return host; }
    string getService(){ return service; }
    string getPort(){ return service; }
    int getQueueLength(){ return qlen; }

protected:

private:
	SOCKET passivesock(const string &service, const string &transport, const int qlen);
	SOCKET connectsock(const string &host, const string &service, const string &transport );

private:
	SOCKET sock;
	SOCKET_TYPE sock_type;
	string protocal_type;
	string host;
	string service;
	int qlen;
	u_short	portbase;
};

#endif //CONNETION_H

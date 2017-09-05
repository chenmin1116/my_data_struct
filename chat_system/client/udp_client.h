#ifndef _UDP_CLIENT_H_
#define _UDP_CLIENT_H_

#include <iostream>
#include <map>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

class udp_client{
	public:
		udp_client(const std::string &_ip, const int &_port);
		int initClient();
		int recvData(std::string &outString);
		int sendData(std::string &inString);
		~udp_client();
	private:
		struct sockaddr_in server;
		int sock;
};

#endif










#ifndef _UDP_SERVER_H_
#define _UDP_SERVER_H_

#include <iostream>
#include <map>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "data_pool.h"

#define PSIZE 128

class udp_server{
	public:
		udp_server(const std::string &_ip, const int &_port);
		int initServer();
		int recvData(std::string &outString);
		void broadcast();
		~udp_server();
	private:
		void addUser(const struct sockaddr_in &client,\
				const socklen_t &len); 
		void delUser(const struct sockaddr_in &client,\
				const socklen_t &len); 
		int sendData(std::string &inString,\
				struct sockaddr_in &client, const socklen_t &len);
		std::string ip;
		int port;
		int sock;


		data_pool pool;
		std::map<int, struct sockaddr_in> online_user;
};

#endif










#include "udp_server.h"
#include "data.h"

udp_server::udp_server(const std::string &_ip,\
		const int &_port):ip(_ip), port(_port), sock(-1), pool(PSIZE)
{}

void udp_server::addUser(const struct sockaddr_in &client,\
		const socklen_t &len)
{
	online_user.insert(std::pair<int, struct sockaddr_in>(client.sin_addr.s_addr, client));
}

void udp_server::delUser(const struct sockaddr_in &client,\
		const socklen_t &len)
{
	std::map<int,struct sockaddr_in>::iterator iter = online_user.find(client.sin_addr.s_addr);
	if(iter != online_user.end()){
		online_user.erase(iter);
	}
}


int udp_server::initServer()
{
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock < 0){
		std::cerr << "socket error!" << std::endl;
		return -1;
	}

	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(port);
	local.sin_addr.s_addr = inet_addr(ip.c_str());

	if(bind(sock, (struct sockaddr*)&local, sizeof(local)) < 0){
		std::cerr << "bind error!" << std::endl;
		return -2;
	}
	return 0;
}

int udp_server::recvData(std::string &outString)
{
	int ret = 0;
	struct sockaddr_in client;
	socklen_t len = sizeof(client);

	char buf[1024];
	ssize_t s = recvfrom(sock, buf, sizeof(buf)-1, 0,\
			(struct sockaddr*)&client, &len);
	if(s > 0){
		buf[s] = 0;
		outString = buf;
		//put data to data_pool
		pool.putData(outString);
		//add user online user
		data d;
		d.dataUnserialize(outString);
		if(d.cmd != "QUIT"){
			addUser(client, len);
		}else{
			delUser(client, len);
		}
	}else{
		ret = -1;
	}

	return ret;
}


int udp_server::sendData(std::string &inString,\
		struct sockaddr_in &client, const socklen_t &len)
{
	ssize_t s = sendto(sock, inString.c_str(), inString.size(), 0,\
			(struct sockaddr*)&client, len);
	if(s < 0){
		std::cerr << "sendto error!" << std::endl;
	}
	return s;
}

void udp_server::broadcast()
{
	std::string sendString;
	pool.getData(sendString);
	std::map<int,struct sockaddr_in>::iterator iter = online_user.begin();
	for(; iter != online_user.end(); iter++ ){
		socklen_t len = sizeof(iter->second);
		sendData(sendString, iter->second, len);
	}
}

udp_server::~udp_server()
{
	if(sock != -1){
		close(sock);
	}
}














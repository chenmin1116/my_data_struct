#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include "udp_client.h"
#include "data.h"
#include "window.h"

static void usage(const char *proc)
{
	std::cout << "\nUsage:\n\t" << proc << " [remote_ip] [remote_port]\n" << std::endl;
}

udp_client *cp = NULL;
window *w = NULL;
std::string nick_name;
std::string school;
std::vector<std::string> friends;

static void *run_header(void *arg)
{
	window *wp = (window*)arg;

	std::string tips = "Welcome To Chat System!";
	int i = 1;
	int y, x;
	while(1){
		wp->drawHeader();
		getmaxyx(wp->header, y, x);
	    wp->putStrToWin(wp->header, y/2, i++, tips);
		if(i > x - tips.size() - 1){
			i = 1;
		}
		wrefresh(wp->header);
		usleep(200000);
	}
	return (void *)0;
}

static void addUser(std::string &f)
{
	std::vector<std::string>::iterator iter = friends.begin();
	for(; iter != friends.end(); iter++){
		if(*iter == f){
			return;
		}
	}

	friends.push_back(f);
}

static void delUser(std::string &f)
{
	std::vector<std::string>::iterator iter = friends.begin();
	for(; iter != friends.end(); ){
		if(*iter == f){
			iter = friends.erase(iter);
			break;
		}else{
			iter++;
		}
	}
}

static void *run_output_flist(void *arg)
{
	window *wp = (window*)arg;
    wp->drawOutput();
    wrefresh(wp->output);

    wp->drawFlist();
    wrefresh(wp->flist);

	std::string jsonString;
	std::string outputMsg;
	std::string f;
	data d;
	int line = 1;
	int y, x;
	int i = 0;
	while(1){
		cp->recvData(jsonString);
		d.dataUnserialize(jsonString);
		outputMsg = d.nick_name;
		outputMsg += "-";
		outputMsg += d.school;
		f = outputMsg;

		if(d.cmd == "QUIT"){
			delUser(f);
		}else{
		    outputMsg += "# ";
		    outputMsg += d.msg;

		    getmaxyx(wp->output, y, x);
	        wp->putStrToWin(wp->output, line, 2, outputMsg);
    	    wrefresh(wp->output);
		    if(++line > y - 2){
 		    	wp->drawOutput();
		    	line = 1;
		    }
			addUser(f);
		}

    	wp->drawFlist();
		for(i=0; i < friends.size(); i++){
			wp->putStrToWin(wp->flist, i+1, 1, friends[i]);
		}
    	wrefresh(wp->flist);
	}
}

static void *run_input(void *arg)
{
	window *wp = (window*)arg;
	
	std::string tips = "Please Enter# ";
	std::string sendString;
	data d;
	d.nick_name = nick_name;
	d.school = school;
	d.cmd = "";
	while(1){
	    wp->drawInput();
	    wp->putStrToWin(wp->input, 1, 2, tips);
	    wrefresh(wp->input);
	    wp->getStrFromWin(wp->input, d.msg);

		d.dataSerialize(sendString);
		cp->sendData(sendString);
	}
	return (void *)0;
}

void clientQuit(int sig)
{
	std::string quitString;
	data d;
	d.nick_name = nick_name;
	d.school = school;
	d.msg = "";
	d.cmd = "QUIT";
	d.dataSerialize(quitString);
	cp->sendData(quitString);
	delete w;
	exit(0);
}

int main(int argc, char *argv[])
{
	if(argc != 3){
		usage(argv[0]);
		return 1;
	}

	std::cout << "Please Enter Nick Name# ";
	std::cin >> nick_name;
	std::cout << "Please Enter School# ";
	std::cin >> school;

	udp_client client(argv[1], atoi(argv[2]));
	client.initClient();
	cp = &client;

	w = new window();

	signal(2, clientQuit);

	pthread_t header, output_flist, input;
	pthread_create(&header, NULL, run_header, w);
	pthread_create(&output_flist, NULL, run_output_flist, w);
	pthread_create(&input, NULL, run_input, w);

	pthread_join(header, NULL);
	pthread_join(output_flist, NULL);
	pthread_join(input, NULL);

	return 0;
}



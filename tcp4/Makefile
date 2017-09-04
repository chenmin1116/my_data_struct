.PHONY:all
all:tcp_client tcp_server

tcp_client:tcp_client.c
	gcc -o $@ $^
tcp_server:tcp_server.c
	gcc -o $@ $^ -lpthread

#%.o:%.c
#	gcc -c $<

.PHONY:clean
clean:
	rm -rf tcp_client tcp_server

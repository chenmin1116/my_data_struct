.PHONY:all
all:udp_client1 udp_server

udp_client1:udp_client1.c
	gcc -o $@ $^
udp_server:udp_server.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -rf udp_client1 udp_server

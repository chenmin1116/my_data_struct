.PHONY:all
all:select_server client

client:client.c
	gcc -o $@ $^

select_server:select_server.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -f select_server  client

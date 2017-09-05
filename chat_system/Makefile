ROOT=$(shell pwd)
CLIENT=$(ROOT)/client
SERVER=$(ROOT)/server
DATA_POOL=$(ROOT)/data_pool
COMM=$(ROOT)/comm
LIB=$(ROOT)/lib
WINDOW=$(ROOT)/window

LDFLAGS=-lpthread -ljsoncpp -lcurses

INCLUDE=-I$(DATA_POOL) -I$(LIB)/include -I$(COMM) -I$(WINDOW)
LIB_PATH=-L$(LIB)/lib

cc=g++

client_bin=chat_client
server_bin=chat_system


client_src=$(shell ls $(CLIENT)/*.cpp)
client_src+=$(shell ls $(COMM)/*.cpp)
client_src+=$(shell ls $(WINDOW)/*.cpp)
client_obj=$(notdir $(client_src:.cpp=.o))

server_src=$(shell ls $(SERVER)/*.cpp)
server_src+=$(shell ls $(DATA_POOL)/*.cpp)
server_src+=$(shell ls $(COMM)/*.cpp)
server_obj=$(notdir $(server_src:.cpp=.o))

.PHONY:all
all:$(client_bin) $(server_bin)

$(client_bin):$(client_obj)
	@$(cc) -o $@ $^ $(LIB_PATH) $(LDFLAGS) -lncurses
	@echo "Linking [$^] to [$@] ... done"
$(server_bin):$(server_obj)
	@$(cc) -o $@ $^ $(LIB_PATH) $(LDFLAGS) 
	@echo "Linking [$^] to [$@] ... done"
%.o:$(CLIENT)/%.cpp
	@$(cc) -c $< $(INCLUDE)
	@echo "Compling [$<] to [$@] ... done"
%.o:$(SERVER)/%.cpp
	@$(cc) -c $< $(INCLUDE)
	@echo "Compling [$<] to [$@] ... done"
%.o:$(DATA_POOL)/%.cpp
	@$(cc) -c $<
	@echo "Compling [$<] to [$@] ... done"
%.o:$(COMM)/%.cpp
	@$(cc) -c $< $(INCLUDE)
	@echo "Compling [$<] to [$@] ... done"
%.o:$(WINDOW)/%.cpp
	@$(cc) -c $< $(INCLUDE)
	@echo "Compling [$<] to [$@] ... done"
	
.PHONY:clean
clean:
	rm -rf *.o $(client_bin) $(server_bin) output

.PHONY:output
output:
	mkdir -p output/server/log
	mkdir -p output/server/conf
	mkdir -p output/client
	cp $(client_bin) output/client
	cp client_run.sh output/client
	cp $(server_bin) output/server
	cp server_ctl.sh output/server

.PHONY:debug
debug:
	@echo $(client_obj)
	@echo $(server_obj)














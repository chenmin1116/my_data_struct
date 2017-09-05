
ROOT=$(shell pwd)
LIB=$(ROOT)/../lib
LIB_PATH=-L$(LIB)/lib
INCLUDE=-I$(LIB)/include

data:base_json.cpp data.cpp
	g++ -o $@ $^ $(INCLUDE) $(LIB_PATH) -ljsoncpp -D_STYLED_
.PHONY:clean
clean:
	rm -f  data

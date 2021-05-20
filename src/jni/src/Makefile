CC = g++
CC_FLAG = -std=c++11 -D_TEST_DRV -g -fPIC
INC = -I /opt/jdk-11.0.11+9/include -I /opt/jdk-11.0.11+9/include/linux -I ../dependents/inc -I ../include
LIB = -L ../dependents/lib -lserviceinterface
PRG = ../lib/libaubojdr.so
OBJ = util/util.o robotdrv.o

all:$(PRG)
$(PRG):$(OBJ)
	$(CC) -shared -o $@ $(OBJ) $(LIB)

.SUFFIXES: .c .o .cpp
.cpp.o:
	$(CC) $(CC_FLAG) $(INC) -c $*.cpp -o $*.o


.PRONY:clean
clean:
	@echo "clean..."
	rm -rvf $(OBJ) $(PRG)
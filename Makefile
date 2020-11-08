CXXFLAGS =  -g -O3 -Wall -Wextra -Wuninitialized -pedantic -Wshadow -std=c++14

OBJS = Railway StackTest

all: ${OBJS}

Railway: stack.o car.o destination.o
StackTest: stack.o car.o destination.o

stack.o: stack.h car.h destination.h
car.o: car.h destination.h
destination.o: destination.h

clean:
	rm -f ${OBJS} *.o
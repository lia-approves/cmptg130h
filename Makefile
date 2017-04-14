CC = g++
CXXFLAGS = -std=c++11 -Wall -O2
OBJS = testAliceBob

testAliceBob: testAliceBob.cpp ModArith.o

ModArith.o: ModArith.cpp ModArith.h

clean:
	/bin/rm -f *.o *~ ${OBJS}

CC = g++
CXXFLAGS = -std=c++11 -Wall -O2
OBJS = TestAliceBob TestABE

TestABE: TestABE.cpp ModArith.o DiffieHellman.o

TestAliceBob: TestAliceBob.cpp ModArith.o

DiffieHellman.o: DiffieHellman.cpp DiffieHellman.h ModArith.o

ModArith.o: ModArith.cpp ModArith.h

clean:
	/bin/rm -f *.o *~ ${OBJS}

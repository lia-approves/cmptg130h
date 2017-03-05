OBJS = testAliceBob

testAliceBob: testAliceBob.cpp modArith.o

modArith.o: modArith.cpp modArith.h

clean:
	/bin/rm -f *.o *.~ ${OBJS}

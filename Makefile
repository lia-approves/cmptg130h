OBJS = modArith testAliceBob

testAliceBob: testAliceBob.cpp modArith.o

modArith.o: modArith.cpp modArith.h


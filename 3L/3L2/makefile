CXX=g++

all: queue.o stack.o stacktest queuetest queuetest1 queuetest2 queuetest3 queuetest4 stacktest1 stacktest2 stacktest3 stacktest4 stacktest5

queue.o: queue.cpp queue.h
	$(CXX) -c queue.cpp -o queue.o

stack.o: stack.cpp stack.h
	$(CXX) -c stack.cpp -o stack.o

tests: queuetest stacktest

queuetest: queuetest.cpp queue.cpp queue.h
	$(CXX) queuetest.cpp queue.cpp -o queuetest
queuetest1: queuetest1.cpp queue.cpp queue.h
	$(CXX) queuetest1.cpp queue.cpp -o queuetest1
queuetest2: queuetest2.cpp queue.cpp queue.h
	$(CXX) queuetest2.cpp queue.cpp -o queuetest2
queuetest3: queuetest3.cpp queue.cpp queue.h
	$(CXX) queuetest3.cpp queue.cpp -o queuetest3
queuetest4: queuetest4.cpp queue.cpp queue.h
	$(CXX) queuetest4.cpp queue.cpp -o queuetest4

stacktest: stacktest.cpp stack.cpp stack.h
	$(CXX) stacktest.cpp stack.cpp -o stacktest
stacktest1: stacktest1.cpp stack.cpp stack.h
	$(CXX) stacktest1.cpp stack.cpp -o stacktest1
stacktest2: stacktest2.cpp stack.cpp stack.h
	$(CXX) stacktest2.cpp stack.cpp -o stacktest2
stacktest3: stacktest3.cpp stack.cpp stack.h
	$(CXX) stacktest3.cpp stack.cpp -o stacktest3
stacktest4: stacktest4.cpp stack.cpp stack.h
	$(CXX) stacktest4.cpp stack.cpp -o stacktest4
stacktest5: stacktest5.cpp stack.cpp stack.h
	$(CXX) stacktest5.cpp stack.cpp -o stacktest5

clean: 
	rm -f queuetest stacktest queue.o stack.o queuetest1 queuetest2 queuetest3 queuetest4 stacktest1 stacktest2 stacktest3 stacktest4 stacktest5

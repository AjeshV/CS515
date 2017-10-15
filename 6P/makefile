CXX=g++

all: set.o setTest setTestFixtures

set.o: set.cpp  set.h
	$(CXX) -c set.cpp

setTest: setTest.cpp  set.o set.h
	$(CXX) setTest.cpp set.o -lgtest -lpthread -o setTest

setTestFixtures: setTestFixtures.cpp set.o set.h
	$(CXX) setTestFixtures.cpp set.o -lgtest -lpthread -o setTestFixtures

clean:
	rm -f *.o  setTest setTestFixtures

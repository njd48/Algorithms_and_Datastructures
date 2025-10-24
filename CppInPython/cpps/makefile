
FULLPATH=~/Documents/PythonProjects/CppInP/cpps/
IDIR=./
CXX=g++
CXXFLAGS=-I$(IDIR) -Wall -Wextra -pedantic-errors -O2 -pthread



inCpp: myFunc.cpp test_myFunc.cpp myFunc.hpp

	$(CXX) -c myFunc.o $(CXXFLAGS) myFunc.cpp
	$(CXX) -c test_myFunc.o $(CXXFLAGS) test_myFunc.cpp

.PHONY: clean


shared: myFunc.cpp myFunc.hpp

	$(CXX) -c myFunc.o $(CXXFLAGS) myFunc.cpp
	$(CXX) -fPIC -shared -o myFunc.so $(CXXFLAGS) myFunc.o

.PHONY: clean


test: myFunc.o test_myFunc.o myFunc.so myFunc.hpp

	$(CXX) -o test1.exe $(CXXFLAGS) test_myFunc.o myFunc.o
	$(CXX) -o test2.exe $(CXXFLAGS) test_myFunc.o -L. myFunc.so -Wl,-rpath=$(IDIR)

.PHONY: clean


all: myFunc.cpp test_myFunc.cpp

	make clean
	make inCpp
	make shared
	make test

.PHONY: clean

#build: *.cpp
#	$(CXX) -o assignment.exe $(CXXFLAGS) *.cpp

#.PHONY: clean

clean:
	rm *.o *.so *.exe


FULLPATH=~/Documents/PythonProjects/CppInP/cpps/
IDIR=./
CXX=g++
CXXFLAGS=-I$(IDIR) -Wall -Wextra -pedantic-errors -O2 -pthread


vfncs: vfncs.cpp

	$(CXX) -fopenmp -c vfncs.o $(CXXFLAGS) vfncs.cpp

.PHONY: clean

testS: vfncs.o test_addition.cpp

	$(CXX) -o test_addition_serial.exe $(CXXFLAGS) test_addition.cpp vfncs.o

.PHONY: clean


testpar: vfncs.o test_addition.cpp

	$(CXX) -fopenmp -o test_addition_omp.exe $(CXXFLAGS) test_addition.cpp vfncs.o

.PHONY: clean


#build: *.cpp
#	$(CXX) -o assignment.exe $(CXXFLAGS) *.cpp

#.PHONY: clean

clean:
	rm *.o *.exe
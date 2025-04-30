IDIR=./
CXX=g++
CXXFLAGS=-I$(IDIR) -Wall -Wextra -pedantic-errors -O2 -pthread

test_H1: test_hash.cpp
	$(CXX) -o test_hash.exe $(CXXFLAGS) test_hash.cpp

	./test_hash.exe

.PHONY: clean


test_LL: test_DLL.cpp
	$(CXX) -o test_DLL.exe $(CXXFLAGS) test_DLL.cpp

	./test_DLL.exe

.PHONY: clean

#build: *.cpp
#	$(CXX) -o assignment.exe $(CXXFLAGS) *.cpp

#.PHONY: clean

clean:
	rm -f a.out 
	rm -f test_DLL.exe
	rm -f test_hash.exe

#run:
#	./assignment.exe $(ARGS)
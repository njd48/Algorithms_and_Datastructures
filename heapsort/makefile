IDIR=./
CXX=g++
CXXFLAGS=-I$(IDIR) -Wall -Wextra -pedantic-errors -O2 -pthread

.PHONY: clean

test: test_heapsort.cpp
	$(CXX) test_heapsort.cpp -o heapsort.exe $(CXXFLAGS) 
	./heapsort.exe

time: time_heapsort.cpp
	$(CXX) time_heapsort.cpp -o time_heapsort.exe $(CXXFLAGS) 
	./time_heapsort.exe

clean:
	rm -f test.exe
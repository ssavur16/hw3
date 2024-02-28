CXX = g++
CXXFLAGS = -g -Wall --std=c++11
VALGRIND = valgrind --tool=memcheck --leak-check=yes

all: llrec-test

llrec-test: llrec-test.o llrec.o
	$(CXX) $(CXXFLAGS) $^ -o $@

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean
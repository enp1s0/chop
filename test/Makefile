CXX=g++
CXXFLAGS=-std=c++17 -I../include
TARGET=chop-test.out

#CXXFLAGS+=-DTEST_BINARY16

$(TARGET): main.cpp
	$(CXX) $< -o $@ $(CXXFLAGS)

clean:
	rm -f *.out

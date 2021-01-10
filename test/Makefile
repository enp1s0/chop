CXX=g++
CXXFLAGS=-std=c++17 -I../include
TARGET=chop-test.out

$(TARGET): main.cpp
	$(CXX) $< -o $@ $(CXXFLAGS)

clean:
	rm -f *.out

CXX=g++
CXXFLAGS=-std=c++17 -I../include
TARGET=chop-test.out

# e.g. arm
#CXXFLAGS+=-DTEST_BINARY16 -DCHOPFP_BINARY16_TYPENAME=__fp16 -mfp16-format=ieee

$(TARGET): main.cpp
	$(CXX) $< -o $@ $(CXXFLAGS)

clean:
	rm -f *.out

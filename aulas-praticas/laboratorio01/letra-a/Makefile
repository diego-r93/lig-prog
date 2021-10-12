#!/usr/bin/make -f

TARGET = fibonacci

CXX = g++

ifeq ($(compiler), CLANG)
CXX = clang++
endif

LD = $(CXX)

CXXFLAGS = -Wall -std=c++11
LDFLAGS = -Wall

ifeq ($(dialect), C++14)
CXXFLAGS = -Wall -std=c++14
endif

ifeq ($(dialect), C++17)
CXXFLAGS = -Wall -std=c++17
endif

OBJS = main.o fibonacci.o

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f *.o $(TARGET)
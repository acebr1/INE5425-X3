.PHONY: clean run test

CPPFLAGS = -std=c++11 -Iinclude
CC = g++
LDFLAGS = -lm -lstdc++

SRC = $(wildcard src/*.cpp main.cpp)
OBJ = $(SRC:.cpp=.o)

TST = $(wildcard src/*.cpp tests.cpp)
TSTOBJ = $(TST:.cpp=.o)

all: main

main: $(OBJ)

run: main
	@./main

tests: $(TSTOBJ)

test: tests
	@echo "Done Compiling!\n"
	@./tests

clean:
	rm -f $(OBJ)
	rm -f main
	rm -f $(TSTOBJ)
	rm -f tests

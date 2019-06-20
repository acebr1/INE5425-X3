.PHONY: clean run 

CPPFLAGS = -std=c++11 -Iinclude
LDFLAGS = -lm -lstdc++

SRC = $(wildcard src/*.cpp main.cpp)
OBJ = $(SRC:.cpp=.o)

all: main

main: $(OBJ)

run: main
	@./main

clean:
	rm -f $(OBJ)
	rm -f main

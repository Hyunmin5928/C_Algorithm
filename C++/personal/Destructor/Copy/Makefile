CC = g++
CFLAGS = -Wall -Wextra -std=c++11
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = Copy

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(OBJ) $(TARGET)

.PHONY: all clean
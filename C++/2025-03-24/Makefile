CC = g++
CFLAGS = -Wall -Wextra -std=c++11
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = Class_1

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(OBJ)
	del /Q $(TARGET).exe

.PHONY: all clean
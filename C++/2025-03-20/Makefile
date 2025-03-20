CC = g++
CFLAGS = -Wall -Wextra -std=c++11
SRC = example_5.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = Friend_3


all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(OBJ)

.PHONY: all clean
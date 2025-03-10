CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = ArrayStack

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(OBJ)
	del /Q $(TARGET).exe

.PHONY: all clean
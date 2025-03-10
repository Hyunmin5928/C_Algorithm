CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET = LCRSTree

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del /Q $(OBJ)
	del /Q $(TARGET)

.PHONY: all clean
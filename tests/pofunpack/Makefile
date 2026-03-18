SHELL := /bin/bash

CC := gcc
CFLAGS := -Wall -g
# LDFLAGS := -L../libalterapof -lalterapof

SRCS := $(wildcard *.c *.cpp)
OBJS := $(SRCS:.c=.o) $(SRCS:.cpp=.o)
TARGET := test


.PHONY: all run
all: $(TARGET)

run: $(TARGET)
	./$^

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)
	@chmod +x $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)

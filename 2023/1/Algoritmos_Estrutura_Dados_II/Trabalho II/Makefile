CC = gcc
CFLAGS = -Wall -Wextra

SRCS = main.c biblioteca.c 
OBJS = $(SRCS:.c=.o)
TARGET = programa

all: $(TARGET)

run: programa
	./programa

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
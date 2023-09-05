CC=gcc
CFLAGS=-Wall -Wextra
SRC=main.c
BINS=main

all: main

main: main.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BINS)

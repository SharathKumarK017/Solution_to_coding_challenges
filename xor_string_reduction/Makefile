CC=g++
CFLAGS=-Wall -Wextra
SRC=main.c
OBJS:=$(SRC:.c=)
BINS=$(SRC:.c=)

all: $(OBJS)

$(OBJS):
	$(CC) $(CFLAGS) $@.c -o $@

clean:
	rm -f $(BINS)

CC=gcc
CFLAGS=-I.
OBJ=files.o

%.o: %.c
	$(CC) -c $@ $< $(CFLAGS)


CC=gcc
CFLAGS=-I.
OBJ=files.o

.PHONY: clean

%.o: %.c
	$(CC) -c $@ $< $(CFLAGS)

clean:
	rm -rf *.o

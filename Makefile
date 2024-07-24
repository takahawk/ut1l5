CC=gcc
CFLAGS=-I.
OBJ=files.o

.PHONY: clean

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf *.o

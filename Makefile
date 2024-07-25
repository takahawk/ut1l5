CC=gcc
CFLAGS=-I. $(if $(NODEBUG),,-g)
OBJ=files.o

.PHONY: clean

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -rf *.o

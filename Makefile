CC=gcc
CFLAGS=-I. $(if $(NODEBUG),,-g)
SRC=describe.c files.c
HEADER=describe.h files.h io.h
OBJ=$(SRC:.c=.o)
OBJ_PIC = $(OBJ:.o=_pic.o)

INSTALL_INCLUDE_DIR ?= /usr/local/include/w/ut1l5
INSTALL_LIB_DIR ?= /usr/local/lib
INSTALL_SRC_DIR ?= /usr/local/src/w/ut1l5

SHARED_LIB = libut1l5.so
STATIC_LIB = libut1l5.a
.DEFAULT_GOAL := all

.PHONY: all clean check shared static

all: shared static

shared: $(SHARED_LIB)

static: $(STATIC_LIB)

%_pic.o: %.c
	$(CC) -fPIC -c -o $@ $< $(CFLAGS)
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(SHARED_LIB): $(OBJ_PIC)
	$(CC) -shared -o $@ $^

$(STATIC_LIB): $(OBJ)
	ar rcs $@ $^

install:
	mkdir -p $(INSTALL_INCLUDE_DIR) $(INSTALL_LIB_DIR) $(INSTALL_SRC_DIR)
	for h in $(HEADER); do \
		cp $$h $(INSTALL_INCLUDE_DIR) ; \
	done
	
	for s in $(SRC); do \
		cp $$s $(INSTALL_SRC_DIR) ; \
	done
	
	cp $(SHARED_LIB) $(INSTALL_LIB_DIR)
	cp $(STATIC_LIB) $(INSTALL_LIB_DIR)

check:
	$(CC) -fsyntax-only $(HEADER) $(SRC)

clean:
	rm -rf *.o *.so *.a

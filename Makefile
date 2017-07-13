CC=gcc
SRC=$(wildcard src/*.c)
TMP=$(subst src, build, $(SRC))
OBJ=$(TMP:.c=.o)
CFLAGS=-Wall -Werror -pedantic-errors -std=c99
LIB_OUTPUT=build/libcmat.a
INCLUDE_FILE=include/cmat.h
DESTDIR=/usr/local

.PHONY: build
build:
	$(CC) -c $(SRC) $(CFLAGS)
	mv *.o build/
	ar rcs $(LIB_OUTPUT) $(OBJ)

install: build

	cp $(LIB_OUTPUT) $(DESTDIR)/lib/
	cp $(INCLUDE_FILE) $(DESTDIR)/include/

.PHONY: clean
clean:
	rm -f $(OBJ)

CC=gcc
CFLAGS=-Wall -Werror -pedantic-errors -std=c99
INPUT=init.c views.c arithmetic.c operations.c special_metrices.c
OUTPUT=init.o views.o arithmetic.o operations.o special_metrices.o
LIB_OUTPUT=libcmat.a
INCLUDE_FILE=cmat.h
LIB_PATH=/usr/local/lib
INCLUDED_PATH=/usr/local/include

build:
	$(CC) -c $(INPUT) $(CFLAGS)
	ar rcs $(LIB_OUTPUT) $(OUTPUT)

install: build
	cp $(LIB_OUTPUT) $(LIB_PATH)/$(LIB_OUTPUT)
	cp $(INCLUDE_FILE) $(INCLUDED_PATH)/$(INCLUDE_FILE)

clean:
	rm -f $(OUTPUT) $(LIB_OUTPUT)
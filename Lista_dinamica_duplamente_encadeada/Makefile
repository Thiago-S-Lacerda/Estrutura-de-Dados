CC     = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -Iinclude

all: programa programa_otm

programa: build build/programa

programa_otm: build build/programa_otm

build/programa: build/main.o build/ListaDinEncadDupla.o build/menu.o
	$(CC) $(CFLAGS) -o build/programa build/main.o build/ListaDinEncadDupla.o build/menu.o -lm

build/programa_otm: build/mainOtm.o build/ListaDinEncadDuplaOtm.o build/menuOtm.o
	$(CC) $(CFLAGS) -o build/programa_otm build/mainOtm.o build/ListaDinEncadDuplaOtm.o build/menuOtm.o -lm

build:
	mkdir -p build

build/main.o: src/main.c include/ListaDinEncadDupla.h
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/mainOtm.o: src/mainOtm.c include/ListaDinEncadDuplaOtm.h
	$(CC) $(CFLAGS) -c src/mainOtm.c -o build/mainOtm.o

build/ListaDinEncadDupla.o: src/ListaDinEncadDupla.c include/ListaDinEncadDupla.h
	$(CC) $(CFLAGS) -c src/ListaDinEncadDupla.c -o build/ListaDinEncadDupla.o

build/ListaDinEncadDuplaOtm.o: src/ListaDinEncadDuplaOtm.c include/ListaDinEncadDuplaOtm.h
	$(CC) $(CFLAGS) -c src/ListaDinEncadDuplaOtm.c -o build/ListaDinEncadDuplaOtm.o

build/menu.o: src/menu.c include/menu.h
	$(CC) $(CFLAGS) -c src/menu.c -o build/menu.o

build/menuOtm.o: src/menuOtm.c include/menuOtm.h
	$(CC) $(CFLAGS) -c src/menuOtm.c -o build/menuOtm.o

clean:
	rm -f build/*.o build/programa build/programa_otm
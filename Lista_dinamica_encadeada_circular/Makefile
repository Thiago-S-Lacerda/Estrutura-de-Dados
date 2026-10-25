CC     = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -Iinclude

all: programa programa_otm

programa: build/main.o build/ListaDinEncadCirc.o build/menu.o
	$(CC) $(CFLAGS) -o build/programa build/main.o build/ListaDinEncadCirc.o build/menu.o -lm

programa_otm: build/mainOtm.o build/ListaDinEncadCircOtm.o build/menuOtm.o
	$(CC) $(CFLAGS) -o build/programa_otm build/mainOtm.o build/ListaDinEncadCircOtm.o build/menuOtm.o -lm

build/main.o: src/main.c include/ListaDinEncadCirc.h
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/mainOtm.o: src/mainOtm.c include/ListaDinEncadCircOtm.h
	$(CC) $(CFLAGS) -c src/mainOtm.c -o build/mainOtm.o

build/ListaDinEncadCirc.o: src/ListaDinEncadCirc.c include/ListaDinEncadCirc.h
	$(CC) $(CFLAGS) -c src/ListaDinEncadCirc.c -o build/ListaDinEncadCirc.o

build/ListaDinEncadCircOtm.o: src/ListaDinEncadCircOtm.c include/ListaDinEncadCircOtm.h
	$(CC) $(CFLAGS) -c src/ListaDinEncadCircOtm.c -o build/ListaDinEncadCircOtm.o

build/menu.o: src/menu.c include/menu.h
	$(CC) $(CFLAGS) -c src/menu.c -o build/menu.o

build/menuOtm.o: src/menuOtm.c include/menuOtm.h
	$(CC) $(CFLAGS) -c src/menuOtm.c -o build/menuOtm.o

clean:
	rm -f build/*.o build/programa build/programa_otm
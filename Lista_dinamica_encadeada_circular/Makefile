CC     = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -Iinclude

programa: build/main.o build/ListaDinEncadCirc.o build/menu.o
	$(CC) $(CFLAGS) -o build/programa build/main.o build/ListaDinEncadCirc.o build/menu.o -lm

build/main.o: src/main.c include/ListaDinEncadCirc.h include/menu.h
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/ListaDinEncadCirc.o: src/ListaDinEncadCirc.c include/ListaDinEncadCirc.h
	$(CC) $(CFLAGS) -c src/ListaDinEncadCirc.c -o build/ListaDinEncadCirc.o

build/menu.o: src/menu.c include/menu.h
	$(CC) $(CFLAGS) -c src/menu.c -o build/menu.o

clean:
	rm -f build/*.o build/programa

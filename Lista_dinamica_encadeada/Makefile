CC     = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -Iinclude

programa: build/main.o build/ListaDinEncad.o build/menu.o
	$(CC) $(CFLAGS) -o build/programa build/main.o build/ListaDinEncad.o build/menu.o -lm

build/main.o: src/main.c include/ListaDinEncad.h include/menu.h
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

build/ListaDinEncad.o: src/ListaDinEncad.c include/ListaDinEncad.h
	$(CC) $(CFLAGS) -c src/ListaDinEncad.c -o build/ListaDinEncad.o

build/menu.o: src/menu.c include/menu.h
	$(CC) $(CFLAGS) -c src/menu.c -o build/menu.o

clean:
	rm -f build/*.o build/programa

CC     = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -Iinclude

all: fila pilha pilha_dupla

fila: build build/fila
pilha: build build/pilha
pilha_dupla: build build/pilha_dupla

build/fila: build/mainFila.o build/FilaEstatica.o build/menuFila.o
	$(CC) $(CFLAGS) -o build/fila build/mainFila.o build/FilaEstatica.o build/menuFila.o -lm

# Adicionado build/PilhaChar.o aqui nas dependências e na linha de comando do gcc:
build/pilha: build/mainPilha.o build/PilhaSequencial.o build/PilhaChar.o build/menuPilha.o
	$(CC) $(CFLAGS) -o build/pilha build/mainPilha.o build/PilhaSequencial.o build/PilhaChar.o build/menuPilha.o -lm

build/pilha_dupla: build/mainPilhaDupla.o build/PilhaDupla.o build/menuPilhaDupla.o
	$(CC) $(CFLAGS) -o build/pilha_dupla build/mainPilhaDupla.o build/PilhaDupla.o build/menuPilhaDupla.o -lm

build:
	mkdir -p build

build/mainFila.o: src/mainFila.c include/FilaEstatica.h include/menuFila.h
	$(CC) $(CFLAGS) -c src/mainFila.c -o build/mainFila.o

build/mainPilha.o: src/mainPilha.c include/PilhaSequencial.h include/menuPilha.h
	$(CC) $(CFLAGS) -c src/mainPilha.c -o build/mainPilha.o

build/mainPilhaDupla.o: src/mainPilhaDupla.c include/PilhaDupla.h include/menuPilhaDupla.h
	$(CC) $(CFLAGS) -c src/mainPilhaDupla.c -o build/mainPilhaDupla.o

build/FilaEstatica.o: src/FilaEstatica.c include/FilaEstatica.h
	$(CC) $(CFLAGS) -c src/FilaEstatica.c -o build/FilaEstatica.o

build/PilhaSequencial.o: src/PilhaSequencial.c include/PilhaSequencial.h
	$(CC) $(CFLAGS) -c src/PilhaSequencial.c -o build/PilhaSequencial.o

# Adicionada a regra de compilação para o PilhaChar.o:
build/PilhaChar.o: src/PilhaChar.c include/PilhaChar.h
	$(CC) $(CFLAGS) -c src/PilhaChar.c -o build/PilhaChar.o

build/PilhaDupla.o: src/PilhaDupla.c include/PilhaDupla.h
	$(CC) $(CFLAGS) -c src/PilhaDupla.c -o build/PilhaDupla.o

build/menuFila.o: src/menuFila.c include/menuFila.h
	$(CC) $(CFLAGS) -c src/menuFila.c -o build/menuFila.o

build/menuPilha.o: src/menuPilha.c include/menuPilha.h include/PilhaChar.h
	$(CC) $(CFLAGS) -c src/menuPilha.c -o build/menuPilha.o

build/menuPilhaDupla.o: src/menuPilhaDupla.c include/menuPilhaDupla.h
	$(CC) $(CFLAGS) -c src/menuPilhaDupla.c -o build/menuPilhaDupla.o

clean:
	rm -f build/*.o build/fila build/pilha build/pilha_dupla
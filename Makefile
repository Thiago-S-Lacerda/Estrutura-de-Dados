CC     = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

programa: main.o lista.o
	$(CC) $(CFLAGS) -o programa main.o lista.o -lm

main.o: main.c lista.h
	$(CC) $(CFLAGS) -c main.c

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c

clean:
	rm -f *.o programa
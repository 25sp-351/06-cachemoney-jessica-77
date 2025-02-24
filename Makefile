all: main

OBJS = main.o money_to_text.o cache.o 
CC = gcc
CFLAGS = -Wall

main: $(OBJS)
	clang -o main $(CFLAGS) $(OBJS)

main.o: main.c money_to_text.h cache.h memoize.h

money_to_text.o: money_to_text.c money_to_text.h

cache.o: cache.c cache.h

memoize.o: memoize.c memoize.h

clean:
	rm -f $(OBJS)
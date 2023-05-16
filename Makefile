# Makefile

CC=gcc
CFLAGS=
OBJS=main.o revise_lgy.o
LIBS=
all : movie

movie : $(OBJS)
	$(CC) $(CFLAGS) -o movie $(OBJS) $(LIBS)

main.o : main.c
	$(CC) $(CFLAGS) -c main.c
revise_lgy.o : revise_lgy.c
	$(CC) $(CFLAGS) -c revise_lgy.c 

clean : 
	rm -f $(OBJS) movie *.o core
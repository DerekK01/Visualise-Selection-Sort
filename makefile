CC = gcc
CFLAGS = -Wall -pedantic -ansi -g -Werror
OBJ = main.o input.o newSleep.o display.o linkedlist.o linklistfuncptr.o
EXEC = sort

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c input.h newSleep.h display.h linkedlist.h linklistfuncptr.h
	$(CC) -c main.c $(CFLAGS)

input.o : input.c input.h
	$(CC) -c input.c $(CFLAGS)

newSleep.o : newSleep.c newSleep.h
	$(CC) -c newSleep.c $(CFLAGS)

display.o : display.c display.h
	$(CC) -c display.c $(CFLAGS)

linkedlist.o : linkedlist.c linkedlist.h
	$(CC) -c linkedlist.c $(CFLAGS)

linklistfuncptr.o : linklistfuncptr.c linklistfuncptr.h
	$(CC) -c linklistfuncptr.c $(CFLAGS)

clean :
	rm -f $(EXEC) $(OBJ)

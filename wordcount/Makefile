
CFLAGS= -O3 -Wall -g -std=c11 


wordcount:	wordcount.o
	cc ${CFLAGS} -o wordcount wordcount.o 

wordcount.o : wordcount.c
	cc ${CFLAGS} -c wordcount.c

clean :
	rm -f wordcount

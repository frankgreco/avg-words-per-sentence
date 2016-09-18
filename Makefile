all: main

main: main.o average.o count.o
	gcc main.o average.o count.o -o main

main.o: main.c
	gcc -Wall -c main.c

average.o: average.c
	gcc -Wall -c average.c

count.o: count.c
	gcc -Wall -c count.c

clean:
	rm *.o
	rm main

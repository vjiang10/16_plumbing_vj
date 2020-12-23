all: processor.c console.c 
	gcc -o processor.o processor.c
	gcc -o console.o console.c

run: 
	./processor.o & ./console.o

clean:
	rm *.out
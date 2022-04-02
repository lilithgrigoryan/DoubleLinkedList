run: all
	./main

all: main.c doublelinkedlist.a
	gcc main.c doublelinkedlist.a -o main

doublelinkedlist.a: doublelinkedlist.o
	ar rcs doublelinkedlist.a doublelinkedlist.o

doublelinkedlist.o: doublelinkedlist.c
	gcc -c doublelinkedlist.c -o doublelinkedlist.o

clean:
	rm -f main
	rm -f doublelinkedlist.a
	rm -f doublelinkedlist.o
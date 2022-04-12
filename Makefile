run: all
	./main

all: main.c doublelinkedlist.a
	gcc main.c doublelinkedlist.a -o main

test: doublelinkedlist.a
	gcc unit_tests.c doublelinkedlist.a -o unit_tests.o
	./unit_tests.o

doublelinkedlist.a: doublelinkedlist.o
	ar rcs doublelinkedlist.a doublelinkedlist.o

doublelinkedlist.o: doublelinkedlist.c
	gcc -c doublelinkedlist.c -o doublelinkedlist.o

clean:
	rm -f main
	rm -f doublelinkedlist.a
	rm -f doublelinkedlist.o
	rm -f unit_tests.o
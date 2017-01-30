wait: waitList.o waitListb.o waitListc.o
	gcc -o wait waitList.o waitListb.o waitListc.o

waitList.o: waitList.c waitList.h
	gcc -c waitList.c

waitListb.o: waitListb.c waitList.h
	gcc -c waitListb.c

waitListc.o: waitListc.c waitList.h
	gcc -c waitListc.c

clean:
	rm waitList.o waitListb.o waitListc.o

targetInt:
	cp dataInt.c data.c
	cp dataInt.h data.h
	gcc -Wall -g -I. -o tree data.c tree.c client.c -lm

targetStr:
	cp dataStr.c data.c
	cp dataStr.h data.h
	gcc -Wall -g -I. -o tree data.c tree.c client.c -lm

clean:
	rm -rf tree
	rm -rf *~
	rm -rf #*
	rm -rf *.bak

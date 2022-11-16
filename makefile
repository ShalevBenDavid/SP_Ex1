
all: mains maindloop maindrec recursives recursived loopd loops


mains:

maindloop:

maindrec:

	
loops: basicClassification.o advancedClassificationLoop.o
	ar -rcs -o libclassloops.a basicClassification.o advancedClassificationLoop.o

recursives: basicClassification.o advancedClassificationRecursion.o
	ar -rcs -o libclassrec.a basicClassification.o advancedClassificationRecursion.o

recursived:

loopd:

mains:
	gcc libclassrec.a main.c -o mains -Wall

maindloop:

maindrec:

basicClassification.o: basicClassification.c
	gcc -c basicClassification.c -Wall

advancedClassificationLoop.o: advancedClassificationLoop.c
	gcc -c advancedClassificationLoop.c -Wall

advancedClassificationRecursion.o: advancedClassificationRecursion.c
	gcc -c advancedClassificationRecursion.c -Wall

clean:
	rm -f *.o *.a

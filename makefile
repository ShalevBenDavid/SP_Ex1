
all: mains maindloop maindrec recursives recursived loopd loops

loops: basicClassification.o advancedClassificationLoop.o
	ar -rcs -o libclassloops.a basicClassification.o advancedClassificationLoop.o

recursives: basicClassification.o advancedClassificationRecursion.o
	ar -rcs -o libclassrec.a basicClassification.o advancedClassificationRecursion.o

recursived: basicClassification.o advancedClassificationRecursion.o
	gcc -shared -Wall -g basicClassification.o advancedClassificationRecursion.o -o libclassrec.so -lm

loopd: basicClassification.o advancedClassificationLoop.o
	gcc -shared -Wall -g basicClassification.o advancedClassificationLoop.o -o libclassloops.so -lm

mains: main.o libclassrec.a
	gcc -Wall -g -o mains main.o libclassrec.a -lm

maindloop: main.o libclassloops.so
	gcc -Wall -g -o maindloop main.o ./libclassloops.so -lm

maindrec: main.o libclassrec.so
	gcc -Wall -g -o maindrec main.o ./libclassrec.so -lm

basicClassification.o: basicClassification.c NumClass.h
	gcc -Wall -g -c basicClassification.c -lm

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc -Wall -g -c advancedClassificationLoop.c -lm

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc -Wall -g -c advancedClassificationRecursion.c -lm

clean:
	rm -f *.o *.a *.so mains maindloop maindrec

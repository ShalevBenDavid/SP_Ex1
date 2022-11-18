.PHONY: all clean loops loopd recursives recursived
#Defining Macros
CC = gcc
AR = ar
FLAGS= -Wall -g
LOOP = basicClassification.o advancedClassificationLoop.o
RECURSIVE = basicClassification.o advancedClassificationRecursion.o

all: mains maindloop maindrec loops loopd recursives recursived

#Creating Main Files
mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o -lclassrec -L. -lm
maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o -lclassloops -L. -lm
maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o -lclassrec -L. -lm
#Creating Static Libraries
loops: libclassloops.a
libclassloops.a: $(LOOP)
	$(AR) rcu libclassloops.a $(LOOP)
recursives: libclassrec.a
libclassrec.a: $(RECURSIVE)
	$(AR) rcu libclassrec.a $(RECURSIVE)
#Creating Dynamic Libraries
loopd:libclassloops.so
libclassloops.so: $(LOOP)
	$(CC) $(FLAGS) -shared -o libclassloops.so $(LOOP)
recursived: libclassrec.so
libclassrec.so: $(RECURSIVE)
	$(CC) $(FLAGS) -shared -o libclassrec.so $(RECURSIVE)
#Crating Objects
main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c -lm
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c -lm
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c -lm

clean:
	rm -f *.o *.a *.so mains maindloop maindrec

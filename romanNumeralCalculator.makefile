CFLAGS=-Wall
LIBS=-lcheck -lm -lrt -lpthread

all: romanNumeralCalculator

romanNumeralCalculator: main.o romanNumeralCalculator.o
	gcc -o romanNumeralCalculator main.o romanNumeralCalculator.o

main.o: main.c romanNumeralCalculator.h
	gcc $(CFLAGS) -c main.c

romanNumeralCalculator.o: romanNumeralCalculator.c romanNumeralCalculator.h
	gcc $(CFLAGS) -c romanNumeralCalculator.c

test: romanNumeralCalculator-test

romanNumeralCalculator-test: romanNumeralCalculator-test.o romanNumeralCalculator.o
	gcc -o romanNumeralCalculator-test romanNumeralCalculator.o romanNumeralCalculator-test.o $(LIBS)

romanNumeralCalculator-test.o: romanNumeralCalculator-test.c romanNumeralCalculator.h
	gcc $(CFLAGS) -c romanNumeralCalculator-test.c

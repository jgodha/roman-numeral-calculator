CFLAGS=-Wall
LIBS=-lcheck -lm -lrt -lpthread

all: romanNumeralCalculator

romanNumeralCalculator: main.o romanNumeralCalculator.o stringUtils.o
	gcc -o romanNumeralCalculator main.o romanNumeralCalculator.o stringUtils.o

main.o: main.c romanNumeralCalculator.h stringUtils.h
	gcc $(CFLAGS) -c main.c

romanNumeralCalculator.o: romanNumeralCalculator.c romanNumeralCalculator.h
	gcc $(CFLAGS) -c romanNumeralCalculator.c

stringUtils.o: stringUtils.c stringUtils.h
	gcc $(CFLAGS) -c stringUtils.c

test: romanNumeralCalculator-test

romanNumeralCalculator-test: romanNumeralCalculator-test.o romanNumeralCalculator.o  stringUtils.o
	gcc -o romanNumeralCalculator-test romanNumeralCalculator.o romanNumeralCalculator-test.o  stringUtils.o $(LIBS)

romanNumeralCalculator-test.o: romanNumeralCalculator-test.c romanNumeralCalculator.h
	gcc $(CFLAGS) -c romanNumeralCalculator-test.c

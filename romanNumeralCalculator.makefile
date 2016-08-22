CFLAGS=-Wall
LIBS=-lcheck -lm -lrt -lpthread

all: romanNumeralCalculator

romanNumeralCalculator: main.o romanNumeralCalculator.o stringUtils.o romanSymbolUtils.o
	gcc -o romanNumeralCalculator main.o romanNumeralCalculator.o stringUtils.o romanSymbolUtils.o

main.o: main.c romanNumeralCalculator.h stringUtils.h
	gcc $(CFLAGS) -c main.c

romanNumeralCalculator.o: romanNumeralCalculator.c romanNumeralCalculator.h
	gcc $(CFLAGS) -c romanNumeralCalculator.c

stringUtils.o: stringUtils.c stringUtils.h
	gcc $(CFLAGS) -c stringUtils.c

romanSymbolUtils.o: romanSymbolUtils.c romanSymbolUtils.h
	gcc $(CFLAGS) -c romanSymbolUtils.c

test: romanNumeralCalculator-test stringUtils-test romanSymbolUtils-test

romanNumeralCalculator-test: romanNumeralCalculator-test.o romanNumeralCalculator.o romanSymbolUtils.o stringUtils.o
	gcc -o romanNumeralCalculator-test romanNumeralCalculator.o romanNumeralCalculator-test.o romanSymbolUtils.o stringUtils.o $(LIBS)
romanNumeralCalculator-test.o: romanNumeralCalculator-test.c romanNumeralCalculator.h
	gcc $(CFLAGS) -c romanNumeralCalculator-test.c

romanSymbolUtils-test: romanSymbolUtils-test.o romanSymbolUtils.o stringUtils.o
	gcc -o romanSymbolUtils-test romanSymbolUtils.o romanSymbolUtils-test.o stringUtils.o $(LIBS)
romanSymbolUtils-test.o: romanSymbolUtils-test.c romanSymbolUtils.h
	gcc $(CFLAGS) -c romanSymbolUtils-test.c

stringUtils-test: stringUtils-test.o stringUtils.o
	gcc -o stringUtils-test stringUtils.o stringUtils-test.o $(LIBS)
stringUtils-test.o: stringUtils-test.c stringUtils.h
	gcc $(CFLAGS) -c stringUtils-test.c

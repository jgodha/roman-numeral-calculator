<h3>Roman Numeral Calculator</h3>

Supports adding and subtracting two Roman numerals. The program currently does not validate user input.

Developed in C programming language in the following environment -
- Ubuntu	Linux 14.04
-	GNU	GCC	compiler	tool	chain
-	GNU	Make
-	Check	unit	testing	framework	(	https://libcheck.github.io/check/)

Do the following to compile the program
```
checkmk romanNumeralCalculator-test.check >romanNumeralCalculator-test.c
checkmk stringUtils-test.check >stringUtils-test.c
checkmk romanSymbolUtils-test.check >romanSymbolUtils-test.c

make -f romanNumeralCalculator.makefile
make -f romanNumeralCalculator.makefile test
```
<p>You can run the main using 
```
./romanNumeralCalculator
```
<p>
<p>
Tests can be executed as follows - 
```
./romanNumeralCalculator-test, .romanSymbolUtils-test, .stringUtils-test</code>
```
<p>

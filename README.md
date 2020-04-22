# computer-algebra-system
Colloquium on algorithms with long numbers

## Command line interface in Windows
Just download and run the executable file with the label `main.exe` in the release directory if you want to run and test the program.

## Project structure
1. `modules` directory contains `4` subdirectories:
    * N - non-negative integers
    * Z - integers
    * Q - rationals
    * P - polynomials
2. `ui` directory implements the program interface
3. `src` directory contains source file with main function called `main.c`
4. `release` directory contains the executable file with the label `main.exe`

In each module there is `utils` directory with `input` sub-directory which contains input/output functions of corresponding number

## Implementation details
1. Structure for non-negative integer called `longNumberN` consists of the following fields:
   * integer array called `num`
   * length of the number which represents amount of `9` decimal digits
2. Structure for integer called `longNumberZ` consists of the following fields:
   * integer array called `num`
   * length of number which represents amount of `9` decimal digits
   * sign of number:
     * Plus
     * Minus
     * Neutral for zero
3. Structure for rational called `longNumberQ` consists of the following fields:
   * integer called `numerator`
   * non-negative integer called `denominator`
4. Structure for polynomial called `longNumberP` consists of the following fields:
   * rational array which represents polynomial coefficients called `coefficient`
   * degree of polynomial called `degree`

### Functions for non-negative integers
1. **incN** - increasing a number by `1`
2. **sumN** - summation of two numbers
3. **compN** - comparison of two numbers
4. **divN** - division of two numbers
5. **gcfN** - finding greatest common divisor of two numbers
6. **lcmN** - finding least common multiple of two numbers
7. **modN** - finding remainder of division of two numbers
8. **multiByDigit** - multiplication of number and digit
9. **multiN** - multiplication of two numbers
10. **subN** - subtraction of two numbers

### Functions for integers
1. **sumZ** - summation of two numbers
2. **divZ** - division of two numbers
3. **modZ** - finding remainder of division of two numbers
4. **multiZ** - multiplication of two numbers
5. **subZ** - subtraction of two numbers

### Functions for rationals
1. **addQ** - summation of two numbers
2. **divQ** - division of two numbers
3. **isInt** - checking for integer number
4. **mulQ** - multiplication of two numbers
5. **redQ** - fraction reduction
6. **subQ** - subtraction of two numbers

### Functions for polynomials
1. **sumP** - summation of two polynomials
2. **derP** - finding first derivative of polynomial
3. **divP** - division of two polynomials
4. **gcfP** - finding greatest common divisor of two polynomials
5. **modP** - finding remainder of division of two polynomials
6. **mulP** - multiplication of two polynomials
7. **multyByRational** - multiplication of polynomial and rational
8. **subP** - subtraction of two polynomials

# computer-algebra-system
Colloquium on algorithms with long numbers

## Command line interface in Windows
Just download and run the executable file with the label `main.exe` in the release directory if you want to run and test the program.

Note on polynomials:
Input is carried out in the following form: 
1) The polynomial is written from a large degree to a smaller one, i.e. x ^ 2 + x ^ 3 + 4x - Wrong !!!!! Correct - x ^ 3 + x ^ 2 + 4x
2) The coefficients before x are introduced in the form of the fraction or in common form: 1 / 2x ^ 2 + 3x + 4/5

## Input/Output examples
- ![Natural](https://github.com/antisheeeh/computer-algebra-system/blob/master/screenshots/natural_example.PNG)
- ![Integer](https://github.com/antisheeeh/computer-algebra-system/blob/master/screenshots/integer_example.PNG)
- ![Rational](https://github.com/antisheeeh/computer-algebra-system/blob/master/screenshots/rational_example.PNG)
- ![Polynomial](https://github.com/antisheeeh/computer-algebra-system/blob/master/screenshots/polynomial_example.PNG)

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
1. **sumN** - summation of two numbers
2. **compN** - comparison of two numbers
3. **divN** - division of two numbers
4. **gcfN** - finding greatest common divisor of two numbers
5. **lcmN** - finding least common multiple of two numbers
6. **modN** - finding remainder of division of two numbers
7. **multiByDigit** - multiplication of number and digit
8. **multiN** - multiplication of two numbers
9.  **subN** - subtraction of two numbers
### Secondary functions
1. **incN** - increasing a number by `1`

### Functions for integers
1. **sumZ** - summation of two numbers
2. **divZ** - division of two numbers
3. **modZ** - finding remainder of division of two numbers
4. **multiZ** - multiplication of two numbers
5. **subZ** - subtraction of two numbers
### Secondary functions
1. **abosule** - return absolute value of number
2. **changeSign** - change sign of number
3. **getSign** - return sign of number
4. **transNtoZ** - Converting a natural number to an integer
5. **transZtoN** - Converting a integer to a natural number

### Functions for rationals
1. **addQ** - summation of two numbers
2. **divQ** - division of two numbers
3. **mulQ** - multiplication of two numbers
4. **redQ** - fraction reduction
5. **subQ** - subtraction of two numbers
### Secondary functions
1. **isInt** - checking for integer number
2. **transQtoZ** - Converting a rational number to an integer
3. **transZtoQ** - Converting a integer to a rational number

### Functions for polynomials
1. **sumP** - summation of two polynomials
2. **divP** - division of two polynomials
3. **derP** - finding first derivative of polynomial
4. **multyByRational** - multiplication of polynomial and rational
5. **subP** - subtraction of two polynomials
6. **modP** - finding remainder of division of two polynomials 
7. **mulP** - multiplication of two polynomials
8. **gcfP** - finding greatest common divisor of two polynomials
9. **multyByXk** - multiplication of a polynomial by x ^ k
### Secondary functions
1. **facP** - removal from the polynomial lcm of denominator and gcf from numenator
2. **led** - finding the highest polynomial coefficient
3. **deg** - finding number degree

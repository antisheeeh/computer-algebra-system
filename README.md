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
   * integer
   * non-negative integer
4. Structure for polynomial called `longNumberP` consists of the following fields:
   * rational array which represents polynomial coefficients
   * degree of polynomial
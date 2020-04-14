#include <stdio.h>
#include <stdlib.h>

#include "../../ui/lib/N_FUNC_LIST.h"
#include "../../ui/lib/Z_FUNC_LIST.h"
#include "../../ui/lib/Q_FUNC_LIST.h"

#include "../lib/menu.h"

#ifdef linux
#define CLS system("clear")
#else
#define CLS system("cls")
#endif

void (*menu[NUMBER_OF_BLOCS])();
void (*natural[NUMBER_OF_NFUNC])();
void (*whole[NUMBER_OF_ZFUNC])();
void (*rational[NUMBER_OF_QFUNC])();
void (*polynomial[NUMBER_OF_PFUNC])();

void showHelp() {
    int c;

	puts("\nPress any key to continue...");
	getchar();
	CLS;

	do {
	    puts("Do you want back to start menu?");
		puts("1 - Yes");
		puts("2 - No");

		c = getchar();
	    CLS;
	} while (c < '1' || c > '2');

	if (c == '1') {
        showMenu();
    }
}

void showMenu() {
	int c;	
    
    do {
    	puts("Please choose type of number");
		puts("1 - Natural");
		puts("2 - Whole number");
		puts("3 - Rational");
		puts("4 - Polynomial");

		puts("Press 'Q' to exit from program");

    	c = getchar();

		CLS;

		if(c == 'Q') {
			return;
		}

    } while (c < '1' || c > '4');

	menu[c - '1']();
}

void naturalMenu() {	
	int c;

    do {
    	puts("The natural number menu:");
    	puts("A - Compare 2 numbers");
		puts("B - Addition 1 to number");
		puts("C - Addition 2 numbers");
		puts("D - Subtraction 2 numbers");
		puts("E - Multiplication 2 numbers");
		puts("F - Division of 2 numbers");
		puts("G - Calculate the remainder of division");
		puts("H - GCF of 2 numbers");
		puts("I - LCM of 2 numbers");

		puts("Q - Back to start menu");

		puts("Enter your choose");
		
		c = getchar();

		CLS;

		if(c == 'Q') {
			showMenu();
			return;
		}
	} while(c < 'A' || c > 'I');

	getchar();

	natural[c - 'A']();
	showHelp();
}

void integerMenu() {
	int c;

    do {
		puts("A - Addition 2 numbers");
		puts("B - Subtraction 2 numbers");
		puts("C - Multiplication 2 numbers");
		puts("D - Division 2 numbers");
		puts("E - Calculate the remainder of division");

		puts("Q - Back to start menu");

		puts("Enter your choose: ");		

		c = getchar();

		CLS;

		if(c == 'Q') {
			showMenu();
			return;
		}
	} while(c < 'A'|| c > 'E');

	getchar();

	whole[c - 'A']();
	showHelp();
}

void rationalMenu() {
	int c;

	do {
		puts("A - Reduction of fraction");
		puts("B - Check for integer");
		puts("C - Addition 2 numbers");
		puts("D - Subtraction 2 numbers");
		puts("E - Multiplication 2 numbers");
		puts("F - Division 2 numbers");

		puts("Q - Back to start menu");

		puts("Enter your choose");

		c = getchar();

		CLS;

		if(c == 'Q') {
			showMenu();
			return;
		}
	} while(c < 'A'|| c > 'F');

	getchar();

	rational[c - 'A']();
	showHelp();
}

void polynomialMenu() {	
	int c;

	do {
		puts("A - Addition 2 polinomials");
		puts("B - Subtraction 2 polinomials");
		puts("C - Multiply polinomial by rational number");
		puts("D - Multiply polinomial by x^k");
		puts("E - Leading coefficient of polynomial");
		puts("F - Highest degree of the polynomial");
		puts("G - The derivation of a coefficient from a polynomial");
		puts("H - Multiplication 2 polinomials");
		puts("I - Division 2 polinomials");
		puts("J - Calculate the remainder of division 2 polinomials");
		puts("K - GCF of 2 polinomials");
		puts("L - Derivative of polinomial");
		puts("M - Multiple roots in simple");
		puts("N - Back to start menu");
		puts("Enter your choose");

		c = getchar();
		CLS;
	} while(c < 'A'|| c > 'N');

	getchar();

	if(c - 'A' == 13) {
		showMenu();
	} else {
		polynomial[c - 'A']();
		showHelp();
	}
}

void init() {
	initMenu();
	initNatural();
	initWhole();
	initRational();
	initPolynomial();
}

void initMenu() {
	menu[0] = naturalMenu;
    menu[1] = integerMenu;
    menu[2] = rationalMenu;
    menu[3] = polynomialMenu;
}

void initNatural() {
	natural[0] = menu_COM_NN;
	natural[1] = menu_ADD_1N_N;
	natural[2] = menu_ADD_NN_N;
	natural[3] = menu_SUB_NN_N;
	natural[4] = menu_MUL_NN_N;
	natural[5] = menu_DIV_NN_N;
	natural[6] = menu_MOD_NN_N;
	natural[7] = menu_GCF_NN_N;
	natural[8] = menu_LCM_NN_N;
}

void initWhole() {
	whole[0] = menu_ADD_ZZ_Z;
	whole[1] = menu_SUB_ZZ_Z;
	whole[2] = menu_MUL_ZZ_Z;
	whole[3] = menu_DIV_ZZ_Z;
	whole[4] = menu_MOD_ZZ_Z;
}

void initRational() {
	rational[0] = menu_RED_QQ_Q;
	rational[1] = menu_INT_Q;
	rational[2] = menu_ADD_QQ_Q;
	rational[3] = menu_SUB_QQ_Q;
	rational[4] = menu_MUL_QQ_Q;
	rational[5] = menu_DIV_QQ_Q;
}

void initPolynomial() {
	/*polynomial[0] = menu_ADD_PP_P;
	polynomial[1] = menu_SUB_PP_P;
	polynomial[2] = menu_MUL_PQ_P;
	polynomial[3] = menu_MUL_Pxk_P;
	polynomial[4] = menu_LED_L_Q;
	polynomial[5] = menu_DEG_P_N;
	polynomial[6] = menu_FAC_P_Q;
	polynomial[7] = menu_MUL_PP_P;
	polynomial[8] = menu_DIV_PP_P;
	polynomial[9] = menu_MOD_PP_P;
	polynomial[10] = menu_GCF_PP_P;
	polynomial[11] = menu_DER_P_P;
	polynomial[12] = menu_NMR_P_P;*/
}
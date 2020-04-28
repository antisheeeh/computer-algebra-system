#include <stdio.h>
#include <stdlib.h>

#include "../../ui/lib/N_FUNC_LIST.h"
#include "../../ui/lib/Z_FUNC_LIST.h"
#include "../../ui/lib/Q_FUNC_LIST.h"
#include "../../ui/lib/P_FUNC_LIST.h"

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

	getchar();

	if (c == '1') {
        showMenu();
    }
}

void showMenu() {
	int c;	
    
    do {
    	puts("Please choose type of number");
		puts("1 - Natural");
		puts("2 - Integer");
		puts("3 - Rational");
		puts("4 - Polynomial");

		puts("Press 'Q' to exit from program");

    	c = getchar();

		CLS;

		if(c == 'Q') {
			return;
		}

    } while (c < '1' || c > '4');

	getchar();

	menu[c - '1']();
}

void naturalMenu() {	
	int c;

    do {
    	puts("The natural number menu:");
    	puts("A - Compare 2 numbers");
		puts("B - Addition 2 numbers");
		puts("C - Subtraction 2 numbers");
		puts("D - Multiplication 2 numbers");
		puts("E - Division 2 numbers");
		puts("F - Remainder of division 2 numbers");
		puts("G - GCF 2 numbers");
		puts("H - LCM 2 numbers");

		puts("Q - Back to start menu");

		puts("Enter your choose");
		
		c = getchar();

		CLS;

		if(c == 'Q') {
			showMenu();
			return;
		}
	} while(c < 'A' || c > 'H');

	getchar();

	puts("Natural");
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
		puts("E - Remainder of division 2 numbers");

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

	puts("Integer");
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

	puts("Rational");
	rational[c - 'A']();
	showHelp();
}

void polynomialMenu() {	
	int c;

	do {
		puts("A - Addition 2 polynomials");
		puts("B - Subtraction 2 polynomials");
		puts("C - Multiplication 2 polynomials");
		puts("D - Division 2 polynomials");
		puts("E - Calculate the remainder of division 2 polynomials");
		puts("F - GCF of 2 polynomials");
		puts("G - Derivative of polynomial");
		puts("H - Multiple roots to simple");

		puts("Q - Back to start menu");
		
		puts("Enter your choose");

		c = getchar();

		CLS;

		if(c == 'Q'){
			showMenu();
			return;
		};

	} while(c < 'A'|| c > 'I');

	getchar();

	puts("Polynomial");
	polynomial[c - 'A']();
	showHelp();
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
	natural[1] = menu_ADD_NN_N;
	natural[2] = menu_SUB_NN_N;
	natural[3] = menu_MUL_NN_N;
	natural[4] = menu_DIV_NN_N;
	natural[5] = menu_MOD_NN_N;
	natural[6] = menu_GCF_NN_N;
	natural[7] = menu_LCM_NN_N;
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
	polynomial[0] = menu_ADD_PP_P;
	polynomial[1] = menu_SUB_PP_P;
	polynomial[2] = menu_MUL_PP_P;
	polynomial[3] = menu_DIV_PP_P;
	polynomial[4] = menu_MOD_PP_P;
	polynomial[5] = menu_GCF_PP_P;
	polynomial[6] = menu_DER_P_P;
	polynomial[7] = menu_NMR_P_P;
}
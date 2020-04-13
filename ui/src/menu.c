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

void show_help() {
    int choice;

	puts("\nPress any key to continue...");
	getchar();
	CLS;

	do {
	    puts("Do you want back to start menu?\n1 - Yes\n2 - No");	
	    scanf("%d", &choice);
	    CLS;
	} while (choice < 1 || choice > 2);

	if (choice == 1) {
        show_menu();
    }
}

void show_menu() {
	int choice;	
    
    do {
    	puts("Please choose type of number");
		puts("1 - Natural\n2 - Whole number\n3 - Rational\n4 - Polynomial\nPress '5' to exit from program");

    	scanf("%d", &choice);
    	CLS;
    } while (choice < 1 || choice > 5);

	if (choice == 5){
		CLS;
	} else {
		menu[choice - 1]();
	}
}

void Natural_menu() {	
	int c;

    do {
    	puts("The natural number menu:");
    	puts("A - Compare 2 numbers");
		puts("B - Check number for zero");
		puts("C - Addition 1 to number");
		puts("D - Addition 2 numbers");
		puts("E - Subtraction 2 numbers");
		puts("F - Multiplying number by digit");
		puts("G - Multiplying number by 10^k");
		puts("H - Multiplication 2 numbers");
		puts("I - Subtraction from number other number, multiplied by a digit");
		puts("J - Calculate the first digit of the division, multiplied by 10^k");
		puts("K - Division of 2 numbers");
		puts("L - Calculate the remainder of division");
		puts("M - GCF of 2 numbers");
		puts("N - LCM of 2 numbers");
		puts("O - Back to start menu");

		puts("Enter your choose");
		
		c = getchar();
		CLS;
	} while(c < 'A' || c > 'O');

	getchar();

	if(c - 'A' == 14) {
		show_menu();
	} else {
		natural[c - 'A']();
		show_help();
	}
}

void Whole_menu() {
	int c;

    do {
    	puts("A - Absolute number");
		puts("B - Sign of number");
		puts("C - Change sign of number");
		puts("D - Translate natural to integer");
		puts("E - Translate integer to natural");
		puts("F - Addition 2 numbers");
		puts("G - Subtraction 2 numbers");
		puts("H - Multiplication 2 numbers");
		puts("I - Division 2 numbers");
		puts("J - Calculate the remainder of division");
		puts("K - Back to start menu");
		puts("Enter your choose: ");		

		c = getchar();
		CLS;
	} while(c < 'A'|| c > 'K');

	getchar();

	if(c - 'A' == 10) {
		show_menu();
	} else {
		whole[c - 'A']();
		show_help();
	}
}

void Rational_menu() {
	int c;
	do{
		puts("A - Reduction of fraction");
		puts("B - Check for integer");
		puts("C - Translate integer to rational");
		puts("D - Translate rational to integer");
		puts("E - Addition 2 numbers");
		puts("F - Subtraction 2 numbers");
		puts("G - Multiplication 2 numbers");
		puts("H - Division 2 numbers");
		puts("I - Back to start menu");
		puts("Enter your choose");

		c = getchar();
		CLS;
	} while(c < 'A'|| c > 'I');

	getchar();

	if(c - 'A' == 8) {
		show_menu();
	} else {
		rational[c - 'A']();
		show_help();
	}
}

void Polynomial_menu() {	
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
		show_menu();
	} else {
		polynomial[c - 'A']();
		show_help();
	}
}

void init() {
	initMenu();
	initNatural();
	initRational();
	initPolynomial();
}

void initMenu() {
	menu[0] = Natural_menu;
    menu[1] = Whole_menu;
    menu[2] = Rational_menu;
    menu[3] = Polynomial_menu;
}

void initNatural() {
	natural[0] = menu_COM_NN;
	natural[1] = menu_NZER_N_B;
	natural[2] = menu_ADD_1N_N;
	natural[3] = menu_ADD_NN_N;
	natural[4] = menu_SUB_NN_N;
	natural[5] = menu_MUL_ND_N;
	natural[6] = menu_MUL_NK_N;
	natural[7] = menu_MUL_NN_N;
	natural[8] = menu_SUB_NDN_N;
	natural[9] = menu_DIV_NN_DK;
	natural[10] = menu_DIV_NN_N;
	natural[11] = menu_MOD_NN_N;
	natural[12] = menu_GCF_NN_N;
	natural[13] = menu_LCM_NN_N;
}

void initWhole() {
	whole[0] = menu_ABS_Z_N;
	whole[1] = menu_POZ_Z_D;
	whole[2] = menu_MUL_ZM_Z;
	whole[3] = menu_TRANS_N_Z;
	whole[4] = menu_TRANS_Z_N;
	whole[5] = menu_ADD_ZZ_Z;
	whole[6] = menu_SUB_ZZ_Z;
	whole[7] = menu_MUL_ZZ_Z;
	whole[8] = menu_DIV_ZZ_Z;
	whole[9] = menu_MOD_ZZ_Z;
}

void initRational() {
	rational[0] = menu_RED_QQ_Q;
	rational[1] = menu_INT_Q;
	rational[2] = menu_TRANS_Z_Q;
	rational[3] = menu_TRANS_Q_Z;
	rational[4] = menu_ADD_QQ_Q;
	rational[5] = menu_SUB_QQ_Q;
	rational[6] = menu_MUL_QQ_Q;
	rational[7] = menu_DIV_QQ_Q;
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
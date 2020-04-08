#include <stdio.h>
#include <stdlib.h>

#include "../../ui/lib/N_FUNC_LIST.h"
#include "../../ui/lib/Z_FUNC_LIST.h"

#include "../lib/menu.h"

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
    void (**kind)() = malloc(NUMBER_OF_BLOCS * sizeof(void (*)()));
    if (kind == NULL) return;
    
    //Array of function pointers
    
    kind[0] = Natural_menu;
    kind[1] = Whole_menu;
    kind[2] = Rational_menu;
    kind[3] = Polynomial_menu;
    
    //User choice
    
    do {
    	puts("Please choose type of number");
		puts("1 - Natural\n2 - Whole number\n3 - Rational\n4 - Polynomial\nPress '5' to exit from program");

    	scanf("%d", &choice);
    	CLS;
    } while (choice < 1 || choice > 5);

	if (choice == 5){
		CLS;
	} else {
		kind[choice - 1]();
	}

	free(kind);
	kind = NULL;
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

	void (**kind)() = malloc(NUMBER_OF_NFUNC * sizeof(void(*)()));
	if (kind == NULL) return;

	kind[0] = menu_COM_NN;
	kind[1] = menu_NZER_N_B;
	kind[2] = menu_ADD_1N_N;
	kind[3] = menu_ADD_NN_N;
	kind[4] = menu_SUB_NN_N;
	kind[5] = menu_MUL_ND_N;
	kind[6] = menu_MUL_NK_N;
	kind[7] = menu_MUL_NN_N;
	kind[8] = menu_SUB_NDN_N;
	kind[9] = menu_DIV_NN_DK;
	kind[10] = menu_DIV_NN_N;
	kind[11] = menu_MOD_NN_N;
	kind[12] = menu_GCF_NN_N;
	//kind[13] = menu_LCM_NN_N;
	kind[14] = show_menu;
	//fflush(stdin);
	getchar();

	kind[c - 'A']();

	free(kind);
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

	void (**kind)() = malloc(NUMBER_OF_NFUNC * sizeof(void(*)()));
	if (kind == NULL) return;

	kind[0] = menu_ABS_Z_N;
	kind[1] = menu_POZ_Z_D;
	kind[2] = menu_MUL_ZM_Z;
	kind[3] = menu_TRANS_N_Z;
	kind[4] = menu_TRANS_Z_N;
	kind[5] = menu_ADD_ZZ_Z;
	kind[6] = menu_SUB_ZZ_Z;
	kind[7] = menu_MUL_ZZ_Z;
	//kind[8] = menu_DIV_ZZ_Z;
	//kind[9] = menu_MOD_ZZ_Z;
	kind[10] = show_menu;
	getchar();

	kind[c - 'A']();

	free(kind);
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

	void (**kind)() = malloc(NUMBER_OF_NFUNC * sizeof(void(*)()));
	if (kind == NULL) return;
	/*
	kind[0] = menu_RED_Q_Q();
	kind[1] = menu_INT_Q_B();
	kind[2] = menu_TRANS_Z_Q();
	kind[3] = menu_TRANS_Q_Z();
	kind[4] = menu_ADD_QQ_Q();
	kind[5] = menu_SUB_QQ_Q();
	kind[6] = menu_MUL_QQ_Q();
	kind[7] = menu_DIV_QQ_Q();
	*/
	kind[8] = show_menu;	
	getchar();

	kind[c - 'A']();

	free(kind);
}

void Polynomial_menu() {	
	int c;
	do{
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
	} while(c < 'A'|| c > 'Y');

	void (**kind)() = malloc(NUMBER_OF_NFUNC * sizeof(void(*)()));
	if (kind == NULL) return;
	/*
	kind[0] = menu_ADD_PP_P();
	kind[1] = menu_SUB_PP_P();
	kind[2] = menu_MUL_PQ_P();
	kind[3] = menu_MUL_Pxk_P();
	kind[4] = menu_LED_L_Q();
	kind[5] = menu_DEG_P_N();
	kind[6] = menu_FAC_P_Q();
	kind[7] = menu_MUL_PP_P();
	kind[8] = menu_DIV_PP_P();
	kind[9] = menu_MOD_PP_P();
	kind[10] = menu_GCF_PP_P();
	kind[11] = menu_DER_P_P();
	kind[12] = menu_NMR_P_P();
	*/
	kind[13] = show_menu;
	getchar();
	kind[c - 'A']();

	free(kind);
}
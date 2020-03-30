#include <stdio.h>
#include <stdlib.h>

#include "../N_FUNC_LIST.h"
#include "../Z_FUNC_LIST.h"
#include "menu.h"

#define NUMBER_OF_BLOCS 4
#define NUMBER_OF_NFUNC 15

void show_menu(){
	void (**kind)() = NULL;
	int user_choice;	
    kind = malloc(NUMBER_OF_BLOCS * sizeof(void (*)()));
    if (kind == NULL) return;
    
    //Array of function pointers
	
    
    kind[0] = Natural_menu;
    kind[1] = Whole_menu;
    kind[2] = Rational_menu;
    kind[3] = Polynomial_menu;
    
    //User choice
    
    do {
        printf("Please choose type of number\n");
		printf("1 - Natural\n2 - Whole number\n3 - Rational\n4 - Polynomial\nPress '5' to exit from program\n");
        scanf("%d", &user_choice);
        system("cls");
    } while ((user_choice < 1) || (user_choice > 5));
	if (user_choice == 5){
		system("cls");
	}
	else kind[user_choice-1]();
	free(kind);
	kind = NULL;
}

void Natural_menu() {	
	int c;
    void (**kind)() = NULL;
    do{
    printf("The natural number menu:\n");
    printf("A - Compare 2 numbers\n");
	printf("B - Check number for zero\n");
	printf("C - Addition 1 to number\n");
	printf("D - Addition 2 numbers\n");
	printf("E - Subtraction 2 numbers\n");
	printf("F - Multiplying number by digit\n");
	printf("G - Multiplying number by 10^k\n");
	printf("H - Multiplication 2 numbers\n");
	printf("I - Subtraction from number other number, multiplied by a digit\n");
	printf("J - Calculate the first digit of the division, multiplied by 10^k\n");
	printf("K - Division of 2 numbers\n");
	printf("L - Calculate the remainder of division\n");
	printf("M - GCF of 2 numbers\n");
	printf("N - LCM of 2 numbers\n");
	printf("O - Back to start menu\n");
	printf("Enter your choose: ");
	fflush(stdin);
	c = getchar();
	system("cls");
	}while((c < 'A') || (c > 'O'));

	kind = malloc(NUMBER_OF_NFUNC * sizeof(void(*)()));
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
	//kind[10] = menu_DIV_NN_N;
	//kind[11] = menu_MOD_NN_N;
	//kind[12] = menu_GCF_NN_N;
	//kind[13] = menu_LCM_NN_N;
	kind[14] = show_menu;
	fflush(stdin);
	kind[c-65]();
	free(kind);
	kind = NULL;
}

void Whole_menu() {
	int c;
    void (**kind)() = NULL;
    do{
    printf("A - Absolute number\n");
	printf("B - Sign of number\n");
	printf("C - Change sign of number\n");
	printf("D - Translate natural to integer\n");
	printf("E - Translate integer to natural\n");
	printf("F - Addition 2 numbers\n");
	printf("G - Subtraction 2 numbers\n");
	printf("H - Multiplication 2 numbers\n");
	printf("I - Division 2 numbers\n");
	printf("J - Calculate the remainder of division\n");
	printf("K - Back to start menu\n");
	printf("Enter your choose: ");
	fflush(stdin);
	c = getchar();
	system("cls");
	}while((c < 'A') || (c > 'K'));
	kind = malloc(NUMBER_OF_NFUNC * sizeof(void(*)()));
	if (kind == NULL) return;
	kind[0] = menu_ABS_Z_N;
	//kind[1] = menu_POZ_Z_D;
	//kind[2] = menu_MUL_ZM_Z;
	//kind[3] = menu_TRANS_N_Z;
	//kind[4] = menu_TRANS_Z_N;
	//kind[5] = menu_ADD_ZZ_Z;
	//kind[6] = menu_SUB_ZZ_Z;
	//kind[7] = menu_MUL_ZZ_Z;
	//kind[8] = menu_DIV_ZZ_Z;
	//kind[9] = menu_MOD_ZZ_Z;
	kind[10] = show_menu;
	fflush(stdin);
	kind[c-65]();
	free(kind);
	kind = NULL;
}

void Rational_menu() {
    printf("A - Reduction of fraction\n");
	printf("B - Check for integer\n");
	printf("C - Translate integer to rational\n");
	printf("D - Translate rational to integer\n");
	printf("E - Addition 2 numbers\n");
	printf("F - Subtraction 2 numbers\n");
	printf("G - Multiplication 2 numbers\n");
	printf("H - Division 2 numbers\n");
	printf("I - Back to start menu\n");
	printf("Enter your choose: ");
}

void Polynomial_menu() {	
	printf("A - Addition 2 polinomials\n");
	printf("B - Subtraction 2 polinomials\n");
	printf("C - Multiply polinomial by rational number\n");
	printf("D - Multiply polinomial by x^k\n");
	printf("E - Leading coefficient of polynomial\n");
	printf("F - Highest degree of the polynomial\n");
	printf("G - The derivation of a coefficient from a polynomial\n");
	printf("H - Multiplication 2 polinomials\n");
	printf("I - Division 2 polinomials\n");
	printf("J - Calculate the remainder of division 2 polinomials\n");
	printf("K - GCF of 2 polinomials\n");
	printf("L - Derivative of polinomial\n");
	printf("M - Multiple roots in simple\n");
	printf("Y - Back to start menu\n");
	printf("Enter your choose: ");
}
#include <stdio.h>
#include <stdlib.h>

#include "utils/input.h"
#include "utils/memory.h"
#include "utils/menu.h"

#include "modules/N/lib/number.h"

#include "modules/N/lib/COM_NN_D/COM_NN_D.h"
#include "modules/N/lib/NZER_N_B/NZER_N_B.h"
#include "modules/N/lib/ADD_1N_N/ADD_1N_N.h"
#include "modules/N/lib/ADD_NN_N/ADD_NN_N.h"
#include "modules/N/lib/SUB_NN_N/SUB_NN_N.h"
#include "modules/N/lib/MUL_ND_N/MUL_ND_N.h"
#include "modules/N/lib/MUL_NK_N/MUL_NK_N.h"
#include "modules/N/lib/MUL_NN_N/MUL_NN_N.h"
#include "modules/N/lib/SUB_NDN_N/SUB_NDN_N.h"
#include "modules/N/lib/DIV_NN_Dk/DIV_NN_Dk.h"

#include "N_FUNC_LIST.h"

void show_help(){
    int user_choice;
    fflush(stdin);
	printf("\nPress any key to continue...");
	getchar();
	system("cls");
	do{
	printf("Do you want back to start menu?\n1 - Yes\n2 - No\n");	
	scanf("%d", &user_choice);
	system("cls");
	} while ((user_choice < 1) || (user_choice > 2));
	if (user_choice == 1) show_menu();
    else printf("Bye...");
}

//Compare 2 numbers

void menu_COM_NN(){
    printf("Please enter first number: ");
    char* str = getString();
    printf("Please enter second number: ");
    char *str1 = getString();

    longNumber* a = parseNumber(str);
    longNumber* b = parseNumber(str1);
    
    int answer = compare(a, b);
    if(answer == GREATER) puts("The first number is greater than the second");
    else if(answer == LESS) puts("The first number is less than the second");
    else if(answer == EQUAL) puts("The first number is equal to the second");
    
    clearString(str);
    clearString(str1);
    clearStruct(a);
    clearStruct(b);

    show_help();
}

//Check number for zero

void menu_NZER_N_B(){
    printf("Please enter number: ");
    char* str = getString();

    longNumber* a = parseNumber(str);

    int res = isZero(a);

    if(res == YES) printf("Yes");
    else if(res == NO) printf("No");

    show_help();
}

//Addition 1 to number

void menu_ADD_1N_N(){
    printf("Please enter a number: ");
    char *str = getString();

    longNumber* a = parseNumber(str);

    printf("Answer: ");
    printf("%s",toString(add_1n(a)));
    
    show_help();
}


//Addition 2 numbers

void menu_ADD_NN_N(){
    printf("Please enter first number: ");
    char* str = getString();
    printf("Please enter second number: ");
    char *str1 = getString();

    longNumber* a = parseNumber(str);
    longNumber* b = parseNumber(str1);

    printf("Answer: ");
    printf("%s",toString(sum(a, b)));

    clearString(str);
    clearString(str1);
    clearStruct(a);
    clearStruct(b);

    show_help();
}


//Subtraction 2 numbers

void menu_SUB_NN_N(){
    printf("Please enter first number: ");
    char* str = getString();
    printf("Please enter second number: ");
    char *str1 = getString();

    longNumber* a = parseNumber(str);
    longNumber* b = parseNumber(str1);

    printf("Answer: ");
    printf("%s",toString(sub(a, b)));

    clearString(str);
    clearString(str1);
    clearStruct(a);
    clearStruct(b);

    show_help();
}

//Multiplying number by digit

void menu_MUL_ND_N(){
    printf("Please enter first number: ");
    char* str = getString();
    printf("Please enter second number: ");
    char *str1 = getString();

    longNumber* a = parseNumber(str);
    longNumber* b = parseNumber(str1);

    printf("Answer: ");
    printf("%s",toString(multiByDigit(a, b->num[0])));

    clearString(str);
    clearString(str1);
    clearStruct(a);
    clearStruct(b);

    show_help();
}

//Multiplying number by 10^k

void menu_MUL_NK_N(){
    int k;
    printf("Please enter number: ");
    char* a = getString();
    longNumber* num = parseNumber(a);
    printf("Please enter 'k': ");
    scanf("%d", &k);
    printf("Answer: ");
    printf("%s",toString(multiplyBy10k(num, k)));

    clearStruct(num);
    clearString(a);

    show_help();
}


//Multiplication 2 numbers

void menu_MUL_NN_N(){
    printf("Please enter first number: ");
    char* str = getString();
    printf("Please enter second number: ");
    char *str1 = getString();

    longNumber* a = parseNumber(str);
    longNumber* b = parseNumber(str1);

    printf("Answer: ");
    printf("%s",toString(multi(a,b)));
    clearString(str);
    clearString(str1);
    clearStruct(a);
    clearStruct(b);

    show_help();
}

void menu_DIV_NN_DK(){
    printf("Please enter first number: ");
    char* str = getString();
    printf("Please enter second number: ");
    char *str1 = getString();
    printf("Please enter the power of ten: ");
    int k;
    scanf("%d", &k);

    longNumber* a = parseNumber(str);
    longNumber* b = parseNumber(str1);

    printf("Answer: %d", div_nn_dk(a, b, k));

    clearString(str);
    clearString(str1);
    clearStruct(a);
    clearStruct(b);

    show_help();
}

void menu_SUB_NDN_N(){
    printf("Please enter first number: ");
    char* str = getString();
    printf("Please enter second number: ");
    char *str1 = getString();
    printf("Please enter the digit: ");
    int d;
    scanf("%d", &d);

    longNumber* a = parseNumber(str);
    longNumber* b = parseNumber(str1);

    printf("Answer: %d", sub_ndn(a, b, d));

    clearString(str);
    clearString(str1);
    clearStruct(a);
    clearStruct(b);

    show_help();
}

/*
//Subtraction from number other number, multiplied by a di

//Division of 2 numbers

void menu_DIV_NN_N(){

}

//Calculate the remainder of division

void menu_MOD_NN_N(){

}

//GCF of 2 numbers

void menu_GCF_NN_N(){

}

//LCM of 2 numbers

void menu_LCM_NN_N(){

}

*/
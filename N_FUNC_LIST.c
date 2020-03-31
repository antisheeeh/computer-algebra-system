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

//Compare 2 numbers

void menu_COM_NN(){
    char *str1, *str2;

    puts("Please enter a first number");
    str1 = getString();
    longNumber* a = parseNumber(str1);

    puts("Please enter a second number");
    str2 = getString();
    longNumber* b = parseNumber(str2);
    
    int res = compare(a, b);

    puts("");
    
    if(res == GREATER) puts("The first number is greater than the second");
    else if(res == LESS) puts("The first number is less than the second");
    else if(res == EQUAL) puts("The first number is equal to the second");
    
    clearString(str1);
    clearString(str2);
    clearStruct(a);
    clearStruct(b);

    show_help();
}

//Check number for zero

void menu_NZER_N_B(){
    puts("Please enter a number");
    char* str = getString();
    longNumber* a = parseNumber(str);

    int res = isZero(a);

    puts("");

    if(res == YES) puts("The number is zero");
    else if(res == NO) puts("The number is not zero");

    clearString(str);
    clearStruct(a);

    show_help();
}

//Addition 1 to number

void menu_ADD_1N_N(){
    puts("Please enter a number");
    char *str = getString();
    longNumber* a = parseNumber(str);

    puts("");

    puts("Result");
    longNumber* c = add_1n(a);
    char* res = toString(c);
    puts(res);

    clearString(str);
    clearString(res);
    clearStruct(a);
    clearStruct(c);
    
    show_help();
}


//Addition 2 numbers

void menu_ADD_NN_N(){
    char *str1, *str2;

    puts("Please enter a first number");
    str1 = getString();
    longNumber* a = parseNumber(str1);

    puts("Please enter a second number");
    str2 = getString();
    longNumber* b = parseNumber(str2);

    puts("");

    puts("Result");
    longNumber* c = sum(a, b);
    char* res = toString(c);
    puts(res);

    clearString(str1);
    clearString(str2);
    clearString(res);
    clearStruct(a);
    clearStruct(b);
    clearStruct(c);

    show_help();
}


//Subtraction 2 numbers

void menu_SUB_NN_N(){
    char *str1, *str2;

    puts("Please enter a first number");
    str1 = getString();
    longNumber* a = parseNumber(str1);

    puts("Please enter a second number");
    str2 = getString();
    longNumber* b = parseNumber(str2);

    puts("");

    puts("Result");
    longNumber* c = sub(a, b);
    char* res = toString(c);
    puts(res);

    clearString(str1);
    clearString(str2);
    clearString(res);
    clearStruct(a);
    clearStruct(b);
    clearStruct(c);

    show_help();
}

//Multiplying number by digit

void menu_MUL_ND_N(){
    char *str1, *str2;

    puts("Please enter a first number");
    str1 = getString();
    longNumber* a = parseNumber(str1);

    puts("Please enter a second number");
    str2 = getString();
    longNumber* b = parseNumber(str2);

    puts("");

    puts("Result");
    longNumber* c = multiByDigit(a, b->num[0]);
    char* res = toString(c);
    puts(res);

    clearString(str1);
    clearString(str2);
    clearString(res);
    clearStruct(a);
    clearStruct(b);
    clearStruct(c);

    show_help();
}

//Multiplying number by 10^k

void menu_MUL_NK_N(){
    int k;

    puts("Please enter a number");
    char* a = getString();
    longNumber* num = parseNumber(a);

    puts("Please enter a power of ten");
    scanf("%d", &k);

    puts("");

    puts("Result");
    longNumber* c = multiplyBy10k(num, k);
    char* res = toString(c);
    puts(res);

    clearStruct(num);
    clearString(a);
    clearString(res);
    clearStruct(c);

    show_help();
}


//Multiplication 2 numbers

void menu_MUL_NN_N(){
    char *str1, *str2;

    puts("Please enter a first number");
    str1 = getString();
    longNumber* a = parseNumber(str1);

    puts("Please enter a second number");
    str2 = getString();
    longNumber* b = parseNumber(str2);

    puts("");

    puts("Result");
    longNumber* c = multi(a, b);
    char* res = toString(c);
    puts(res);

    clearString(str1);
    clearString(str2);
    clearString(res);
    clearStruct(a);
    clearStruct(b);
    clearStruct(c);

    show_help();
}

void menu_DIV_NN_DK(){
    char *str1, *str2;

    puts("Please enter a first number");
    str1 = getString();
    longNumber* a = parseNumber(str1);

    puts("Please enter a second number");
    str2 = getString();
    longNumber* b = parseNumber(str2);

    puts("");

    puts("Please enter a power of ten");
    int k;
    scanf("%d", &k);

    puts("Result");
    int res = div_nn_dk(a, b, k);
    printf("%d", res);

    clearString(str1);
    clearString(str2);
    clearStruct(a);
    clearStruct(b);

    show_help();
}

void menu_SUB_NDN_N(){
    char *str1, *str2;

    puts("Please enter a first number");
    str1 = getString();
    longNumber* a = parseNumber(str1);

    puts("Please enter a second number");
    str2 = getString();
    longNumber* b = parseNumber(str2);

    puts("Please enter a digit");
    int d;
    scanf("%d", &d);

    puts("");

    puts("Answer");
    longNumber* c = sub_ndn(a, b, d);
    char* res = toString(c);
    puts(res);

    clearString(str1);
    clearString(str2);
    clearString(res);
    clearStruct(a);
    clearStruct(b);
    clearStruct(c);

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
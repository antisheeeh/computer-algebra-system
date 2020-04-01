#include <stdio.h>
#include <stdlib.h>

#include "../../utils/lib/input.h"
#include "../../utils/lib/memory.h"
#include "../../utils/lib/menu.h"
#include "../../modules/N/lib/number.h"

//#include "test.h"

#include "../../modules/Z/lib/ABS_Z_N/ABS_Z_N.h"
#include "../../modules/Z/lib/POZ_Z_D/POZ_Z_D.h"
/*
#include "modules/Z/lib/MUL_ZM_Z/MUL_ZM_Z.h"
#include "modules/Z/lib/TRANS_N_Z/TRANS_N_Z.h"
#include "modules/Z/lib/TRANS_Z_N/TRANS_Z_N.h"
#include "modules/Z/lib/ADD_ZZ_Z/ADD_ZZ_Z.h"
#include "modules/Z/lib/SUB_ZZ_Z/SUB_ZZ_Z.h"
#include "modules/Z/lib/MUL_ZZ_Z/MUL_ZZ_Z.h"
#include "modules/Z/lib/DIV_ZZ_Z/DIV_ZZ_Z.h"
#include "modules/Z/lib/MOD_ZZ_Z/MOD_ZZ_Z.h"
*/
#include "../lib/Z_FUNC_LIST.h"

//Absolute number


void menu_ABS_Z_N(){
    printf("Please enter a number: ");
    char* str = getString();
    longNumber* a = parseNumber(str);
    printf("Answer: ");
    printf("%s", toString(absolute(a)));    
    show_help();
  
}

//Sign of number

void menu_POZ_Z_D(){
    printf("Please enter a number: ");
    char* str = getString();
    longNumber* a = parseNumber(str);
    printf("%d", check_sign(a));
    show_help();
}
/*
//Change sign of number

void menu_MUL_ZM_Z(){
    
    show_help();
}

//Translate natural to integer

void menu_TRANS_N_Z(){
    
    show_help();
}

//Translate integer to natural

void menu_TRANS_Z_N(){
    
    show_help();
}

//Addition 2 numbers

void menu_ADD_ZZ_Z(){
    
    show_help();
}

//Subtraction 2 numbers

void menu_SUB_ZZ_Z(){
    
    show_help();
}

//Multiplication 2 numbers

void menu_MUL_ZZ_Z(){
    
    show_help();
}

//Division 2 numbers

void menu_DIV_ZZ_Z(){
    
    show_help();
}

//Calculate the remainder of division

void menu_MOD_ZZ_Z(){
    
    show_help();
}
*/
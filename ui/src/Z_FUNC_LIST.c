#include <stdio.h>
#include <stdlib.h>

#include "../../modules/Z/utils/lib/input.h"
#include "../../modules/N/utils/lib/memory.h"
#include "../lib/menu.h"
#include "../../modules/Z/lib/number.h"

#include "../../modules/Z/lib/ABS_Z_N.h"
#include "../../modules/Z/lib/POZ_Z_D.h"
#include "../../modules/Z/lib/MUL_ZM_Z.h"

/*
#include "../../modules/Z/lib/TRANS_N_Z.h"
#include "../../modules/Z/lib/TRANS_Z_N.h"
*/
#include "../../modules/Z/lib/ADD_ZZ_Z.h"
/*
#include "modules/Z/lib/SUB_ZZ_Z.h"
#include "../../modules/Z/lib/MUL_ZZ_Z.h"
#include "../../modules/Z/lib/DIV_ZZ_Z.h"
#include "../../modules/Z/lib/MOD_ZZ_Z.h"
*/

#include "../lib/Z_FUNC_LIST.h"

//Absolute number

void menu_ABS_Z_N() {
    printf("Please enter a number: ");
    char* str = getStringZ();
    longNumberZ* a = parseNumberZ(str);
    printf("Answer: ");
    printf("%s", toStringZ(absolute(a)));    
    show_help();
  
}

//Sign of number
/*
void menu_POZ_Z_D() {
    printf("Please enter a number: ");
    char* str = getStringZ();
    longNumberZ* a = parseNumberZ(str);
    printf("%d", getSign(a));
    show_help();
}

/*
//Change sign of number

void menu_MUL_ZM_Z() {
    puts("Please enter a number: ");
    char* str = getString();
    longNumber* a = parseNumber(str);
    
    changeSign(a);
    
    //puts(toString(a));
    int i;
    for(i = a->len - 1; i >= 0; --i) printf("%d", a->num[i]);
    show_help();
}

//Translate natural to integer

void menu_TRANS_N_Z() {
    
    show_help();
}

//Translate integer to natural

void menu_TRANS_Z_N() {
    
    show_help();
}

//Addition 2 numbers

void menu_ADD_ZZ_Z() {
    
    show_help();
}

//Subtraction 2 numbers

void menu_SUB_ZZ_Z() {
    
    show_help();
}

//Multiplication 2 numbers

void menu_MUL_ZZ_Z() {
    
    show_help();
}

//Division 2 numbers

void menu_DIV_ZZ_Z() {
    
    show_help();
}

//Calculate the remainder of division

void menu_MOD_ZZ_Z() {
    
    show_help();
}
*/
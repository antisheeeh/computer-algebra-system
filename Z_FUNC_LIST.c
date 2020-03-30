#include <stdio.h>
#include <stdlib.h>

#include "utils/input.h"
#include "utils/memory.h"
#include "utils/menu.h"
#include "modules/N/lib/number.h"

//#include "test.h"

#include "modules\Z\lib\ABS_Z_N\ABS_Z_N.h"
/*
#include "modules/Z/lib/POZ_Z_D/POZ_Z_D.h"
#include "modules/Z/lib/MUL_ZM_Z/MUL_ZM_Z.h"
#include "modules/Z/lib/TRANS_N_Z/TRANS_N_Z.h"
#include "modules/Z/lib/TRANS_Z_N/TRANS_Z_N.h"
#include "modules/Z/lib/ADD_ZZ_Z/ADD_ZZ_Z.h"
#include "modules/Z/lib/SUB_ZZ_Z/SUB_ZZ_Z.h"
#include "modules/Z/lib/MUL_ZZ_Z/MUL_ZZ_Z.h"
#include "modules/Z/lib/DIV_ZZ_Z/DIV_ZZ_Z.h"
#include "modules/Z/lib/MOD_ZZ_Z/MOD_ZZ_Z.h"
*/
#include "Z_FUNC_LIST.h"

/*
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

//Absolute number


*/
void menu_ABS_Z_N(){
 
    int i;
    printf("Please enter first number: ");
    char* str = getString();
    longNumber* a = parseNumber(str);   
    printf("%d", absolute(a));
    show_help();
  
}
/*
//Sign of number

void menu_POZ_Z_D(){
    
    show_help();
}

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
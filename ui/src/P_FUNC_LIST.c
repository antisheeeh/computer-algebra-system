#include <stdio.h>

#include "../lib/menu.h"

#include "../../modules/P/utils/lib/input.h"
#include "../../modules/N/utils/lib/input.h"
#include "../../modules/Z/utils/lib/input.h"
#include "../../modules/P/lib/number.h"

#include "../../modules/P/utils/lib/memory.h"

#include "../../modules/P/lib/ADD_PP_P.h"
#include "../../modules/P/lib/DEG_P_N.h"
#include "../../modules/P/lib/SUB_PP_P.h"
#include "../../modules/P/lib/MUL_PQ_P.h"
#include "../../modules/P/lib/LED_PQ_Q.h"
#include "../../modules/P/lib/MUL_PXK_P.h"
#include "../../modules/P/lib/FAC_P_Q.h"
#include "../../modules/P/lib/MUL_PP_P.h"


//Addition 2 polinomials

void menu_ADD_PP_P(){
    longNumberP *a = getNumberP(); 
    longNumberP *b = getNumberP();

    printNumberP(sumP(a,b));
}

//Subtraction 2 polinomials

void menu_SUB_PP_P(){
    longNumberP *a = getNumberP(); 
    longNumberP *b = getNumberP();

    printNumberP(subP(a , b));
}
//Multiply polinomial by rational number

void menu_MUL_PQ_P(){
    longNumberP *a = getNumberP();
    longNumberQ *rat = malloc(sizeof(longNumberQ));

    getchar();
    puts("Enter the numerator of the first Rational:");
    rat->numerator = parseNumberZ(getStringZ());
    puts("Enter the denominator of the first Rational:");
    rat->denominator = parseNumberN(getStringN());

    printNumberP(multyByRational(a,rat));
}

//Multiply polinomial by x^k

void menu_MUL_Pxk_P(){
    int pow;
    longNumberP *a = getNumberP();
    scanf("%d" , &pow);
    printNumberP(multyByXk(a , pow));
}

//Leading coefficient of polynomial

void menu_LED_L_Q(){
    longNumberP *a = getNumberP();
    
    puts("Highest coefficient: ");
    printf("%s / %s\n" , toStringZ(led(a)->numerator) , toStringN(led(a)->denominator));
}

//Highest degree of the polynomial

void menu_DEG_P_N(){
    longNumberP *a = getNumberP(); 
    printf("Degree is: %d\n",deg(a));
}

//The derivation of a coefficient from a polynomial

void menu_FAC_P_Q(){
    longNumberP *a = getNumberP();
    longNumberN *gcf;
    longNumberN *lcm;

    facP(a,&gcf,&lcm);

    puts(toStringN(gcf));
    puts(toStringN(lcm));
}

//Multiplication 2 polinomials

void menu_MUL_PP_P(){
    longNumberP *a = getNumberP(); 
    longNumberP *b = getNumberP();

    printNumberP(mulP(a , b));
}

//Division 2 polinomials
/*
void menu_DIV_PP_P(){

}
*/
//Calculate the remainder of division 2 polinomials
/*
void menu_MOD_PP_P(){

}
*/
//GCF of 2 polinomials
/*
void menu_GCF_PP_P(){

}
*/
//Derivative of polinomial
/*
void menu_DER_P_P(){

}
*/
//Multiple roots in simple
/*
void menu_NMR_P_P(){

}
*/
#include <stdio.h>
#include <string.h>

#include "../lib/menu.h"

#include "../../modules/Z/utils/lib/input.h"
#include "../../modules/Z/lib/number.h"

#include "../../modules/Q/utils/lib/memory.h"

#include "../../modules/N/utils/lib/input.h"
#include "../../modules/N/lib/number.h"

#include "../../modules/Q/lib/INT_Q_B.h"
#include "../../modules/Q/lib/TRANS_Z_Q.h"
#include "../../modules/Q/lib/TRANS_Q_Z.h"
#include "../../modules/Q/lib/MUL_QQ_Q.h"
#include "../../modules/Q/lib/DIV_QQ_Q.h"
#include "../../modules/Q/lib/ADD_QQ_Q.h"
#include "../../modules/Q/lib/SUB_QQ_Q.h"

void menu_INT_Q()
{
    char *str1 = NULL , *str2 = NULL;
    int res;
    longNumberQ *a = malloc(sizeof(longNumberQ));

    puts("Enter the numerator:");
    str1 = getStringZ();
    a->numerator = absolute(parseNumberZ(str1));
    puts("Enter the denominator:");
    str2 = getStringN();
    a->denominator = parseNumberN(str2);

    if((res = isInt(a)) == WHOLE) puts("Yes");
    else puts("No");

    clearStructQ(a);
    clearStringQ(str1);
    clearStringQ(str2);

    show_help();
}

void menu_TRANS_Z_Q()
{
    longNumberQ *res;

    char *str1 = NULL;
    puts("Enter whole number:");
    str1 = getStringZ();
    longNumberZ *a = parseNumberZ(str1);
    
    res = transZtoQ(a);

    printf("New rational is: %s / %s\n",toStringZ(res->numerator) , toStringN(res->denominator));

    clearStructQ(res);
    clearStringQ(str1);

    show_help();
}

void menu_TRANS_Q_Z()
{
    char *str1 = NULL , *str2 = NULL;
    longNumberZ *res;
    longNumberQ *a = malloc(sizeof(longNumberQ));

    puts("Enter the numerator:");
    str1 = getStringZ();
    a->numerator = parseNumberZ(str1);
    puts("Enter the denominator:");
    str2 = getStringN();
    a->denominator = parseNumberN(str2);

    res = transQtoZ(a);

    puts("Transformed Rational:");
    puts(toStringZ(res));

    clearStructQ(a);
    clearStringQ(str1);
    clearStringQ(str2);

    show_help();
}

void menu_MUL_QQ_Q()
{
    char *str1 = NULL , *str2 = NULL, *str3 = NULL, *str4 = NULL;
    longNumberQ *a = malloc(sizeof(longNumberQ));
    longNumberQ *b = malloc(sizeof(longNumberQ));
    longNumberQ *res = malloc(sizeof(longNumberQ));

    puts("Enter the numerator of the first Rational:");
    str1 = getStringZ();
    a->numerator = parseNumberZ(str1);
    puts("Enter the denominator of the first Rational:");
    str2 = getStringN();
    a->denominator = parseNumberN(str2);

    puts("Enter the numerator of the second Rational:");
    str3 = getStringZ();
    b->numerator = parseNumberZ(str3);
    puts("Enter the denominator of the second Rational:");
    str4 = getStringN();
    b->denominator = parseNumberN(str4);

    res = mulQ(a , b);

    printf("New rational is: %s / %s\n",toStringZ(res->numerator) , toStringN(res->denominator));

    clearStringQ(str1);
    clearStringQ(str2);
    clearStringQ(str3);
    clearStringQ(str4);
    clearStructQ(a);
    clearStructQ(b);
    clearStructQ(res);

    show_help();
}

void menu_DIV_QQ_Q()
{
    char *str1 = NULL , *str2 = NULL, *str3 = NULL, *str4 = NULL;
    longNumberQ *a = malloc(sizeof(longNumberQ));
    longNumberQ *b = malloc(sizeof(longNumberQ));
    longNumberQ *res = malloc(sizeof(longNumberQ));

    puts("Enter the numerator of the first Rational:");
    str1 = getStringZ();
    a->numerator = parseNumberZ(str1);
    puts("Enter the denominator of the first Rational:");
    str2 = getStringN();
    a->denominator = parseNumberN(str2);

    puts("Enter the numerator of the second Rational:");
    str3 = getStringZ();
    b->numerator = parseNumberZ(str3);
    puts("Enter the denominator of the second Rational:");
    str4 = getStringN();
    b->denominator = parseNumberN(str4);

    res = divQ(a , b);

    printf("New rational is: %s / %s\n",toStringZ(res->numerator) , toStringN(res->denominator));
    clearStringQ(str1);
    clearStringQ(str2);
    clearStringQ(str3);
    clearStringQ(str4);
    clearStructQ(a);
    clearStructQ(b);
    clearStructQ(res);

    show_help();
}

void menu_ADD_QQ_Q(){
    char *str1, *str2 , *str3 , *str4;

    puts("Enter the numerator of the first rational:");
    str1 = getStringZ();
    puts("Enter the denominator of the first rational:");
    str2 = getStringN();
    puts("Enter the numerator of the second rational:");
    str3 = getStringZ();
    puts("Enter the denominator of the second rational:");
    str4 = getStringN();

    longNumberQ *a = malloc(sizeof(longNumberQ));
    a->numerator = parseNumberZ(str1);
    a->denominator = parseNumberN(str2);

    longNumberQ *b = malloc(sizeof(longNumberQ));
    b->numerator = parseNumberZ(str3);
    b->denominator = parseNumberN(str4);

    longNumberQ *c = addQ(a , b);

    printf("New rational is: %s / %s\n",toStringZ(c->numerator) , toStringN(c->denominator));
    clearStringQ(str1);
    clearStringQ(str3);
    clearStringQ(str2);
    clearStringQ(str4);

    clearStructQ(a);
    clearStructQ(b);
    clearStructQ(c);

    show_help();
}


void menu_SUB_QQ_Q(){

    char *str1, *str2 , *str3 , *str4;

    puts("Enter the numerator of the first rational:");
    str1 = getStringZ();
    puts("Enter the denominator of the first rational:");
    str2 = getStringN();
    puts("Enter the numerator of the second rational:");
    str3 = getStringZ();
    puts("Enter the denominator of the second rational:");
    str4 = getStringN();

    longNumberQ *a = malloc(sizeof(longNumberQ));
    a->numerator = parseNumberZ(str1);
    a->denominator = parseNumberN(str2);

    longNumberQ *b = malloc(sizeof(longNumberQ));
    b->numerator = parseNumberZ(str3);
    b->denominator = parseNumberN(str4);

    longNumberQ *c = subQ(a , b);

    printf("New rational is: %s / %s\n",toStringZ(c->numerator) , toStringN(c->denominator));
    clearStringQ(str1);
    clearStringQ(str3);
    clearStringQ(str2);
    clearStringQ(str4);

    clearStructQ(a);
    clearStructQ(b);
    clearStructQ(c);

    show_help();
}

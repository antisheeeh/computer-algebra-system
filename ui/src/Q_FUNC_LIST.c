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
#include "../../modules/Q/lib/RED_Q_Q.h"

void menu_RED_QQ_Q() {
    longNumberQ *a = malloc(sizeof(longNumberQ));

    puts("Enter the numerator of the first rational:");
    a->numerator = parseNumberZ(getStringZ());
    puts("Enter the denominator of the first rational:");
    a->denominator = parseNumberN(getStringN());

    longNumberQ *c = redQ(a);

    printf("New rational is: %s / %s\n", toStringZ(c->numerator) , toStringN(c->denominator));
}

void menu_INT_Q() {
    longNumberQ *a = malloc(sizeof(longNumberQ));

    puts("Enter the numerator:");
    a->numerator = parseNumberZ(getStringZ());
    puts("Enter the denominator:");
    a->denominator = parseNumberN(getStringN());

    if(isInt(a)) {
        puts("Yes");
    } else {
        puts("No");
    }
}

void menu_MUL_QQ_Q() {
    longNumberQ *a = malloc(sizeof(longNumberQ));
    longNumberQ *b = malloc(sizeof(longNumberQ));

    puts("Enter the numerator of the first Rational:");
    a->numerator = parseNumberZ(getStringZ());
    puts("Enter the denominator of the first Rational:");
    a->denominator = parseNumberN(getStringN());

    puts("Enter the numerator of the second Rational:");
    b->numerator = parseNumberZ(getStringZ());
    puts("Enter the denominator of the second Rational:");
    b->denominator = parseNumberN(getStringN());

    longNumberQ* res = mulQ(a , b);

    printf("New rational is: %s / %s\n", toStringZ(res->numerator), toStringN(res->denominator));
}

void menu_DIV_QQ_Q() {
    longNumberQ *a = malloc(sizeof(longNumberQ));
    longNumberQ *b = malloc(sizeof(longNumberQ));

    puts("Enter the numerator of the first Rational:");
    a->numerator = parseNumberZ(getStringZ());
    puts("Enter the denominator of the first Rational:");
    a->denominator = parseNumberN(getStringN());

    puts("Enter the numerator of the second Rational:");
    b->numerator = parseNumberZ(getStringZ());
    puts("Enter the denominator of the second Rational:");
    b->denominator = parseNumberN(getStringN());

    longNumberQ* res = divQ(a , b);

    printf("New rational is: %s / %s\n", toStringZ(res->numerator), toStringN(res->denominator));
}

void menu_ADD_QQ_Q(){
    longNumberQ *a = malloc(sizeof(longNumberQ));
    longNumberQ *b = malloc(sizeof(longNumberQ));

    puts("Enter the numerator of the first rational:");
    a->numerator = parseNumberZ(getStringZ());
    puts("Enter the denominator of the first rational:");
    a->denominator = parseNumberN(getStringN());

    puts("Enter the numerator of the second rational:");
    b->numerator = parseNumberZ(getStringZ());
    puts("Enter the denominator of the second rational:");
    b->denominator = parseNumberN(getStringN());
   
    longNumberQ *c = addQ(a , b);

    printf("New rational is: %s / %s\n", toStringZ(c->numerator), toStringN(c->denominator));
}


void menu_SUB_QQ_Q() {
    longNumberQ *a = malloc(sizeof(longNumberQ));
    longNumberQ *b = malloc(sizeof(longNumberQ));

    puts("Enter the numerator of the first rational:");
    a->numerator = parseNumberZ(getStringZ());
    puts("Enter the denominator of the first rational:");
    a->denominator = parseNumberN(getStringN());
    puts("Enter the numerator of the second rational:");
    b->numerator = parseNumberZ(getStringZ());
    puts("Enter the denominator of the second rational:");
    b->denominator = parseNumberN(getStringN());

    longNumberQ *c = subQ(a , b);

    printf("New rational is: %s / %s\n", toStringZ(c->numerator), toStringN(c->denominator));
}

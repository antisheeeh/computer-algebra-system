#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../lib/menu.h"

#include "../../modules/Z/utils/lib/input.h"
#include "../../modules/Z/lib/number.h"

#include "../../modules/Q/utils/lib/input.h"

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
    puts("Please enter a number");
    longNumberQ* a = parseNumberQ(getStringN());

    puts("");

    puts(toStringQ(redQ(a)));
}

void menu_INT_Q() {
    puts("Please enter a number");
    longNumberQ* a = parseNumberQ(getStringN());

    puts("");

    if(isInt(a)) {
        puts("The number is an integer");
    } else {
        puts("The number is not an integer");
    }
}

void menu_MUL_QQ_Q() {
    puts("Please enter a first number");
    longNumberQ* a = parseNumberQ(getStringN());

    puts("Please enter a second number");
    longNumberQ* b = parseNumberQ(getStringN());

    puts("");

    puts("Result");
    puts(toStringQ(mulQ(a, b)));
}

void menu_DIV_QQ_Q() {
    puts("Please enter a first number");
    longNumberQ* a = parseNumberQ(getStringN());

    puts("Please enter a second number");
    longNumberQ* b = parseNumberQ(getStringN());

    puts("");

    puts("Result");
    puts(toStringQ(divQ(a, b)));
}

void menu_ADD_QQ_Q(){
    puts("Please enter a first number");
    longNumberQ* a = parseNumberQ(getStringN());

    puts("Please enter a second number");
    longNumberQ* b = parseNumberQ(getStringN());

    puts("");

    puts("Result");
    puts(toStringQ(addQ(a, b)));
}


void menu_SUB_QQ_Q() {
    puts("Please enter a first number");
    longNumberQ* a = parseNumberQ(getStringN());

    puts("Please enter a second number");
    longNumberQ* b = parseNumberQ(getStringN());

    puts("");

    puts("Result");
    puts(toStringQ(subQ(a, b)));
}

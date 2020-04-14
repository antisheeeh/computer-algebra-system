#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../lib/input.h"
#include "../../../Z/lib/TRANS_Z_N.h"
#include "../../../N/lib/NZER_N_B.h"
#include "../../../Z/utils/lib/input.h"
#include "../../../N/utils/lib/input.h"
#include "../../../Q/lib/INT_Q_B.h"
#include "../../../Q/lib/TRANS_Q_Z.h"

longNumberP* getNumberP() {
    longNumberP* number = malloc(sizeof(longNumberP));

    puts("Please enter polynomial degree");
    scanf("%d", &number->degree);

    number->coefficient = malloc((number->degree + 1)*sizeof(longNumberQ*));

    for(int i = 0; i <= number->degree; ++i) {
        number->coefficient[i] = malloc(sizeof(longNumberQ));
        number->coefficient[i]->numerator = malloc(sizeof(longNumberZ));
        number->coefficient[i]->numerator->num = malloc(sizeof(int));
        number->coefficient[i]->numerator->num[0] = 0;
        number->coefficient[i]->denominator = malloc(sizeof(longNumberN));
        number->coefficient[i]->denominator->num = malloc(sizeof(int));
        number->coefficient[i]->denominator->num[0] = 1;
    }

    int power;

    do {
        puts("Enter power of x");
        scanf("%d", &power);
        if(power == -1) break;
        getchar();

        puts("Enter a numerator");
        number->coefficient[power]->numerator = parseNumberZ(getStringZ());
        puts("Enter a denominator");
        number->coefficient[power]->denominator = parseNumberN(getStringN());
    } while(power != -1);

    return number;
}

void printNumberP(longNumberP *number) {
    longNumberQ* num;

    for(int i = number->degree; i >= 0; --i) {
        num = number->coefficient[i];
        //if(!isZero(transZtoN(num->numerator))) {
            if((num->numerator->sign == PLUS) && (i != number->degree)) printf("+  ");
            if(isInt(num)) printf("%s x^%d  " , toStringZ(transQtoZ(num)) , i);
            else printf("%s / %s x^%d  ", toStringZ(num->numerator), toStringN(num->denominator), i);
        //}
    }
 }

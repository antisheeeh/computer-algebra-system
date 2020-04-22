/*
    author Kirill Konoplev
    group 9305
*/

#include <stdlib.h>
#include "../utils/lib/input.h"

#include "../lib/MUL_ND_N.h"

longNumberN* multiByDigit(longNumberN* number, int digit) {
    longNumberN* c = malloc(sizeof(longNumberN));

    c->len = number->len + 1;
    c->num = calloc(c->len, sizeof(int));

    //переменная для случая переполнения произведения двух цифр

    long long temp;

    for(int i = 0; i < c->len - 1; ++i) {
        // В переменную записывается произведение двух чисел
        temp = c->num[i] + number->num[i] * 1ll * digit;
        //В данный разряд записывается остаток от деления произведения двух чисел на максимальную величину разряда
        c->num[i] = temp % BASE;
        //В следующий разряд записывается остаток от целочисленного деления двух чисел
        c->num[i + 1] += temp / BASE;
    }

    removeLeadingZerosN(c);

    return c;
}
#pragma once

#define NUMBER_OF_BLOCS 4
#define NUMBER_OF_NFUNC 15

#ifdef linux
#define CLS system("clear")
#else
#define CLS system("cls")
#endif

void show_help();
void show_menu();
void Natural_menu();
void Whole_menu();
void Rational_menu();
void Polynomial_menu();
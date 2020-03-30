#pragma once

#ifdef linux
#define CLS system("clear")
#else
#define CLS system("cls")
#endif

void show_menu();
void Natural_menu();
void Whole_menu();
void Rational_menu();
void Polynomial_menu();
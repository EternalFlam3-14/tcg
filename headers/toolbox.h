#ifndef TOOLBOX_H
#define TOOLBOX_H
#include <string>

int random(int min, int max);

char random_char(char a, char b);
char random_char(char a, char b, char c);

//  Converts a char to string
std::string char_toString(char a);
//  Converts an int to string
std::string int_toString(int a);

void Fibonacci_Sequence();

std::string random_plant();
std::string random_pest();

#endif // TOOLBOX_H
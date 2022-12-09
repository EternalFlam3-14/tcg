#include <string>
#include <sstream>
#include <random>
#include "toolbox.h"
#include "terminal.h"

#include<chrono>
#include<thread>

int random(int min, int max)
{
    int range = max - min;          // Rand() % a + b returns a value between (0,a-1 (n) ), then adds b
    range++;                        // 0+b = b = min  ||  max = n + min
    return rand() % range + min;    // n = max - min  ||  a = n + 1  ||  (max - min) + 1 = a
}
 
char random_char(char a, char b)
{
    int r = random(1, 2);
    char out;
    if (r == 1)
    {
        out = a;
    }
    if (r == 2)
    {
        out = b;
    }
    return out;
};

char random_char(char a, char b, char c)
{
    int r = random(1, 3);
    char out;
    if (r == 1)
    {
        out = a;
    }
    if (r == 2)
    {    
        out = b;
    }
    if (r == 3)
    {
        out = c;
    }
    return out;
}

std::string char_toString(char a)
{
    std::string s = {a};
    return s;
}

std::string int_toString(int a)
{
    std::stringstream ss;
    ss << a;
    return ss.str();
}

void Fibonacci_Sequence()
{
    Terminal_C Terminal;
    long long int t1(1), t2(0), sum(0);
    for (int i(1); i <= 46; i++)
    {
        sum = t1 + t2;
        t1 = t2;
        t2 = sum;
        Terminal.Say( int_toString(i) + " " + int_toString(sum));
        std::this_thread::sleep_for(std::chrono::milliseconds(sum % 1000));
    }
}

std::string random_plant()
{
    int c = random(1, 3); //(rand() % 3 + 1);
    std::string Return;

    if (c == 1)
    {
        Return = "Indica";
    }
    if (c == 2)
    {
        Return = "Hybrid";
    }
    if (c == 3)
    {
        Return = "Sativa";
    }
    return Return;
}

std::string random_pest()
{
    int c = random(1, 3); //(rand() % 3 + 1);
    std::string p;
    if (c == 1)
    {
        p = "Insect";
    }
    if (c == 2)
    {
        p = "Fung";
    }
    if (c == 3)
    {
        p = "Herb";
    }
    return p;
}




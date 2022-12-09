#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "terminal.h"

////////////////////////////////////   PUBLIC    ////////////////////////////////////

//                                  Input
void Terminal_C::In()
{
    std::getline(std::cin, Input);
    Set_Words();
}

//                                  Output
void Terminal_C::Say(std::string output)
{
    std::cout << output << std::endl;
}

////////////////////////////////////   PRIVATE   ////////////////////////////////////

//                                  Input Data Functions
void Terminal_C::Set_Words()
{
    Words = 0;

    for (int i(0); i < Input.size(); i++)
    {
        if (Input.at(i) == ' ')
        {
            Words++;
        }
    }
}
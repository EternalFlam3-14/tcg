#include <iostream>
#include <chrono>
#include "world.h"

int main()
{
    auto seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); // Making seed
    srand(seed); // Seeding random

    World World;

    std::cout << R"(~~~~~~~~~~~~~~~~~~~~~~{ }~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~     Program Completed     ~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~)" << std::endl;
}
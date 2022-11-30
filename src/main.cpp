#include <iostream>
#include <chrono>
#include "world.h"

void quick_test()
{
    int deck_s = 14, hand_s = 7, cash_s = 100;                  //  Game variable

    std::vector<std::shared_ptr<Player>> Ptrs;                  //  Player vector
    Shoe S1;

    Ptrs.push_back(std::make_shared<Player> (hand_s, cash_s));  //  Make a new player
    Ptrs.push_back(std::make_shared<Player> (hand_s, cash_s));  //  Make a new player
    S1.new_Deck(deck_s);                                        //  Add a deck to the shoe

    for (std::shared_ptr<Player> player : Ptrs)                 //  For each player
    {
        for (int i(0); i < hand_s; i++)                         //  Draw hand
        {
            player.get()->Draw(i, S1.Draw());
        }
    }
    for (std::shared_ptr<Player> player : Ptrs)                 //  Print hands for each player
    {
        player.get()->print_Hand();
    }
    for (std::shared_ptr<Player> player : Ptrs)                 //  Play card for each player
    {
        player.get()->play_Card(random(0,hand_s));
    }
    for (std::shared_ptr<Player> player : Ptrs)                 //  Print hands for each player
    {
        player.get()->print_Hand();
    }

    std::cout << R"(~~~~~~~~~~~~~~~~~~~~~~{ }~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~{  Quick Test Complete  }~~~~~~~~~~~)" << std::endl;
}

int main()
{
    srand(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()); // Seeding Random once


    //World World;

    quick_test();

    std::cout << R"(~~~~~~~~~~~~~~~~~~~~~~{ }~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~     Program Completed     ~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~)" << std::endl;
}
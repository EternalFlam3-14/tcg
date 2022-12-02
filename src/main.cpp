#include <iostream>
#include <chrono>
#include "world.h"

void quick_test()
{
    int deck_s = 15, hand_s = 7, cash_s = 100, pool = 0;           //  Game variables

    std::vector<std::shared_ptr<Player>> Ptrs;                  //  Player vector
    std::vector<std::shared_ptr<Card_C>> Playercards;           //  Card vector

    Shoe S1;                                                    //  Dealer's Shoe
    Ptrs.push_back(std::make_shared<Player> (hand_s, cash_s));  //  Make a new player
    Ptrs.push_back(std::make_shared<Player> (hand_s, cash_s));  //  Make a new player

    S1.new_Deck(deck_s);                                        //  Add a deck to the shoe

    for (std::shared_ptr<Player> player : Ptrs)                 //  For each player
    {
        for (int i(0); i < hand_s; i++)                         //  For handsize
        {
            player.get()->Draw(i, S1.Draw());                   //  Draw hand
        }
        player.get()->print_Hand();                             //  Print hand
        Playercards.push_back(player.get()->play_Card(random(0, hand_s - 1)));  //  Play card
        if (S1.shoe_Size() > 0)                                 //  If the shoe has cards to draw
        {
            player.get()->Draw(6, S1.Draw());                   //  Draw card
        }
        player.get()->print_Hand();                             //  Print hand
    }
    for (auto card : Playercards)                               //  For each card played
    {
        std::cout << card->get_Name() << std::endl;             //  Say name
        if (card->type_Is(CardType::Lotto))
        {
            int multiplier = card->get_Value();
            int max = 100 * multiplier;
            pool += random(0, max);
        }
        if (card->type_Is(CardType::Item))
        {
            pool += card->get_Value();
        }
    }
    std::cout << pool << std::endl;

    std::cout << R"(~~~~~~~~~~~~~~~~~~~~~~{ }~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~{  Quick Test Complete  }~~~~~~~~~~~)" << std::endl;
}

int main()
{
    auto seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); // Making seed
    srand(seed); // Seeding random

    quick_test();

    std::cout << R"(~~~~~~~~~~~~~~~~~~~~~~{ }~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~     Program Completed     ~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~)" << std::endl;
}
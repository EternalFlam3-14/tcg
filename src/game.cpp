#include "game.h"


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void HempCeed_C::Play()
{
    
}

void Debug_C::Play()
{
}

void QuickTest_C::Play()
{
    Players.push_back(std::make_shared<Player> (hand_s, cash_s));  //  Make a new player
    Players.push_back(std::make_shared<Player> (hand_s, cash_s));  //  Make a new player
    Shoe.new_Deck(deck_s);                                      //  Add a deck to the shoe

    for (std::shared_ptr<Player> player : Players)                 //  For each player
    {
        for (int i(0); i < hand_s; i++)                         //  For handsize
        {
            player.get()->Draw(i, Shoe.Draw());                   //  Draw hand
        }
        player.get()->print_Hand();                             //  Print hand
        Playercards.push_back(player.get()->play_Card(random(0, hand_s - 1)));  //  Play card
        if (Shoe.shoe_Size() > 0)                                 //  If the shoe has cards to draw
        {
            player.get()->Draw(6, Shoe.Draw());                   //  Draw card
        }
        player.get()->print_Hand();                             //  Print hand
    }
    for (auto card : Playercards)                               //  For each card played
    {
        Terminal.Say(card->get_Name());                         //  Say name
        if (card->type_Is(CardType::Lotto))                     //  If card is lotto
        {
            int multiplier = card->get_Value();
            int max = 100 * multiplier, min = 0 - max;
            pool += random(min, max);                           //  Add random value to pool
        }
        if (card->type_Is(CardType::Item))
        {
            pool += card->get_Value();
        }
    }
    Terminal.Say(int_toString(pool));
    Terminal.Say(R"(~~~~~~~~~~~~~~~~~~~~~~{ }~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~{  Quick Test Complete  }~~~~~~~~~~~)");
}


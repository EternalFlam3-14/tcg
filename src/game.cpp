#include "game.h"
#include <algorithm>

void Game_C::set_Players()
{
    for (int i(0); i < player_s; i++)                               //  For player size
    {
        Players.push_back(std::make_shared<Player> (hand_s, cash_s));   //  Make a new player
    }
}

void Game_C::draw_Card(std::shared_ptr<Player> player, int pos)
{
    pos = std::clamp(pos, 0, hand_s - 1);
    if (Shoe.shoe_Size() > 0)                                       //  If the shoe has cards to draw
    {
        player->Draw(pos, Shoe.Draw());                             //  Draw card
    }
}

void Game_C::set_Hand(std::shared_ptr<Player> player)
{
    for (int i(0); i < hand_s; i++)                                 //  For handsize
    {
        draw_Card(player, i);                                       //  Draw card
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void HempCeed_C::Play()
{
    
}

void Debug_C::Play()
{
    Shoe.new_Deck(deck_s);
    set_Players();
    while (!gameEnd)
    {
        for (std::shared_ptr<Player> player : Players)
        {
            player->print_Hand();
        }
        gameEnd = true;
    }
}

void QuickTest_C::Play()
{
    set_Players();
    Shoe.new_Deck(deck_s);                                          //  Add a deck to the shoe

    for (std::shared_ptr<Player> player : Players)                  //  For each player
    {
        set_Hand(player);                                           //  Draw Hand

        player->print_Hand();                                       //  Print hand

        Playercards.push_back(player->play_Card(random(0, hand_s - 1)));  //  Play card

        draw_Card(player, hand_s);                                  //  Draw card

        player->print_Hand();                                       //  Print hand
    }
    for (auto card : Playercards)                                   //  For each card played
    {
        Terminal.Say(card->get_Name());                             //  Say name
        if (card->type_Is(CardType::Lotto))                         //  If card is lotto
        {
            int multiplier = card->get_Value();
            int max = 100 * multiplier, min = 0 - max;
            pool += random(min, max);                               //  Add random value to pool
        }
        if (card->type_Is(CardType::Item))                          //  If card is item
        {
            pool += card->get_Value();
        }
    }
    Terminal.Say(int_toString(pool));
    Terminal.Say(R"(~~~~~~~~~~~~~~~~~~~~~~{ }~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~{  Quick Test Complete  }~~~~~~~~~~~)");
}


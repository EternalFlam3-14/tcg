#include "game.h"
#include <algorithm>

void Game_C::set_Players()
{
    switch(gametype)
    {   
        case Hemp_Ceed :
        {     
            for (int i(0); i < player_s; i++)                       //  For player size
            {
                Players.push_back(std::make_shared<PaidPlayer_C> (Hemp, hand_s, cash_s));   //  Make a new player
            }
            break;
        }
        case Texas :
        {
            for (int i(0); i < player_s; i++)
            {
                Players.push_back(std::make_shared<BetPlayer_C> (Standard, hand_s, cash_s));
            }
            break;
        }
        case Debug :
        {
            for (int i(0); i < player_s; i++)                       //  For player size
            {
                Players.push_back(std::make_shared<PaidPlayer_C> (Hemp, hand_s, cash_s));   //  Make a new player
            }
            break;
        }
        case Quick_Test :
        {
            for (int i(0); i < player_s; i++)                       //  For player size
            {
                Players.push_back(std::make_shared<PaidPlayer_C> (Hemp, hand_s, cash_s));   //  Make a new player
            }
            break;
        }
    }
}

void Game_C::new_Deck()
{
    switch (gametype)
    {
        case Texas :
        {
            Shoe.new_Deck(Standard, deck_s);                        //  Add deck to shoe
            break;
        }
        case Hemp_Ceed :
        {
            Shoe.new_Deck(Hemp, deck_s);                            //  Add deck to shoe
            break;
        }
        case Debug :
        {
            Shoe.new_Deck(Hemp, deck_s);                            //  Add deck to shoe
            break;
        }
        case Quick_Test : 
        {
            Shoe.new_Deck(Hemp, deck_s);                            //  Add deck to shoe
            break;
        }
    }
}

void Game_C::set_Hands()
{
    for (auto player : Players)                                         //  For players
    {
        for (int i(0); i < hand_s; i++)                                 //  For handsize
        {
            draw_Card(player, i);                                       //  Draw card
        }
    }
}

void Game_C::clamp_Card(int &pos)
{
    pos = std::clamp(pos, 0, hand_s - 1);                           //  Handsize is +1 from the hand
}

void Game_C::draw_Card(std::shared_ptr<Player_C> player, int pos)
{
    clamp_Card(pos);
    if (Shoe.shoe_Size() > 0)                                       //  If the shoe has cards to draw
    {
        player->Draw(pos, Shoe.Draw());                             //  Draw card
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void HempCeed_C::Play()
{
    
}

void Debug_C::Play()                                                //  Allows interaction, better test
{
    new_Deck();                                                     //  Add a deck to the shoe
    set_Players();                                                  //  3 players, handsize of 5
    set_Hands();                                                    //  Draws from shoe to fill hands
    while (!gameEnd)                                                //  Decksize of 52
    {                                                               
        for (std::shared_ptr<Player_C> player : Players)
        {
            bool cardChosen = false;
            std::shared_ptr<Card_C> playercard;                     //  Chosen card -- for demonstration, not optimal
            player->print_Hand();                                   
            Terminal.Say(R"(~~~~~~~         Choose a card to draw)");
            Terminal.In();
            std::stringstream In(Terminal.Get_Input());
            if (!cardChosen)
            {
                if (In >> pos)                                      //  If input is a number
                { 
                    pos--;                                          //  Compensate for interface
                    clamp_Card(pos);                                //  Make sure number is within hand
                    playercard = player->play_Card(pos);            //  Play chosen card
                    cardChosen = true;
                }
                else{
                    Terminal.Say("Not a number. try again");
                }
            }
            Cards.push_back(playercard);                            //  This abstraction isn't optimal
        }
        for (int i(0); std::shared_ptr<Card_C> card : Cards)        //  Check for highest value
        {    
            if (largest_val < card->get_Value())
            {                                                       //  Highest value is rewarded to the
                largest_val = card->get_Value();                    //  Player who played it
                winnerindex = i;
            }
            i++;                                                    //  Tiny piece of crucial code
        }
        Terminal.Say("Player " + int_toString(winnerindex + 1) + " won " + int_toString(largest_val));
        std::shared_ptr<PaidPlayer_C> player = std::static_pointer_cast<PaidPlayer_C>(Players[winnerindex]);
        player->set_Cash(largest_val);
        player->print_Cash();
        gameEnd = true;
    }
}

void QuickTest_C::Play()                                            //  First successful program
{                                                                   //  Keeping comments for documentation
    new_Deck();                                                     //  Add a deck to the shoe
    set_Players();                                                  //  All players added
    set_Hands();                                                    //  Player's hands filled from Shoe

    for (std::shared_ptr<Player_C> player : Players)                //  For each player
    {
        player->print_Hand();                                       //  Print hand

        Playercards.push_back(player->play_Card(random(0, hand_s - 1)));  //  Play card

        draw_Card(player, hand_s);                                  //  Draw card

        player->print_Hand();                                       //  Print hand
    }
    for (auto pcard : Playercards)                                   //  For each card played
    {
        auto card = std::reinterpret_pointer_cast<HempCard_C> (pcard); // To gain access to the name
        Terminal.Say(card->get_Name());                             //  Say name
        if (card->type_Is(HempCard_C::cardType::Lotto))             //  If card is lotto
        {
            int max = 100 * card->get_Value();                      
            pool += random(0 - max, max);                           //  Add random value to pool
        }
        if (card->type_Is(HempCard_C::cardType::Item))              //  If card is item
        {
            pool += card->get_Value();                              //  Add to pool
        }
    }
    Terminal.Say(int_toString(pool));
}


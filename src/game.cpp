#include "game.h"

void Game::set_Players()
{
    Terminal.Say(int_toString(playercount));
    for (int i(0); i < playercount; i++)
    {
        players.push_back(std::make_shared<Player>(handsize, startingcash));
        Terminal.Say("Player instanced, players size: " + int_toString(players.size()));
        if (players.at(i))
        {
            Terminal.Say("In loop");
            Terminal.Say(int_toString(get_Player().hand_Size()));
            Terminal.Say("Draw hand");
            draw_Hand();
        }
        else
        {
            Terminal.Say("Error in creating player");
        }
        Terminal.Say("Player done");
        next_Player();
    }
    currentplayer = 0;
}

void Game::next_Player()
{
    currentplayer = (currentplayer + 1) % playercount;
}

Player Game::get_Player()
{
    return (*players[currentplayer]);
}

void Game::Draw(int i)
{
    if (Shoe.shoe_Size() == 0)
    {
        Terminal.Say("No cards to draw");
        return;
    }
    else
    {
        Terminal.Say("To draw");
        get_Player().Draw(i, Shoe.Draw());
    }
}

void Game::draw_Hand()
{
    int handsize = get_Player().hand_Size();
    for (int i(0); i < handsize; i++)
    {
        Terminal.Say("Draw");
        Draw(i);
    }
    Terminal.Say("Player " + int_toString(currentplayer) + "'s hand has been drawn");
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Ceed::Play()
{
    Shoe.new_Deck(decksize);
    Terminal.Say("Deck made");
    set_Players();
    Terminal.Say("Players set");
    while (!gameEnd)
    {
        Terminal.Say(int_toString(currentplayer));
        get_Player().check_Hand();
        gameEnd = true;
    }
}

void Debug::Play()
{
    Shoe.new_Deck(decksize);
    set_Players();
    while (!gameEnd)
    {
        Terminal.Say("Number of Players: " + int_toString(players.size()));
        for (int i(0); i < playercount; i++)
        {
            Terminal.Say("Player Number " + int_toString(currentplayer));
            get_Player().print_Cash();
            get_Player().print_Hand();
            next_Player();
        }
        gameEnd = true;
    }
}

void Fib::Play()
{
    Fibonacci_Sequence();
}


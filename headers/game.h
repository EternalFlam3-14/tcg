#ifndef GAME_H
#define GAME_H


#include <vector>
#include <memory>
#include "player.h"
#include "shoe.h"
#include "garden.h"

class Game  //  Base Class
{
public:

    virtual void Play() = 0;

    void set_Players();

    void next_Player();

    Player get_Player();

    void Draw(int i);

    void draw_Hand();

protected:

    Shoe Shoe;
    Terminal_C Terminal;
    int decksize, handsize, playercount, startingcash, currentplayer = 0;
    bool gameEnd = false;
    std::vector<std::shared_ptr<Player>> players;
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Ceed : public Game
{   //  Hemp Ceed++
public:
    Ceed() { decksize = 14; handsize = 7, playercount = 1, startingcash = 100; };
    void Play() override;
    
};

class Debug : public Game
{   //  Debug Mode
public:
    Debug() { decksize = 52; handsize = 7; playercount = 3, startingcash = 50; };
    void Play() override;
};

class Fib : public Game
{   //  Fibbonacci Sequence
public:
    void Play() override;
};
#endif
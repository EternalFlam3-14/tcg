#ifndef GAME_H
#define GAME_H


#include <vector>
#include <memory>
#include "player.h"
#include "shoe.h"
#include "garden.h"

class Game_C  //  Base Class
{
public:
    virtual void Play() = 0;


protected:
    Terminal_C Terminal;
    int deck_s, hand_s, cash_s, pool;                           //  Game variables
    std::vector<std::shared_ptr<Player>> Players;               //  Players go here
    Shoe_C Shoe;                                                //  Dealer's decks are stored here
};

enum GameType
{
    Quick_Test = 0,
    Debug,
    Hemp_Ceed
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class HempCeed_C : public Game_C
{
public:
    void Play() override;


private:


};

class Debug_C : public Game_C
{
public:
    void Play() override;


private:
};

class QuickTest_C : public Game_C
{
public:
    void Play() override;


private:

    int deck_s = 15, hand_s = 7, cash_s = 100, pool = 0;        //  Game variables
    std::vector<std::shared_ptr<Card_C>> Playercards;           //  This is where played cards go
};

#endif
#ifndef GAME_H
#define GAME_H


#include <vector>
#include <memory>
#include "player.h"
#include "shoe.h"
#include "garden.h"


enum GameType
{
    Quick_Test = 0,
    Debug,
    Hemp_Ceed
};


class Game_C                                                        //  Base Class
{
public:

    virtual void Play() = 0;                                        //  Pure virtual function


protected:

    void set_Players();
    void draw_Card(std::shared_ptr<Player> player, int pos);
    void set_Hand(std::shared_ptr<Player> player);


    Terminal_C Terminal;
    GameType gametype;
    int deck_s, hand_s, player_s, cash_s;                           //  Game variables
    std::vector<std::shared_ptr<Player>> Players;                   //  Players go here
    Shoe_C Shoe;                                                    //  Dealer's decks are stored here
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class HempCeed_C : public Game_C
{
public:
    HempCeed_C() {  };

    void Play() override;


private:


};

class Debug_C : public Game_C
{
public:
    Debug_C() { deck_s = 52, hand_s = 5, player_s = 3; };

    void Play() override;


private:
    bool gameEnd = false;                                           //  Controls game loop

};

class QuickTest_C : public Game_C
{
public:
    QuickTest_C() { deck_s = 15, hand_s = 7, player_s = 2; };

    void Play() override;


private:

    int cash_s = 100, pool = 0;                                     //  Game variables
    std::vector<std::shared_ptr<Card_C>> Playercards;               //  This is where played cards go
};

#endif
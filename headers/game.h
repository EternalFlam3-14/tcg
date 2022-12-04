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

    void clamp_Card(int &pos);
    void draw_Card(std::shared_ptr<Player_C> player, int pos);

    void set_Players();
    void set_Hand(std::shared_ptr<Player_C> player);

    Terminal_C Terminal;
    GameType gametype;
    int deck_s, hand_s, player_s, cash_s;                           //  Game variables
    std::vector<std::shared_ptr<Player_C>> Players;                 //  Players go here
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
    Debug_C() { deck_s = 52, hand_s = 5, player_s = 3, gametype = Debug; };

    void Play() override;


private:
    std::vector<std::shared_ptr<Card_C>> Cards;                     //  Played cards
    int pos, largest_val = 0, winnerindex = 0;                      //  Game variables
    bool gameEnd = false;                                           //  Controls game loop

};

class QuickTest_C : public Game_C
{
public:
    QuickTest_C() { deck_s = 15, hand_s = 7, player_s = 2, gametype = Quick_Test; };

    void Play() override;


private:

    int cash_s = 100, pool = 0;                                     //  Game variables
    std::vector<std::shared_ptr<Card_C>> Playercards;               //  This is where played cards go
};

#endif
#ifndef GAME_H
#define GAME_H


#include <vector>
#include <memory>
#include "player.h"
#include "shoe.h"
#include "gameenum.h"


class Game_C                                                        //  Base Class
{
public:

    virtual void Play() = 0;                                        //  Game loop


protected:

    void clamp_Card(int &pos);                                      //  Clamps pos within the hand size
    virtual void draw_Card(std::shared_ptr<Player_C> player, int pos);//  Draws a card from shoe

    virtual void new_Deck();                                        //  Adds deck to the shoe

    virtual void set_Players();                                     //  Determines playertype
    virtual void set_Hands();                                       //  Draws from shoe to fill hand

    Terminal_C Terminal;                                            //  Interface
    GameType gametype;                                              //  Determines cardtype & playertype
    int deck_s, hand_s, player_s, cash_s;                           //  Game variables
    std::vector<std::shared_ptr<Player_C>> Players;                 //  Players go here
    Shoe_C Shoe;                                                    //  Dealer's decks are stored here
};

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Debug_C : public Game_C
{
public:
    Debug_C() { deck_s = 52, hand_s = 5, player_s = 3, cash_s = 0, gametype = Debug; };

    void Play() override;


private:

    void set_Players();

    std::vector<std::shared_ptr<Card_C>> Cards;                     //  Played cards
    int pos, largest_val = 0, winnerindex = 0;                      //  Game variables
    bool gameEnd = false;                                           //  Controls game loop

};

class QuickTest_C : public Game_C
{
public:
    QuickTest_C() { deck_s = 15, hand_s = 7, player_s = 2, cash_s = 100, gametype = Quick_Test; };

    void Play() override;


private:

    int pool = 0;                                                   //  Game variables
    std::vector<std::shared_ptr<Card_C>> Playercards;               //  This is where played cards go
};

#endif
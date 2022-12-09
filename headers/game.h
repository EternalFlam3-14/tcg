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
    Texas,
    Hemp_Ceed
};


class Game_C                                                        //  Base Class
{
public:

    virtual void Play() = 0;                                        //  Game loop


protected:

    void clamp_Card(int &pos);                                      //  Clamps pos within the hand size
    void draw_Card(std::shared_ptr<Player_C> player, int pos);      //  Draws a card from shoe

    void new_Deck();                                                //  Adds deck to the shoe

    void set_Players();                                             //  Determines playertype
    void set_Hands();                                               //  Draws from shoe to fill hand

    Terminal_C Terminal;                                            //  Interface
    GameType gametype;                                              //  Determines cardtype & playertype
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

class Texas_C : public Game_C
{
public:
    Texas_C() { deck_s = 52, hand_s = 2, player_s = 3, cash_s = 100, gametype = Texas; };

    void Play() override;

private:

    void Bet(std::shared_ptr<BetPlayer_C> player);

    void set_Big_Blind(int newBlind) { minBet = newBlind; };

    int get_Min_Bet() const { return minBet; };

    

    int pool = 0, minBet = 0;
    std::vector<std::shared_ptr<Card_C>> Table;
    bool gameEnd = false;
};

class Debug_C : public Game_C
{
public:
    Debug_C() { deck_s = 52, hand_s = 5, player_s = 3, cash_s = 0, gametype = Debug; };

    void Play() override;


private:
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
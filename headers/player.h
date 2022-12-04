#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <memory>

#include "deck.h"
#include "terminal.h"
#include "toolbox.h"


class Player_C
{
public:
//                                  PUBLIC

//                              Constructor
    Player_C(int handsize) : Hand(handsize) {};

//                              Functions
    std::shared_ptr<Card_C> play_Card(int pos);

    void print_Hand();

    void check_Hand();

//      Getters

    Card_C card_At(int i) const { return Hand.card_At(i); };

    int hand_Size() { return Hand.deck_Size(); };

//      Setters
    void Draw(int pos, std::shared_ptr<Card_C> Card);

protected:
//                                  PROTECTED

    Terminal_C Terminal;

    Deck_C Hand;

};

class PaidPlayer_C : public Player_C
{
public:
    
    PaidPlayer_C(int handsize, int startcash) : Player_C(handsize), cash(startcash) {};

    void print_Cash();

    int get_Cash() const { return cash; }; 

    void set_Cash(int value) { cash = value; };

private:

    int cash;

};

#endif
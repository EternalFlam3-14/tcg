#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <memory>

#include "deck.h"
#include "terminal.h"
#include "toolbox.h"


class Player
{
public:
//                                  PUBLIC

//                              Constructor
    Player(int handsize, int startcash) : cash(startcash), Hand(handsize) {};

//                              Functions
    std::shared_ptr<Card_C> play_Card(int pos);

    void print_Hand();

    void check_Hand();

    void print_Cash();

//      Getters

    Card_C card_At(int i) const { return Hand.card_At(i); };

    int get_Cash() const { return cash; }; 

    int hand_Size() { return Hand.deck_Size(); };

//      Setters
    void Draw(int pos, std::shared_ptr<Card_C> Card);

    void set_Cash(int value) { cash = value; };

private:
//                                  PRIVATE

    Terminal_C Terminal;

    Deck_C Hand;

    int cash;


};

#endif
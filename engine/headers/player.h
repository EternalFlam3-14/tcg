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
    // Constructor: Initializes the player's hand with the specified deck type and number of cards
    //  type: the type of deck the player's hand should be drawn from
    //  handsize: the number of cards in the player's hand
    Player_C(deckType type, int handsize) : Hand(type, handsize) {};

    // Plays the card at the specified position in the player's hand
    std::shared_ptr<Card_C> play_Card(int pos);

    // Prints the player's current hand to the terminal
    void print_Hand();

    // Debug Info
    void check_Hand();

    // Returns the card at the specified position in the player's hand
    std::shared_ptr<Card_C> card_At(int i) const { return Hand.card_At(i); };

    // Returns the number of cards in the player's hand
    int hand_Size() { return Hand.deck_Size(); };

    //  Draw a card at the specified position in the player's hand
    void Draw(int pos, std::shared_ptr<Card_C> Card);

protected:

    //  Object for printing text to the terminal
    Terminal_C Terminal;

    //  The player's current hand of cards
    Deck_C Hand;

};

//  Represents a player who has a balance of cash that they can bet with
class PaidPlayer_C : public Player_C
{
public:
    //  Constructor
    //  type: the type of deck the player's hand should be drawn from
    //  handsize: the number of cards in the player's hand
    //  startcash: the starting balance of cash for the player
    PaidPlayer_C(deckType type, int handsize, int startcash) : Player_C(type, handsize), cash(startcash) {};

    //  Prints the player's current balance of cash
    void print_Cash();

    //  Returns the player's current balance of cash
    int get_Cash() const { return cash; }

    //  Sets the player's balance of cash to the specified value
    void set_Cash(int value) { cash = value; }

private:
    //  The player's current balance of cash
    int cash = 0;
};

//  Represents a player who has a balance of cash and a current bet amount
class BetPlayer_C : public PaidPlayer_C
{
public:
    //  Constructor
    //  type: the type of deck the player's hand should be drawn from
    //  handsize: the number of cards in the player's hand
    //  startcash: the starting balance of cash for the player
    BetPlayer_C(deckType type, int handsize, int startcash) : PaidPlayer_C(type, handsize, startcash) {}

    //  Returns the player's current bet amount
    int get_Bet() const { return bet; }

    //  Sets the player's current bet amount to the specified value
    void set_Bet(int value) { bet = value; }

    //  Returns whether or not the player has folded
    bool has_Folded() const { return folded; }

    //  Sets the player's fold status to the opposite of its current value
    void Fold() { folded = !folded; }

    //  Returns whether or not the player has gone all in
    bool is_allIn() const { return allIn; };

    //  Sets the player's all in status to the opposite of its current value
    void all_In() { allIn = !allIn; };

private:
    // Whether or not this player has folded
    bool folded = false;

    // Whether or not the player has gone all-in
    bool allIn = false;

    // The current bet amount for this player
    int bet = 0;
};

#endif
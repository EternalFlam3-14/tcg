#ifndef DECK_H
#define DECK_H

#include <vector>
#include <memory>
#include "card.h"
#include "toolbox.h"

enum deckType
{
    Standard = 0,
    Hemp
};

class Deck_C
{
public:

    Deck_C(deckType type, int size) : Type(type), Deck(size) {};

    void card_Set(int &pos, std::shared_ptr<Card_C> card);          //  Sets card at pos 
    std::shared_ptr<Card_C> card_At(int &pos) const                 //  Const reference to card in hand
    {               
        if(Deck.at(pos)) {return Deck.at(pos);}
        else{return nullptr;}
    };

    std::shared_ptr<Card_C> card_Pull(int pos);                     //  Takes card from deck at pos
    std::shared_ptr<Card_C> Draw();                                 //  Takes last card from deck
    void card_Push(std::shared_ptr<Card_C> card) { Deck.push_back(card); }; // Will increase deck size

    int deck_Size() { return Deck.size(); };                        //  Returns size of deck vector
    void Resize(int &size);                                         //  Useful for the hand
    void Populate();                                                //  Useful for the shoe

    void deck_Check();                                              //  Debug function

private:

    deckType Type;
    std::vector<std::shared_ptr<Card_C>> Deck;

};

#endif // DECK_H
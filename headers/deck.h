#ifndef DECK_H
#define DECK_H

#include <vector>
#include <memory>
#include "card.h"
#include "toolbox.h"

class Deck_C
{
public:
//                                  PUBLIC

//                              Constructor
    Deck_C(int size) : deck(size) {};
    
//                              Functions
    void Resize(int &size);

    void Populate();

    int deck_Size() { return deck.size(); };

    void deck_Check();

    Card_C card_At(int &pos) const { if(deck.at(pos)){ return (*deck.at(pos).get()); } else { Card_C card; return card ; } }

    void card_Set(int &pos, std::shared_ptr<Card_C> card);

    void card_Push(std::shared_ptr<Card_C> card) { deck.push_back(card); };

    std::shared_ptr<Card_C> Draw();

    std::shared_ptr<Card_C> card_Pull(int pos);

//                              Destructor
    
private:
//                                  PRIVATE

    std::vector<std::shared_ptr<Card_C>> deck; // Reference using (*deck)

   //               Tl;Dr   Deck.card_At(i)->type ugly, Deck.card_At(i).type pretty

    /* I like the way the code looks when everything is referenced using periods, and it's easier to read the code that way instead of registering "pointer" vs "direct" when wanting the card. */

};

#endif // DECK_H
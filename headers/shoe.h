#ifndef PACK_H
#define PACK_H

#include <vector>
#include <memory>

#include "deck.h"
#include "card.h"

class Shoe_C
{
public:

    void new_Deck(deckType type, int Decksize);

    int shoe_Size() const { return shoe.size(); };

    void erase_Deck();

    std::shared_ptr<Card_C> Draw();

private:

    std::vector<std::shared_ptr<Deck_C>> shoe;

};

#endif // PACK_H
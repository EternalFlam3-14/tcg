
#include <vector>
#include <memory>

#include "shoe.h"

void Shoe_C::new_Deck(int Decksize)
{
    shoe.push_back(std::make_shared<Deck_C>(Decksize));
    (*shoe.back()).Populate();
}

void Shoe_C::erase_Deck()
{
    if ((*shoe.back()).deck_Size() == 0)
    {
        shoe.pop_back();
    }
}

std::shared_ptr<Card_C> Shoe_C::Draw()
{
    auto out = (*shoe.back()).Draw();
    erase_Deck();
    return out;
}


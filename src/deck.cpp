#include <memory>
#include <iostream>
#include "deck.h"

void Deck_C::Resize(int &size)
{
    deck.resize(size);
}

void Deck_C::Populate()
{
    for (int i(0); i < deck_Size(); i++)
    {
        int r = random(1, 5);
        if (r == 1)
        {
            deck.at(i) = std::make_shared<Card_C>(CardType::Plant, random_plant(), random(1, 6));
        }
        if (r == 2)
        {
            deck.at(i) = std::make_shared<Card_C>(CardType::Fertilizer, char_toString(random_char('N', 'P', 'K')), random(1, 3));
        }
        if (r == 3)
        {
            deck.at(i) = std::make_shared<Card_C>(CardType::Pesticide, random_pest(), random(1, 3));
        }
        if (r == 4)
        {
            deck.at(i) = std::make_shared<Card_C>(CardType::Lotto, char_toString(random_char('A', 'B', 'C')), random(1, 6));
        }
        if (r == 5)
        {
            deck.at(i) = std::make_shared<Card_C>(CardType::Item, "$", random(-100, 100));
        }
    }
}

void Deck_C::deck_Check()
{
    std::cout << "Checking..." << std::endl;
    std::cout << deck.empty() << std::endl;
    std::cout << deck.size() << std::endl;
    std::cout << deck.back().use_count() << std::endl;
    std::cout << deck.back()->get_Name() << std::endl;

}

void Deck_C::card_Set(int &pos, std::shared_ptr<Card_C> card)
{
    deck.at(pos) = card;
    // std::cout << "Set " << deck.at(pos).get()->get_Name() << std::endl;
}

std::shared_ptr<Card_C> Deck_C::Draw()
{
    std::shared_ptr<Card_C> out = deck.back();
    deck.pop_back();
    return out;
}

std::shared_ptr<Card_C> Deck_C::card_Pull(int pos)
{
    int size = deck_Size();
    std::shared_ptr<Card_C> out = deck.at(pos);
    deck.erase(deck.begin() + pos);
    Resize(size);
    return out;
}

#include <memory>
#include <iostream>
#include "deck.h"

void Deck_C::Resize(int &size)
{
    Deck.resize(size);
}

void Deck_C::Populate()
{
    if (Type == Hemp)
    {
        for (int i(0); i < deck_Size(); i++)
        {
            int r = random(1, 5);
            if (r == 1)
            {
                Deck.at(i) = std::make_shared<HempCard_C>(HempCard_C::cardType::Plant, random_plant(), random(1, 6));
            }
            if (r == 2)
            {
                Deck.at(i) = std::make_shared<HempCard_C>(HempCard_C::cardType::Fertilizer, char_toString(random_char('N', 'P', 'K')), random(1, 3));
            }
            if (r == 3)
            {
                Deck.at(i) = std::make_shared<HempCard_C>(HempCard_C::cardType::Pesticide, random_pest(), random(1, 3));
            }
            if (r == 4)
            {
                Deck.at(i) = std::make_shared<HempCard_C>(HempCard_C::cardType::Lotto, char_toString(random_char('A', 'B', 'C')), random(1, 6));
            }
            if (r == 5)
            {
                Deck.at(i) = std::make_shared<HempCard_C>(HempCard_C::cardType::Item, "$", random(-100, 100));
            }
        }
    }
    if (Type == Standard)
    {
        // Create a list of all the possible cards
        std::vector<std::shared_ptr<StandardCard_C>> cards;
        for (int i = 1; i <= 13; i++)
        {
            cards.push_back(std::make_shared<StandardCard_C>(StandardCard_C::Clubs, i));
            cards.push_back(std::make_shared<StandardCard_C>(StandardCard_C::Spades, i));
            cards.push_back(std::make_shared<StandardCard_C>(StandardCard_C::Hearts, i));
            cards.push_back(std::make_shared<StandardCard_C>(StandardCard_C::Diamonds, i));
        }

        // Shuffle the list of cards
        std::random_shuffle(cards.begin(), cards.end());

        // Assign the cards to the deck
        for (int i(0); i < deck_Size(); i++)
        {
            Deck.at(i) = cards.at(i);
        }
    }
    // if (Type == Standard)
    // {
    //     for (int i(0); i < deck_Size(); i++)
    //     {
    //         int r = random(1, 4);
    //         if (r == 1)
    //         {
    //             Deck.at(i) = std::make_shared<StandardCard_C>(StandardCard_C::Clubs, random(1,13));
    //         }
    //         if (r == 2)
    //         {
    //             Deck.at(i) = std::make_shared<StandardCard_C>(StandardCard_C::Spades, random(1,13));
    //         }
    //         if (r == 3)
    //         {
    //             Deck.at(i) = std::make_shared<StandardCard_C>(StandardCard_C::Hearts, random(1,13));
    //         }
    //         if (r == 4)
    //         {
    //             Deck.at(i) = std::make_shared<StandardCard_C>(StandardCard_C::Diamonds, random(1,13));
    //         }
    //     }
    // }
}

void Deck_C::deck_Check()
{
    std::cout << "Checking..." << std::endl;
    std::cout << Deck.empty() << std::endl;
    std::cout << Deck.size() << std::endl;
    std::cout << Deck.back().use_count() << std::endl;
    std::cout << Deck.back()->get_Name() << std::endl;

}

void Deck_C::card_Set(int &pos, std::shared_ptr<Card_C> card)
{
    Deck.at(pos) = card;
}

std::shared_ptr<Card_C> Deck_C::Draw()
{
    std::shared_ptr<Card_C> out = Deck.back();
    Deck.pop_back();
    return out;
}

std::shared_ptr<Card_C> Deck_C::card_Pull(int pos)
{
    int size = deck_Size();
    std::shared_ptr<Card_C> out = Deck.at(pos);
    Deck.erase(Deck.begin() + pos);
    Resize(size);
    return out;
}

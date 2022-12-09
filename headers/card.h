#ifndef CARD_H
#define CARD_H

#include <string>
#include <variant>

    //  BASE CARD
class Card_C
{
public:

    Card_C() = default;

    Card_C(int value) : Value(value) {};

    virtual std::string get_Name() = 0;

    int get_Value();

protected:

    int Value;
};


class HempCard_C : public Card_C
{
public:
    enum cardType
    {
        Empty = 0,
        Plant,
        Fertilizer,
        Pesticide,
        Lotto,
        Item
    };

    HempCard_C(cardType type, std::string string, int value) : Card_C(value), String(string), Type(type) {};

    std::string get_Name() override;

    cardType get_Type();
    std::string get_String();
    bool type_Is(cardType type);
    


private:

    cardType Type;
    std::string String;

};

class StandardCard_C : public Card_C
{
public:
    enum cardType
    {
        Empty = 0,
        Spades,
        Hearts,
        Clubs,
        Diamonds
    };

    StandardCard_C(cardType type, int value) : Card_C(value), Type(type) {};

    std::string get_Name() override;

    cardType get_Type();
    bool type_Is(cardType type);
    
private:

    cardType Type;

};

#endif
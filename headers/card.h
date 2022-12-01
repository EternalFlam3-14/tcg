#ifndef CARD_H
#define CARD_H

#include <string>
#include <variant>

//                                  CARD TYPE
enum CardType
{
    Empty = 0,
    Plant,
    Fertilizer,
    Pesticide,
    Lotto,
    Item
};

//                                  BASE CARD
class Card_C
{
public:
//                                  PUBLIC

//                              Constructor
    Card_C() = default;

    Card_C(CardType cardtype, std::string string, int value) : Type(cardtype), String(string), Value(value) {};

//                              Functions
    CardType get_Type();
    std::string get_Name();
    std::string get_String();
    int get_Value();
    bool type_Is(CardType type);

private:
//                                  PRIVATE

//                                  Data
    int Value;
    std::string String;
    CardType Type;

};

#endif
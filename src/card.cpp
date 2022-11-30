#include <sstream>
#include <string>
#include "card.h"

CardType Card_C::get_Type()
{
    return Type;
}

bool Card_C::type_Is(CardType type)
{
    if (get_Type() == type)
    {
        return true;
    }
    return false;
}

std::string Card_C::get_Name()
{
    std::stringstream str;
    if (Type == CardType::Fertilizer)
    {
        str << "Fertilizer " << String << ' ' << Value;
    }
    if (Type == CardType::Pesticide)
    {
        str << String << "icide " << Value;
    }
    if (Type == CardType::Lotto)
    {
        str << "Lotto " << String << ' ' << Value;
    }
    if (Type == CardType::Plant || Type == CardType::Item)
    {
        str << String << ' ' << Value;
    }
    return str.str();
}

std::string Card_C::get_String()
{
    return String;
}

int Card_C::get_Value()
{
    return Value;
}

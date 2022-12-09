#include <sstream>
#include <string>
#include "card.h"

int Card_C::get_Value()
{
    return Value;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

std::string HempCard_C::get_String()
{
    return String;
}

HempCard_C::cardType HempCard_C::get_Type()
{
    return Type;
}

bool HempCard_C::type_Is(HempCard_C::cardType type)
{
    if (get_Type() == type)
    {
        return true;
    }
    return false;
}

std::string HempCard_C::get_Name()
{
    std::stringstream str;
    if (Type == cardType::Fertilizer)
    {
        str << "Fertilizer " << String << ' ' << Value;
    }
    if (Type == cardType::Pesticide)
    {
        str << String << "icide " << Value;
    }
    if (Type == cardType::Lotto)
    {
        str << "Lotto " << String << ' ' << Value;
    }
    if (Type == cardType::Plant || Type == cardType::Item)
    {
        str << String << ' ' << Value;
    }
    return str.str();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

StandardCard_C::cardType StandardCard_C::get_Type()
{
    return Type;
}

bool StandardCard_C::type_Is(StandardCard_C::cardType type)
{
    if (get_Type() == type)
    {
        return true;
    }
    return false;
}

std::string StandardCard_C::get_Name()
{
    std::stringstream str;
    if (Value == 1)
    {
        str << "Ace";
    }
    else if (Value == 11)
    {
        str << "Jack";
    }
    else if (Value == 12)
    {
        str << "Queen";
    }
    else if (Value == 13)
    {
        str << "King";
    }
    else
    {
        str << Value;
    }

    if (Type == cardType::Hearts) // Red
    {
        str << " of Hearts";
    }
    if (Type == cardType::Diamonds) // Red
    {
        str << " of Diamonds";
    }
    if (Type == cardType::Spades) // Black
    {
        str << " of Spades";
    }
    if (Type == cardType::Clubs) // Black
    {
        str << " of Clubs";
    }
    return str.str();
}


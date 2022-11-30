#include "gamefactory.h"


std::shared_ptr<Game> GameFactory::NewGame(int in)
{
    if (in == '1')
    {
        return std::make_shared<Ceed>();
    }
    if (in == '2')
    {
        return std::make_shared<Debug>();
    }
    if (in == '3')
    {
        return std::make_shared<Fib>();
    }
    else return nullptr;
}
#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include "game.h"
#include <memory>

class GameFactory
{
public:
std::shared_ptr<Game> NewGame(int in);

};
#endif
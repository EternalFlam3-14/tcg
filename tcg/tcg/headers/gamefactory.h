#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include "game.h"
#include "tex.h"
#include <memory>

class GameFactory_C
{
public:

    std::shared_ptr<Game_C> new_Game(GameType type);

};
#endif
#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <memory>
#include "gamefactory.h"
#include "game.h"


class World
{
public:
    World();

private:

    Terminal_C Terminal;

    std::shared_ptr<Game_C> Game;

};

#endif // WORLD_H
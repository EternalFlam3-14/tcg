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

    int gameCount = 3;

    Terminal_C Terminal;

    std::shared_ptr<Game> Game;

};

#endif // WORLD_H
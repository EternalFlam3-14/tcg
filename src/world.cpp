#include "world.h"
#include <math.h>
#include <memory>



World::World()
{
    GameFactory GameFactory;

    Terminal.Say(
R"(~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~
~~~~~
~~~~            Welcome to the TCG Terminal Interface!
~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~
~~~~~
~~~~            What game would you like to play?
~~~~~
~~~~            1   Hemp Ceed++
~~~~~
~~~~            2   Debug Mode
~~~~~
~~~~            3   Fibonacci
~~~~~
~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~)");

    bool game_IsMade(false); 
    while (!game_IsMade)
    {
        Terminal.In();
        char in = *Terminal.Get_Input().c_str();
        if (std::isdigit(in) && std::stoi(&in) <= gameCount)
        {
            Game = GameFactory.NewGame(in);
            game_IsMade = true;
        }
        else
        {
            Terminal.Say( "Your input: " + char_toString(in) + " doesn't exist.");
        }
    }
    Game->Play();
}




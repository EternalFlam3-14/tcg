#include "world.h"
#include <memory>



World::World()
{
    GameFactory_C GameFactory;

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
~~~~            1   Hemp Ceed
~~~~~
~~~~            2   Texas Hold 'Em
~~~~~
~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~)");

    bool game_Made(false); 
    while (!game_Made)
    {
        Terminal.In();
        char in = *Terminal.Get_Input().c_str();
        if (in == '1')
        {
            Game = GameFactory.new_Game(GameType::Hemp_Ceed);
            game_Made = true;
        }
        else if (in == '2')
        {
            Game = GameFactory.new_Game(GameType::Texas);
            game_Made = true;
        }
        else if (in == '~')
        {
            Game = GameFactory.new_Game(GameType::Debug);
            game_Made = true;
        }
        else if (in == '`')
        {
            Game = GameFactory.new_Game(GameType::Quick_Test);
            game_Made = true;
        }
        else
        {
            Terminal.Say( "Your input: " + char_toString(in) + " doesn't exist.");
        }
    }
    Game->Play();
}




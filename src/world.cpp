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
~~~~            2   Debug Mode
~~~~~
~~~~            3   Quick Test
~~~~~
~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~)");

    bool game_IsMade(false); 
    while (!game_IsMade)
    {
        Terminal.In();
        char in = *Terminal.Get_Input().c_str();
        if (std::isdigit(in))
        {
            if (in == '1')
            {
                Game = GameFactory.new_Game(GameType::Hemp_Ceed);
                game_IsMade = true;
            }
            if (in == '2')
            {
                Game = GameFactory.new_Game(GameType::Debug);
                game_IsMade = true;
            }
            if (in == '3')
            {
                Game = GameFactory.new_Game(GameType::Quick_Test);
                game_IsMade = true;
            }
        }
        else
        {
            Terminal.Say( "Your input: " + char_toString(in) + " doesn't exist.");
        }
    }
    Game->Play();
}




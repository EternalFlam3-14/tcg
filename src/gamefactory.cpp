#include "gamefactory.h"


std::shared_ptr<Game_C> GameFactory_C::new_Game(GameType type)
{
    switch(type)
    {
        case Hemp_Ceed :
        {
            
            return std::make_shared<HempCeed_C>();
        }
        case Debug :
        {
            return std::make_shared<Debug_C>();
        }
        case Quick_Test : 
        {
            return std::make_shared<QuickTest_C>();
        }
        default :
        {
            return nullptr;
        }
    }
}

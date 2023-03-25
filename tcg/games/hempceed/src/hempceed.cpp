#include "hempceed.h"

void HempCeed_C::Play()
{
    // Set the number of players in the game
    set_Players();

    // Create a new deck of cards
    new_Deck();

    // Deal the initial hands to each player
    set_Hands();


}

#include <iostream>
#include "tex.h"

void Texas_C::Play()
{
    // Set the number of players in the game
    set_Players();

    // Create a new deck of cards
    new_Deck();

    // Deal the initial hands to each player
    set_Hands();

    // Set the big blind
    Terminal.Say("Enter the value of the big blind: ");
    Terminal.In();
    std::stringstream ss(Terminal.Get_Input());
    if (!(ss >> big_Blind && big_Blind > 0)){
        Terminal.Say("Invalid input, defaulting to 10");
        set_min_Bet(10);
    }
    set_min_Bet(big_Blind);

    // Main game loop
    while (!End)
    {
        // Pre flop bet
        BetPhase();

        // Deal the flop (first three community cards)
        Deal(Flop);

        // Players take turns betting again
        BetPhase();

        // Deal the turn (fourth community card)
        Deal(Turn);

        // Players take turns betting again
        BetPhase();

        // Deal the river (final community card)
        Deal(River);

        // Players take turns betting again
        BetPhase();

        // End the game
        End = true;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Texas_C::Deal(Phase_C Phase)
{
    switch (Phase)
    {
        case Flop :
        {
            Table.push_back(Shoe.Draw());
            Table.push_back(Shoe.Draw());
            Table.push_back(Shoe.Draw());
            break;
        }
        case Turn :
        {
            Table.push_back(Shoe.Draw());
            break;
        }
        case River :
        {   
            Table.push_back(Shoe.Draw());
            break;
        }
    }
}

void Texas_C::BetPhase()
{
    // Players take turns betting
    for (int i(0); i < Players.size(); i++)
    {
        // Get the current player
        std::shared_ptr<BetPlayer_C> player = std::static_pointer_cast<BetPlayer_C>(Players[i]);
        
        // Skip player if they've folded or gone all in
        if (player->has_Folded() || player->is_allIn())
        {
            continue;
        }

        // Show the table to the player
        for (auto card : Table)
        {
            Terminal.Say(card->get_Name());
        }
        Terminal.Say("Player " + std::to_string(i));

        // Allow the player to make a bet
        Bet(player);
    }

    bool CheckEnd = false;

    while (!CheckEnd)
    {
        // Check for raised bet
        for (int i(0); i < Players.size(); i++)
        {
            // Get the current player
            std::shared_ptr<BetPlayer_C> player = std::static_pointer_cast<BetPlayer_C>(Players[i]);
            
            // Skip player if they've folded or gone all in
            if (player->has_Folded() || player->is_allIn())
            {
                continue;
            }

            // If the minimum bet is higher than the player's bet, bet again
            if (player->get_Bet() < min_Bet)
            {
                Terminal.Say("Player " + std::to_string(i));
                Bet(player);
            }
        }

        // Make sure all players have completed
        for (auto Player : Players)
        {
            // Get the current player
            std::shared_ptr<BetPlayer_C> player = std::static_pointer_cast<BetPlayer_C>(Player);

            // If the player hasn't folded or gone all in and their bet is lower than the minimum bet
            if (player->get_Bet() < get_min_Bet() && !player->has_Folded() || !player->is_allIn())
            {
                // Check players again
                break;
            }
        }

        // End loop
        CheckEnd = true;
    }
}

void Texas_C::Bet(std::shared_ptr<BetPlayer_C> player)
{
    // Get the current minimum bet
    int min_Bet = get_min_Bet();

    // Get the player's current bet and cash balance
    int bet = player->get_Bet();
    int cash = player->get_Cash();

    // Show the player's current hand and cash balance
    player->print_Hand();
    player->print_Cash();

    // Variable to loop
    bool BetEnd = false;

    // Loop until a valid bet is made
    while (!BetEnd)
    {
        // Prompt the player to make a bet
        Terminal.Say("Enter your bet (min bet: " + std::to_string(min_Bet) +
        ", max bet: " + std::to_string(cash) +
        " Your bet: " + std::to_string(player->get_Bet()) + "):");
        Terminal.Say("Type 'call', 'raise', or 'fold'");

        // Get the player's input
        Terminal.In();
        std::stringstream ss(Terminal.Get_Input());
        std::string my_str(ss.str());

        // Transform to lowercase
        transform(my_str.begin(), my_str.end(), my_str.begin(), ::tolower);

        if (my_str == "fold")
        {
            // If the player entered "fold", show a message indicating that they folded and update their status
            Terminal.Say("Player folded");
            player->Fold();
            BetEnd = true;
        }
        else if (my_str == "call")
        {
            // If the player entered "call"

            // check if player goes all in
            if(min_Bet >= cash)
            {
                // If the bet would put the player all in, prompt the player to go all in
                if (!AllIn(player))
                {
                    // If the player doesn't go all in, loop again
                    continue;
                }
                // Exit loop
                BetEnd = true;
            }

            // Update the player's bet and cash balance to match the minimum bet
            player->set_Bet(min_Bet);
            player->set_Cash(cash - min_Bet);

            // Exit loop
            BetEnd = true;
        }
        else if (my_str == "raise")
        {
            if(min_Bet > cash)
            {
                // If the player doesn't have enough cash to pay the minumum bet, then they can't raise
                Terminal.Say("Invalid bet! Cannot raise.");
                continue;
            }

            // Allow the player to raise
            Raise(player);

            // Exit loop
            BetEnd = true;
        }
        else
        {
            // If the player's input is invalid, show an error message and allow the player to try again
            Terminal.Say("Invalid bet! Please try again.");
        }
    }
}

void Texas_C::Raise(std::shared_ptr<BetPlayer_C> player)
{
    // Variable to loop
    bool RaiseEnd = false;
    
    // Loop until they enter a valid total bet amount
    while (!RaiseEnd)
    {

        // Prompt player for the amount they want to raise by
        Terminal.Say("Current bet: " + std::to_string(min_Bet) + " Type '0' to call or 'fold' to fold");
        Terminal.Say("Enter the amount you want to raise by (current bet: " +
        std::to_string(min_Bet) + " Your bet: " + std::to_string(player->get_Bet()) + "):");

        // Get the player's input
        Terminal.In();
        std::stringstream ss(Terminal.Get_Input());
        int in;
        
        // Check if the player's input is a number
        if (!(ss >> in))
        {
            // Transform to lowercase
            transform(ss.str().begin(), ss.str().end(), ss.str().begin(), ::tolower);

            if (ss.str() == "fold")
            {
                // If the player entered "fold", show a message indicating that they folded and update their status
                Terminal.Say("Player folded");
                player->Fold();
                RaiseEnd = true;
            }

            // If input is not a keyword
            Terminal.Say("Invalid bet! Please try again.");
            continue;
        }

        // Calculate the raise amount
        new_Bet = in + min_Bet;

        // Check if the total bet amount is valid
        if (new_Bet > player->get_Cash() || 0 > in)
        {
            // If bet amount is invalid
            Terminal.Say("Invalid bet! Please try again.");
            continue;
        }

        // Check if the total bet amount is all in
        if (new_Bet == player->get_Cash())
        {
            // If the bet would put the player all in, prompt the player to go all in
            if (!AllIn(player))
            {
                // If the player doesn't go all in, loop again
                continue;
            }
        }

        // Update the player's bet and cash balance
        player->set_Bet(new_Bet);
        player->set_Cash(player->get_Cash() - new_Bet);

        // Update the minimum bet to the new total bet amount
        set_min_Bet(new_Bet);
        RaiseEnd = true;
    }
}

bool Texas_C::AllIn(std::shared_ptr<BetPlayer_C> player)
{
    // Prompt player to go all in
    Terminal.Say("Go all in?");
    Terminal.Say("Type: 'all in' to confirm");

    // Get the player's input
    Terminal.In();
    std::stringstream ss(Terminal.Get_Input());
    std::string my_str(ss.str());
    transform(my_str.begin(), my_str.end(), my_str.begin(), ::tolower);

    if (my_str != "all in")
    {
        return false;
    }

    player->all_In();
    return true;
}

void Texas_C::Showdown()
{
    for (auto Player : Players)
    {
        // Get the current player
        std::shared_ptr<BetPlayer_C> player = std::static_pointer_cast<BetPlayer_C>(Player);

        // Skip player if they have folded
        if (player->has_Folded())
        {
            continue;
        }

        


    }
}

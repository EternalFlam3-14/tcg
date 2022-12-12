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
        // Players take turns betting
        for (std::shared_ptr<Player_C> Player : Players)
        {
            // Get the current player
            std::shared_ptr<BetPlayer_C> player = std::static_pointer_cast<BetPlayer_C>(Player);
            
            // Allow the player to make a bet
            Bet(player);
        }

        // Deal the flop (first three community cards)
        Table.push_back(Shoe.Draw());
        Table.push_back(Shoe.Draw());
        Table.push_back(Shoe.Draw());

        // Show the flop to all players
        for (auto card : Table)
        {
            Terminal.Say(card->get_Name());
        }

        // Players take turns betting again
        for (std::shared_ptr<Player_C> Player : Players)
        {
            // Get the current player
            std::shared_ptr<BetPlayer_C> player = std::static_pointer_cast<BetPlayer_C>(Player);

            // Allow the player to make another bet
            Bet(player);
        }

        // Deal the turn (fourth community card)
        Table.push_back(Shoe.Draw());

        // Show the turn to all players
        for (auto card : Table)
        {
            Terminal.Say(card->get_Name());
        }

        // Players take turns betting again
        for (std::shared_ptr<Player_C> Player : Players)
        {
            // Get the current player
            std::shared_ptr<BetPlayer_C> player = std::static_pointer_cast<BetPlayer_C>(Player);
            // Allow the player to make another bet
            Bet(player);
        }

        // End the game
        End = true;
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Texas_C::Bet(std::shared_ptr<BetPlayer_C> player)
{
    // Skip player if they've folded
    if (player->has_Folded())
    {
        return;
    }

    // Get the current minimum bet
    int min_Bet = get_min_Bet();

    // Get the player's current bet and cash balance
    int bet = player->get_Bet();
    int cash = player->get_Cash();

    // Show the player's current hand and cash balance
    player->print_Hand();
    player->print_Cash();

    // Prompt the player to make a bet
    Terminal.Say("Enter your bet (min bet: " + std::to_string(min_Bet) + ", max bet: " + std::to_string(cash) + "):");
    Terminal.Say("Type 'call', 'raise', or 'fold'");

    // Loop until a valid bet is made
    while (true)
    {
        // Get the player's input
        Terminal.In();
        std::stringstream ss(Terminal.Get_Input());
        std::string my_str(ss.str());
        transform(my_str.begin(), my_str.end(), my_str.begin(), ::tolower);

        if (my_str == "fold")
        {
            // If the player entered "fold", show a message indicating that they folded and update their status
            Terminal.Say("Player folded");
            player->Fold();
            break;
        }
        else if (my_str == "call")
        {
            if(min_Bet > cash)
            {
                // "continue" will repeat the loop
                Terminal.Say("Invalid bet! Cannot call.");
                continue;
            }

            // Update the player's bet and cash balance to match the minimum bet
            player->set_Bet(min_Bet);
            player->set_Cash(cash - min_Bet);
            break;
        }
        else if (my_str == "raise")
        {
            // If the player doesn't have enough cash to pay the minumum bet, then they can't raise
            if(min_Bet > cash)
            {
                // "continue" will repeat the loop
                Terminal.Say("Invalid bet! Cannot raise.");
                continue;
            }

            // Prompt player for the amount they want to raise by
            Terminal.Say("Enter the amount you want to raise by (current bet: " + std::to_string(min_Bet) + "):");

            // Loop until they enter a valid total bet amount
            while (true)
            {
                // Get the player's input
                Terminal.In();
                std::stringstream ss(Terminal.Get_Input());
                int in;
                if (!(ss >> in))
                {
                    // "continue" will repeat the loop
                    Terminal.Say("Invalid bet! Please try again.");
                    continue;
                }

                // Calculate the raise amount
                new_Bet = in + min_Bet;

                // Check if the total bet amount is valid
                if (new_Bet > cash || 0 > in)
                {
                    // "continue" will repeat the loop
                    Terminal.Say("Invalid bet! Please try again.");
                    continue;
                }

                // Update the player's bet and cash balance
                player->set_Bet(new_Bet);
                player->set_Cash(cash - new_Bet);

                // Update the minimum bet to the new total bet amount
                set_min_Bet(new_Bet);
                break;
            }
            break;
        }

        // If the player's input is invalid, show an error message and allow the player to try again
        Terminal.Say("Invalid bet! Please try again.");
    }
}

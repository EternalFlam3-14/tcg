#include <iostream>
#include "tex.h"

void Texas_C::Bet(std::shared_ptr<BetPlayer_C> player)
{
    // Get the current minimum bet
    int min_Bet = get_Min_Bet();

    // Get the player's current bet and cash balance
    int bet = player->get_Bet();
    int cash = player->get_Cash();

    // Calculate the maximum bet the player can make
    int max_Bet = cash + bet;

    // Prompt the player to make a bet
    Terminal.Say("Enter your bet (min: " + std::to_string(min_Bet) + ", max: " + std::to_string(max_Bet) + "):");
    Terminal.Say("Type 'call', 'raise', 'fold', or enter a value");

    // Keep prompting the player until a valid bet is made
    while (true)
    {
        // Get the player's input
        Terminal.In();
        std::stringstream ss(Terminal.Get_Input());
        int in;

        // Check if the player's input is a valid bet
        if (ss >> in && in >= min_Bet && in <= max_Bet)
        {
            // If the bet is valid, update the player's bet and cash balance
            player->set_Bet(in);
            player->set_Cash(cash - in);
            break;
        }
        else if (ss.str() == "fold")
        {
            // If the player entered "fold", show a message indicating that they folded and update their status
            Terminal.Say("Player folded");
            player->Fold();
            break;
        }
        else if (ss.str() == "call")
        {
            // If the player entered "call", update the player's bet and cash balance to match the minimum bet
            player->set_Bet(min_Bet);
            player->set_Cash(cash - min_Bet);
            break;
        }
        else if (ss.str() == "raise")
        {
            // If the player entered "raise", prompt them for the amount they want to raise by
            Terminal.Say("Enter the amount you want to raise by (min: " + std::to_string(min_Bet) + ", max: " + std::to_string(max_Bet) + "):");

            // Keep prompting the player until they enter a valid raise amount
            while (true)
            {
                // Get the player's input
                Terminal.In();
                std::stringstream ss(Terminal.Get_Input());
                int in;

                // Check if the raise amount is valid
                if (ss >> in && in >= min_Bet && in <= max_Bet)
                {
                    // If the raise amount is valid, update the player's bet and cash balance
                    player->set_Bet(in);
                    player->set_Cash(cash - in);
                    break;
                }
                else
                {
                    // If the raise amount is invalid, show an error message and allow the player to try again
                    Terminal.Say("Invalid raise amount! Please try again.");
                }
            }
            break;
        }
        else
        {
            // If the player's input is invalid, show an error message and allow the player to try again
            Terminal.Say("Invalid bet! Please try again.");
        }
    }
}

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
    int bigBlind;
    if (ss >> bigBlind && bigBlind > 0)
    {
        set_Min_Bet(bigBlind);
    }
    else
    {
        Terminal.Say("Invalid input, defaulting to 10");
        set_Min_Bet(10);
    }

    // Main game loop
    while (!gameEnd)
    {
        // Players take turns betting
        for (std::shared_ptr<Player_C> Player : Players)
        {
            // Get the current player
            std::shared_ptr<BetPlayer_C> player = std::static_pointer_cast<BetPlayer_C>(Player);

            // Show the player's current hand and cash balance
            player->print_Hand();
            player->print_Cash();

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

            // If the player hasn't folded, allow them to make another bet
            if (!player->has_Folded())
            {
                // Show the player's current hand and cash balance
                player->print_Hand();
                player->print_Cash();

                // Allow the player to make another bet
                Bet(player);
            }
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

            // If the player hasn't folded, allow them to make another bet
            if (!player->has_Folded())
            {
                // Show the player's current hand and cash balance
                player->print_Hand();
                player->print_Cash();

                // Allow the player to make another bet
                Bet(player);
            }
        }

        // End the game
        gameEnd = true;
    }
}

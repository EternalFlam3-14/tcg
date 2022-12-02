#include "player.h"

#include <string>
#include <memory>

void Player::Draw(int pos, std::shared_ptr<Card_C> Card)
{
    Hand.card_Set(pos, Card);
}

std::shared_ptr<Card_C> Player::play_Card(int pos)
{
    std::shared_ptr<Card_C> card = Hand.card_Pull(pos);
    Terminal.Say(card->get_Name());
    return card;
}

void Player::print_Hand()
{
    Terminal.Say(R"(~~~~~)");
    for (int i(0); i < hand_Size(); i++)
    {
        Terminal.Say(R"(~~~~            )" + int_toString(i+1) + "   " + Hand.card_At(i).get_Name() + R"(
~~~~~)");
    }
    Terminal.Say(R"(~~~~~~)");
}

void Player::check_Hand()
{
    Terminal.Say("To check hand");
    Hand.deck_Check();
}

void Player::print_Cash()
{
    Terminal.Say(R"(~~~~~~          $   )" + int_toString(get_Cash()));
}
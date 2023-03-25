#ifndef TEX_H
#define TEX_H
#include "game.h"

enum Phase_C
{
    Flop = 0,
    Turn,
    River
};


class Texas_C : public Game_C
{
public:
    Texas_C() { deck_s = 52, hand_s = 2, player_s = 3, cash_s = 100, gametype = Texas; };

    void Play() override;

private:

    // High level dealing feature. Takes arguments "Flop", "Turn", and "River"
    void Deal(Phase_C Phase);

    // High level betting feature, handles fold, all-in, raise, etc.
    void BetPhase();

    // Low level bet feature, to be used in larger function
    void Bet(std::shared_ptr<BetPlayer_C> player);

    // Handles confirmation and sets the bool
    bool AllIn(std::shared_ptr<BetPlayer_C> player);

    // Low level raise feature, to be used in larger function
    void Raise(std::shared_ptr<BetPlayer_C> player);

    void Showdown();

    void set_min_Bet(int new_minBet) { min_Bet = new_minBet; };

    int get_min_Bet() const { return min_Bet; };

    int pool = 0, min_Bet = 0, big_Blind = 0, new_Bet = 0;
    std::vector<std::shared_ptr<Card_C>> Table;
    bool End = false;
};


#endif
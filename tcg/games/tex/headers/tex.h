#include "game.h"

class Texas_C : public Game_C
{
public:
    Texas_C() { deck_s = 52, hand_s = 2, player_s = 3, cash_s = 100, gametype = Texas; };

    void Play() override;

private:

    void Bet(std::shared_ptr<BetPlayer_C> player);

    void set_min_Bet(int new_minBet) { min_Bet = new_minBet; };

    int get_min_Bet() const { return min_Bet; };

    int pool = 0, min_Bet = 0, big_Blind = 0, new_Bet = 0;
    std::vector<std::shared_ptr<Card_C>> Table;
    bool End = false;
};

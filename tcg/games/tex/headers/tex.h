#include "game.h"

class Texas_C : public Game_C
{
public:
    Texas_C() { deck_s = 52, hand_s = 2, player_s = 3, cash_s = 100, gametype = Texas; };

    void Play() override;

private:

    void Bet(std::shared_ptr<BetPlayer_C> player);

    void set_Min_Bet(int newminBet) { minBet = newminBet; };

    int get_Min_Bet() const { return minBet; };

    int pool = 0, minBet = 0;
    std::vector<std::shared_ptr<Card_C>> Table;
    bool gameEnd = false;
};

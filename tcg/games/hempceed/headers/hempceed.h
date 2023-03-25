#ifndef HEMPCEED_H
#define HEMPCEED_H
#include "game.h"

class HempCeed_C : public Game_C
{
public:
    HempCeed_C() { deck_s = 21, hand_s = 7, player_s = 1, cash_s = 100, gametype = Hemp_Ceed; };

    void Play() override;


private:




};


#endif
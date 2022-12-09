#ifndef GARDEN_H
#define GARDEN_H

#include "card.h"
#include "deck.h"
#include <vector>
#include <memory>
#include <array>

struct Slot
{
    std::shared_ptr<HempCard_C> plant;
    int N, P, K;
    bool is_Planted = false;
};

class Garden_C
{
public:
    Garden_C() : Slots(slotsize) {};

    void harvest_Card(int slotno, std::string *harvest_Type, int *harvest_Size);

    void add_Card(std::shared_ptr<HempCard_C> in, int slotno);

    void remove_Card(int i);

    void add_Fertilizer(std::shared_ptr<HempCard_C> in, int slotno);


//      Getters

    int get_Plants() const { return plants; };

    std::shared_ptr<HempCard_C> card_At(int i) const { return Slots[i].plant; };


private:
    
    std::vector<Slot> Slots;
    int plants, slotsize = 12;

    void set_Plants();
};



#endif
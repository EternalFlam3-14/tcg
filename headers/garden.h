#ifndef GARDEN_H
#define GARDEN_H

#include "card.h"
#include "deck.h"
#include <vector>
#include <memory>
#include <array>

struct Slot
{
    std::shared_ptr<Card_C> plant;
    int N, P, K;
    bool is_Planted = false;
};

class Garden
{
public:

    void harvest_Card(int slotno, std::string *harvest_Type, int *harvest_Size);

    void add_Card(std::shared_ptr<Card_C> in, int slotno);

    void remove_Card(int i);

    void add_Fertilizer(std::shared_ptr<Card_C> in, int slotno);


//      Getters

    int get_Plants() const { return plants; };

    Card_C card_At(int i) const { return (*Slot[i].plant.get()); };


private:
    
    std::array<Slot, 12> Slot;
    int plants, slotsize = 12;

    void set_Plants();
};



#endif
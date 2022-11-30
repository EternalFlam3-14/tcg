#include "garden.h"
#include "card.h"
#include "terminal.h"
#include <vector>
#include <memory>

void Garden::harvest_Card(int slotno, std::string *harvest_Type, int *harvest_Size)
{
}

void Garden::add_Card(std::shared_ptr<Card_C> in, int slotno)
{
    if (!Slot[slotno].is_Planted)
    {
        Slot[slotno].plant = in;
        Slot[slotno].is_Planted = true;
    }
    else { // Fail
    Terminal_C Terminal;
    Terminal.Say("Slot already planted.");
    }
    set_Plants();
}

void Garden::remove_Card(int slotno)
{
    if (Slot[slotno].is_Planted)
    {
        Slot[slotno].plant = nullptr;

        if (Slot[slotno].plant){ // Fail
            Terminal_C Terminal;
            Terminal.Say("Error deleting slot.");
        }
    }
    else { // Fail
        Terminal_C Terminal;
        Terminal.Say("Slot already empty.");
    }
    set_Plants();
}

void Garden::add_Fertilizer(std::shared_ptr<Card_C> in, int slotno)
{
}

void Garden::set_Plants()
{
    int temp(0);
    for (int i(0); i < slotsize; ++i)
    {
        temp += card_At(i).get_Value();
    }
    plants = temp;
}

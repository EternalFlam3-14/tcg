#include "garden.h"
#include "card.h"
#include "terminal.h"
#include <vector>
#include <memory>

void Garden_C::harvest_Card(int slotno, std::string *harvest_Type, int *harvest_Size)
{
}

void Garden_C::add_Card(std::shared_ptr<HempCard_C> in, int slotno)
{
    if (!Slots[slotno].is_Planted)
    {
        Slots[slotno].plant = in;
        Slots[slotno].is_Planted = true;
    }
    else { // Fail
    Terminal_C Terminal;
    Terminal.Say("Slot already planted.");
    }
    set_Plants();
}

void Garden_C::remove_Card(int slotno)
{
    if (Slots[slotno].is_Planted)
    {
        Slots[slotno].plant = nullptr;

        if (Slots[slotno].plant){ // Fail
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

void Garden_C::add_Fertilizer(std::shared_ptr<HempCard_C> in, int slotno)
{
}

void Garden_C::set_Plants()
{
    int temp(0);
    for (int i(0); i < slotsize; ++i)
    {
        temp += card_At(i)->get_Value();
    }
    plants = temp;
}

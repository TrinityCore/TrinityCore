#include "CreatureOutfit.h"
#include "DB2Structure.h" // ChrRacesEntry
#include "DB2Stores.h" // sChrRacesStore, sDB2Manager

constexpr uint32 CreatureOutfit::invisible_model;
constexpr uint32 CreatureOutfit::max_real_modelid;
constexpr EquipmentSlots CreatureOutfit::item_slots[];

CreatureOutfit::CreatureOutfit(uint8 race, Gender gender) : race(race), gender(gender)
{
    auto* model = sDB2Manager.GetChrModel(race, gender);
    if (!model)
    {
        model = sDB2Manager.GetChrModel(RACE_HUMAN, GENDER_MALE);
        ASSERT(model);
    }
    displayId = model->DisplayID;
}

CreatureOutfit& CreatureOutfit::SetItemEntry(EquipmentSlots slot, uint32 item_entry, uint32 appearancemodid)
{
    if (uint32 display = sDB2Manager.GetItemDisplayId(item_entry, appearancemodid))
        outfitdisplays[slot] = display;
    else
        outfitdisplays[slot] = 0;
    return *this;
}

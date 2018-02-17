#include "CreatureOutfit.h"
#include "DBCStructure.h" // ChrRacesEntry
#include "DBCStores.h" // sChrRacesStore
#include "ItemTemplate.h"
#include "ObjectMgr.h"

constexpr uint32 CreatureOutfit::invisible_model;
constexpr uint32 CreatureOutfit::max_real_modelid;
constexpr EquipmentSlots CreatureOutfit::item_slots[];

CreatureOutfit::CreatureOutfit(uint8 race, Gender gender) : race(race), gender(gender)
{
    const ChrRacesEntry* rEntry = sChrRacesStore.LookupEntry(race);
    if (!rEntry)
    {
        rEntry = sChrRacesStore.LookupEntry(RACE_HUMAN);
    }
    switch (gender)
    {
        case GENDER_FEMALE: displayId = rEntry->model_f; break;
        default: displayId = rEntry->model_m; break;
    }
}

CreatureOutfit& CreatureOutfit::SetItemEntry(EquipmentSlots slot, uint32 item_entry)
{
    if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(item_entry))
        outfitdisplays[slot] = proto->DisplayInfoID;
    else
        outfitdisplays[slot] = 0;
    return *this;
}

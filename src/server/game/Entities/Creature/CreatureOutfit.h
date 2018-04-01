#ifndef CREATURE_OUTFIT_H
#define CREATURE_OUTFIT_H

#include "Define.h"
#include "Player.h" // EquipmentSlots
#include "SharedDefines.h" // Gender
#include <memory>

class Creature;
class WorldSession;

class TC_GAME_API CreatureOutfit
{
public:
    friend class ObjectMgr;

    // Remember to change DB query too!
    static constexpr uint32 max_custom_displays = 3;
    static constexpr uint32 invisible_model = 11686;
    static constexpr uint32 max_real_modelid = 0x7FFFFFFF;
    static constexpr EquipmentSlots item_slots[] =
    {
        EQUIPMENT_SLOT_HEAD,
        EQUIPMENT_SLOT_SHOULDERS,
        EQUIPMENT_SLOT_BODY,
        EQUIPMENT_SLOT_CHEST,
        EQUIPMENT_SLOT_WAIST,
        EQUIPMENT_SLOT_LEGS,
        EQUIPMENT_SLOT_FEET,
        EQUIPMENT_SLOT_WRISTS,
        EQUIPMENT_SLOT_HANDS,
        EQUIPMENT_SLOT_TABARD,
        EQUIPMENT_SLOT_BACK,
    };

    static bool IsFake(uint32 modelid) { return modelid > max_real_modelid; };

    CreatureOutfit(uint8 race, Gender gender);

    uint8 Class = 1;
    uint8 face = 0;
    uint8 skin = 0;
    uint8 hair = 0;
    uint8 facialhair = 0;
    uint8 haircolor = 0;
    uint8 customdisplay[max_custom_displays] = { 0 };
    uint32 outfitdisplays[EQUIPMENT_SLOT_END] = { 0 };
    uint32 npcsoundsid = 0;
    uint64 guild = 0;

    uint32 GetId() const { return id; }
    uint8 GetGender() const { return gender; }
    uint8 GetRace() const { return race; }
    uint32 GetDisplayId() const { return displayId; }

    CreatureOutfit& SetItemEntry(EquipmentSlots slot, uint32 item_entry, uint32 appearancemodid = 0);
    CreatureOutfit& SetItemDisplay(EquipmentSlots slot, uint32 displayid)
    {
        outfitdisplays[slot] = displayid;
        return *this;
    }

private:
    CreatureOutfit() {};
    uint32 id = 0;
    uint8 race;
    uint8 gender;
    uint32 displayId;
};

#endif

#ifndef ROBOT_STRATEGIES_SCRIPT_BASE_H
#define ROBOT_STRATEGIES_SCRIPT_BASE_H

#ifndef AOE_TARGETS_RANGE
# define AOE_TARGETS_RANGE 5
#endif

#ifndef MIN_DISTANCE_GAP
# define MIN_DISTANCE_GAP 0.5f
#endif

#ifndef FOLLOW_MIN_DISTANCE
# define FOLLOW_MIN_DISTANCE 1.0f
#endif

#ifndef FOLLOW_MAX_DISTANCE
# define FOLLOW_MAX_DISTANCE 30.0f
#endif

#ifndef MELEE_MIN_DISTANCE
# define MELEE_MIN_DISTANCE 1.0f
#endif

#ifndef MELEE_MAX_DISTANCE
# define MELEE_MAX_DISTANCE 3.0f
#endif

#ifndef RANGED_MIN_DISTANCE
# define RANGED_MIN_DISTANCE 15.0f
#endif

#ifndef RANGED_MAX_DISTANCE
# define RANGED_MAX_DISTANCE 30.0f
#endif

#include "Unit.h"
#include "Item.h"

class Script_Base
{
public:
	Script_Base();
	virtual bool DPS(Unit* pmTarget) = 0;
	virtual bool Tank(Unit* pmTarget) = 0;
	virtual bool Heal(Unit* pmTarget) = 0;
	virtual bool Attack(Unit* pmTarget) = 0;
	virtual bool Buff(Unit* pmTarget) = 0;

    void InitializeCharacter(uint32 pmTargetLevel);    
    void InitialEquipment(uint32 pmWeaponType, bool pmDual, uint32 pmArmorType, bool pmHasRange, uint32 pmRangeType, bool pmHasShield);
    bool EquipNewItem(uint32 pmEntry);
    bool EquipNewItem(uint32 pmEntry, uint8 pmEquipSlot);
    Item* GetItemInInventory(uint32 pmEntry);
    bool UseItem(Item* pmItem, Unit* pmTarget);
    bool ApplyGlyph(uint32 pmGlyphItemEntry, uint32 pmSlot);
    void RandomTeleport();
    void Prepare();
    void Logout();

    void Chase(Unit* pmTarget, float pmMinDistance, float pmMaxDistance);

    uint32 account;
    uint32 character;

    std::unordered_map<std::string, uint32> spellIDMap;
    std::unordered_map<std::string, uint8> spellLevelMap;

    uint8 characterTalentTab;
    // 0 dps, 1 tank, 2 healer
    uint32 characterType;
};
#endif

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

#ifndef FOLLOW_NORMAL_DISTANCE
# define FOLLOW_NORMAL_DISTANCE 20.0f
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

#ifndef ATTACK_RANGE_LIMIT
# define ATTACK_RANGE_LIMIT 200.0f
#endif

#ifndef DEFAULT_REST_DELAY
# define DEFAULT_REST_DELAY 20000
#endif

#include "Unit.h"
#include "Item.h"
#include "Player.h"

class Script_Base
{
public:
    Script_Base(Player* pmMe);
    virtual bool DPS(Unit* pmTarget, bool pmChase, bool pmAOE);
    virtual bool Tank(Unit* pmTarget);
    virtual bool Heal(Unit* pmTarget, bool pmCure);
    virtual bool Attack(Unit* pmTarget);
    virtual bool Buff(Unit* pmTarget, bool pmCure);

    void PetAttack(Unit* pmTarget);
    void PetStop();

    void InitializeCharacter(uint32 pmTargetLevel);
    void InitializeValues();
    void InitialEquipment(uint32 pmWeaponType, bool pmDual, uint32 pmArmorType, bool pmHasRange, uint32 pmRangeType, bool pmHasShield);
    bool EquipNewItem(uint32 pmEntry);
    bool EquipNewItem(uint32 pmEntry, uint8 pmEquipSlot);
    Item* GetItemInInventory(uint32 pmEntry);
    bool UseItem(Item* pmItem, Unit* pmTarget);
    bool ApplyGlyph(uint32 pmGlyphItemEntry, uint32 pmSlot);
    uint32 FindSpellID(std::string pmSpellName);
    bool SpellValid(uint32 pmSpellID);
    bool CastSpell(Unit* pmTarget, std::string pmSpellName, float pmDistance = MELEE_MAX_DISTANCE, bool pmCheckAura = false, bool pmOnlyMyAura = false);
    bool HasAura(Unit* pmTarget, std::string pmSpellName, bool pmOnlyMyAura = false);
    void ClearShapeshift();
    void CancelAura(uint32 pmSpellID);
    bool CancelAura(std::string pmSpellName);
    bool Rest();
    void WhisperTo(std::string pmContent, Language pmLanguage, Player* pmTarget);
    void RandomTeleport();
    void Prepare();    
    bool Chase(Unit* pmTarget, float pmMaxDistance = MELEE_MIN_DISTANCE, float pmMinDistance = MIN_DISTANCE_GAP);
    bool Follow(Unit* pmTarget, float pmDistance = FOLLOW_MIN_DISTANCE);

    Player* me;
    std::unordered_map<std::string, uint32> spellIDMap;
    std::unordered_map<std::string, uint8> spellLevelMap;

    uint8 characterTalentTab;
    // 0 dps, 1 tank, 2 healer
    uint32 characterType;
};
#endif

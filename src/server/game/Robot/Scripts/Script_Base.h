#ifndef ROBOT_STRATEGIES_SCRIPT_BASE_H
#define ROBOT_STRATEGIES_SCRIPT_BASE_H

#ifndef RANGE_CHASE_DISTANCE
# define RANGE_CHASE_DISTANCE 25.0f
#endif

#include "Unit.h"
#include "Item.h"
#include "Player.h"
#include "RobotManager.h"

class Script_Base
{
public:
    Script_Base(Player* pmMe);
    virtual void Reset();    
    virtual bool DPS(Unit* pmTarget, bool pmChase, bool pmAOE, Player* pmTank, bool pmInterruptTargetCasting = true);
    virtual bool Tank(Unit* pmTarget, bool pmChase, bool pmSingle = false);
    virtual bool SubTank(Unit* pmTarget, bool pmChase);
    virtual bool Taunt(Unit* pmTarget);
    virtual bool InterruptCasting(Unit* pmTarget);
    virtual bool Heal(Unit* pmTarget, bool pmCure = true);
    virtual bool SubHeal(Unit* pmTarget, bool pmCure = true);
    virtual bool GroupHeal(float pmMaxHealthPercent = 60.0f);
    virtual bool Attack(Unit* pmTarget);
    virtual bool Buff(Unit* pmTarget, bool pmCure = true);
    virtual bool Assist();

    bool Update(uint32 pmDiff);

    void PetAttack(Unit* pmTarget);
    void PetStop();

    void IdentifyCharacterSpells();
    Item* GetItemInInventory(uint32 pmEntry);
    bool UseItem(Item* pmItem, Unit* pmTarget);
    bool UseHealingPotion();
    bool UseManaPotion();
    uint32 FindSpellID(std::string pmSpellName);
    bool SpellValid(uint32 pmSpellID);
    bool CastSpell(Unit* pmTarget, std::string pmSpellName, float pmDistance = MELEE_MAX_DISTANCE, bool pmCheckAura = false, bool pmOnlyMyAura = false, bool pmClearShapeShift = false);
    bool HasAura(Unit* pmTarget, std::string pmSpellName, bool pmOnlyMyAura = false);
    uint32 GetAuraDuration(Unit* pmTarget, std::string pmSpellName, bool pmOnlyMyAura = false);
    void ClearShapeshift();
    void CancelAura(uint32 pmSpellID);
    bool CancelAura(std::string pmSpellName);
    bool Rest();
    void WhisperTo(std::string pmContent, Language pmLanguage, Player* pmTarget);
    void RandomTeleport();
    bool Chase(Unit* pmTarget, float pmMaxDistance = MELEE_MIN_DISTANCE, float pmMinDistance = MIN_DISTANCE_GAP);
    bool Follow(Unit* pmTarget, float pmDistance = FOLLOW_MIN_DISTANCE);
    void ChooseTarget(Unit* pmTarget);
    void ClearTarget();
    std::set<Unit*> GetAttackersInRange(float pmRangeLimit = RANGED_MAX_DISTANCE);

    Player* me;
    std::unordered_map<std::string, uint32> spellIDMap;
    std::unordered_map<std::string, uint8> spellLevelMap;

    int actionDelay;

    // 0 dps, 1 tank, 2 healer
    uint32 characterType;
    bool petting;
    float chaseDistanceMin;
    float chaseDistanceMax;    
    int rti;
};
#endif

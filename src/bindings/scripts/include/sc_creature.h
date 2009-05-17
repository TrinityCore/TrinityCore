/* Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * Thanks to the original authors: ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software licensed under GPL version 2
 * Please see the included DOCS/LICENSE.TXT for more information */

#ifndef SC_CREATURE_H
#define SC_CREATURE_H

#include "Creature.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "InstanceData.h"

class ScriptedInstance;

class SummonList : private std::list<uint64>
{
    public:
        explicit SummonList(Creature* creature) : m_creature(creature) {}
        void Summon(Creature *summon) { push_back(summon->GetGUID()); }
        void Despawn(Creature *summon) { remove(summon->GetGUID()); }
        void DespawnEntry(uint32 entry);
        void DespawnAll();
        void DoAction(uint32 entry, uint32 info);
        void DoZoneInCombat(uint32 entry = 0);
    private:
        Creature *m_creature;
};

float GetSpellMaxRangeForHostile(uint32 id);

//Get a single creature of given entry
Unit* FindCreature(uint32 entry, float range, Unit* Finder);

//Get a single gameobject of given entry
GameObject* FindGameObject(uint32 entry, float range, Unit* Finder);

struct PointMovement
{
    uint32 m_uiCreatureEntry;
    uint32 m_uiPointId;
    float m_fX;
    float m_fY;
    float m_fZ;
    uint32 m_uiWaitTime;
};

struct TRINITY_DLL_DECL ScriptedAI : public CreatureAI
{
    explicit ScriptedAI(Creature* creature);
    ~ScriptedAI() {}

    //*************
    //CreatureAI Functions
    //*************

    void AttackStartNoMove(Unit *target);

    // Called at any Damage from any attacker (before damage apply)
    void DamageTaken(Unit *done_by, uint32 &damage) {}

    //Called at World update tick
    void UpdateAI(const uint32);

    //Called at creature death
    void JustDied(Unit*){}

    //Called at creature killing another unit
    void KilledUnit(Unit*){}

    // Called when the creature summon successfully other creature
    void JustSummoned(Creature* ) {}

    // Called when a summoned creature is despawned
    void SummonedCreatureDespawn(Creature* /*unit*/) {}

    // Called when hit by a spell
    void SpellHit(Unit* caster, const SpellEntry*) {}

    // Called when spell hits a target
    void SpellHitTarget(Unit* target, const SpellEntry*) {}

    //Called at waypoint reached or PointMovement end
    void MovementInform(uint32 type, uint32 id){}

    // Called when AI is temporarily replaced or put back when possess is applied or removed
    void OnPossess(bool apply) {}

    //*************
    // Variables
    //*************

    //Pointer to creature we are manipulating
    Creature* m_creature;

    //For fleeing
    bool IsFleeing;

    bool HeroicMode;

    //*************
    //Pure virtual functions
    //*************

    //Called at creature reset either by death or evade
    void Reset() {}

    //Called at creature aggro either by MoveInLOS or Attack Start
    void EnterCombat(Unit*) {}

    //*************
    //AI Helper Functions
    //*************

    //Start movement toward victim
    void DoStartMovement(Unit* victim, float distance = 0, float angle = 0);

    //Start no movement on victim
    void DoStartNoMovement(Unit* victim);

    //Stop attack of current victim
    void DoStopAttack();

    //Cast spell by Id
    void DoCast(Unit* victim, uint32 spellId, bool triggered = false);
    void DoCastAOE(uint32 spellId, bool triggered = false);

    //Cast spell by spell info
    void DoCastSpell(Unit* who,SpellEntry const *spellInfo, bool triggered = false);

    //Creature say
    void DoSay(const char* text, uint32 language, Unit* target, bool SayEmote = false);

    //Creature Yell
    void DoYell(const char* text, uint32 language, Unit* target);

    //Creature Text emote, optional bool for boss emote text
    void DoTextEmote(const char* text, Unit* target, bool IsBossEmote = false);

    //Creature whisper, optional bool for boss whisper
    void DoWhisper(const char* text, Unit* reciever, bool IsBossWhisper = false);

    //Plays a sound to all nearby players
    void DoPlaySoundToSet(Unit* unit, uint32 sound);

    //Drops all threat to 0%. Does not remove players from the threat list
    void DoResetThreat();

    float DoGetThreat(Unit *u);
    void DoModifyThreatPercent(Unit *pUnit, int32 pct);

    void DoTeleportTo(float x, float y, float z, uint32 time = 0);
    void DoTeleportTo(const float pos[4]);

    void DoAction(const int32 param) {}

    //Teleports a player without dropping threat (only teleports to same map)
    void DoTeleportPlayer(Unit* pUnit, float x, float y, float z, float o);
    void DoTeleportAll(float x, float y, float z, float o);

    //Returns friendly unit with the most amount of hp missing from max hp
    Unit* DoSelectLowestHpFriendly(float range, uint32 MinHPDiff = 1);

    //Returns a list of friendly CC'd units within range
    std::list<Creature*> DoFindFriendlyCC(float range);

    //Returns a list of all friendly units missing a specific buff within range
    std::list<Creature*> DoFindFriendlyMissingBuff(float range, uint32 spellid);

    //Spawns a creature relative to m_creature
    Creature* DoSpawnCreature(uint32 id, float x, float y, float z, float angle, uint32 type, uint32 despawntime);
    Creature *DoSummon(uint32 entry, const float pos[4], uint32 despawntime = 30000, TempSummonType type = TEMPSUMMON_CORPSE_TIMED_DESPAWN);
    Creature *DoSummon(uint32 entry, WorldObject *obj, float radius = 5.0f, uint32 despawntime = 30000, TempSummonType type = TEMPSUMMON_CORPSE_TIMED_DESPAWN);

    //Selects a unit from the creature's current aggro list
    Unit* SelectUnit(SelectAggroTarget target, uint32 position);

    bool HealthBelowPct(uint32 pct) const { return me->GetHealth() * 100 < m_creature->GetMaxHealth() * pct; }

    //Returns spells that meet the specified criteria from the creatures spell list
    SpellEntry const* SelectSpell(Unit* Target, int32 School, int32 Mechanic, SelectTargetType Targets,  uint32 PowerCostMin, uint32 PowerCostMax, float RangeMin, float RangeMax, SelectEffect Effect);

    //Checks if you can cast the specified spell
    bool CanCast(Unit* Target, SpellEntry const *Spell, bool Triggered = false);

    void SetEquipmentSlots(bool bLoadDefault, int32 uiMainHand = EQUIP_NO_CHANGE, int32 uiOffHand = EQUIP_NO_CHANGE, int32 uiRanged = EQUIP_NO_CHANGE);

    void SetSheathState(SheathState newState);
};

struct TRINITY_DLL_DECL Scripted_NoMovementAI : public ScriptedAI
{
    Scripted_NoMovementAI(Creature* creature) : ScriptedAI(creature) {}

    //Called if IsVisible(Unit *who) is true at each *who move
    //void MoveInLineOfSight(Unit *);

    //Called at each attack of m_creature by any victim
    void AttackStart(Unit *);
};

struct TRINITY_DLL_DECL BossAI : public ScriptedAI
{
    BossAI(Creature *c, uint32 id);

    const uint32 bossId;
    EventMap events;
    SummonList summons;
    InstanceData * const instance;
    const BossBoundaryMap * const boundary;

    void JustSummoned(Creature *summon);
    void SummonedCreatureDespawn(Creature *summon);

    void UpdateAI(const uint32 diff) = 0;

    void Reset() { _Reset(); }
    void EnterCombat(Unit *who) { _EnterCombat(); }
    void JustDied(Unit *killer) { _JustDied(); }

    protected:
        void _Reset();
        void _EnterCombat();
        void _JustDied();

        bool CheckInRoom()
        {
            if(CheckBoundary(me))
                return true;
            EnterEvadeMode();
            return false;
        }
        bool CheckBoundary(Unit *who);
};

#endif


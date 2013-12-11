/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Cell.h"
#include "CellImpl.h"
#include "obsidian_sanctum.h"

enum Enums
{
    WHISPER_HATCH_EGGS                          = 6,
    WHISPER_OPEN_PORTAL                         = 6,         // whisper, shared by two dragons

    //Mini bosses common spells
    SPELL_TWILIGHT_RESIDUE                      = 61885,    // makes immune to shadow damage, applied when leave phase

    //Miniboses (Vesperon, Shadron, Tenebron)
    SPELL_SHADOW_BREATH_H                       = 59126,    // Inflicts 8788 to 10212 Fire damage to enemies in a cone in front of the caster.
    SPELL_SHADOW_BREATH                         = 57570,    // Inflicts 6938 to 8062 Fire damage to enemies in a cone in front of the caster.

    SPELL_SHADOW_FISSURE_H                      = 59127,    // Deals 9488 to 13512 Shadow damage to any enemy within the Shadow fissure after 5 sec.
    SPELL_SHADOW_FISSURE                        = 57579,    // Deals 6188 to 8812 Shadow damage to any enemy within the Shadow fissure after 5 sec.

    //Vesperon
    //In portal is a disciple, when disciple killed remove Power_of_vesperon, portal open multiple times
    NPC_ACOLYTE_OF_VESPERON                     = 31219,    // Acolyte of Vesperon
    SPELL_POWER_OF_VESPERON                     = 61251,    // Vesperon's presence decreases the maximum health of all enemies by 25%.
    SPELL_TWILIGHT_TORMENT_VESP                 = 57948,    // (Shadow only) trigger 57935 then 57988
    SPELL_TWILIGHT_TORMENT_VESP_ACO             = 58853,    // (Fire and Shadow) trigger 58835 then 57988

    //Shadron
    //In portal is a disciple, when disciple killed remove Power_of_vesperon, portal open multiple times
    NPC_ACOLYTE_OF_SHADRON                      = 31218,    // Acolyte of Shadron
    SPELL_POWER_OF_SHADRON                      = 58105,    // Shadron's presence increases Fire damage taken by all enemies by 100%.
    SPELL_GIFT_OF_TWILIGTH_SHA                  = 57835,    // TARGET_SCRIPT shadron
    SPELL_GIFT_OF_TWILIGTH_SAR                  = 58766,    // TARGET_SCRIPT sartharion
    SPELL_VOID_BLAST                            = 57581,    // Twilight Fissure
    SPELL_VOID_BLAST_H                          = 59128,

    //Tenebron
    //in the portal spawns 6 eggs, if not killed in time (approx. 20s)  they will hatch,  whelps can cast 60708
    SPELL_POWER_OF_TENEBRON                     = 61248,    // Tenebron's presence increases Shadow damage taken by all enemies by 100%.
    //Tenebron, dummy spell
    SPELL_SUMMON_TWILIGHT_WHELP                 = 58035,    // doesn't work, will spawn NPC_TWILIGHT_WHELP
    SPELL_SUMMON_SARTHARION_TWILIGHT_WHELP      = 58826,    // doesn't work, will spawn NPC_SHARTHARION_TWILIGHT_WHELP
    SPELL_TWILIGHT_REVENGE                      = 60639,
    SPELL_HATCH_EGGS_H                          = 59189,
    SPELL_HATCH_EGGS                            = 58542,
    SPELL_HATCH_EGGS_EFFECT_H                   = 59190,
    SPELL_HATCH_EGGS_EFFECT                     = 58685,
    NPC_TWILIHT_WHELP                           = 31214,
    NPC_TWILIGHT_EGG                            = 30882,
    NPC_SARTHARION_TWILIGHT_EGG                 = 31204,

    SPELL_TWILIGHT_SHIFT_ENTER                  = 57620,    // enter phase. Player get this when click GO
    SPELL_TWILIGHT_SHIFT                        = 57874,    // Twilight Shift Aura
    SPELL_TWILIGHT_SHIFT_REMOVAL                = 61187,    // leave phase
    SPELL_TWILIGHT_SHIFT_REMOVAL_ALL            = 61190,    // leave phase (probably version to make all leave)

    //Whelps
    NPC_TWILIGHT_WHELP                          = 30890,
    NPC_SHARTHARION_TWILIGHT_WHELP              = 31214,
    SPELL_FADE_ARMOR                            = 60708,    // Reduces the armor of an enemy by 1500 for 15s

    //flame tsunami
    SPELL_FLAME_TSUNAMI                         = 57494,    // the visual dummy
    SPELL_FLAME_TSUNAMI_LEAP                    = 60241,    // SPELL_EFFECT_138 some leap effect, causing caster to move in direction

    SPELL_FLAME_TSUNAMI_DMG_AURA                = 57491,    // periodic damage, npc has this aura
    SPELL_FLAME_TSUNAMI_BUFF                    = 60430,
    NPC_LAVA_BLAZE                              = 30643,    // adds spawning from flame strike

    //using these custom points for dragons start and end
    POINT_ID_INIT                               = 100,
    POINT_ID_LAND                               = 200
};

enum Misc
{
    DATA_CAN_LOOT           = 0
};

struct Location
{
    float x, y, z;
};

struct Locations
{
    float x, y, z;
};

struct Waypoint
{
    float m_fX, m_fY, m_fZ;
};

#define MAX_WAYPOINT 6
//points around raid "isle", counter clockwise. should probably be adjusted to be more alike
Waypoint dragonCommon[MAX_WAYPOINT]=
{
    {3214.012f, 468.932f, 98.652f},
    {3244.950f, 468.427f, 98.652f},
    {3283.520f, 496.869f, 98.652f},
    {3287.316f, 555.875f, 98.652f},
    {3250.479f, 585.827f, 98.652f},
    {3209.969f, 566.523f, 98.652f}
};

static Location AcolyteofShadron = { 3363.92f, 534.703f, 97.2683f };
static Location AcolyteofShadron2 = { 3246.57f, 551.263f, 58.6164f };
static Location AcolyteofVesperon = { 3145.68f, 520.71f, 89.7f };
static Location AcolyteofVesperon2 = { 3246.57f, 551.263f, 58.6164f };

Locations TwilightEggs[] =
{
    {3219.28f, 669.121f, 88.5549f},
    {3221.55f, 682.852f, 90.5361f},
    {3239.77f, 685.94f, 90.3168f},
    {3250.33f, 669.749f, 88.7637f},
    {3246.6f, 642.365f, 84.8752f},
    {3233.68f, 653.117f, 85.7051f}
};
Locations TwilightEggsSarth[] =
{
    {3252.73f, 515.762f, 58.5501f},
    {3256.56f, 521.119f, 58.6061f},
    {3255.63f, 527.513f, 58.7568f},
    {3264.90f, 525.865f, 58.6436f},
    {3264.26f, 516.364f, 58.8011f},
    {3257.54f, 502.285f, 58.2077f}
};

enum SharedTextIDs
{
    SAY_AGGRO                      = 0,
    SAY_SLAY                       = 1,
    SAY_DEATH                      = 2,
    SAY_BREATH                     = 3,
    SAY_RESPOND                    = 4,
    SAY_SPECIAL                    = 5
};

enum DummyDragonEvents
{
    EVENT_FREE_MOVEMENT           = 1
};

//to control each dragons common abilities
struct dummy_dragonAI : public ScriptedAI
{
    dummy_dragonAI(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
    }

    void Reset() OVERRIDE
    {
        if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

        waypointId = 0;
        portalRespawnTime = 30000;
        _canMoveFree = false;
        _canLoot = true;
    }

    void SetData(uint32 type, uint32 value) OVERRIDE
    {
        if (type == DATA_CAN_LOOT)
            _canLoot = value;
    }

    void MovementInform(uint32 type, uint32 pointId) OVERRIDE
    {
        if (!instance || type != POINT_MOTION_TYPE)
            return;

        // debug_log("dummy_dragonAI: %s reached point %u", me->GetName(), uiPointId);

        // if healers messed up the raid and we was already initialized
        if (instance->GetBossState(DATA_SARTHARION) != IN_PROGRESS)
        {
            EnterEvadeMode();
            return;
        }

        // this is end, if we reach this, don't do much
        if (pointId == POINT_ID_LAND)
        {
            me->GetMotionMaster()->Clear();
            me->SetInCombatWithZone();
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
            {
                me->AddThreat(target, 1.0f);
                me->Attack(target, true);
                me->GetMotionMaster()->MoveChase(target);
            }

            _canMoveFree = false;
            return;
        }

        // get amount of common points
        uint32 commonWPCount = sizeof(dragonCommon)/sizeof(Waypoint);

        // increase
        waypointId = pointId+1;

        // if we have reached a point bigger or equal to count, it mean we must reset to point 0
        if (waypointId >= commonWPCount)
        {
            if (!_canMoveFree)
                _canMoveFree = true;

            waypointId = 0;
        }

        events.ScheduleEvent(EVENT_FREE_MOVEMENT, 500);
    }

    // used when open portal and spawn mobs in phase
    void DoRaidWhisper(int32 iTextId)
    {
        Map* map = me->GetMap();

        if (map && map->IsDungeon())
        {
            Map::PlayerList const &PlayerList = map->GetPlayers();

            if (!PlayerList.isEmpty())
            {
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    Talk(iTextId, i->GetSource()->GetGUID());
            }
        }
    }

    // "opens" the portal and does the "opening" whisper
    void OpenPortal()
    {
        int32 textId = 0;

        // there are 4 portal spawn locations, each are expected to be spawned with negative spawntimesecs in database

        // using a grid search here seem to be more efficient than caching all four guids
        // in instance script and calculate range to each.
        GameObject* portal = me->FindNearestGameObject(GO_TWILIGHT_PORTAL, 50.0f);

        switch (me->GetEntry())
        {
            case NPC_TENEBRON:
            {
                textId = WHISPER_HATCH_EGGS;
                if (instance && !instance->GetBossState(DATA_SARTHARION) == IN_PROGRESS)
                {
                    for (uint32 i = 0; i < 6; ++i)
                        me->SummonCreature(NPC_TWILIGHT_EGG, TwilightEggs[i].x, TwilightEggs[i].y, TwilightEggs[i].z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000);
                }
                else
                {
                    for (uint32 i = 0; i < 6; ++i)
                        me->SummonCreature(NPC_SARTHARION_TWILIGHT_EGG, TwilightEggsSarth[i].x, TwilightEggsSarth[i].y, TwilightEggsSarth[i].z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000);
                }
                break;
            }
            case NPC_SHADRON:
            {
                textId = WHISPER_OPEN_PORTAL;
                if (instance && !instance->GetBossState(DATA_SARTHARION) == IN_PROGRESS)
                    me->SummonCreature(NPC_ACOLYTE_OF_SHADRON, AcolyteofShadron.x, AcolyteofShadron.y, AcolyteofShadron.z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 28000);
                else
                    me->SummonCreature(NPC_ACOLYTE_OF_SHADRON, AcolyteofShadron2.x, AcolyteofShadron2.y, AcolyteofShadron2.z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 28000);

                break;
            }
            case NPC_VESPERON:
            {
                textId = WHISPER_OPEN_PORTAL;
                if (instance && !instance->GetBossState(DATA_SARTHARION) == IN_PROGRESS)
                {
                    if (Creature* acolyte = me->SummonCreature(NPC_ACOLYTE_OF_VESPERON, AcolyteofVesperon.x, AcolyteofVesperon.y, AcolyteofVesperon.z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                    {
                        me->InterruptNonMeleeSpells(true);
                        acolyte->InterruptNonMeleeSpells(true);
                        me->CastSpell(me, 32747, false);
                    }
                }
                else
                {
                    if (Creature* acolyte = me->SummonCreature(NPC_ACOLYTE_OF_VESPERON, AcolyteofVesperon2.x, AcolyteofVesperon2.y, AcolyteofVesperon2.z, 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20000))
                    {
                        me->InterruptNonMeleeSpells(true);
                        acolyte->InterruptNonMeleeSpells(true);
                        me->CastSpell(me, 32747, false);
                    }
                }

                 break;
            }
        }

        DoRaidWhisper(textId);

        // By using SetRespawnTime() we will actually "spawn" the object with our defined time.
        // Once time is up, portal will disappear again.
        if (portal && !portal->isSpawned())
            portal->SetRespawnTime(portalRespawnTime);

        // Unclear what are expected to happen if one drake has a portal open already
        // Refresh respawnTime so time again are set to 30secs?
    }

    void JustDied(Unit* /*killer*/) OVERRIDE
    {
        if (!_canLoot)
            me->SetLootRecipient(NULL);

        uint32 spellId = 0;

        switch (me->GetEntry())
        {
            case NPC_TENEBRON:
                spellId = SPELL_POWER_OF_TENEBRON;
                if (instance && instance->GetBossState(DATA_SARTHARION) != IN_PROGRESS)
                    instance->SetBossState(DATA_TENEBRON, DONE);
                break;
            case NPC_SHADRON:
                spellId = SPELL_POWER_OF_SHADRON;
                if (instance && instance->GetBossState(DATA_SARTHARION) != IN_PROGRESS)
                    instance->SetBossState(DATA_SHADRON, DONE);
                if (Creature* acolyte = me->FindNearestCreature(NPC_ACOLYTE_OF_SHADRON, 100.0f))
                    acolyte->Kill(acolyte);
                break;
            case NPC_VESPERON:
                spellId = SPELL_POWER_OF_VESPERON;
                if (instance && instance->GetBossState(DATA_SARTHARION) != IN_PROGRESS)
                    instance->SetBossState(DATA_VESPERON, DONE);
                if (Creature* acolyte = me->FindNearestCreature(NPC_ACOLYTE_OF_VESPERON, 100.0f))
                    acolyte->Kill(acolyte);
                break;
        }

        Talk(SAY_DEATH);
        me->RemoveAurasDueToSpell(spellId);

        if (instance)
        {
            instance->DoRemoveAurasDueToSpellOnPlayers(spellId);

            // not if solo mini-boss fight
            if (instance->GetBossState(DATA_SARTHARION) != IN_PROGRESS)
                return;

            // Twilight Revenge to main boss
            if (Unit* sartharion = Unit::GetUnit(*me, instance->GetData64(DATA_SARTHARION)))
                if (sartharion->IsAlive())
                {
                    sartharion->RemoveAurasDueToSpell(spellId);
                    DoCast(sartharion, SPELL_TWILIGHT_REVENGE, true);
                }
        }
    }

    void UpdateAI(uint32 diff) OVERRIDE
    {
        events.Update(diff);

        if (events.ExecuteEvent() == EVENT_FREE_MOVEMENT)
        {
            if (_canMoveFree && waypointId < MAX_WAYPOINT)
                me->GetMotionMaster()->MovePoint(waypointId, dragonCommon[waypointId].m_fX, dragonCommon[waypointId].m_fY, dragonCommon[waypointId].m_fZ);
        }
    }

    private:
        InstanceScript* instance;
        EventMap events;
        uint32   waypointId;
        int32    portalRespawnTime;
        bool     _canMoveFree;
        bool     _canLoot;
};

/*######
## Tenebron
######*/

enum TenebronEvents
{
    EVENT_SHADOW_FISSURE_TENEBRON = 2,
    EVENT_HATCH_EGGS              = 3,
    EVENT_SHADOW_BREATH_TENEBRON  = 4
};

class npc_tenebron : public CreatureScript
{
public:
    npc_tenebron() : CreatureScript("npc_tenebron") { }

    struct npc_tenebronAI : public dummy_dragonAI
    {
        npc_tenebronAI(Creature* creature) : dummy_dragonAI(creature) { }

        void Reset() OVERRIDE
        {
            dummy_dragonAI::Reset();
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);
            DoZoneInCombat();
            events.ScheduleEvent(EVENT_SHADOW_FISSURE_TENEBRON, 5000);
            events.ScheduleEvent(EVENT_HATCH_EGGS, 30000);
            events.ScheduleEvent(EVENT_SHADOW_BREATH_TENEBRON, 20000);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_SLAY);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //if no target, update dummy and return
            if (!UpdateVictim())
            {
                dummy_dragonAI::UpdateAI(diff);
                return;
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHADOW_FISSURE_TENEBRON:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, RAID_MODE(SPELL_SHADOW_FISSURE, SPELL_SHADOW_FISSURE));
                        events.ScheduleEvent(EVENT_SHADOW_FISSURE_TENEBRON, urand(15000, 20000));
                        break;
                    case EVENT_HATCH_EGGS:
                        OpenPortal();
                        events.ScheduleEvent(EVENT_HATCH_EGGS, 30000);
                        break;
                    case EVENT_SHADOW_BREATH_TENEBRON:
                        Talk(SAY_BREATH);
                        DoCastVictim(RAID_MODE(SPELL_SHADOW_BREATH, SPELL_SHADOW_BREATH_H));
                        events.ScheduleEvent(EVENT_SHADOW_BREATH_TENEBRON, urand(20000, 25000));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_tenebronAI(creature);
    }
};

/*######
## Shadron
######*/

enum ShadronEvents
{
    EVENT_SHADOW_FISSURE_SHADRON  = 5,
    EVENT_ACOLYTE_SHADRON         = 6,
    EVENT_SHADOW_BREATH_SHADRON   = 7
};

class npc_shadron : public CreatureScript
{
public:
    npc_shadron() : CreatureScript("npc_shadron") { }

    struct npc_shadronAI : public dummy_dragonAI
    {
        npc_shadronAI(Creature* creature) : dummy_dragonAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() OVERRIDE
        {
            dummy_dragonAI::Reset();

            if (me->HasAura(SPELL_TWILIGHT_TORMENT_VESP))
                me->RemoveAurasDueToSpell(SPELL_TWILIGHT_TORMENT_VESP);

            if (me->HasAura(SPELL_GIFT_OF_TWILIGTH_SHA))
                me->RemoveAurasDueToSpell(SPELL_GIFT_OF_TWILIGTH_SHA);

            if (instance)
                instance->SetBossState(DATA_PORTAL_OPEN, NOT_STARTED);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);
            DoZoneInCombat();
            events.ScheduleEvent(EVENT_SHADOW_FISSURE_SHADRON, 5000);
            events.ScheduleEvent(EVENT_ACOLYTE_SHADRON, 60000);
            events.ScheduleEvent(EVENT_SHADOW_BREATH_SHADRON, 20000);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_SLAY);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //if no target, update dummy and return
            if (!UpdateVictim())
            {
                dummy_dragonAI::UpdateAI(diff);
                return;
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHADOW_FISSURE_SHADRON:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, RAID_MODE(SPELL_SHADOW_FISSURE, SPELL_SHADOW_FISSURE_H));
                        events.ScheduleEvent(EVENT_SHADOW_FISSURE_SHADRON, urand(15000, 20000));
                        break;
                    case EVENT_ACOLYTE_SHADRON:
                        if (instance->GetBossState(DATA_PORTAL_OPEN) == NOT_STARTED)
                            events.ScheduleEvent(EVENT_ACOLYTE_SHADRON, 10000);
                        else
                        {
                            if (me->HasAura(SPELL_GIFT_OF_TWILIGTH_SHA))
                                return;

                            OpenPortal();

                            if (instance)
                                instance->SetBossState(DATA_PORTAL_OPEN, IN_PROGRESS);

                            events.ScheduleEvent(EVENT_ACOLYTE_SHADRON, urand(60000, 65000));
                        }
                        break;
                    case EVENT_SHADOW_BREATH_SHADRON:
                        Talk(SAY_BREATH);
                        DoCastVictim(RAID_MODE(SPELL_SHADOW_BREATH, SPELL_SHADOW_BREATH_H));
                        events.ScheduleEvent(EVENT_SHADOW_BREATH_SHADRON, urand(20000, 25000));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_shadronAI(creature);
    }
};

/*######
## Vesperon
######*/

enum VesperonEvents
{
    EVENT_SHADOW_FISSURE_VESPERON = 8,
    EVENT_ACOLYTE_VESPERON        = 9,
    EVENT_SHADOW_BREATH_VESPERON  = 10
};

class npc_vesperon : public CreatureScript
{
public:
    npc_vesperon() : CreatureScript("npc_vesperon") { }

    struct npc_vesperonAI : public dummy_dragonAI
    {
        npc_vesperonAI(Creature* creature) : dummy_dragonAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() OVERRIDE
        {
            dummy_dragonAI::Reset();
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            Talk(SAY_AGGRO);
            DoZoneInCombat();
            events.ScheduleEvent(EVENT_SHADOW_FISSURE_VESPERON, 5000);
            events.ScheduleEvent(EVENT_ACOLYTE_VESPERON, 60000);
            events.ScheduleEvent(EVENT_SHADOW_BREATH_VESPERON, 20000);
        }

        void KilledUnit(Unit* /*victim*/) OVERRIDE
        {
            Talk(SAY_SLAY);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            //if no target, update dummy and return
            if (!UpdateVictim())
            {
                dummy_dragonAI::UpdateAI(diff);
                return;
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SHADOW_FISSURE_VESPERON:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            DoCast(target, RAID_MODE(SPELL_SHADOW_FISSURE, SPELL_SHADOW_FISSURE_H));
                        events.ScheduleEvent(EVENT_SHADOW_FISSURE_VESPERON, urand(15000, 20000));
                        break;
                    case EVENT_ACOLYTE_VESPERON:
                        if (instance->GetBossState(DATA_PORTAL_OPEN) == IN_PROGRESS)
                            events.ScheduleEvent(EVENT_ACOLYTE_VESPERON, 10000);
                        else
                        {
                            OpenPortal();
                            DoCastVictim(SPELL_TWILIGHT_TORMENT_VESP);
                            events.ScheduleEvent(EVENT_ACOLYTE_VESPERON, urand(60000, 70000));
                        }
                        break;
                    case EVENT_SHADOW_BREATH_VESPERON:
                        Talk(SAY_BREATH);
                        DoCastVictim(RAID_MODE(SPELL_SHADOW_BREATH, SPELL_SHADOW_BREATH_H));
                        events.ScheduleEvent(EVENT_SHADOW_BREATH_VESPERON, urand(20000, 25000));
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_vesperonAI(creature);
    }
};

/*######
## Acolyte of Shadron
######*/

class npc_acolyte_of_shadron : public CreatureScript
{
public:
    npc_acolyte_of_shadron() : CreatureScript("npc_acolyte_of_shadron") { }

    struct npc_acolyte_of_shadronAI : public ScriptedAI
    {
        npc_acolyte_of_shadronAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() OVERRIDE
        {
            // Despawn the NPC automatically after 28 seconds
            me->DespawnOrUnsummon(28000);

            if (instance)
            {
                Creature* target = NULL;
                //if not solo figth, buff main boss, else place debuff on mini-boss. both spells TARGET_SCRIPT
                if (instance->GetBossState(DATA_SARTHARION) == IN_PROGRESS)
                {
                    if (target = Unit::GetCreature((*me), instance->GetData64(DATA_SARTHARION)))
                        target->AddAura(SPELL_GIFT_OF_TWILIGTH_SAR, target);
                }
                else
                {
                    if (target = Unit::GetCreature((*me), instance->GetData64(DATA_SHADRON)))
                        target->AddAura(SPELL_GIFT_OF_TWILIGTH_SHA, target);
                }
            }

            me->AddAura(SPELL_TWILIGHT_SHIFT_ENTER, me);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            if (instance)
            {
                if (Creature* shadron = instance->instance->GetCreature(instance->GetData64(DATA_SHADRON)))
                    instance->SetBossState(DATA_PORTAL_OPEN, NOT_STARTED);

                Map* map = me->GetMap();
                if (map->IsDungeon())
                {
                    Map::PlayerList const &PlayerList = map->GetPlayers();

                    if (PlayerList.isEmpty())
                        return;

                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if (i->GetSource()->IsAlive() && i->GetSource()->HasAura(SPELL_TWILIGHT_SHIFT, 0) && !i->GetSource()->GetVictim())
                        {
                            i->GetSource()->CastSpell(i->GetSource(), SPELL_TWILIGHT_SHIFT_REMOVAL_ALL, true);
                            i->GetSource()->CastSpell(i->GetSource(), SPELL_TWILIGHT_RESIDUE, true);
                            i->GetSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_SHIFT);
                            i->GetSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_SHIFT_ENTER);
                        }
                   }
                }

                //not solo fight, so main boss has deduff
                if (Creature* debuffTarget = instance->instance->GetCreature(instance->GetData64(DATA_SARTHARION)))
                    if (debuffTarget->IsAlive() && debuffTarget->HasAura(SPELL_GIFT_OF_TWILIGTH_SAR))
                        debuffTarget->RemoveAurasDueToSpell(SPELL_GIFT_OF_TWILIGTH_SAR);

                //event not in progress, then solo fight and must remove debuff mini-boss
                if (Creature* debuffTarget = instance->instance->GetCreature(instance->GetData64(DATA_SHADRON)))
                    if (debuffTarget->IsAlive() && debuffTarget->HasAura(SPELL_GIFT_OF_TWILIGTH_SHA))
                        debuffTarget->RemoveAurasDueToSpell(SPELL_GIFT_OF_TWILIGTH_SHA);
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_acolyte_of_shadronAI(creature);
    }
};

/*######
## Acolyte of Vesperon
######*/

class npc_acolyte_of_vesperon : public CreatureScript
{
public:
    npc_acolyte_of_vesperon() : CreatureScript("npc_acolyte_of_vesperon") { }

    struct npc_acolyte_of_vesperonAI : public ScriptedAI
    {
        npc_acolyte_of_vesperonAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        void Reset() OVERRIDE
        {
            // Despawn the NPC automatically after 28 seconds
            me->DespawnOrUnsummon(28000);

            if (instance)
                me->AddAura(SPELL_TWILIGHT_SHIFT_ENTER, me);

            DoCast(me, SPELL_TWILIGHT_TORMENT_VESP_ACO);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            me->RemoveAurasDueToSpell(SPELL_TWILIGHT_TORMENT_VESP_ACO);

            // remove twilight torment on Vesperon
            if (instance)
            {
                if (Creature* vesperon = instance->instance->GetCreature(instance->GetData64(DATA_VESPERON)))
                {
                    instance->SetBossState(DATA_PORTAL_OPEN, NOT_STARTED);

                if (vesperon->IsAlive() && vesperon->HasAura(SPELL_TWILIGHT_TORMENT_VESP))
                    vesperon->RemoveAurasDueToSpell(SPELL_TWILIGHT_TORMENT_VESP);
                }

                Map* map = me->GetMap();
                if (map->IsDungeon())
                {
                    Map::PlayerList const &PlayerList = map->GetPlayers();

                    if (PlayerList.isEmpty())
                        return;

                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if (i->GetSource()->IsAlive() && i->GetSource()->HasAura(SPELL_TWILIGHT_SHIFT, 0) && !i->GetSource()->GetVictim())
                        {
                            i->GetSource()->CastSpell(i->GetSource(), SPELL_TWILIGHT_SHIFT_REMOVAL_ALL, true);
                            i->GetSource()->CastSpell(i->GetSource(), SPELL_TWILIGHT_RESIDUE, true);
                            i->GetSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_SHIFT);
                            i->GetSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_SHIFT_ENTER);
                        }
                        if (i->GetSource()->IsAlive() && i->GetSource()->HasAura(SPELL_TWILIGHT_TORMENT_VESP, 0) && !i->GetSource()->GetVictim())
                            i->GetSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_TORMENT_VESP);
                    }
                }

                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_TORMENT_VESP_ACO);
                instance->DoRemoveAurasDueToSpellOnPlayers(57935);
                instance->DoRemoveAurasDueToSpellOnPlayers(58835); // Components of spell Twilight Torment
            }
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* instance;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_acolyte_of_vesperonAI(creature);
    }
};

/*######
## Twilight Eggs
######*/

enum TwilightEggs
{
    EVENT_TWILIGHT_EGGS           = 11
};

class npc_twilight_eggs : public CreatureScript
{
public:
    npc_twilight_eggs() : CreatureScript("npc_twilight_eggs") { }

    struct npc_twilight_eggsAI : public ScriptedAI
    {
        npc_twilight_eggsAI(Creature* creature) : ScriptedAI(creature)
        {
            SetCombatMovement(false);
            instance = creature->GetInstanceScript();
        }

        void Reset() OVERRIDE
        {
            if (instance)
                me->AddAura(SPELL_TWILIGHT_SHIFT_ENTER, me);

            events.ScheduleEvent(EVENT_TWILIGHT_EGGS, 20000);
        }

        void SpawnWhelps()
        {
            me->RemoveAllAuras();

            if (!instance->GetBossState(DATA_SARTHARION) == IN_PROGRESS)
                me->SummonCreature(NPC_TWILIGHT_WHELP, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000);
            else
                me->SummonCreature(NPC_SHARTHARION_TWILIGHT_WHELP, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60000);
            me->DealDamage(me, me->GetHealth());
        }

        void JustSummoned(Creature* who) OVERRIDE
        {
            who->SetInCombatWithZone();
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            events.Update(diff);

            if (events.ExecuteEvent() == EVENT_TWILIGHT_EGGS)
            {
                if (Creature* tenebron = instance->instance->GetCreature(instance->GetData64(DATA_TENEBRON)))
                    instance->SetBossState(DATA_PORTAL_OPEN, NOT_STARTED);

                SpawnWhelps();
            }
        }

    private:
        InstanceScript* instance;
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_twilight_eggsAI(creature);
    }
};

/*######
## Flame Tsunami
######*/

enum FlameTsunami
{
    EVENT_TSUNAMI_TIMER           = 12,
    EVENT_TSUNAMI_BUFF            = 13
};

class npc_flame_tsunami : public CreatureScript
{
public:
    npc_flame_tsunami() : CreatureScript("npc_flame_tsunami") { }

    struct npc_flame_tsunamiAI : public ScriptedAI
    {
        npc_flame_tsunamiAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisplayId(11686);
            me->AddAura(SPELL_FLAME_TSUNAMI, me);
        }

        void Reset() OVERRIDE
        {
            me->SetReactState(REACT_PASSIVE);
            events.ScheduleEvent(EVENT_TSUNAMI_TIMER, 100);
            events.ScheduleEvent(EVENT_TSUNAMI_BUFF, 1000);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TSUNAMI_TIMER:
                        DoCast(me, SPELL_FLAME_TSUNAMI_DMG_AURA);
                        events.ScheduleEvent(EVENT_TSUNAMI_TIMER, 500);
                        break;
                    case EVENT_TSUNAMI_BUFF:
                        if (Unit* lavaBlaze = GetClosestCreatureWithEntry(me, NPC_LAVA_BLAZE, 10.0f, true))
                            lavaBlaze->CastSpell(lavaBlaze, SPELL_FLAME_TSUNAMI_BUFF, true);
                        events.ScheduleEvent(EVENT_TSUNAMI_BUFF, 1000);
                        break;
                }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_flame_tsunamiAI(creature);
    }
};

/*######
## Twilight Fissure
######*/

enum TwilightFissure
{
    EVENT_VOID_BLAST              = 14
};

class npc_twilight_fissure : public CreatureScript
{
public:
    npc_twilight_fissure() : CreatureScript("npc_twilight_fissure") { }

    struct npc_twilight_fissureAI : public ScriptedAI
    {
        npc_twilight_fissureAI(Creature* creature) : ScriptedAI(creature)
        {
            SetCombatMovement(false);
        }

        void Reset() OVERRIDE
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->AddAura( 46265, me ); // Wrong, can't find proper visual
            me->AddAura( 69422, me );
            events.ScheduleEvent(EVENT_VOID_BLAST, 5000);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            events.Update(diff);

            if (events.ExecuteEvent() == EVENT_VOID_BLAST)
            {
                DoCastAOE(RAID_MODE(SPELL_VOID_BLAST, SPELL_VOID_BLAST_H));
                ////twilight realm
                //DoCastVictim(57620, true);
                //DoCastVictim(57874, true);
                me->RemoveAllAuras();
                me->Kill(me);
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_twilight_fissureAI(creature);
    }
};

/*######
## Twilight Whelps
######*/

enum TwilightWhelps
{
    EVENT_FADE_ARMOR              = 15
};

class npc_twilight_whelp : public CreatureScript
{
public:
    npc_twilight_whelp() : CreatureScript("npc_twilight_whelp") { }

    struct npc_twilight_whelpAI : public ScriptedAI
    {
        npc_twilight_whelpAI(Creature* creature) : ScriptedAI(creature)
        {
            Reset();
        }

        void Reset() OVERRIDE
        {
            me->RemoveAllAuras();
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_FADE_ARMOR, 1000);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            // twilight torment
            events.Update(diff);

            if (events.ExecuteEvent() == EVENT_FADE_ARMOR)
            {
                DoCastVictim(SPELL_FADE_ARMOR);
                events.ScheduleEvent(EVENT_FADE_ARMOR, urand(5000, 10000));
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_twilight_whelpAI(creature);
    }
};

class achievement_twilight_assist : public AchievementCriteriaScript
{
    public:
        achievement_twilight_assist() : AchievementCriteriaScript("achievement_twilight_assist") { }

        bool OnCheck(Player* /*player*/, Unit* target) OVERRIDE
        {
            if (!target)
                return false;

            if (Creature* sartharion = target->ToCreature())
                if (sartharion->AI()->GetData(TWILIGHT_ACHIEVEMENTS) >= 1)
                    return true;

            return false;
        }
};

class achievement_twilight_duo : public AchievementCriteriaScript
{
    public:
        achievement_twilight_duo() : AchievementCriteriaScript("achievement_twilight_duo") { }

        bool OnCheck(Player* /*player*/, Unit* target) OVERRIDE
        {
            if (!target)
                return false;

            if (Creature* sartharion = target->ToCreature())
                if (sartharion->AI()->GetData(TWILIGHT_ACHIEVEMENTS) >= 2)
                    return true;

            return false;
        }
};

class achievement_twilight_zone : public AchievementCriteriaScript
{
    public:
        achievement_twilight_zone() : AchievementCriteriaScript("achievement_twilight_zone") { }

        bool OnCheck(Player* /*player*/, Unit* target) OVERRIDE
        {
            if (!target)
                return false;

            if (Creature* sartharion = target->ToCreature())
                if (sartharion->AI()->GetData(TWILIGHT_ACHIEVEMENTS) == 3)
                    return true;

            return false;
        }
};

void AddSC_obsidian_sanctum()
{
    new npc_vesperon();
    new npc_shadron();
    new npc_tenebron();
    new npc_acolyte_of_shadron();
    new npc_acolyte_of_vesperon();
    new npc_twilight_eggs();
    new npc_flame_tsunami();
    new npc_twilight_fissure();
    new npc_twilight_whelp();
    new achievement_twilight_assist();
    new achievement_twilight_duo();
    new achievement_twilight_zone();
}


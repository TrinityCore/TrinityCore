/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "obsidian_sanctum.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

enum Enums
{
    //Mini bosses common spells
    SPELL_TWILIGHT_RESIDUE                      = 61885,    // makes immune to shadow damage, applied when leave phase

    //Miniboses (Vesperon, Shadron, Tenebron)
    SPELL_SHADOW_BREATH                         = 57570,    // Inflicts 6938 to 8062 Fire damage to enemies in a cone in front of the caster.
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
    NPC_SARTHARION_TWILIGHT_WHELP              = 31214,
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

#define MAX_WAYPOINT 6
//points around raid "isle", counter clockwise. should probably be adjusted to be more alike
Position const dragonCommon[MAX_WAYPOINT]=
{
    { 3214.012f, 468.932f, 98.652f, 0.0f },
    { 3244.950f, 468.427f, 98.652f, 0.0f },
    { 3283.520f, 496.869f, 98.652f, 0.0f },
    { 3287.316f, 555.875f, 98.652f, 0.0f },
    { 3250.479f, 585.827f, 98.652f, 0.0f },
    { 3209.969f, 566.523f, 98.652f, 0.0f }
};

Position const AcolyteofShadron   = { 3363.92f, 534.703f, 97.2683f, 0.0f };
Position const AcolyteofShadron2  = { 3246.57f, 551.263f, 58.6164f, 0.0f };
Position const AcolyteofVesperon  = { 3145.68f, 520.71f,  89.7f,    0.0f };
Position const AcolyteofVesperon2 = { 3246.57f, 551.263f, 58.6164f, 0.0f };

Position const TwilightEggs[] =
{
    { 3219.28f, 669.121f, 88.5549f, 0.0f },
    { 3221.55f, 682.852f, 90.5361f, 0.0f },
    { 3239.77f, 685.94f,  90.3168f, 0.0f },
    { 3250.33f, 669.749f, 88.7637f, 0.0f },
    { 3246.6f,  642.365f, 84.8752f, 0.0f },
    { 3233.68f, 653.117f, 85.7051f, 0.0f }
};

Position const TwilightEggsSarth[] =
{
    { 3252.73f, 515.762f, 58.5501f, 0.0f },
    { 3256.56f, 521.119f, 58.6061f, 0.0f },
    { 3255.63f, 527.513f, 58.7568f, 0.0f },
    { 3264.90f, 525.865f, 58.6436f, 0.0f },
    { 3264.26f, 516.364f, 58.8011f, 0.0f },
    { 3257.54f, 502.285f, 58.2077f, 0.0f }
};

enum SharedTextIds
{
    SAY_AGGRO                      = 0,
    SAY_SLAY                       = 1,
    SAY_DEATH                      = 2,
    SAY_BREATH                     = 3,
    SAY_RESPOND                    = 4,
    SAY_SPECIAL                    = 5,
    WHISPER_OPEN_PORTAL            = 6,
    WHISPER_OPENED_PORTAL          = 7
};

enum DragonEvents
{
    // Shared Events
    EVENT_FREE_MOVEMENT            = 1,
    EVENT_SHADOW_FISSURE           = 2,
    EVENT_SHADOW_BREATH            = 3,

    // Tenebron
    EVENT_HATCH_EGGS               = 4,

    // Shadron
    EVENT_ACOLYTE_SHADRON          = 5,

    // Vesperon
    EVENT_ACOLYTE_VESPERON         = 6
};

// to control each dragons common abilities
struct dummy_dragonAI : public ScriptedAI
{
    dummy_dragonAI(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
        instance = creature->GetInstanceScript();
    }

    void Initialize()
    {
        waypointId = 0;
        portalRespawnTime = 30000;
        _canMoveFree = false;
        _canLoot = true;
    }

    void Reset() override
    {
        if (me->HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE))
            me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);

        events.Reset();
        Initialize();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_AGGRO);
        DoZoneInCombat();

        events.ScheduleEvent(EVENT_SHADOW_FISSURE, 5s);
        events.ScheduleEvent(EVENT_SHADOW_BREATH, 20s);
    }

    void SetData(uint32 type, uint32 value) override
    {
        if (type == DATA_CAN_LOOT)
            _canLoot = value != 0;
    }

    void MovementInform(uint32 type, uint32 pointId) override
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
            DoZoneInCombat();
            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0, true))
            {
                AddThreat(target, 1.0f);
                me->Attack(target, true);
                me->GetMotionMaster()->MoveChase(target);
            }

            _canMoveFree = false;
            return;
        }

        // increase
        waypointId = pointId + 1;

        // if we have reached a point bigger or equal to count, it mean we must reset to point 0
        if (waypointId >= MAX_WAYPOINT)
        {
            if (!_canMoveFree)
                _canMoveFree = true;

            waypointId = 0;
        }

        events.ScheduleEvent(EVENT_FREE_MOVEMENT, 500ms);
    }

    // "opens" the portal and does the "opening" whisper
    void OpenPortal()
    {
        // there are 4 portal spawn locations, each are expected to be spawned with negative spawntimesecs in database

        // using a grid search here seem to be more efficient than caching all four guids
        // in instance script and calculate range to each.
        GameObject* portal = me->FindNearestGameObject(GO_TWILIGHT_PORTAL, 50.0f, false);

        switch (me->GetEntry())
        {
            case NPC_TENEBRON:
            {
                if (instance->GetBossState(DATA_SARTHARION) != IN_PROGRESS)
                {
                    for (uint32 i = 0; i < 6; ++i)
                        me->SummonCreature(NPC_TWILIGHT_EGG, TwilightEggs[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20s);
                }
                else
                {
                    for (uint32 i = 0; i < 6; ++i)
                        me->SummonCreature(NPC_SARTHARION_TWILIGHT_EGG, TwilightEggsSarth[i], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20s);
                }
                break;
            }
            case NPC_SHADRON:
            {
                if (instance->GetBossState(DATA_SARTHARION) != IN_PROGRESS)
                    me->SummonCreature(NPC_ACOLYTE_OF_SHADRON, AcolyteofShadron, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 28s);
                else
                    me->SummonCreature(NPC_ACOLYTE_OF_SHADRON, AcolyteofShadron2, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 28s);

                break;
            }
            case NPC_VESPERON:
            {
                if (instance->GetBossState(DATA_SARTHARION) != IN_PROGRESS)
                {
                    if (Creature* acolyte = me->SummonCreature(NPC_ACOLYTE_OF_VESPERON, AcolyteofVesperon, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20s))
                    {
                        me->InterruptNonMeleeSpells(true);
                        acolyte->InterruptNonMeleeSpells(true);
                        me->CastSpell(me, 32747, false);
                    }
                }
                else
                {
                    if (Creature* acolyte = me->SummonCreature(NPC_ACOLYTE_OF_VESPERON, AcolyteofVesperon2, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 20s))
                    {
                        me->InterruptNonMeleeSpells(true);
                        acolyte->InterruptNonMeleeSpells(true);
                        me->CastSpell(me, 32747, false);
                    }
                }

                break;
            }
        }

        Talk(WHISPER_OPEN_PORTAL);
        Talk(WHISPER_OPENED_PORTAL);

        // By using SetRespawnTime() we will actually "spawn" the object with our defined time.
        // Once time is up, portal will disappear again.
        if (portal && !portal->isSpawned())
            portal->SetRespawnTime(portalRespawnTime);

        // Unclear what are expected to happen if one drake has a portal open already
        // Refresh respawnTime so time again are set to 30secs?
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (!_canLoot)
            me->SetLootRecipient(nullptr);

        uint32 spellId = 0;

        switch (me->GetEntry())
        {
            case NPC_TENEBRON:
                spellId = SPELL_POWER_OF_TENEBRON;
                if (instance->GetBossState(DATA_SARTHARION) != IN_PROGRESS)
                    instance->SetBossState(DATA_TENEBRON, DONE);
                break;
            case NPC_SHADRON:
                spellId = SPELL_POWER_OF_SHADRON;
                if (instance->GetBossState(DATA_SARTHARION) != IN_PROGRESS)
                    instance->SetBossState(DATA_SHADRON, DONE);
                if (Creature* acolyte = me->FindNearestCreature(NPC_ACOLYTE_OF_SHADRON, 100.0f))
                    acolyte->KillSelf();
                break;
            case NPC_VESPERON:
                spellId = SPELL_POWER_OF_VESPERON;
                if (instance->GetBossState(DATA_SARTHARION) != IN_PROGRESS)
                    instance->SetBossState(DATA_VESPERON, DONE);
                if (Creature* acolyte = me->FindNearestCreature(NPC_ACOLYTE_OF_VESPERON, 100.0f))
                    acolyte->KillSelf();
                break;
        }

        Talk(SAY_DEATH);
        me->RemoveAurasDueToSpell(spellId);

        instance->DoRemoveAurasDueToSpellOnPlayers(spellId);

        // not if solo mini-boss fight
        if (instance->GetBossState(DATA_SARTHARION) != IN_PROGRESS)
            return;

        // Twilight Revenge to main boss
        if (Unit* sartharion = ObjectAccessor::GetUnit(*me, instance->GetGuidData(DATA_SARTHARION)))
            if (sartharion->IsAlive())
            {
                sartharion->RemoveAurasDueToSpell(spellId);
                DoCast(sartharion, SPELL_TWILIGHT_REVENGE, true);
            }
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (events.ExecuteEvent() == EVENT_FREE_MOVEMENT)
        {
            if (_canMoveFree && waypointId < MAX_WAYPOINT)
                me->GetMotionMaster()->MovePoint(waypointId, dragonCommon[waypointId]);
        }
    }

    void ExecuteEvent(uint32 eventId)
    {
        switch (eventId)
        {
            case EVENT_SHADOW_FISSURE:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                    DoCast(target, SPELL_SHADOW_FISSURE);
                events.ScheduleEvent(eventId, 15s, 20s);
                break;
            case EVENT_SHADOW_BREATH:
                Talk(SAY_BREATH);
                DoCastVictim(SPELL_SHADOW_BREATH);
                events.ScheduleEvent(eventId, 20s, 25s);
                break;
            default:
                break;
        }
    }

    protected:
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

struct npc_tenebron : public dummy_dragonAI
{
    npc_tenebron(Creature* creature) : dummy_dragonAI(creature) { }

    void Reset() override
    {
        dummy_dragonAI::Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        dummy_dragonAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_HATCH_EGGS, 30s);
    }

    void UpdateAI(uint32 diff) override
    {
        // if no target, update dummy and return
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
                case EVENT_HATCH_EGGS:
                    OpenPortal();
                    events.ScheduleEvent(EVENT_HATCH_EGGS, 30s);
                    break;
                default:
                    dummy_dragonAI::ExecuteEvent(eventId);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

/*######
## Shadron
######*/

struct npc_shadron : public dummy_dragonAI
{
    npc_shadron(Creature* creature) : dummy_dragonAI(creature) { }

    void Reset() override
    {
        dummy_dragonAI::Reset();

        if (me->HasAura(SPELL_TWILIGHT_TORMENT_VESP))
            me->RemoveAurasDueToSpell(SPELL_TWILIGHT_TORMENT_VESP);

        if (me->HasAura(SPELL_GIFT_OF_TWILIGTH_SHA))
            me->RemoveAurasDueToSpell(SPELL_GIFT_OF_TWILIGTH_SHA);

        instance->SetBossState(DATA_PORTAL_OPEN, NOT_STARTED);
    }

    void JustEngagedWith(Unit* who) override
    {
        dummy_dragonAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_ACOLYTE_SHADRON, 1min);
    }

    void UpdateAI(uint32 diff) override
    {
        // if no target, update dummy and return
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
                case EVENT_ACOLYTE_SHADRON:
                    if (instance->GetBossState(DATA_PORTAL_OPEN) == NOT_STARTED)
                        events.ScheduleEvent(EVENT_ACOLYTE_SHADRON, 10s);
                    else
                    {
                        if (me->HasAura(SPELL_GIFT_OF_TWILIGTH_SHA))
                            return;

                        OpenPortal();

                        instance->SetBossState(DATA_PORTAL_OPEN, IN_PROGRESS);

                        events.ScheduleEvent(EVENT_ACOLYTE_SHADRON, 60s, 65s);
                    }
                    break;
                default:
                    dummy_dragonAI::ExecuteEvent(eventId);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

/*######
## Vesperon
######*/

struct npc_vesperon : public dummy_dragonAI
{
    npc_vesperon(Creature* creature) : dummy_dragonAI(creature) { }

    void Reset() override
    {
        dummy_dragonAI::Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        dummy_dragonAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_ACOLYTE_VESPERON, 1min);
    }

    void UpdateAI(uint32 diff) override
    {
        // if no target, update dummy and return
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
                case EVENT_ACOLYTE_VESPERON:
                    if (instance->GetBossState(DATA_PORTAL_OPEN) == IN_PROGRESS)
                        events.ScheduleEvent(EVENT_ACOLYTE_VESPERON, 10s);
                    else
                    {
                        OpenPortal();
                        DoCastVictim(SPELL_TWILIGHT_TORMENT_VESP);
                        events.ScheduleEvent(EVENT_ACOLYTE_VESPERON, 60s, 70s);
                    }
                    break;
                default:
                    dummy_dragonAI::ExecuteEvent(eventId);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

/*######
## Acolyte of Shadron
######*/

struct npc_acolyte_of_shadron : public ScriptedAI
{
    npc_acolyte_of_shadron(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
    }

    void Reset() override
    {
        // Despawn the NPC automatically after 28 seconds
        me->DespawnOrUnsummon(28s);

        //if not solo fight, buff main boss, else place debuff on mini-boss. both spells TARGET_SCRIPT
        if (instance->GetBossState(DATA_SARTHARION) == IN_PROGRESS)
        {
            if (Creature* sartharion = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SARTHARION)))
                sartharion->AddAura(SPELL_GIFT_OF_TWILIGTH_SAR, sartharion);
        }
        else
        {
            if (Creature* shadron = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SHADRON)))
                shadron->AddAura(SPELL_GIFT_OF_TWILIGTH_SHA, shadron);
        }

        me->AddAura(SPELL_TWILIGHT_SHIFT_ENTER, me);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SHADRON)))
            instance->SetBossState(DATA_PORTAL_OPEN, NOT_STARTED);

        Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();

        if (PlayerList.isEmpty())
            return;

        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
        {
            if (i->GetSource()->IsAlive() && i->GetSource()->HasAura(SPELL_TWILIGHT_SHIFT) && !i->GetSource()->GetVictim())
            {
                i->GetSource()->CastSpell(i->GetSource(), SPELL_TWILIGHT_SHIFT_REMOVAL_ALL, true);
                i->GetSource()->CastSpell(i->GetSource(), SPELL_TWILIGHT_RESIDUE, true);
                i->GetSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_SHIFT);
                i->GetSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_SHIFT_ENTER);
            }
        }

        // not solo fight, so main boss has debuff
        if (Creature* debuffTarget = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SARTHARION)))
            if (debuffTarget->IsAlive() && debuffTarget->HasAura(SPELL_GIFT_OF_TWILIGTH_SAR))
                debuffTarget->RemoveAurasDueToSpell(SPELL_GIFT_OF_TWILIGTH_SAR);

        // event not in progress, then solo fight and must remove debuff mini-boss
        if (Creature* debuffTarget = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SHADRON)))
            if (debuffTarget->IsAlive() && debuffTarget->HasAura(SPELL_GIFT_OF_TWILIGTH_SHA))
                debuffTarget->RemoveAurasDueToSpell(SPELL_GIFT_OF_TWILIGTH_SHA);
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    InstanceScript* instance;
};

/*######
## Acolyte of Vesperon
######*/

struct npc_acolyte_of_vesperon : public ScriptedAI
{
    npc_acolyte_of_vesperon(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
    }

    void Reset() override
    {
        // Despawn the NPC automatically after 28 seconds
        me->DespawnOrUnsummon(28s);

        me->AddAura(SPELL_TWILIGHT_SHIFT_ENTER, me);

        DoCast(me, SPELL_TWILIGHT_TORMENT_VESP_ACO);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->RemoveAurasDueToSpell(SPELL_TWILIGHT_TORMENT_VESP_ACO);

        // remove twilight torment on Vesperon
        if (Creature* vesperon = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_VESPERON)))
        {
            instance->SetBossState(DATA_PORTAL_OPEN, NOT_STARTED);

            if (vesperon->IsAlive() && vesperon->HasAura(SPELL_TWILIGHT_TORMENT_VESP))
                vesperon->RemoveAurasDueToSpell(SPELL_TWILIGHT_TORMENT_VESP);
        }

        Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();

        if (PlayerList.isEmpty())
            return;

        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
        {
            if (i->GetSource()->IsAlive() && i->GetSource()->HasAura(SPELL_TWILIGHT_SHIFT) && !i->GetSource()->GetVictim())
            {
                i->GetSource()->CastSpell(i->GetSource(), SPELL_TWILIGHT_SHIFT_REMOVAL_ALL, true);
                i->GetSource()->CastSpell(i->GetSource(), SPELL_TWILIGHT_RESIDUE, true);
                i->GetSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_SHIFT);
                i->GetSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_SHIFT_ENTER);
            }
            if (i->GetSource()->IsAlive() && i->GetSource()->HasAura(SPELL_TWILIGHT_TORMENT_VESP) && !i->GetSource()->GetVictim())
                i->GetSource()->RemoveAurasDueToSpell(SPELL_TWILIGHT_TORMENT_VESP);
        }

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_TORMENT_VESP_ACO, true, true);
        instance->DoRemoveAurasDueToSpellOnPlayers(57935, true, true);
        instance->DoRemoveAurasDueToSpellOnPlayers(58835, true, true); // Components of spell Twilight Torment
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    InstanceScript* instance;
};

/*######
## Twilight Eggs
######*/

enum TwilightEggs
{
    EVENT_TWILIGHT_EGGS           = 11
};

struct npc_twilight_eggs : public ScriptedAI
{
    npc_twilight_eggs(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
        instance = creature->GetInstanceScript();
    }

    void Reset() override
    {
        me->AddAura(SPELL_TWILIGHT_SHIFT_ENTER, me);

        events.ScheduleEvent(EVENT_TWILIGHT_EGGS, 20s);
    }

    void SpawnWhelps()
    {
        me->RemoveAllAuras();

        if (instance->GetBossState(DATA_SARTHARION) != IN_PROGRESS)
            me->SummonCreature(NPC_TWILIGHT_WHELP, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 1min);
        else
            me->SummonCreature(NPC_SARTHARION_TWILIGHT_WHELP, 0.0f, 0.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 1min);
        me->KillSelf();
    }

    void JustSummoned(Creature* who) override
    {
        DoZoneInCombat(who);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (events.ExecuteEvent() == EVENT_TWILIGHT_EGGS)
        {
            if (ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_TENEBRON)))
                instance->SetBossState(DATA_PORTAL_OPEN, NOT_STARTED);

            SpawnWhelps();
        }
    }

private:
    InstanceScript* instance;
    EventMap events;
};

/*######
## Flame Tsunami
######*/

enum FlameTsunami
{
    EVENT_TSUNAMI_TIMER           = 12,
    EVENT_TSUNAMI_BUFF            = 13
};

struct npc_flame_tsunami : public ScriptedAI
{
    npc_flame_tsunami(Creature* creature) : ScriptedAI(creature)
    {
        me->SetDisplayId(11686);
        me->AddAura(SPELL_FLAME_TSUNAMI, me);
    }

    void Reset() override
    {
        me->SetReactState(REACT_PASSIVE);
        events.ScheduleEvent(EVENT_TSUNAMI_TIMER, 100ms);
        events.ScheduleEvent(EVENT_TSUNAMI_BUFF, 1s);
        me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TSUNAMI_TIMER:
                    DoCast(me, SPELL_FLAME_TSUNAMI_DMG_AURA);
                    events.ScheduleEvent(EVENT_TSUNAMI_TIMER, 500ms);
                    break;
                case EVENT_TSUNAMI_BUFF:
                    if (Unit* lavaBlaze = GetClosestCreatureWithEntry(me, NPC_LAVA_BLAZE, 10.0f, true))
                        lavaBlaze->CastSpell(lavaBlaze, SPELL_FLAME_TSUNAMI_BUFF, true);
                    events.ScheduleEvent(EVENT_TSUNAMI_BUFF, 1s);
                    break;
            }
        }
    }

private:
    EventMap events;
};

/*######
## Twilight Fissure
######*/

enum TwilightFissure
{
    EVENT_VOID_BLAST              = 14
};

struct npc_twilight_fissure : public ScriptedAI
{
    npc_twilight_fissure(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
    }

    void Reset() override
    {
        me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_UNINTERACTIBLE);
        me->AddAura(46265, me); // Wrong, can't find proper visual
        me->AddAura(69422, me);
        events.ScheduleEvent(EVENT_VOID_BLAST, 5s);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (events.ExecuteEvent() == EVENT_VOID_BLAST)
        {
            DoCastAOE(SPELL_VOID_BLAST);
            ////twilight realm
            //DoCastVictim(57620, true);
            //DoCastVictim(57874, true);
            me->RemoveAllAuras();
            me->KillSelf();
        }
    }

private:
    EventMap events;
};

/*######
## Twilight Whelps
######*/

enum TwilightWhelps
{
    EVENT_FADE_ARMOR              = 15
};

struct npc_twilight_whelp : public ScriptedAI
{
    npc_twilight_whelp(Creature* creature) : ScriptedAI(creature)
    {
    }

    void Reset() override
    {
        me->RemoveAllAuras();
        DoZoneInCombat();
        events.ScheduleEvent(EVENT_FADE_ARMOR, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        // twilight torment
        events.Update(diff);

        if (events.ExecuteEvent() == EVENT_FADE_ARMOR)
        {
            DoCastVictim(SPELL_FADE_ARMOR);
            events.ScheduleEvent(EVENT_FADE_ARMOR, 5s, 10s);
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap events;
};

class achievement_twilight_assist : public AchievementCriteriaScript
{
    public:
        achievement_twilight_assist() : AchievementCriteriaScript("achievement_twilight_assist") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            return target && target->GetAI()->GetData(TWILIGHT_ACHIEVEMENTS) >= 1;
        }
};

class achievement_twilight_duo : public AchievementCriteriaScript
{
    public:
        achievement_twilight_duo() : AchievementCriteriaScript("achievement_twilight_duo") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            return target && target->GetAI()->GetData(TWILIGHT_ACHIEVEMENTS) >= 2;
        }
};

class achievement_twilight_zone : public AchievementCriteriaScript
{
    public:
        achievement_twilight_zone() : AchievementCriteriaScript("achievement_twilight_zone") { }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            return target && target->GetAI()->GetData(TWILIGHT_ACHIEVEMENTS) == 3;
        }
};

void AddSC_obsidian_sanctum()
{
    RegisterObsidianSanctumCreatureAI(npc_vesperon);
    RegisterObsidianSanctumCreatureAI(npc_shadron);
    RegisterObsidianSanctumCreatureAI(npc_tenebron);
    RegisterObsidianSanctumCreatureAI(npc_acolyte_of_shadron);
    RegisterObsidianSanctumCreatureAI(npc_acolyte_of_vesperon);
    RegisterObsidianSanctumCreatureAI(npc_twilight_eggs);
    RegisterObsidianSanctumCreatureAI(npc_flame_tsunami);
    RegisterObsidianSanctumCreatureAI(npc_twilight_fissure);
    RegisterObsidianSanctumCreatureAI(npc_twilight_whelp);
    new achievement_twilight_assist();
    new achievement_twilight_duo();
    new achievement_twilight_zone();
}

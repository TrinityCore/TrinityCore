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
#include "blackrock_caverns.h"
#include "AreaTrigger.h"
#include "GossipDef.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "InstanceScript.h"

/*#####
# npc_fire_cyclone
#####*/

enum FireCyclone
{
    SPELL_FIRE_CYCLONE_AURA     = 74851,
    EVENT_FIRE_CYCLONE_AURA     = 1
};

struct npc_fire_cyclone : public ScriptedAI
{
    npc_fire_cyclone(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_FIRE_CYCLONE_AURA, 100);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_FIRE_CYCLONE_AURA:
                    DoCast(me, SPELL_FIRE_CYCLONE_AURA, true);
                    _events.ScheduleEvent(EVENT_FIRE_CYCLONE_AURA, 4000);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap        _events;
    InstanceScript* _instance;
};


/*#####
# npc_twilight_flame_caller
#####*/

enum TwilightFlameCaller
{
    SPELL_FIRE_CHANNELING_1 = 74911,
    SPELL_FIRE_CHANNELING_2 = 74912,
    SPELL_BLAST_WAVE        = 76473,
    SPELL_CALL_FLAMES       = 76325,
    NPC_FIRE_CYCLONE        = 40164,
    EVENT_CHANNEL           = 1,
    EVENT_BLAST_WAVE,
    EVENT_CALL_FLAMES
};

Position const SummonPos[6] =
{
    { 162.5990f, 1085.321f, 201.1190f, 0.0f },
    { 170.5469f, 1063.403f, 201.1409f, 0.0f },
    { 191.2326f, 1100.160f, 201.1071f, 0.0f },
    { 228.0816f, 1106.000f, 201.1292f, 0.0f },
    { 252.8351f, 1095.127f, 201.1436f, 0.0f },
    { 253.6476f, 1070.226f, 201.1344f, 0.0f }
};

struct npc_twilight_flame_caller : public ScriptedAI
{
    npc_twilight_flame_caller(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _summons(me)
    {
        Initialize();
    }

    void Initialize()
    {
        _combatPhase = false;
    }

    void Reset() override
    {
        Initialize();
        _flamecaller1GUID.Clear();
        _flamecaller2GUID.Clear();

        if (me->GetPositionX() > 172 && me->GetPositionX() < 173 && me->GetPositionY() > 1086 && me->GetPositionY() < 1087)
        {
            _flamecaller1GUID = me->GetGUID();
            me->SummonCreature(NPC_FIRE_CYCLONE, SummonPos[0], TEMPSUMMON_CORPSE_DESPAWN, 0);
            me->SummonCreature(NPC_FIRE_CYCLONE, SummonPos[1], TEMPSUMMON_CORPSE_DESPAWN, 0);
            me->SummonCreature(NPC_FIRE_CYCLONE, SummonPos[2], TEMPSUMMON_CORPSE_DESPAWN, 0);
        }
        if (me->GetPositionX() > 247 && me->GetPositionX() < 248 && me->GetPositionY() > 1081 && me->GetPositionY() < 1082)
        {
            _flamecaller2GUID = me->GetGUID();
            me->SummonCreature(NPC_FIRE_CYCLONE, SummonPos[3], TEMPSUMMON_CORPSE_DESPAWN, 0);
            me->SummonCreature(NPC_FIRE_CYCLONE, SummonPos[4], TEMPSUMMON_CORPSE_DESPAWN, 0);
            me->SummonCreature(NPC_FIRE_CYCLONE, SummonPos[5], TEMPSUMMON_CORPSE_DESPAWN, 0);
        }

        _events.ScheduleEvent(EVENT_CHANNEL, 100);
    }

    void JustSummoned(Creature* summoned) override
    {
        _summons.Summon(summoned);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _summons.DespawnAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.Reset();
        _combatPhase = true;
        _events.ScheduleEvent(EVENT_BLAST_WAVE, urand(8000, 10000));
        _events.ScheduleEvent(EVENT_CALL_FLAMES, urand(10000, 14000));
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (!_combatPhase)
        {
            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CHANNEL:
                        if (me->GetGUID() == _flamecaller1GUID)
                            DoCast(me, SPELL_FIRE_CHANNELING_1);
                        if (me->GetGUID() == _flamecaller2GUID)
                            DoCast(me, SPELL_FIRE_CHANNELING_2);
                        _events.ScheduleEvent(EVENT_CHANNEL, 12000);
                        break;
                    default:
                        break;
                }
            }
            return;
        }

        if (!UpdateVictim())
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BLAST_WAVE:
                    DoCast(me, SPELL_BLAST_WAVE);
                    _events.ScheduleEvent(EVENT_BLAST_WAVE, 16000, 20000);
                    break;
                case EVENT_CALL_FLAMES:
                    DoCast(me, SPELL_CALL_FLAMES);
                    _events.ScheduleEvent(EVENT_CALL_FLAMES, 12000, 15000);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    ObjectGuid _flamecaller1GUID;
    ObjectGuid _flamecaller2GUID;
    SummonList _summons;
    bool _combatPhase;
};

/*#####
# npc_twilight_torturer
#####*/

enum TwilightTorturer
{
    SPELL_INFLICT_PAIN      = 75590,
    SPELL_RED_HOT_POKER     = 76478,
    SPELL_SHACKLES          = 76484,
    SPELL_WILD_BEATDOWN     = 76487,
    EVENT_INFLICT_PAIN_TT   = 1,
    EVENT_RED_HOT_POKER,
    EVENT_SHACKLES,
    EVENT_WILD_BEATDOWN
};

struct npc_twilight_torturer : public ScriptedAI
{
    npc_twilight_torturer(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
    {
        Initialize();
    }

    void Initialize()
    {
        _combatPhase = false;
    }

    void Reset() override
    {
        Initialize();
        if (!me->GetWaypointPath())
            _events.ScheduleEvent(EVENT_INFLICT_PAIN_TT, urand(6000, 18000));
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.Reset();
        _combatPhase = true;
        _events.ScheduleEvent(EVENT_RED_HOT_POKER, 9000);
        _events.ScheduleEvent(EVENT_SHACKLES, 13000);
        _events.ScheduleEvent(EVENT_WILD_BEATDOWN, 17000);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (!_combatPhase)
        {
            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_INFLICT_PAIN_TT:
                        DoCast(me, SPELL_INFLICT_PAIN);
                        _events.ScheduleEvent(EVENT_INFLICT_PAIN_TT, urand(25000, 32000));
                        break;
                    default:
                        break;
                }
            }
            return;
        }

        if (!UpdateVictim())
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_RED_HOT_POKER:
                    DoCast(me, SPELL_RED_HOT_POKER);
                    _events.ScheduleEvent(EVENT_RED_HOT_POKER, 16000, 20000);
                    break;
                case EVENT_SHACKLES:
                    DoCast(me, SPELL_SHACKLES);
                    _events.ScheduleEvent(EVENT_SHACKLES, 12000, 15000);
                    break;
                case EVENT_WILD_BEATDOWN:
                    DoCast(me, SPELL_WILD_BEATDOWN);
                    _events.ScheduleEvent(EVENT_WILD_BEATDOWN, 12000, 15000);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    bool _combatPhase;
};

/*#####
# npc_twilight_sadist
#####*/

enum TwilightSadist
{
    SPELL_INFLICT_PAIN_1    = 76497,
    SPELL_HEAT_SEEKER_BLADE = 76502,
    SPELL_SHORT_THROW       = 76572,
    SPELL_SINISTER_STRIKE   = 76500,
    EVENT_INFLICT_PAIN_TS   = 1,
    EVENT_HEAT_SEEKER_BLADE,
    EVENT_SHORT_THROW,
    EVENT_SINISTER_STRIKE
};

struct npc_twilight_sadist : public ScriptedAI
{
    npc_twilight_sadist(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _combatPhase = false;
        if (!me->GetWaypointPath())
            _events.ScheduleEvent(EVENT_INFLICT_PAIN_TS, urand(6000, 18000));
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.Reset();
        _combatPhase = true;
        _events.ScheduleEvent(EVENT_INFLICT_PAIN_TS, 9000);
        _events.ScheduleEvent(EVENT_HEAT_SEEKER_BLADE, 13000);
        _events.ScheduleEvent(EVENT_SHORT_THROW, 17000);
        _events.ScheduleEvent(EVENT_SINISTER_STRIKE, 17000);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (!_combatPhase)
        {
            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_INFLICT_PAIN_TS:
                        DoCast(me, SPELL_INFLICT_PAIN);
                        _events.ScheduleEvent(EVENT_INFLICT_PAIN_TS, urand(25000, 32000));
                        break;
                    default:
                        break;
                }
            }
            return;
        }

        if (!UpdateVictim())
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_RED_HOT_POKER:
                    DoCast(me, SPELL_RED_HOT_POKER);
                    _events.ScheduleEvent(EVENT_RED_HOT_POKER, 16000, 20000);
                    break;
                case EVENT_SHACKLES:
                    DoCast(me, SPELL_SHACKLES);
                    _events.ScheduleEvent(EVENT_SHACKLES, 12000, 15000);
                    break;
                case EVENT_WILD_BEATDOWN:
                    DoCast(me, SPELL_WILD_BEATDOWN);
                    _events.ScheduleEvent(EVENT_WILD_BEATDOWN, 12000, 15000);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    bool _combatPhase;
};

/*#####
# npc_mad_prisoner
#####*/

enum MadPrisoner
{
    SPELL_HEAD_CRACK        = 77568,
    SPELL_INFECTED_WOUND    = 76512,
    SPELL_ENRAGE            = 8599,
    EVENT_HEAD_CRACK        = 1,
    EVENT_INFECTED_WOUND,
    EVENT_ENRAGE
};

struct npc_mad_prisoner : public ScriptedAI
{
    npc_mad_prisoner(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_HEAD_CRACK, 9000);
        _events.ScheduleEvent(EVENT_INFECTED_WOUND, 13000);
        _events.ScheduleEvent(EVENT_ENRAGE, 17000);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HEAD_CRACK:
                    DoCast(me, SPELL_HEAD_CRACK);
                    _events.ScheduleEvent(EVENT_HEAD_CRACK, 16000, 20000);
                    break;
                case EVENT_INFECTED_WOUND:
                    DoCast(me, SPELL_INFECTED_WOUND);
                    _events.ScheduleEvent(EVENT_INFECTED_WOUND, 12000, 15000);
                    break;
                case EVENT_ENRAGE:
                    DoCast(me, SPELL_ENRAGE);
                    _events.ScheduleEvent(EVENT_ENRAGE, 12000, 15000);
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

/*#####
# npc_crazed_mage
#####*/

enum CrazedMage
{
    EVENT_HEAD_CRACK2 = 1,
    EVENT_INFECTED_WOUND2,
    EVENT_ENRAGE2
};

struct npc_crazed_mage : public ScriptedAI
{
    npc_crazed_mage(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_HEAD_CRACK2, 9000);
        _events.ScheduleEvent(EVENT_INFECTED_WOUND2, 13000);
        _events.ScheduleEvent(EVENT_ENRAGE2, 17000);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HEAD_CRACK2:
                    DoCast(me, SPELL_HEAD_CRACK);
                    _events.ScheduleEvent(EVENT_HEAD_CRACK2, 16000, 20000);
                    break;
                case EVENT_INFECTED_WOUND2:
                    DoCast(me, SPELL_INFECTED_WOUND);
                    _events.ScheduleEvent(EVENT_INFECTED_WOUND2, 12000, 15000);
                    break;
                case EVENT_ENRAGE2:
                    DoCast(me, SPELL_ENRAGE);
                    _events.ScheduleEvent(EVENT_ENRAGE2, 12000, 15000);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

/*#####
# npc_raz_the_crazed
#####*/

enum RazTheCrazed
{
    // Texts
    SAY_SMASH                           = 0,
    SAY_TIRED                           = 1,

    // Spells
    SPELL_AGGRO_NEARBY_TARGETS          = 80189,
    SPELL_HIGH_SECURITY_SHADOW_PRISON   = 79725,
    SPELL_LEAP_FROM_CAGE                = 79720,
    SPELL_LEAP_FROM_BRIDGE              = 80273,
    SPELL_LEAP_FROM_LEDGE               = 80300,
    SPELL_LEAP_OVER_BORER_PACKS         = 80305,
    SPELL_LEAP_AT_OBSIDIUS              = 80320,
    SPELL_FURIOUS_SWIPE                 = 80206,
    SPELL_FURIOUS_SWIPE_DUMMY           = 80340,
    SPELL_FURIOUS_RAGE                  = 80218,
    SPELL_STOP_HEART                    = 82393,
    SPELL_INSTAKILL_SELF                = 29878,

    EVENT_SAY_SMASH                     = 1,
    EVENT_START_ESCORT_PATH,
    EVENT_FACE_TO_THE_SIDE,
    EVENT_LEAP_FROM_BRIDGE,
    EVENT_LEAP_FROM_LEDGE,
    EVENT_LEAP_OVER_BORER_PACKS,
    EVENT_RESUME_ESCORT,
    EVENT_LEAP_AT_OBSIDIUS,
    EVENT_KILL_RAZ
};

Position const RazPathRomogg[] =
{
    { 208.311f,  946.102f,  191.0072f },
    { 216.6545f, 913.2952f, 190.9795f },
    { 230.5486f, 910.7917f, 191.057f  },
    { 242.2326f, 905.5382f, 190.97f   },
    { 255.8333f, 910.5886f, 191.0629f },
    { 268.3038f, 918.5191f, 190.9722f },
    { 288.9861f, 949.3038f, 190.8299f },
    { 314.5087f, 949.7239f, 191.1788f },
    { 345.4254f, 948.5174f, 190.9669f },
    { 375.7309f, 949.0417f, 192.2794f },
    { 398.0313f, 945.6302f, 193.3367f },
    { 470.9601f, 905.092f,  165.8345f }
};

Position const RazPathCorla[] =
{
    { 283.8698f, 817.0018f, 99.45939f },
    { 273.4479f, 816.1007f, 95.95034f }
};

struct npc_raz_the_crazed : public EscortAI
{
    npc_raz_the_crazed(Creature* creature) : EscortAI(creature), _instance(creature->GetInstanceScript()) { }

    void EnterEvadeMode(EvadeReason why) override
    {
        EscortAI::EnterEvadeMode(why);
        DoCastSelf(SPELL_AGGRO_NEARBY_TARGETS, true);
    }

    void JustAppeared() override
    {
        SetRun(true);
        if (_instance->GetData(DATA_RAZ_LAST_AREA_INDEX) == RAZ_AREA_INDEX_ROMOGG)
        {
            me->SetDisableGravity(true);
            me->SetHover(true);
            BuildRomoggPath();
            DoCastSelf(SPELL_HIGH_SECURITY_SHADOW_PRISON, true);
        }
        else if (_instance->GetData(DATA_RAZ_LAST_AREA_INDEX) == RAZ_AREA_INDEX_CORLA)
        {
            _events.ScheduleEvent(EVENT_LEAP_FROM_LEDGE, 2s);
            BuildCorlaPath();
        }
        else if (_instance->GetData(DATA_RAZ_LAST_AREA_INDEX) == RAZ_AREA_INDEX_OBSIDIUS)
            _events.ScheduleEvent(EVENT_LEAP_AT_OBSIDIUS, 2s);

        SetDespawnAtEnd(false);
        DoCastSelf(SPELL_AGGRO_NEARBY_TARGETS, true);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_TIRED);
        me->DespawnOrUnsummon(9s);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_BREAK_OUT_OF_PRISON)
        {
            me->RemoveAurasDueToSpell(SPELL_HIGH_SECURITY_SHADOW_PRISON);
            me->SetDisableGravity(false);
            me->SetHover(false);
            DoCastSelf(SPELL_LEAP_FROM_CAGE);
            _events.ScheduleEvent(EVENT_START_ESCORT_PATH, 4s);
            _events.ScheduleEvent(EVENT_SAY_SMASH, 4s);
        }
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_STOP_HEART)
            _events.ScheduleEvent(EVENT_KILL_RAZ, 4s);
    }

    void BuildRomoggPath()
    {
        for (uint8 i = 0; i < 12; i++)
            AddWaypoint(i, RazPathRomogg[i].GetPositionX(), RazPathRomogg[i].GetPositionY(), RazPathRomogg[i].GetPositionZ());
    }

    void BuildCorlaPath()
    {
        for (uint8 i = 0; i < 2; i++)
            AddWaypoint(i, RazPathCorla[i].GetPositionX(), RazPathCorla[i].GetPositionY(), RazPathCorla[i].GetPositionZ());
    }

    void WaypointReached(uint32 id, uint32 /*pathId*/) override
    {
        if (id == 10 && _instance->GetData(DATA_RAZ_LAST_AREA_INDEX) == RAZ_AREA_INDEX_ROMOGG)
        {
            SetEscortPaused(true);
            _events.ScheduleEvent(EVENT_FACE_TO_THE_SIDE, 1s);
            _events.ScheduleEvent(EVENT_LEAP_FROM_BRIDGE, 2s);
            _events.ScheduleEvent(EVENT_RESUME_ESCORT, 2s + 500ms);
            me->DespawnOrUnsummon(12s);
        }
        else if (id == 1 && _instance->GetData(DATA_RAZ_LAST_AREA_INDEX) == RAZ_AREA_INDEX_CORLA)
            _events.ScheduleEvent(EVENT_LEAP_OVER_BORER_PACKS, 1s);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (!target)
            return;

        if (!target->IsInCombat())
            return;

        if (spell->Id == SPELL_FURIOUS_SWIPE_DUMMY)
        {
            DoCast(target, SPELL_FURIOUS_SWIPE);
            DoCastSelf(SPELL_FURIOUS_RAGE, true);
        }
    }

    void UpdateEscortAI(uint32 diff) override
    {
        UpdateVictim();

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SAY_SMASH:
                    Talk(SAY_SMASH);
                    break;
                case EVENT_START_ESCORT_PATH:
                    me->SetHomePosition(me->GetPosition());
                    Start(true, true);
                    break;
                case EVENT_FACE_TO_THE_SIDE:
                    me->SetFacingTo(5.061455f);
                    break;
                case EVENT_LEAP_FROM_BRIDGE:
                    DoCastSelf(SPELL_LEAP_FROM_BRIDGE);
                    break;
                case EVENT_RESUME_ESCORT:
                    SetEscortPaused(false);
                    break;
                case EVENT_LEAP_FROM_LEDGE:
                    DoCastSelf(SPELL_LEAP_FROM_LEDGE);
                    _events.ScheduleEvent(EVENT_SAY_SMASH, 1s);
                    _events.ScheduleEvent(EVENT_START_ESCORT_PATH, 2s);
                    break;
                case EVENT_LEAP_OVER_BORER_PACKS:
                    DoCastSelf(SPELL_LEAP_OVER_BORER_PACKS);
                    me->DespawnOrUnsummon(2s);
                    break;
                case EVENT_LEAP_AT_OBSIDIUS:
                    Talk(SAY_SMASH);
                    DoCastSelf(SPELL_LEAP_AT_OBSIDIUS);
                    break;
                case EVENT_KILL_RAZ:
                    DoCastSelf(SPELL_INSTAKILL_SELF);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

class at_raz_corla_event : public AreaTriggerScript
{
    public:
        at_raz_corla_event() : AreaTriggerScript("at_raz_corla_event") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_RAZ_LAST_AREA_INDEX) == RAZ_AREA_INDEX_ROMOGG
                    && instance->GetBossState(DATA_CORLA_HERALD_OF_TWILIGHT) == DONE)
                    instance->SetData(DATA_RAZ_LAST_AREA_INDEX, RAZ_AREA_INDEX_CORLA);

            return true;

        }
};

class at_raz_obsidius_event : public AreaTriggerScript
{
    public:
        at_raz_obsidius_event() : AreaTriggerScript("at_raz_obsidius_event") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetData(DATA_RAZ_LAST_AREA_INDEX) == RAZ_AREA_INDEX_CORLA
                    && instance->GetBossState(DATA_KARSH_STEELBENDER) == DONE)
                    instance->SetData(DATA_RAZ_LAST_AREA_INDEX, RAZ_AREA_INDEX_OBSIDIUS);

            return true;
        }
};

enum AreaTriggerQuests
{
    SPELL_UPDATE_PLAYER_PHASE_AURAS     = 89457,
    QUEST_ID_WHAT_IS_THIS_PLACE         = 28737,
    QUEST_ID_THE_TWILIGHT_FORGE         = 28738,
    QUEST_ID_DO_MY_EYES_DECEIVE_ME      = 28740,
    QUEST_ID_ASCENDANT_LORD_OBSIDIUS    = 28741
};

class at_brc_quest_trigger : public AreaTriggerScript
{
public:
    at_brc_quest_trigger(char const* scriptName, uint32 questId) : AreaTriggerScript(scriptName), _questId(questId) { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/)
    {
        if (Quest const* quest = sObjectMgr->GetQuestTemplate(_questId))
        {
            if (!player->CanTakeQuest(quest, false))
                return false;

            player->AddQuestAndCheckCompletion(quest, player);
            player->PlayerTalkClass->SendQuestGiverQuestDetails(quest, player->GetGUID(), true, true);
        }

        player->CastSpell(player, SPELL_UPDATE_PLAYER_PHASE_AURAS);

        return true;
    }
private:
    uint32 _questId = 0;
};

void AddSC_blackrock_caverns()
{
    RegisterBlackrockCavernsCreatureAI(npc_fire_cyclone);
    RegisterBlackrockCavernsCreatureAI(npc_twilight_flame_caller);
    RegisterBlackrockCavernsCreatureAI(npc_twilight_torturer);
    RegisterBlackrockCavernsCreatureAI(npc_twilight_sadist);
    RegisterBlackrockCavernsCreatureAI(npc_mad_prisoner);
    RegisterBlackrockCavernsCreatureAI(npc_crazed_mage);
    RegisterBlackrockCavernsCreatureAI(npc_raz_the_crazed);
    new at_raz_corla_event();
    new at_raz_obsidius_event();
    new at_brc_quest_trigger("at_brc_corla_quest", QUEST_ID_WHAT_IS_THIS_PLACE);
    new at_brc_quest_trigger("at_brc_karsh_quest", QUEST_ID_THE_TWILIGHT_FORGE);
    new at_brc_quest_trigger("at_brc_beauty_quest", QUEST_ID_DO_MY_EYES_DECEIVE_ME);
    new at_brc_quest_trigger("at_brc_obsidius_quest", QUEST_ID_ASCENDANT_LORD_OBSIDIUS);
}

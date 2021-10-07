/*
 * This file is part of the AshamaneCore Project. See AUTHORS file for Copyright information
 * Copyright (C) 2018+ MagicStormProject <https://github.com/MagicStormTeam>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "Player.h"
#include "SpellScript.h"
#include "ScriptedGossip.h"
#include "InstanceScript.h"
#include "antorus_the_burning_throne.h"

enum Spells
{
    SPELL_TAESHALACH_S_REACH                = 243431,
    //SPELL_TAESHALACH_S_REACH                = 245990,
    //SPELL_FLAME_REND                        = 244033,
    SPELL_FLAME_REND                        = 245463,//????
    //SPELL_FLAME_REND                        = 254654,
    //SPELL_FOE_BREAKER                       = 244291,
    SPELL_FOE_BREAKER                       = 245458,//???
    //SPELL_FOE_BREAKER                       = 254655,
    SPELL_WAKE_OF_FLAME                     = 244693,
    //SPELL_WAKE_OF_FLAME                     = 244736,
    SPELL_BURNING_RAGE                      = 244713,
    SPELL_CORRUPT_AEGIS                     = 244894,
    SPELL_SEARING_TEMPEST                   = 245301,
    //SPELL_SEARING_TEMPEST                   = 246014,
    SPELL_SCORCHING_BLAZE                   = 245994,
    SPELL_EMPOWERED_FLAME_REND              = 247079,
    //SPELL_EMPOWERED_FLAME_REND              = 255058,
    SPELL_RAVENOUS_BLAZE                    = 254452,
    SPELL_EMPOWERED_FOE_BREAKER             = 255059,
    //SPELL_EMPOWERED_FOE_BREAKER             = 255060,
    SPELL_EMPOWERED_SEARING_TEMPEST         = 255061,
    //SPELL_EMPOWERED_SEARING_TEMPEST         = 255062,
    SPELL_SEARING_BINDING                   = 255528,

    SPELL_TAESHALACH_TECHNIQUE              = 256208, // 244688

    NPC_EMBER_OF_TAESHALACH                 = 122532,
    SPELL_BLAZING_ERUPTION                  = 244912,
    SPELL_MOLTEN_REMNANTS                   = 245905,
    //SPELL_SEARING_TEMPEST                   = 254653,
    SPELL_UNENDING_BLAZE                    = 254695,

    SPELL_TITANS_ASSEMBLE_MOVIE             = 254311,
    SPELL_FLARE                             = 245983
};

enum Events
{
    // Intro
    EVENT_INTRO                             = 1,
    EVNET_PHASE_2                           = 2,
    EVNET_PHASE_3                           = 3,
    EVENT_A1                                = 4,
    EVENT_A2                                = 5,
    EVENT_A3                                = 6,
    EVENT_A4                                = 7
};

enum Talk
{
    TALK_AGGRAMAR_AGGRO                     = 1,
    TALK_AGGRAMAR_DEATH                     = 2,
    TALK_AGGRAMAR_LOS                       = 3,
    TALK_AGGRAMAR_HP80                      = 4,
    TALK_AGGRAMAR_WAKE_OF_FLAME             = 5
};

enum Phases
{
    PHASE_NORMAL,
    PHASE_INTRO,
    PHASE_1,
    PHASE_2,
    PHASE_3,
    PHASE_4,
};

struct CustomSpawnData
{
    uint32 event, npcId;
    float X;
    float Y;
    float Z;
    float orientation;
};

CustomSpawnData const spawnData[] =
{
    { EVNET_PHASE_2, NPC_EMBER_OF_TAESHALACH, -12679.456f, -2254.8264f, 2514.2646f },
    { EVNET_PHASE_2, NPC_EMBER_OF_TAESHALACH, -12588.12f,  -2254.8215f, 2514.6276f, 3.101369f },
    { EVNET_PHASE_3, NPC_EMBER_OF_TAESHALACH, -12679.456f, -2254.8264f, 2514.2646f },
    { EVNET_PHASE_3, NPC_EMBER_OF_TAESHALACH, -12588.12f,  -2254.8215f, 2514.6276f, 3.101369f },
};

struct boss_aggramar : public BossAI
{
    boss_aggramar(Creature* creature) : BossAI(creature, DATA_AGGRAMAR)
    {
        Initialize();
    }

    void Initialize()
    {
        PhaseStatus = Phases::PHASE_INTRO;
    }

    void LoadNPC(uint32 event, const CustomSpawnData* data)
    {
        while (data->event)
        {
            if (data->event == event)
                me->SummonCreature(data->npcId, Position(data->X, data->Y, data->Z, data->orientation), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            ++data;
        }
    }

    void EnterCombat(Unit* who) override
    {
        if (who->ToPlayer())
            if (roll_chance_i(30))
                Talk(TALK_AGGRAMAR_AGGRO);
    }

    void JustDied(Unit* killer) override
    {
        _JustDied();
        instance->SetBossState(DATA_AGGRAMAR, DONE);

        if (killer->ToPlayer())
            if (roll_chance_i(30))
                Talk(TALK_AGGRAMAR_DEATH);

        instance->DoDelayedConversation(2000, 6127);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(80, damage))
        {
            PhaseStatus = PHASE_2;
            events.Reset();
            me->GetMotionMaster()->MovePoint(1, Position(-12634.2f, -2255.2478f, 2514.2617f, 4.674f));
            Talk(TALK_AGGRAMAR_HP80);
            DoCastSelf(SPELL_CORRUPT_AEGIS);
            LoadNPC(EVNET_PHASE_2, spawnData);
            killCount = 2;
            events.RescheduleEvent(EVNET_PHASE_2, 1s);
        }
        else if (me->HealthWillBeBelowPctDamaged(40, damage))
        {
            PhaseStatus = PHASE_3;
            events.Reset();
            me->GetMotionMaster()->MovePoint(1, Position(-12634.2f, -2255.2478f, 2514.2617f, 4.674f));
            DoCastSelf(SPELL_CORRUPT_AEGIS);
            LoadNPC(EVNET_PHASE_3, spawnData);
            killCount = 2;
            events.RescheduleEvent(EVNET_PHASE_3, 1s);
            //SPELL_WAKE_OF_FLAME replace by 245983 flare Talk(7)
        }
    }

    void DoAction(int32 action) override
    {
        if (action == 1)
        {
            PhaseStatus = PHASE_INTRO;
            instance->SetBossState(DATA_AGGRAMAR, SPECIAL);
            events.Reset();
            //events.ScheduleEvent(EVENT_INTRO_GLAIDALIS_1, 5000);
        }
        if (action == 2)
        {
            --killCount;
            if (killCount <= 0)
            {
                me->RemoveAurasDueToSpell(SPELL_CORRUPT_AEGIS);

                //events.ScheduleEvent(SPELL_FLAME_REND, 5s);
                //events.ScheduleEvent(SPELL_FOE_BREAKER, 5s);
                if(PhaseStatus<PHASE_2)
                    events.ScheduleEvent(SPELL_WAKE_OF_FLAME, 6s);
                else
                    events.ScheduleEvent(SPELL_FLARE, 6s);
                //events.ScheduleEvent(SPELL_BURNING_RAGE, 5s);
                //events.ScheduleEvent(SPELL_CORRUPT_AEGIS, 5s);
                //events.ScheduleEvent(SPELL_SEARING_TEMPEST, 5s);
                events.ScheduleEvent(SPELL_SCORCHING_BLAZE, 8s);
                events.ScheduleEvent(SPELL_TAESHALACH_TECHNIQUE, 60s);

                if (me->GetMap()->IsMythic())
                {
                    events.ScheduleEvent(SPELL_EMPOWERED_FLAME_REND, 5s);
                    events.ScheduleEvent(SPELL_RAVENOUS_BLAZE, 5s);
                    events.ScheduleEvent(SPELL_EMPOWERED_FOE_BREAKER, 5s);
                    events.ScheduleEvent(SPELL_EMPOWERED_SEARING_TEMPEST, 5s);
                    events.ScheduleEvent(SPELL_SEARING_BINDING, 5s);
                }
            }
        }
    }

    void ScheduleTasks() override
    {
        //Talk(0);
        DoCastSelf(SPELL_TAESHALACH_S_REACH);
        //events.ScheduleEvent(SPELL_FLAME_REND, 5s);
        //events.ScheduleEvent(SPELL_FOE_BREAKER, 5s);
        if (PhaseStatus<PHASE_2)
            events.ScheduleEvent(SPELL_WAKE_OF_FLAME, 6s);
        else
            events.ScheduleEvent(SPELL_FLARE, 6s);
        //events.ScheduleEvent(SPELL_BURNING_RAGE, 5s);
        //events.ScheduleEvent(SPELL_CORRUPT_AEGIS, 5s);
        //events.ScheduleEvent(SPELL_SEARING_TEMPEST, 5s);
        events.ScheduleEvent(SPELL_SCORCHING_BLAZE, 8s);
        events.ScheduleEvent(SPELL_TAESHALACH_TECHNIQUE, 60s);

        if (me->GetMap()->IsMythic())
        {
            events.ScheduleEvent(SPELL_EMPOWERED_FLAME_REND, 5s);
            events.ScheduleEvent(SPELL_RAVENOUS_BLAZE, 5s);
            events.ScheduleEvent(SPELL_EMPOWERED_FOE_BREAKER, 5s);
            events.ScheduleEvent(SPELL_EMPOWERED_SEARING_TEMPEST, 5s);
            events.ScheduleEvent(SPELL_SEARING_BINDING, 5s);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case SPELL_WAKE_OF_FLAME:
            {
                Talk(TALK_AGGRAMAR_WAKE_OF_FLAME);
                DoCast(SPELL_WAKE_OF_FLAME);
                events.Repeat(25s);
                break;
            }
            case SPELL_FLARE:
            {
                if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    me->CastSpell(target1, SPELL_FLARE, false);

                if (Unit* target2 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    me->CastSpell(target2, SPELL_FLARE, false);

                if (Unit* target3 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    me->CastSpell(target3, SPELL_FLARE, false);

                events.Repeat(25s);
                break;
            }
            case SPELL_SEARING_TEMPEST:
            {
                DoCast(SPELL_SEARING_TEMPEST);
                //events.Repeat(20s);
                break;
            }
            case SPELL_SCORCHING_BLAZE:
            {
                if (Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    me->CastSpell(target1, SPELL_SCORCHING_BLAZE, false);

                if (Unit* target2 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true))
                    me->CastSpell(target2, SPELL_SCORCHING_BLAZE, false);

                events.Repeat(8s);
                break;
            }
            case SPELL_TAESHALACH_TECHNIQUE:
            {
                // alexkulya: text & textemote?
                //Talk(2);
                //Talk(3);
                DoCast(SPELL_TAESHALACH_TECHNIQUE);
                events.ScheduleEvent(EVENT_A1, 1s);
                events.Repeat(60s);
                break;
            }
            case EVENT_A1:
            {
                DoCast(SPELL_FOE_BREAKER);
                events.ScheduleEvent(EVENT_A2, 4s);
                break;
            }
            case EVENT_A2:
            {
                DoCast(SPELL_FLAME_REND);
                DoCast(SPELL_BURNING_RAGE);
                events.ScheduleEvent(EVENT_A3, 4s);
                break;
            }
            case EVENT_A3:
            {
                DoCast(SPELL_FOE_BREAKER);
                events.ScheduleEvent(EVENT_A4, 4s);
                break;
            }
            case EVENT_A4:
            {
                DoCast(SPELL_FLAME_REND);
                DoCast(SPELL_BURNING_RAGE);
                events.ScheduleEvent(SPELL_SEARING_TEMPEST, 5s);
                break;
            }
            case SPELL_EMPOWERED_FLAME_REND:
            {
                DoCast(SPELL_EMPOWERED_FLAME_REND);
                events.Repeat(5s);
                break;
            }
            case SPELL_RAVENOUS_BLAZE:
            {
                DoCast(SPELL_RAVENOUS_BLAZE);
                events.Repeat(5s);
                break;
            }
            case SPELL_EMPOWERED_FOE_BREAKER:
            {
                DoCast(SPELL_EMPOWERED_FOE_BREAKER);
                events.Repeat(5s);
                break;
            }
            case SPELL_EMPOWERED_SEARING_TEMPEST:
            {
                DoCast(SPELL_EMPOWERED_SEARING_TEMPEST);
                events.Repeat(5s);
                break;
            }
            case SPELL_SEARING_BINDING:
            {
                DoCast(SPELL_SEARING_BINDING);
                events.Repeat(5s);
                break;
            }
            default:
                break;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 50.0f, false) && PhaseStatus == Phases::PHASE_INTRO)
        {
            PhaseStatus = Phases::PHASE_1;
   Talk(TALK_AGGRAMAR_LOS);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC));
        }
    }

    void JustSummoned(Creature* summon) override
    {
        BossAI::JustSummoned(summon);

        switch (summon->GetEntry())
        {
            case NPC_EMBER_OF_TAESHALACH:
            {
                summon->SetFaction(me->GetFaction());
                summon->GetMotionMaster()->MovePoint(1, Position(-12634.2f, -2255.2478f, 2514.2617f, 4.674f));
                break;
            }
        }
    }
    uint8 PhaseStatus;
    uint8 killCount;
};

struct npc_ember_of_taeshalach_122532 : public ScriptedAI
{
    npc_ember_of_taeshalach_122532(Creature* creature) : ScriptedAI(creature) { }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (!UpdateVictim())
            return;
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* aggramar = me->FindNearestCreature(NPC_AGGRAMAR, 50.0f, true))
            aggramar->AI()->DoAction(2);

        DoCastSelf(SPELL_MOLTEN_REMNANTS);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->GetEntry() == NPC_AGGRAMAR && me->IsWithinDist(who, 3.0f, false))
        {
            DoCastAOE(SPELL_BLAZING_ERUPTION);
            me->KillSelf();
        }
    }
};

struct npc_magni_bronzebeard_128169 : public ScriptedAI
{
    npc_magni_bronzebeard_128169(Creature* creature) : ScriptedAI(creature) { }

    bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId)
    {
        CloseGossipMenuFor(player);
        player->CastSpell(player, SPELL_TITANS_ASSEMBLE_MOVIE, true);
        player->TeleportTo(4000, 1712, 2826.39f, -4567.94f, 291.95f, 0.02513274f);
        return false;
    }
};

void AddSC_boss_aggramar()
{
    RegisterCreatureAI(boss_aggramar);
    RegisterCreatureAI(npc_ember_of_taeshalach_122532);
    RegisterCreatureAI(npc_magni_bronzebeard_128169);
}

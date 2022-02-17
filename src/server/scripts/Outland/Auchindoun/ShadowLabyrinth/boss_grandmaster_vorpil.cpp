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
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "shadow_labyrinth.h"

enum Texts
{
    SAY_HELP                      = 0,
    SAY_AGGRO                     = 1,
    SAY_SLAY                      = 2,
    SAY_DEATH                     = 3,
    SAY_DRAW                      = 4,
    SAY_WIPE                      = 5
};

enum Spells
{
    SPELL_SHADOWBOLT_VOLLEY       = 33841,
    SPELL_BANISH                  = 38791,
    SPELL_DRAW_SHADOWS            = 33563,
    SPELL_RAIN_OF_FIRE            = 33617,

    SPELL_SUMMON_VOID_PORTAL_A    = 33566,
    SPELL_SUMMON_VOID_PORTAL_B    = 33614,
    SPELL_SUMMON_VOID_PORTAL_C    = 33615,
    SPELL_SUMMON_VOID_PORTAL_D    = 33567,
    SPELL_SUMMON_VOID_PORTAL_E    = 33616,
    SPELL_SUMMON_VOID_SUMMONER    = 33927,

    SPELL_DESPAWN_VOID_PORTALS    = 33568,
    SPELL_GREAT_SACRIFICE         = 33618,

    // Voidwalker Summoner
    SPELL_SUMMON_VOIDWALKER_A     = 33582,
    SPELL_SUMMON_VOIDWALKER_B     = 33583,
    SPELL_SUMMON_VOIDWALKER_C     = 33584,
    SPELL_SUMMON_VOIDWALKER_D     = 33585,
    SPELL_SUMMON_VOIDWALKER_E     = 33586,

    // Void Traveler
    SPELL_SACRIFICE               = 33587,
    SPELL_SHADOW_NOVA             = 33846,
    SPELL_EMPOWERING_SHADOWS      = 33783,
    SPELL_INSTAKILL_SELF          = 29878
};

enum Events
{
    EVENT_HELP                    = 1,
    EVENT_SHADOWBOLT_VOLLEY,
    EVENT_BANISH,
    EVENT_DRAW_SHADOWS,
    EVENT_RAIN_OF_FIRE
};

std::array<uint32, 5> const VoidwalkerSummonSpells =
{
    SPELL_SUMMON_VOIDWALKER_A, SPELL_SUMMON_VOIDWALKER_B, SPELL_SUMMON_VOIDWALKER_C, SPELL_SUMMON_VOIDWALKER_D, SPELL_SUMMON_VOIDWALKER_E
};

struct boss_grandmaster_vorpil : public BossAI
{
    boss_grandmaster_vorpil(Creature* creature) : BossAI(creature, DATA_GRANDMASTER_VORPIL) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_HELP, 6s);
        events.ScheduleEvent(EVENT_SHADOWBOLT_VOLLEY, 10s, 15s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_BANISH, 10s, 20s);
        events.ScheduleEvent(EVENT_DRAW_SHADOWS, 35s, 45s);

        Talk(SAY_AGGRO);
        DoCastSelf(SPELL_SUMMON_VOID_PORTAL_A);
        DoCastSelf(SPELL_SUMMON_VOID_PORTAL_B);
        DoCastSelf(SPELL_SUMMON_VOID_PORTAL_C);
        DoCastSelf(SPELL_SUMMON_VOID_PORTAL_D);
        DoCastSelf(SPELL_SUMMON_VOID_PORTAL_E);
        DoCastSelf(SPELL_SUMMON_VOID_SUMMONER);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    // Despawn is handled by spells, don't store anything
    void JustSummoned(Creature* /*summon*/) override { }

    void EnterEvadeMode(EvadeReason why) override
    {
        Talk(SAY_WIPE);
        DoCastSelf(SPELL_DESPAWN_VOID_PORTALS, true);
        DoCastSelf(SPELL_GREAT_SACRIFICE, true);
        ScriptedAI::EnterEvadeMode(why);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        DoCastSelf(SPELL_DESPAWN_VOID_PORTALS, true);
        DoCastSelf(SPELL_GREAT_SACRIFICE, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HELP:
                    Talk(SAY_HELP);
                    break;
                case EVENT_SHADOWBOLT_VOLLEY:
                    DoCastSelf(SPELL_SHADOWBOLT_VOLLEY);
                    events.Repeat(10s, 25s);
                    break;
                case EVENT_BANISH:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 30.0f, false))
                        DoCast(target, SPELL_BANISH);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_DRAW_SHADOWS:
                    if (roll_chance_i(50))
                        Talk(SAY_DRAW);
                    DoCastSelf(SPELL_DRAW_SHADOWS);
                    events.Repeat(35s, 45s);
                    events.ScheduleEvent(EVENT_RAIN_OF_FIRE, 1s);
                    break;
                case EVENT_RAIN_OF_FIRE:
                    DoCastSelf(SPELL_RAIN_OF_FIRE);
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_voidwalker_summoner : public ScriptedAI
{
    npc_voidwalker_summoner(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        _scheduler.Schedule(10s, [this](TaskContext task)
        {
            DoCastSelf(Trinity::Containers::SelectRandomContainerElement(VoidwalkerSummonSpells));
            task.Repeat(10s, 15s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

struct npc_void_traveler : public ScriptedAI
{
    npc_void_traveler(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    // This part needs more work
    void JustAppeared() override
    {
        if (Creature* vorpil = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_GRANDMASTER_VORPIL)))
            me->GetMotionMaster()->MoveFollow(vorpil, 0, 0);

        _scheduler.Schedule(500ms, [this](TaskContext task)
        {
            if (Creature* vorpil = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_GRANDMASTER_VORPIL)))
            {
                if (me->IsWithinDist(vorpil, 3))
                {
                    DoCastSelf(SPELL_SACRIFICE);

                    task.Schedule(1s, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_EMPOWERING_SHADOWS);
                        DoCastSelf(SPELL_SHADOW_NOVA);
                        DoCastSelf(SPELL_INSTAKILL_SELF);
                    });
                }
                else
                    task.Repeat();
            }
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

void AddSC_boss_grandmaster_vorpil()
{
    RegisterShadowLabyrinthCreatureAI(boss_grandmaster_vorpil);
    RegisterShadowLabyrinthCreatureAI(npc_voidwalker_summoner);
    RegisterShadowLabyrinthCreatureAI(npc_void_traveler);
}

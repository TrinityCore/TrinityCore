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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "ragefire_chasm.h"

enum Spells
{
    // Intro
    SPELL_ADJULES_CHOW_TIME         = 120113,
    SPELL_EAT_TROGG                 = 120064,

    SPELL_INFERNO_CHARGE_CAST       = 119405,
    SPELL_INFERNO_CHARGE_SUMMON     = 119297, // Serverside
    SPELL_FIRE_BREATH               = 119420
};

enum Texts
{
    SAY_INFERNO_CHARGE              = 0,

    // Intro
    SAY_HOUNDMASTER_INTRO_0         = 0,
    SAY_HOUNDMASTER_INTRO_1         = 1
};

enum Events
{
    EVENT_INFERNO_CHARGE            = 1,
    EVENT_FIRE_BREATH               = 2
};

enum Actions
{
    ACTION_KILL_HOUNDMASTERS        = 1
};

enum Waypoints
{
    // Intro Waypoint
    PATH_INTRO                      = 6140800,

    POINT_EAT_1                     = 0,
    POINT_EAT_2                     = 3
};

constexpr Position IntroPoints[2] =
{
    { -282.31488f, -53.24906f, -60.802902f },
    { -281.1894f,  -54.73433f, -60.34256f }
};

// Areatrigger - 7904
class at_adarogg_intro : public OnlyOnceAreaTriggerScript
{
public:
    at_adarogg_intro() : OnlyOnceAreaTriggerScript("at_adarogg_intro") { }

    bool TryHandleOnce(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (Creature* adarogg = instance->GetCreature(BOSS_ADAROGG))
                adarogg->AI()->DoAction(ACTION_KILL_HOUNDMASTERS);

        return true;
    }
};

// 61408 - Adarogg
struct boss_adarogg : public BossAI
{
    using BossAI::BossAI;

    boss_adarogg(Creature* creature) : BossAI(creature, BOSS_ADAROGG), eatCounter(0) { }

    void Reset() override
    {
        _Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_INFERNO_CHARGE, 10s);
        events.ScheduleEvent(EVENT_FIRE_BREATH, 20s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_KILL_HOUNDMASTERS)
        {
            Creature* corruptedHoundmaster1 = me->FindNearestCreatureWithOptions(70.0f, { .StringId = "npc_corrupted_houndmaster_1" });
            Creature* corruptedHoundmaster2 = me->FindNearestCreatureWithOptions(70.0f, { .StringId = "npc_corrupted_houndmaster_2" });

            if (!corruptedHoundmaster1 || !corruptedHoundmaster2)
                return;

            corruptedHoundmaster1->AI()->Talk(SAY_HOUNDMASTER_INTRO_0);
            corruptedHoundmaster2->AI()->Talk(SAY_HOUNDMASTER_INTRO_1);

            scheduler.Schedule(2s, [this](TaskContext task)
            {
                DoCast(SPELL_ADJULES_CHOW_TIME);
                me->GetMotionMaster()->MovePoint(0, IntroPoints[0]);

                task.Schedule(1s, [this](TaskContext task)
                {
                    DoCast(SPELL_ADJULES_CHOW_TIME);
                    me->GetMotionMaster()->MovePoint(0, IntroPoints[1]);

                    task.Schedule(1s + 200ms, [this](TaskContext /*task*/)
                    {
                        DoCast(SPELL_ADJULES_CHOW_TIME);
                        me->GetMotionMaster()->MovePath(PATH_INTRO, true);
                    });
                });
            });
        }
    }

    void WaypointReached(uint32 waypointId, uint32 pathId) override
    {
        if (pathId == PATH_INTRO)
        {
            switch (waypointId)
            {
                case POINT_EAT_1:
                case POINT_EAT_2:
                {
                    scheduler.Schedule(1s, [this](TaskContext task)
                    {
                        if (eatCounter < 2)
                        {
                            DoCast(SPELL_EAT_TROGG);
                            task.Repeat(2s, 3s);
                            eatCounter++;
                        }
                        else
                        {
                            task.CancelAll();
                            eatCounter = 0;
                        }
                    });
                    break;
                }
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INFERNO_CHARGE:
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, NonTankTargetSelector(me)))
                    {
                        Talk(SAY_INFERNO_CHARGE, target);
                        DoCast(target, SPELL_INFERNO_CHARGE_SUMMON);
                        DoCast(target, SPELL_INFERNO_CHARGE_CAST);
                    }
                    events.Repeat(15s, 20s);
                    break;
                }
                case EVENT_FIRE_BREATH:
                {
                    DoCastVictim(SPELL_FIRE_BREATH);
                    events.Repeat(15s, 20s);
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    TaskScheduler scheduler;
    uint8 eatCounter;
};

void AddSC_boss_adarogg()
{
    new at_adarogg_intro();

    RegisterRagefireChasmCreatureAI(boss_adarogg);
}

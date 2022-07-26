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

#include "Player.h"
#include "ScriptMgr.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "TaskScheduler.h"

enum Aspirant
{
    SAY_FINISH_FIGHT = 0,
    SPELL_BLACKOUT_KICK = 109080,
    QUEST_29524_KILLCREDIT = 54586,
    EVENT_RANDOM_EMOTE = 1,
    EVENT_INSTRUCTOR_ZHI_RANDOM_EMOTE = 2,
    NPC_INSTRUCTOR_ZHI = 61411,
    ACTION = 1
};

Emote randomEmotes[5] =
{
    EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMED,
    EMOTE_ONESHOT_MONKOFFENSE_SPECIALUNARMED,
    EMOTE_ONESHOT_MONKOFFENSE_PARRYUNARMED,
    EMOTE_ONESHOT_PALMSTRIKE,
    EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMEDOFF,
};

//54586
struct npc_aspiring_trainee : public ScriptedAI
{
    npc_aspiring_trainee(Creature* c) : ScriptedAI(c)
    {
        events.ScheduleEvent(EVENT_INSTRUCTOR_ZHI_RANDOM_EMOTE, 6s);
    }

    void Reset() override
    {
        ScriptedAI::Reset();
    }

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (attacker && (me->HealthBelowPctDamaged(15, damage) || damage >= me->GetHealth()))
        {
            if (Player* player = attacker->ToPlayer())
                player->KilledMonsterCredit(QUEST_29524_KILLCREDIT);

            damage = 0;

            me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
            me->CombatStop();

            _scheduler.Schedule(Seconds(1), [this](TaskContext /*task*/) { Talk(SAY_FINISH_FIGHT); });
            {
                Talk(SAY_FINISH_FIGHT);
            };

            _scheduler.Schedule(Seconds(3), [this](TaskContext /*task*/)
            {
                me->GetMotionMaster()->MovePoint(0, 1446.302f, 3387.493f, 173.7903f);
            });

            _scheduler.Schedule(Seconds(6), [this](TaskContext /*task*/)
            {
                me->DespawnOrUnsummon();
            });
        }
    }

    void JustEngagedWith(Unit* /*attacker*/) override
    {
        _scheduler.Schedule(Seconds(4), [this](TaskContext task)
        {
            if (me->GetVictim())

            DoCastVictim(SPELL_BLACKOUT_KICK);

            task.Repeat(Seconds(8));
        });

        events.CancelEvent(EVENT_RANDOM_EMOTE);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);
        _scheduler.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_INSTRUCTOR_ZHI_RANDOM_EMOTE:
            {
                if (me->IsInCombat())
                    return;

                if (Creature* instructorZhi = me->FindNearestCreature(NPC_INSTRUCTOR_ZHI, range))
                {
                    instructorZhi->AI()->DoAction(ACTION);
                    events.ScheduleEvent(EVENT_RANDOM_EMOTE, 1s);
                }

                events.Repeat(6s);
                break;
            }
            case EVENT_RANDOM_EMOTE:
            {
                Emote randomEmote = Trinity::Containers::SelectRandomContainerElement(randomEmotes);
                me->HandleEmoteCommand(randomEmote);
                break;
            }
            }
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
    EventMap events;
    float range = 20.0f;
};

struct npc_instructor_zhi : public ScriptedAI
{
    npc_instructor_zhi(Creature* creature) : ScriptedAI(creature) { }

    void DoAction(int32 param) override
    {
        if (param == ACTION)
        {
        Emote randomEmote = Trinity::Containers::SelectRandomContainerElement(randomEmotes);
        me->HandleEmoteCommand(randomEmote);
        }
    }
};

void AddSC_zone_the_wandering_isle()
{
    RegisterCreatureAI(npc_aspiring_trainee);
    RegisterCreatureAI(npc_instructor_zhi);
}

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

enum AspiringTrainee
{
    SAY_FINISH_FIGHT                    = 0,

    SPELL_BLACKOUT_KICK                 = 109080,

    QUEST_29524_KILLCREDIT              = 54586,

    NPC_INSTRUCTOR_ZHI                  = 61411,

    ASPIRING_TRAINEE_PATH_MAX          = 5,
};

std::vector<Position const> AspiringTraineePaths[ASPIRING_TRAINEE_PATH_MAX] = {
    { // waypoints 1
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
    },
    {
        { 0.0f, 0.0f, 0.0f },
    },
};

// 54586 - Aspiring Trainee
struct npc_aspiring_trainee : public ScriptedAI
{
    npc_aspiring_trainee(Creature* creature) : ScriptedAI(creature) { }

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (attacker && me->HealthBelowPctDamaged(15, damage))
        {
            if (Player* player = attacker->ToPlayer())
                player->KilledMonsterCredit(QUEST_29524_KILLCREDIT);

            damage = 0;

            me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
            me->CombatStop();
            _scheduler.CancelAll();

            _scheduler.Schedule(Seconds(1), [this](TaskContext /*task*/)
            {
                Talk(SAY_FINISH_FIGHT);
            });

            _scheduler.Schedule(Seconds(3), [this](TaskContext /*task*/)
            {
                uint32 pathId = urand(0, ASPIRING_TRAINEE_PATH_MAX);
                me->GetMotionMaster()->MoveSmoothPath(pathId, AspiringTraineePaths[pathId].data(), AspiringTraineePaths[pathId].size());
            });
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != EFFECT_MOTION_TYPE)
            return;

        me->DespawnOrUnsummon();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*attacker*/) override
    {
        _scheduler.Schedule(Seconds(4), [this](TaskContext task)
        {
            if (me->GetVictim())
                DoCastVictim(SPELL_BLACKOUT_KICK);

            task.Repeat(Seconds(8));
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

enum InstructorZhiMisc
{
    NPC_ASPIRING_TRAINEE                            = 54586,

    EVENT_INSTRUCTOR_ZHI_START_EMOTE                = 1,
    EVENT_INSTRUCTOR_ZHI_TRAINEES_DO_EMOTE          = 2,
};

Emote const InstructorZhiRandomEmotes[5] =
{
    EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMED,
    EMOTE_ONESHOT_MONKOFFENSE_SPECIALUNARMED,
    EMOTE_ONESHOT_MONKOFFENSE_PARRYUNARMED,
    EMOTE_ONESHOT_PALMSTRIKE,
    EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMEDOFF,
};

// 61411 - Instructor Zhi
struct npc_instructor_zhi : public ScriptedAI
{
    npc_instructor_zhi(Creature* c) : ScriptedAI(c) { }

    void Reset() override
    {
        _events.ScheduleEvent(EVENT_INSTRUCTOR_ZHI_START_EMOTE, 6s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INSTRUCTOR_ZHI_START_EMOTE:
                {
                    _currentEmote = Trinity::Containers::SelectRandomContainerElement(InstructorZhiRandomEmotes);
                    me->HandleEmoteCommand(_currentEmote);

                    _events.ScheduleEvent(EVENT_INSTRUCTOR_ZHI_TRAINEES_DO_EMOTE, 1s);
                    _events.Repeat(6s);
                    break;
                }
                case EVENT_INSTRUCTOR_ZHI_TRAINEES_DO_EMOTE:
                {
                    std::list<Creature*> traineeList;
                    me->GetCreatureListWithEntryInGrid(traineeList, NPC_ASPIRING_TRAINEE, 20.0f);
                    for (Creature* trainee : traineeList)
                    {
                        if (trainee->IsInCombat())
                            continue;
                        trainee->HandleEmoteCommand(_currentEmote);
                    }
                    break;
                }
            }
        }
    }

private:
    EventMap _events;
    Emote _currentEmote;
};

void AddSC_zone_the_wandering_isle()
{
    RegisterCreatureAI(npc_aspiring_trainee);
    RegisterCreatureAI(npc_instructor_zhi);
}

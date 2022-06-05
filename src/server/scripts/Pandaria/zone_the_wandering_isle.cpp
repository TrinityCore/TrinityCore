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
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "TaskScheduler.h"

enum Aspirant
{
    // Texts
    SAY_FINISH_FIGHT = 0,

    // Spells
    SPELL_BLACKOUT_KICK = 109080,

    // Kill Credit
    QUEST_29524_KILLCREDIT = 54586
};

Emote const AspirantEmotes[] =
{
    EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMED,
    EMOTE_ONESHOT_MONKOFFENSE_SPECIALUNARMED,
    EMOTE_ONESHOT_MONKOFFENSE_PARRYUNARMED,
    EMOTE_ONESHOT_PALMSTRIKE,
    EMOTE_ONESHOT_MONKOFFENSE_ATTACKUNARMEDOFF
};

struct npc_aspiring_trainee : public ScriptedAI
{
    npc_aspiring_trainee(Creature* creature) : ScriptedAI(creature) { }

    void DamageTaken(Unit* attacker, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (attacker && (me->HealthBelowPctDamaged(15, damage) || damage >= me->GetHealth()))
        {
            //prevent death
            damage = 0;

            me->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNINTERACTIBLE);
            me->CombatStop();
            attacker->ToPlayer()->KilledMonsterCredit(QUEST_29524_KILLCREDIT);


            _scheduler.Schedule(Seconds(1), [this](TaskContext task)
                {
                    Talk(SAY_FINISH_FIGHT);
                });

            _scheduler.Schedule(Seconds(3), [this](TaskContext task)
                {
                    // ToDo: There are 3 or 4 points where the npc goes randomly
                    me->GetMotionMaster()->MovePoint(0, 1446.302f, 3387.493f, 173.7903f);
                });

            _scheduler.Schedule(Seconds(6), [this](TaskContext task)
                {
                    me->DespawnOrUnsummon();
                });
        }
    }

    void JustEngagedWith(Unit* /*attacker*/) override
    {
        _scheduler.Schedule(Seconds(4), [this](TaskContext task)
            {
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

void AddSC_zone_the_wandering_isle()
{
    RegisterCreatureAI(npc_aspiring_trainee);
}

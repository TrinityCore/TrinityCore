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
#include "blackrock_depths.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_MIGHTYBLOW                                       = 14099,
    SPELL_HAMSTRING                                        = 9080,
    SPELL_CLEAVE                                           = 20691
};

enum Events
{
    EVENT_MIGHTYBLOW                                       = 1,
    EVENT_HAMSTRING                                        = 2,
    EVENT_CLEAVE                                           = 3,
    EVENT_MEDIC                                            = 4,
    EVENT_ADDS                                             = 5
};

enum Phases
{
    PHASE_ONE                                              = 1,
    PHASE_TWO                                              = 2
};

class boss_general_angerforge : public CreatureScript
{
    public:
        boss_general_angerforge() : CreatureScript("boss_general_angerforge") { }

        struct boss_general_angerforgeAI : public BossAI
        {
            boss_general_angerforgeAI(Creature* creature) : BossAI(creature, BOSS_GENERAL_ANGERFORGE) { }

            void JustEngagedWith(Unit* who) override
            {
                _JustEngagedWith(who);
                events.SetPhase(PHASE_ONE);
                events.ScheduleEvent(EVENT_MIGHTYBLOW, 8s);
                events.ScheduleEvent(EVENT_HAMSTRING, 12s);
                events.ScheduleEvent(EVENT_CLEAVE, 16s);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
            {
                if (me->HealthBelowPctDamaged(20, damage) && events.IsInPhase(PHASE_ONE))
                {
                    events.SetPhase(PHASE_TWO);
                    events.ScheduleEvent(EVENT_MEDIC, 0s, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_ADDS, 0s, 0, PHASE_TWO);
                }
            }

            void SummonAdd(Unit* victim)
            {
                if (Creature* SummonedAdd = DoSpawnCreature(8901, float(irand(-14, 14)), float(irand(-14, 14)), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 120s))
                    SummonedAdd->AI()->AttackStart(victim);
            }

            void SummonMedic(Unit* victim)
            {
                if (Creature* SummonedMedic = DoSpawnCreature(8894, float(irand(-9, 9)), float(irand(-9, 9)), 0, 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 120s))
                    SummonedMedic->AI()->AttackStart(victim);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MIGHTYBLOW:
                            DoCastVictim(SPELL_MIGHTYBLOW);
                            events.ScheduleEvent(EVENT_MIGHTYBLOW, 18s);
                            break;
                        case EVENT_HAMSTRING:
                            DoCastVictim(SPELL_HAMSTRING);
                            events.ScheduleEvent(EVENT_HAMSTRING, 15s);
                            break;
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, 9s);
                            break;
                        case EVENT_MEDIC:
                            for (uint8 i = 0; i < 2; ++i)
                                SummonMedic(me->GetVictim());
                            break;
                        case EVENT_ADDS:
                            for (uint8 i = 0; i < 3; ++i)
                                SummonAdd(me->GetVictim());
                            events.ScheduleEvent(EVENT_ADDS, 25s, 0, PHASE_TWO);
                            break;
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBlackrockDepthsAI<boss_general_angerforgeAI>(creature);
        }
};

void AddSC_boss_general_angerforge()
{
    new boss_general_angerforge();
}

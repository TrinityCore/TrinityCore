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

#include "ruins_of_ahnqiraj.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"

enum Yells
{
    // The time of our retribution is at hand! Let darkness reign in the hearts of our enemies! Sound: 8645 Emote: 35
    SAY_ANDOROV_INTRO         = 0,   // Before for the first wave
    SAY_ANDOROV_ATTACK        = 1,   // Beginning the event

    SAY_WAVE3                 = 0,
    SAY_WAVE4                 = 1,
    SAY_WAVE5                 = 2,
    SAY_WAVE6                 = 3,
    SAY_WAVE7                 = 4,
    SAY_INTRO                 = 5,
    SAY_UNK1                  = 6,
    SAY_UNK2                  = 7,
    SAY_UNK3                  = 8,
    SAY_DEATH                 = 9,
    SAY_CHANGEAGGRO           = 10,
    SAY_KILLS_ANDOROV         = 11,
    SAY_COMPLETE_QUEST        = 12    // Yell when realm complete quest 8743 for world event
    // Warriors, Captains, continue the fight! Sound: 8640
};

enum Spells
{
    SPELL_DISARM            = 6713,
    SPELL_FRENZY            = 8269,
    SPELL_THUNDERCRASH      = 25599
};

enum Events
{
    EVENT_DISARM            = 1,        // 03:58:27, 03:58:49
    EVENT_THUNDERCRASH      = 2,        // 03:58:29, 03:58:50
    EVENT_CHANGE_AGGRO      = 3,
};

class boss_rajaxx : public CreatureScript
{
    public:
        boss_rajaxx() : CreatureScript("boss_rajaxx") { }

        struct boss_rajaxxAI : public BossAI
        {
            boss_rajaxxAI(Creature* creature) : BossAI(creature, DATA_RAJAXX)
            {
                Initialize();
            }

            void Initialize()
            {
                enraged = false;
            }

            void Reset() override
            {
                _Reset();
                Initialize();
                events.ScheduleEvent(EVENT_DISARM, 10s);
                events.ScheduleEvent(EVENT_THUNDERCRASH, 12s);
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
                        case EVENT_DISARM:
                            DoCastVictim(SPELL_DISARM);
                            events.ScheduleEvent(EVENT_DISARM, 22s);
                            break;
                        case EVENT_THUNDERCRASH:
                            DoCast(me, SPELL_THUNDERCRASH);
                            events.ScheduleEvent(EVENT_THUNDERCRASH, 21s);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }
            }
            private:
                bool enraged;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAQ20AI<boss_rajaxxAI>(creature);
        }
};

// 25599 - Thundercrash
class spell_rajaxx_thundercrash : public SpellScript
{
    static void HandleDamageCalc(Unit const* victim, int32& damage, int32& /*flatMod*/, float& /*pctMod*/)
    {
        damage = victim->CountPctFromCurHealth(50);
    }

    void Register() override
    {
        CalcDamage += SpellCalcDamageFn(spell_rajaxx_thundercrash::HandleDamageCalc);
    }
};

void AddSC_boss_rajaxx()
{
    new boss_rajaxx();
    RegisterSpellScript(spell_rajaxx_thundercrash);
}

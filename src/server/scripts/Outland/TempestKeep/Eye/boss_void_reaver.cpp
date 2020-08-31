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
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "the_eye.h"

enum Yells
{
    SAY_AGGRO                   = 0,
    SAY_SLAY                    = 1,
    SAY_DEATH                   = 2,
    SAY_POUNDING                = 3
};

enum Spells
{
    SPELL_POUNDING              = 34162,
    SPELL_ARCANE_ORB            = 34172,
    SPELL_KNOCK_AWAY            = 25778,
    SPELL_BERSERK               = 27680
};

enum Events
{
    EVENT_POUNDING              = 1,
    EVENT_ARCANE_ORB,
    EVENT_KNOCK_AWAY,
    EVENT_BERSERK
};

class boss_void_reaver : public CreatureScript
{
    public:
        boss_void_reaver() : CreatureScript("boss_void_reaver") { }

        struct boss_void_reaverAI : public BossAI
        {
            boss_void_reaverAI(Creature* creature) : BossAI(creature, DATA_VOID_REAVER)
            {
                Initialize();
            }

            void Initialize()
            {
                Enraged = false;
            }

            void Reset() override
            {
                Initialize();
                _Reset();
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_SLAY);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                DoZoneInCombat();
                _JustDied();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                _EnterCombat();

                events.ScheduleEvent(EVENT_POUNDING, 15000);
                events.ScheduleEvent(EVENT_ARCANE_ORB, 3000);
                events.ScheduleEvent(EVENT_KNOCK_AWAY, 30000);
                events.ScheduleEvent(EVENT_BERSERK, 600000);
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
                        case EVENT_POUNDING:
                            DoCastVictim(SPELL_POUNDING);
                            Talk(SAY_POUNDING);
                            events.ScheduleEvent(EVENT_POUNDING, 15000);
                            break;
                        case EVENT_ARCANE_ORB:
                        {
                            std::vector<Unit*> target_list;
                            for (auto* ref : me->GetThreatManager().GetUnsortedThreatList())
                            {
                                Unit* target = ref->GetVictim();
                                if (target->GetTypeId() == TYPEID_PLAYER && target->IsAlive() && !target->IsWithinDist(me, 18, false))
                                    target_list.push_back(target);
                            }

                            Unit* target;
                            if (!target_list.empty())
                                target = *(target_list.begin() + rand32() % target_list.size());
                            else
                                target = me->GetVictim();

                            if (target)
                                me->CastSpell(target, SPELL_ARCANE_ORB, false, nullptr, nullptr);

                            events.ScheduleEvent(EVENT_ARCANE_ORB, 3000);
                            break;
                        }
                        case EVENT_KNOCK_AWAY:
                            DoCastVictim(SPELL_KNOCK_AWAY);
                            // Drop 25% aggro
                            if (GetThreat(me->GetVictim()))
                                ModifyThreatByPercent(me->GetVictim(), -25);

                            events.ScheduleEvent(EVENT_KNOCK_AWAY, 30000);
                            break;
                        case EVENT_BERSERK:
                            if (!Enraged)
                            {
                                DoCast(me, SPELL_BERSERK);
                                Enraged = true;
                            }
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }

        private:
            bool Enraged;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetTheEyeAI<boss_void_reaverAI>(creature);
        }
};

void AddSC_boss_void_reaver()
{
    new boss_void_reaver();
}

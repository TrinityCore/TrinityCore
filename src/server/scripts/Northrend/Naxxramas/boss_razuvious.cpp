/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "naxxramas.h"

enum ScriptTexts
{
    SAY_AGGRO   = 0,
    SAY_COMMND  = 1,
    SAY_DEATH   = 2,
};

enum Spells
{
    SPELL_UNBALANCING_STRIKE     = 26613,
    SPELL_DISRUPTING_SHOUT       = 29107,
    SPELL_JAGGED_KNIFE           = 55550,
    SPELL_HOPELESS               = 29125,
};

enum Events
{
    EVENT_NONE,
    EVENT_STRIKE,
    EVENT_SHOUT,
    EVENT_KNIFE,
    EVENT_COMMAND,
};

class boss_razuvious : public CreatureScript
{
    public:
        boss_razuvious() : CreatureScript("boss_razuvious") { }

        struct boss_razuviousAI : public BossAI
        {
            boss_razuviousAI(Creature* creature) : BossAI(creature, DATA_RAZUVIOUS) {}

            void DamageTaken(Unit* pDone_by, uint32& uiDamage)
            {
                if (pDone_by->GetTypeId() == TYPEID_UNIT && (pDone_by->GetEntry() == 16803 || pDone_by->GetEntry() == 29941))
                {
                    me->LowerPlayerDamageReq(uiDamage);
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                TalkToMap(SAY_DEATH);
                me->CastSpell(me, SPELL_HOPELESS, true);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                TalkToMap(SAY_AGGRO);
                events.ScheduleEvent(EVENT_STRIKE, 30000);
                events.ScheduleEvent(EVENT_SHOUT, 25000);
                events.ScheduleEvent(EVENT_COMMAND, 40000);
                events.ScheduleEvent(EVENT_KNIFE, 10000);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_STRIKE:
                            DoCast(me->getVictim(), SPELL_UNBALANCING_STRIKE);
                            events.ScheduleEvent(EVENT_STRIKE, 30000);
                            break;
                        case EVENT_SHOUT:
                            DoCastAOE(SPELL_DISRUPTING_SHOUT);
                            events.ScheduleEvent(EVENT_SHOUT, 25000);
                            break;
                        case EVENT_KNIFE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f))
                                DoCast(target, SPELL_JAGGED_KNIFE);
                            events.ScheduleEvent(EVENT_KNIFE, 10000);
                            break;
                        case EVENT_COMMAND:
                            TalkToMap(SAY_COMMND);
                            events.ScheduleEvent(EVENT_COMMAND, 40000);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetNaxxramasAI<boss_razuviousAI>(creature);
        }
};

void AddSC_boss_razuvious()
{
    new boss_razuvious();
}

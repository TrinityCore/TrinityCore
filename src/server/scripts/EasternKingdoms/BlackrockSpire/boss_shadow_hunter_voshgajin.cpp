/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "blackrock_spire.h"

enum Spells
{
    SPELL_CURSEOFBLOOD              = 24673,
    SPELL_HEX                       = 16708,
    SPELL_CLEAVE                    = 20691,
};

enum Events
{
    EVENT_CURSE_OF_BLOOD            = 1,
    EVENT_HEX                       = 2,
    EVENT_CLEAVE                    = 3,
};

class boss_shadow_hunter_voshgajin : public CreatureScript
{
public:
    boss_shadow_hunter_voshgajin() : CreatureScript("boss_shadow_hunter_voshgajin") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_shadowvoshAI(creature);
    }

    struct boss_shadowvoshAI : public BossAI
    {
        boss_shadowvoshAI(Creature* creature) : BossAI(creature, DATA_SHADOW_HUNTER_VOSHGAJIN) {}

        void Reset()
        {
            _Reset();
            //DoCast(me, SPELL_ICEARMOR, true);
        }

        void EnterCombat(Unit * /*who*/)
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_CURSE_OF_BLOOD, 2*IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_HEX, 8*IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_CLEAVE, 14*IN_MILLISECONDS);
        }

        void JustDied(Unit* /*who*/)
        {
            _JustDied();
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CURSE_OF_BLOOD:
                        DoCast(me->getVictim(), SPELL_CURSEOFBLOOD);
                        events.ScheduleEvent(EVENT_CURSE_OF_BLOOD, 45*IN_MILLISECONDS);
                        break;
                    case EVENT_HEX:
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(pTarget, SPELL_HEX);
                        events.ScheduleEvent(EVENT_HEX, 15*IN_MILLISECONDS);
                        break;
                    case EVENT_CLEAVE:
                        DoCast(me->getVictim(), SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, 7*IN_MILLISECONDS);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_shadowvosh()
{
    new boss_shadow_hunter_voshgajin();
}

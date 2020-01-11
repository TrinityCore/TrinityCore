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

#include "scarlet_monastery.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

enum HoundmasterLokseyYells
{
    SAY_AGGRO = 0,
};

enum HoundmasterLokseySpells
{
    SPELL_SUMMON_SCARLET_HOUND = 17164,
    SPELL_BLOODLUST = 6742
};

enum HoundmasterLokseyEvents
{
    EVENT_BLOODLUST = 1
};

struct boss_houndmaster_loksey : public BossAI
{
    boss_houndmaster_loksey(Creature* creature) : BossAI(creature, DATA_HOUNDMASTER_LOKSEY) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        Talk(SAY_AGGRO);
        DoCast(SPELL_SUMMON_SCARLET_HOUND);
        events.ScheduleEvent(EVENT_BLOODLUST, 20s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_BLOODLUST:
                if (me->HealthBelowPct(60))
                {
                    DoCastSelf(SPELL_BLOODLUST);
                    events.Repeat(60s);
                }
                else
                    events.Repeat(1s);
                break;
            default:
                break;
        }
    }
};

void AddSC_boss_houndmaster_loksey()
{
    RegisterScarletMonasteryCreatureAI(boss_houndmaster_loksey);
}

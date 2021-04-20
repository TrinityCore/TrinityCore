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
#include "blackrock_spire.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_CRYSTALIZE                = 16104,
    SPELL_MOTHERSMILK               = 16468,
    SPELL_SUMMON_SPIRE_SPIDERLING   = 16103,
};

enum Events
{
    EVENT_CRYSTALIZE                = 1,
    EVENT_MOTHERS_MILK              = 2,
};

struct boss_mother_smolderweb : public BossAI
{
    boss_mother_smolderweb(Creature* creature) : BossAI(creature, DATA_MOTHER_SMOLDERWEB) { }

    void Reset() override
    {
        _Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_CRYSTALIZE, 20s);
        events.ScheduleEvent(EVENT_MOTHERS_MILK, 10s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
    }

    void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
    {
        if (me->GetHealth() <= damage)
            DoCast(me, SPELL_SUMMON_SPIRE_SPIDERLING, true);
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
                case EVENT_CRYSTALIZE:
                    DoCast(me, SPELL_CRYSTALIZE);
                    events.ScheduleEvent(EVENT_CRYSTALIZE, 15s);
                    break;
                case EVENT_MOTHERS_MILK:
                    DoCast(me, SPELL_MOTHERSMILK);
                    events.ScheduleEvent(EVENT_MOTHERS_MILK, 5s, 12500ms);
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_mothersmolderweb()
{
    RegisterBlackrockSpireCreatureAI(boss_mother_smolderweb);
}

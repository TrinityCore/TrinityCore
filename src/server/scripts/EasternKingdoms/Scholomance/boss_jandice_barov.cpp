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
#include "scholomance.h"
#include "ScriptedCreature.h"

enum JandiceSpells
{
    SPELL_CURSE_OF_BLOOD        = 24673,
    SPELL_ILLUSION              = 17773,
    SPELL_DROP_JOURNAL          = 26096
};

enum JandiceEvents
{
    EVENT_CURSE_OF_BLOOD = 1,
    EVENT_ILLUSION,
    EVENT_CLEAVE,
    EVENT_SET_VISIBILITY
};

// 10503 - Jandice Barov
struct boss_jandice_barov : public BossAI
{
    boss_jandice_barov(Creature* creature) : BossAI(creature, DATA_JANDICE_BAROV) { }

    void JustSummoned(Creature* summoned) override
    {
        // Illusions should attack a random target.
        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
            summoned->AI()->AttackStart(target);

        summons.Summon(summoned);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_CURSE_OF_BLOOD, 15s);
        events.ScheduleEvent(EVENT_ILLUSION, 30s);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        summons.DespawnAll();
        DoCastSelf(SPELL_DROP_JOURNAL, true);
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
                case EVENT_CURSE_OF_BLOOD:
                    DoCastVictim(SPELL_CURSE_OF_BLOOD);
                    events.Repeat(30s);
                    break;
                case EVENT_ILLUSION:
                    DoCast(SPELL_ILLUSION);
                    me->SetUninteractible(true);
                    me->SetDisplayId(11686);  // Invisible Model
                    ModifyThreatByPercent(me->GetVictim(), -99);
                    events.ScheduleEvent(EVENT_SET_VISIBILITY, 3s);
                    events.Repeat(25s);
                    break;
                case EVENT_SET_VISIBILITY:
                    me->SetUninteractible(false);
                    me->SetDisplayId(11073);     // Jandice Model
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

void AddSC_boss_jandicebarov()
{
    RegisterScholomanceCreatureAI(boss_jandice_barov);
}

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

struct boss_shadow_hunter_voshgajin : public BossAI
{
    boss_shadow_hunter_voshgajin(Creature* creature) : BossAI(creature, DATA_SHADOW_HUNTER_VOSHGAJIN) { }

    void Reset() override
    {
        _Reset();
        //DoCast(me, SPELL_ICEARMOR, true);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_CURSE_OF_BLOOD, 2s);
        events.ScheduleEvent(EVENT_HEX, 8s);
        events.ScheduleEvent(EVENT_CLEAVE, 14s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
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
                    DoCastVictim(SPELL_CURSEOFBLOOD);
                    events.ScheduleEvent(EVENT_CURSE_OF_BLOOD, 45s);
                    break;
                case EVENT_HEX:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100, true))
                        DoCast(target, SPELL_HEX);
                    events.ScheduleEvent(EVENT_HEX, 15s);
                    break;
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    events.ScheduleEvent(EVENT_CLEAVE, 7s);
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_shadowvosh()
{
    RegisterBlackrockSpireCreatureAI(boss_shadow_hunter_voshgajin);
}

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
#include "blackwing_lair.h"
#include "ScriptedCreature.h"

enum Emotes
{
    EMOTE_FRENZY            = 0,
};

enum Spells
{
    SPELL_SHADOWFLAME        = 22539,
    SPELL_WINGBUFFET         = 23339,
    SPELL_FRENZY             = 23342  //This spell periodically triggers fire nova
};

enum Events
{
    EVENT_SHADOWFLAME       = 1,
    EVENT_WINGBUFFET        = 2,
    EVENT_FRENZY            = 3
};

struct boss_flamegor : public BossAI
{
    boss_flamegor(Creature* creature) : BossAI(creature, DATA_FLAMEGOR) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_SHADOWFLAME, 10s, 20s);
        events.ScheduleEvent(EVENT_WINGBUFFET, 30s);
        events.ScheduleEvent(EVENT_FRENZY, 10s);
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
                case EVENT_SHADOWFLAME:
                    DoCastVictim(SPELL_SHADOWFLAME);
                    events.ScheduleEvent(EVENT_SHADOWFLAME, 10s, 20s);
                    break;
                case EVENT_WINGBUFFET:
                    DoCastVictim(SPELL_WINGBUFFET);
                    if (GetThreat(me->GetVictim()))
                        ModifyThreatByPercent(me->GetVictim(), -75);
                    events.ScheduleEvent(EVENT_WINGBUFFET, 30s);
                    break;
                case EVENT_FRENZY:
                    Talk(EMOTE_FRENZY);
                    DoCast(me, SPELL_FRENZY);
                    events.ScheduleEvent(EVENT_FRENZY, 8s, 10s);
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_flamegor()
{
    RegisterBlackwingLairCreatureAI(boss_flamegor);
}

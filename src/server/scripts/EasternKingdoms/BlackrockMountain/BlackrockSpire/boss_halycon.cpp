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
    SPELL_REND                      = 13738,
    SPELL_THRASH                    = 3391,
};

enum Says
{
    EMOTE_DEATH                     = 0
};

enum Events
{
    EVENT_REND                      = 1,
    EVENT_THRASH                    = 2,
};

const Position SummonLocation = { -167.9561f, -411.7844f, 76.23057f, 1.53589f };

struct boss_halycon : public BossAI
{
    boss_halycon(Creature* creature) : BossAI(creature, DATA_HALYCON)
    {
        Initialize();
    }

    void Initialize()
    {
        Summoned = false;
    }

    void Reset() override
    {
        _Reset();
        Initialize();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        events.ScheduleEvent(EVENT_REND, 17s, 20s);
        events.ScheduleEvent(EVENT_THRASH, 10s, 12s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->SummonCreature(NPC_GIZRUL_THE_SLAVENER, SummonLocation, TEMPSUMMON_TIMED_DESPAWN, 5min);
        Talk(EMOTE_DEATH);

        Summoned = true;
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
                case EVENT_REND:
                    DoCastVictim(SPELL_REND);
                    events.ScheduleEvent(EVENT_REND, 8s, 10s);
                    break;
                case EVENT_THRASH:
                    DoCast(me, SPELL_THRASH);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
    private:
        bool Summoned;
};

void AddSC_boss_halycon()
{
    RegisterBlackrockSpireCreatureAI(boss_halycon);
}

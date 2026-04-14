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

/*
 * Timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "blood_furnace.h"
#include "Player.h"
#include "ScriptedCreature.h"

enum MakerTexts
{
    SAY_AGGRO                   = 0,
    SAY_SLAY                    = 1,
    SAY_DEATH                   = 2
};

enum MakerSpells
{
    SPELL_DOMINATION            = 30923,
    SPELL_EXPLODING_BEAKER      = 30925,
    SPELL_EXPLODING_BEAKER_H    = 40059
};

enum MakerEvents
{
    EVENT_DOMINATION            = 1,
    EVENT_EXPLODING_BEAKER
};

// 17381 - The Maker
struct boss_the_maker : public BossAI
{
    boss_the_maker(Creature* creature) : BossAI(creature, DATA_THE_MAKER) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_EXPLODING_BEAKER, 5s, 15s);
        events.ScheduleEvent(EVENT_DOMINATION, 20s, 30s);
    }

    uint8 GetEngagedPlayersCount()
    {
        uint8 count = 0;

        for (ThreatReference const* ref : me->GetThreatManager().GetUnsortedThreatList())
            if (Player* player = ref->GetVictim()->ToPlayer())
                ++count;

        return count;
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_DOMINATION:
                if (GetEngagedPlayersCount() > 1)
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true))
                        DoCast(target, SPELL_DOMINATION);
                events.Repeat(20s, 30s);
                break;
            case EVENT_EXPLODING_BEAKER:
                DoCastVictim(DUNGEON_MODE(SPELL_EXPLODING_BEAKER, SPELL_EXPLODING_BEAKER_H));
                events.Repeat(10s, 20s);
                break;
            default:
                break;
        }
    }
};

void AddSC_boss_the_maker()
{
    RegisterBloodFurnaceCreatureAI(boss_the_maker);
}

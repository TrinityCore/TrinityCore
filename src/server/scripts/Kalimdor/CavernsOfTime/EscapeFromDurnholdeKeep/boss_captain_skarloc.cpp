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

/* Missing adds, missing waypoints to move up to Thrall once spawned + speech before enter combat */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "old_hillsbrad.h"

enum SkarlocTexts
{
    SAY_ENTER                   = 0,
    SAY_TAUNT1                  = 1,
    SAY_TAUNT2                  = 2,
    SAY_SLAY                    = 3,
    SAY_DEATH                   = 4,
};

enum SkarlocSpells
{
    SPELL_HOLY_LIGHT            = 29427,
    SPELL_CLEANSE               = 29380,
    SPELL_HAMMER_OF_JUSTICE     = 13005,
    SPELL_HOLY_SHIELD           = 31904,
    SPELL_DEVOTION_AURA         = 8258,
    SPELL_CONSECRATION          = 38385
};

enum SkarlocEvents
{
    EVENT_HOLY_LIGHT            = 1,
    EVENT_CLEANSE,
    EVENT_HAMMER_OF_JUSTICE,
    EVENT_HOLY_SHIELD,
    EVENT_DEVOTION_AURA,
    EVENT_CONSECRATION
};

// 17862 - Captain Skarloc
struct boss_captain_skarloc : public BossAI
{
    boss_captain_skarloc(Creature* creature) : BossAI(creature, DATA_CAPTAIN_SKARLOC) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        //This is not correct. Should taunt Thrall before engage in combat
        Talk(SAY_TAUNT1);
        Talk(SAY_TAUNT2);
        events.ScheduleEvent(EVENT_HOLY_LIGHT, 20s, 30s);
        events.ScheduleEvent(EVENT_CLEANSE, 10s);
        events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE, 20s, 35s);
        events.ScheduleEvent(EVENT_HOLY_SHIELD, 240s);
        events.ScheduleEvent(EVENT_DEVOTION_AURA, 3s);
        events.ScheduleEvent(EVENT_CONSECRATION, 8s);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        Talk(SAY_DEATH);

        instance->SetData(TYPE_THRALL_EVENT, OH_ESCORT_HORSE_RIDE);
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
                case EVENT_HOLY_LIGHT:
                    DoCastSelf(SPELL_HOLY_LIGHT);
                    events.Repeat(30s);
                    break;
                case EVENT_CLEANSE:
                    DoCastSelf(SPELL_CLEANSE);
                    events.Repeat(10s);
                    break;
                case EVENT_HAMMER_OF_JUSTICE:
                    DoCastVictim(SPELL_HAMMER_OF_JUSTICE);
                    events.Repeat(60s);
                    break;
                case EVENT_HOLY_SHIELD:
                    DoCastSelf(SPELL_HOLY_SHIELD);
                    events.Repeat(240s);
                    break;
                case EVENT_DEVOTION_AURA:
                    DoCastSelf(SPELL_DEVOTION_AURA);
                    events.Repeat(45s, 55s);
                    break;
                case EVENT_CONSECRATION:
                    DoCastSelf(SPELL_CONSECRATION);
                    events.Repeat(5s, 10s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_captain_skarloc()
{
    RegisterOldHillsbradCreatureAI(boss_captain_skarloc);
}

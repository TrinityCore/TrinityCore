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
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Yells
{
    SAY_AGGRO = 0
};

enum Spells
{
    SPELL_BATTLE_SHOUT  = 77808,
    SPELL_BLOODLUST     = 6742
};

enum Events
{
    EVENT_BATTLE_SHOUT = 1,
    EVENT_BLOODLUST
};

enum SpawnGroups
{
    SPAWN_GROUP_ID_HOUNDS = 433
};

struct boss_houndmaster_loksey : public BossAI
{
    boss_houndmaster_loksey(Creature* creature) : BossAI(creature, DATA_HOUNDMASTER_LOKSEY) { }

    void Reset() override
    {
       BossAI::Reset();

       // The dogs will respawn after a wipe
       instance->instance->SpawnGroupSpawn(SPAWN_GROUP_ID_HOUNDS, true);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_BATTLE_SHOUT, 7s);
        events.ScheduleEvent(EVENT_BLOODLUST, 10s);
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
                case EVENT_BATTLE_SHOUT:
                    DoCastAOE(SPELL_BATTLE_SHOUT);
                    events.Repeat(17s, 20s);
                    break;
                case EVENT_BLOODLUST:
                    if (Creature* hound = me->FindNearestCreature(NPC_SCARLET_TRACKING_HOUND, 10.f, true))
                        DoCast(hound, SPELL_BLOODLUST);
                    events.Repeat(46s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_houndmaster_loksey()
{
    RegisterScarletMonasteryCreatureAI(boss_houndmaster_loksey);
}

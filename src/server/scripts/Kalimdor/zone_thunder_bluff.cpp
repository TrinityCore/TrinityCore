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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"

enum CairneBloodhoof
{
    SAY_EVADE               = 0,

    SPELL_CLEAVE            = 15284,
    SPELL_MORTAL_STRIKE     = 16856,
    SPELL_THUNDERCLAP       = 23931,
    SPELL_UPPERCUT          = 22916,
    SPELL_WAR_STOMP         = 59705,

    SPELL_CAIRNES_HOOFPRINT = 23123,

    EVENT_CLEAVE            = 1,
    EVENT_MORTAL_STRIKE     = 2,
    EVENT_THUNDERCLAP       = 3,
    EVENT_UPPERCUT          = 4,
    EVENT_WAR_STOMP         = 5,

    SOUND_AGGRO             = 5884
};

// 3057 - Cairne Bloodhoof
struct npc_cairne_bloodhoof : public ScriptedAI
{
    npc_cairne_bloodhoof(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoPlaySoundToSet(me, SOUND_AGGRO);

        _events.ScheduleEvent(EVENT_CLEAVE, 5s, 10s);
        _events.ScheduleEvent(EVENT_MORTAL_STRIKE, 10s, 15s);
        _events.ScheduleEvent(EVENT_THUNDERCLAP, 15s, 20s);
        _events.ScheduleEvent(EVENT_UPPERCUT, 10s, 20s);
        _events.ScheduleEvent(EVENT_WAR_STOMP, 25s, 30s);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        Talk(SAY_EVADE);
        ScriptedAI::EnterEvadeMode(why);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    _events.Repeat(5s, 10s);
                    break;
                case EVENT_MORTAL_STRIKE:
                    DoCastVictim(SPELL_MORTAL_STRIKE);
                    _events.Repeat(10s, 15s);
                    break;
                case EVENT_THUNDERCLAP:
                    DoCastSelf(SPELL_THUNDERCLAP);
                    _events.Repeat(15s, 20s);
                    break;
                case EVENT_UPPERCUT:
                    DoCastVictim(SPELL_UPPERCUT);
                    _events.Repeat(20s, 25s);
                    break;
                case EVENT_WAR_STOMP:
                    DoCastSelf(SPELL_WAR_STOMP);
                    _events.Repeat(25s, 30s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        DoCast(player, SPELL_CAIRNES_HOOFPRINT);
        return false;
    }

private:
    EventMap _events;
};

void AddSC_thunder_bluff()
{
    RegisterCreatureAI(npc_cairne_bloodhoof);
}

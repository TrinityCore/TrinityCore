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
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "npc_pet_sha_".
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum ShamanSpells
{
    SPELL_SHAMAN_ANGEREDEARTH   = 36213,
    SPELL_SHAMAN_FIREBLAST      = 57984,
    SPELL_SHAMAN_FIRENOVA       = 12470,
    SPELL_SHAMAN_FIRESHIELD     = 13376
};

enum ShamanEvents
{
    // Earth Elemental
    EVENT_SHAMAN_ANGEREDEARTH   = 1,
    // Fire Elemental
    EVENT_SHAMAN_FIRENOVA       = 1,
    EVENT_SHAMAN_FIRESHIELD     = 2,
    EVENT_SHAMAN_FIREBLAST      = 3
};

struct npc_pet_shaman_earth_elemental : public ScriptedAI
{
    npc_pet_shaman_earth_elemental(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_SHAMAN_ANGEREDEARTH, 0s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (_events.ExecuteEvent() == EVENT_SHAMAN_ANGEREDEARTH)
        {
            DoCastVictim(SPELL_SHAMAN_ANGEREDEARTH);
            _events.ScheduleEvent(EVENT_SHAMAN_ANGEREDEARTH, 5s, 20s);
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

struct npc_pet_shaman_fire_elemental : public ScriptedAI
{
    npc_pet_shaman_fire_elemental(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_SHAMAN_FIRENOVA, 5s, 20s);
        _events.ScheduleEvent(EVENT_SHAMAN_FIREBLAST, 5s, 20s);
        _events.ScheduleEvent(EVENT_SHAMAN_FIRESHIELD, 0s);
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
                case EVENT_SHAMAN_FIRENOVA:
                    DoCastVictim(SPELL_SHAMAN_FIRENOVA);
                    _events.ScheduleEvent(EVENT_SHAMAN_FIRENOVA, 5s, 20s);
                    break;
                case EVENT_SHAMAN_FIRESHIELD:
                    DoCastVictim(SPELL_SHAMAN_FIRESHIELD);
                    _events.ScheduleEvent(EVENT_SHAMAN_FIRESHIELD, 2s);
                    break;
                case EVENT_SHAMAN_FIREBLAST:
                    DoCastVictim(SPELL_SHAMAN_FIREBLAST);
                    _events.ScheduleEvent(EVENT_SHAMAN_FIREBLAST, 5s, 20s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

void AddSC_shaman_pet_scripts()
{
    RegisterCreatureAI(npc_pet_shaman_earth_elemental);
    RegisterCreatureAI(npc_pet_shaman_fire_elemental);
}

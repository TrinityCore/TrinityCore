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
  * Scriptnames of files in this file should be prefixed with "npc_pet_pal_".
  */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum PaladinSpells
{
    SPELL_PALADIN_LIGHT_HAMMER_VISUAL       = 122257,
    SPELL_PALADIN_LIGHT_HAMMER_PERIODIC     = 114918
};

enum PaladinEvents
{
    EVENT_PALADIN_LIGHT_HAMMER_PERIODIC     = 1
};

// Light's Hammer - 59738
struct npc_pet_pal_light_hammer : public ScriptedAI
{
    npc_pet_pal_light_hammer(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_PALADIN_LIGHT_HAMMER_VISUAL);

        _events.ScheduleEvent(EVENT_PALADIN_LIGHT_HAMMER_PERIODIC, 2s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_PALADIN_LIGHT_HAMMER_PERIODIC:
                    DoCastSelf(SPELL_PALADIN_LIGHT_HAMMER_PERIODIC);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

void AddSC_paladin_pet_scripts()
{
    RegisterCreatureAI(npc_pet_pal_light_hammer);
}

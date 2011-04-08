/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2011 gmlt.A
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

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "operation_gnomeregan.h"

class npc_og_mekkatorque : public CreatureScript
{
public:
    npc_og_mekkatorque() : CreatureScript("npc_og_mekkatorque") { }

    struct npc_og_mekkatorqueAI : public npc_escortAI
    {
        npc_og_mekkatorqueAI(Creature* pCreature) : npc_escortAI(pCreature) { }

        void Reset()
        {
        }

        void WaypointReached(uint32 i)
        {
            switch (i)
            {
                case 1:
                    break;
            }
        }

        void UpdateAI(const uint32 diff)
        {
            npc_escortAI::UpdateAI(diff);
        }
    };

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_OPERATION_GNOMEREGAN)
        {

        }
        return true;
    }

    CreatureAI *GetAI(Creature *creature) const
    {
        return new npc_og_mekkatorqueAI(creature);
    }
};

void AddSC_operation_gnomeregan()
{
    new npc_og_mekkatorque;
}

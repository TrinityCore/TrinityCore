/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Burning_Steppes
SD%Complete: 100
SDComment: Quest support: 4866
SDCategory: Burning Steppes
EndScriptData */

/* ContentData
npc_ragged_john
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"

/*######
## npc_ragged_john
######*/

enum RaggedJohn
{
    QUEST_MOTHERS_MILK         = 4866,
    SPELL_MOTHERS_MILK         = 16468,
    SPELL_WICKED_MILKING       = 16472
};

class npc_ragged_john : public CreatureScript
{
public:
    npc_ragged_john() : CreatureScript("npc_ragged_john") { }

    struct npc_ragged_johnAI : public ScriptedAI
    {
        npc_ragged_johnAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override { }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->HasAura(SPELL_MOTHERS_MILK))
            {
                if (who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 15) && who->isInAccessiblePlaceFor(me))
                {
                    DoCast(who, SPELL_WICKED_MILKING);
                    if (Player* player = who->ToPlayer())
                        player->AreaExploredOrEventHappens(QUEST_MOTHERS_MILK);
                }
            }

            ScriptedAI::MoveInLineOfSight(who);
        }

        void EnterCombat(Unit* /*who*/) override { }
    };

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (creature->IsQuestGiver())
        {
            player->PrepareQuestMenu(creature->GetGUID());
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ragged_johnAI(creature);
    }
};

void AddSC_burning_steppes()
{
    new npc_ragged_john();
}

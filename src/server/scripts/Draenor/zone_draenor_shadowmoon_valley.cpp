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

#include "PhasingHandler.h"
#include "Player.h"
#include "QuestDef.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellScript.h"

// 79243 - Baros Alexston
enum BarosAlexstonMisc
{
    // Quest
    QUEST_ESTABLISH_YOUR_GARRISON                    = 34586,

    // Gossip
    GOSSIP_OPTION_ESTABLISH_GARRISON                 = 0,

    // Text
    SAY_START_CONSTRUCTION                           = 0,

    // Spells
    SPELL_QUEST_34586_KILLCREDIT                     = 161033,
    SPELL_CREATE_GARRISON_SHADOWMOON_VALLEY_ALLIANCE = 156020,
    SPELL_DESPAWN_ALL_SUMMONS_GARRISON_INTRO_ONLY    = 160938
};

Position const GarrisonLevelOneCreationPlayerPosition = { 1904.58f, 312.906f, 88.9542f, 4.303615f };

struct npc_baros_alexston : public ScriptedAI
{
    npc_baros_alexston(Creature* creature) : ScriptedAI(creature) { }

    bool OnGossipSelect(Player* player, uint32 /*menuId*/, uint32 gossipListId) override
    {
        if (gossipListId == GOSSIP_OPTION_ESTABLISH_GARRISON)
        {
            CloseGossipMenuFor(player);
            player->CastSpell(player, SPELL_QUEST_34586_KILLCREDIT, true);
            player->CastSpell(player, SPELL_CREATE_GARRISON_SHADOWMOON_VALLEY_ALLIANCE, true);
            player->CastSpell(player, SPELL_DESPAWN_ALL_SUMMONS_GARRISON_INTRO_ONLY, true);
            player->NearTeleportTo(GarrisonLevelOneCreationPlayerPosition);

            PhasingHandler::OnConditionChange(player);
        }

        return true;
    }

    void OnQuestAccept(Player* player , Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_ESTABLISH_YOUR_GARRISON)
            Talk(SAY_START_CONSTRUCTION, player);
    }
};

void AddSC_draenor_shadowmoon_valley()
{
    RegisterCreatureAI(npc_baros_alexston);
};

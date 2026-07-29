/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
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
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Creature.h"
#include "Object.h"
#include "SharedDefines.h"

#include "GenAI_npc_memory.h"
#include "GenAI_chat_prompts.h"
#include "Followship_bots_npc_chat_manager.h"
#include "Followship_bots_config.h"

class followship_npcs_player : public PlayerScript
{
public:
    followship_npcs_player() : PlayerScript("followship_npcs_player") { }

    void OnChat(Player* player, uint32 type, uint32 /*lang*/, std::string& msg) override
    {
        if (!player)
            return;

        if (type != CHAT_MSG_SAY)
            return;

        if (!msg.empty() && msg[0] == '.')
            return;

        if (!FollowshipBotsConfig::configFSBGenAIEnabled)
            return;

        std::vector<Creature*> nearby;
        FindCreatureOptions opts;
        opts.IsAlive = FindCreatureAliveState::Alive;
        player->GetCreatureListWithOptionsInGrid(nearby, 5.0f, opts);

        Creature* npc = nullptr;
        for (Creature* candidate : nearby)
        {
            if (candidate->IsFriendlyTo(player))
            {
                npc = candidate;
                break;
            }
        }

        if (!npc || npc->GetCreatureType() != CREATURE_TYPE_HUMANOID)
            return;

        GenAINpcMemoryMgr::Get()->AddEntry(npc->GetGUID(), CHAT_MSG_SAY, player->GetName(), msg, true);

        std::deque<BotChatMemoryEntry> memoryCopy = GenAINpcMemoryMgr::Get()->GetMemory(npc->GetGUID());

        FSBNpcPrompts::NpcChatContext ctx = FSBNpcPrompts::BuildNpcContext(npc, player);
        FSBNpcPrompts::PlayerSnapshot playerSnap = FSBNpcPrompts::BuildPlayerSnapshot(player);

        FSBNpcChatMgr::Get()->AddPendingReply(
            npc->GetGUID(),
            player->GetGUID(),
            playerSnap.name,
            ctx,
            playerSnap,
            msg,
            std::move(memoryCopy));
    }
};

void AddSC_followship_npcs_player()
{
    new followship_npcs_player();
}

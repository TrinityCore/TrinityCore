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

#include "Group.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Unit.h"
#include "Channel.h"

#include "Followship_bots_db.h"
#include "Followship_bots_mgr.h"
#include "Followship_bots_chat_handler.h"
#include "Followship_bots.h"
#include "Followship_bots_priest.h"
#include "Followship_bots_party_handler.h"

#include "Followship_bots_death_handler.h"
#include "Followship_bots_group_handler.h"

class followship_bots_player : public PlayerScript
{
public:
    followship_bots_player() : PlayerScript("followship_bots_player") { }

    void OnLogin(Player* player, bool /*firstLogin*/) override
    {
        FSBMgr::Get()->SyncBotPhasingWithOwner(player);
        FSBMgr::Get()->UpdateHiredBotCount(player);
    }

    void OnMapChanged(Player* player) override
    {
        FSBMgr::Get()->RemovePersistentExpiredPlayerBots(player);
        FSBMgr::Get()->SpawnPlayerBots(player);
        FSBMgr::Get()->UpdateHiredBotCount(player);
    }

    void OnPhaseChange(Player* player) override
    {
        TC_LOG_DEBUG("scripts.fsb.player", "FSB: OnPhaseChange called for player {}", player->GetName());
        FSBMgr::Get()->SyncBotPhasingWithOwner(player);
    }

    void OnChat(Player* player, uint32 /*type*/, uint32 /*lang*/, std::string& msg, Channel* channel) override
    {
        if (!player || !channel)
            return;

        if (channel->GetChannelId() != 1)
            return;

        if (!msg.empty() && msg[0] == '.')
            return;

        FSBChatMgr::Get()->HandlePlayerGeneralChat(player, channel, msg);
    }

    void OnPlayerDeath(Player* player) override
    {
        if (!player)
            return;

        Unit* healer = nullptr;
        auto botsPtr = FSBMgr::Get()->GetPersistentBotsForPlayer(player);
        if (botsPtr)
        {
            for (auto const& botData : *botsPtr)
            {
                if (botData.runtimeGuid.IsEmpty())
                    continue;

                if (Unit* botUnit = ObjectAccessor::GetUnit(*player, botData.runtimeGuid))
                {
                    if (botUnit->IsInWorld() && !botUnit->IsDuringRemoveFromWorld() && botUnit->IsAlive() &&
                        FSBUtils::BotIsHealerClass(botUnit->ToCreature()))
                    {
                        healer = botUnit;
                        break;
                    }
                }
            }
        }

        if (healer)
        {
            TC_LOG_DEBUG("scripts.fsb.death", "FSB: Player {} died, found healer: {}", player->GetName(), healer->GetName());
            FSBDeath::AddToHealerResurrectQueue(player, healer->ToCreature());
        }
    }

};

// GroupScript to re-inject bot data when the real group changes
class followship_bots_group : public GroupScript
{
public:
    followship_bots_group() : GroupScript("followship_bots_group") { }

    void OnAddMember(Group* group, ObjectGuid guid) override
    {
        FSBParty::OnMemberAdd(group, guid);
    }

    void OnRemoveMember(Group* group, ObjectGuid guid, RemoveMethod /*method*/, ObjectGuid /*kicker*/, char const* /*reason*/) override
    {
        FSBParty::OnMemberRemove(group, guid);
    }
};

void AddSC_followship_bots_player()
{
    new followship_bots_player();
    new followship_bots_group();
}

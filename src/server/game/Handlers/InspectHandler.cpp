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

#include "WorldSession.h"
#include "AchievementMgr.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "InspectPackets.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "World.h"

void WorldSession::HandleInspectOpcode(WorldPackets::Inspect::Inspect& inspect)
{
    Player* player = ObjectAccessor::GetPlayer(*_player, inspect.Target);
    if (!player)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleInspectOpcode: Target {} not found.", inspect.Target.ToString());
        return;
    }

    TC_LOG_DEBUG("network", "WorldSession::HandleInspectOpcode: Target {}.", inspect.Target.ToString());

    if (!GetPlayer()->IsWithinDistInMap(player, INSPECT_DISTANCE, false))
        return;

    if (GetPlayer()->IsValidAttackTarget(player))
        return;

    WorldPackets::Inspect::InspectResult inspectResult;
    inspectResult.DisplayInfo.Initialize(player);

    if (GetPlayer()->CanBeGameMaster() || sWorld->getIntConfig(CONFIG_TALENTS_INSPECTING) + (GetPlayer()->GetEffectiveTeam() == player->GetEffectiveTeam()) > 1)
    {
        PlayerTalentMap const* talents = player->GetTalentMap(player->GetActiveTalentGroup());
        for (PlayerTalentMap::value_type const& v : *talents)
            if (v.second != PLAYERSPELL_REMOVED)
                inspectResult.Talents.push_back(v.first);

        PlayerPvpTalentMap const& pvpTalents = player->GetPvpTalentMap(player->GetActiveTalentGroup());
        for (std::size_t i = 0; i < pvpTalents.size(); ++i)
            inspectResult.PvpTalents[i] = pvpTalents[i];

        inspectResult.TalentTraits.Level = player->GetLevel();
        inspectResult.TalentTraits.ChrSpecializationID = AsUnderlyingType(player->GetPrimarySpecialization());
        if (UF::TraitConfig const* traitConfig = player->GetTraitConfig(player->m_activePlayerData->ActiveCombatTraitConfigID))
            inspectResult.TalentTraits.Config = WorldPackets::Traits::TraitConfig(*traitConfig);
    }

    if (Guild* guild = sGuildMgr->GetGuildById(player->GetGuildId()))
    {
        inspectResult.GuildData.emplace();
        inspectResult.GuildData->GuildGUID = guild->GetGUID();
        inspectResult.GuildData->NumGuildMembers = guild->GetMembersCount();
        inspectResult.GuildData->AchievementPoints = guild->GetAchievementMgr().GetAchievementPoints();
    }

    inspectResult.ItemLevel = int32(player->GetAverageItemLevel());
    inspectResult.LifetimeMaxRank = player->m_activePlayerData->LifetimeMaxRank;
    inspectResult.TodayHK = player->m_activePlayerData->TodayHonorableKills;
    inspectResult.YesterdayHK = player->m_activePlayerData->YesterdayHonorableKills;
    inspectResult.LifetimeHK = player->m_activePlayerData->LifetimeHonorableKills;
    inspectResult.HonorLevel = player->m_playerData->HonorLevel;

    SendPacket(inspectResult.Write());
}

void WorldSession::HandleQueryInspectAchievements(WorldPackets::Inspect::QueryInspectAchievements& inspect)
{
    Player* player = ObjectAccessor::GetPlayer(*_player, inspect.Guid);
    if (!player)
    {
        TC_LOG_DEBUG("network", "WorldSession::HandleQueryInspectAchievements: [{}] inspected unknown Player [{}]", GetPlayer()->GetGUID().ToString(), inspect.Guid.ToString());
        return;
    }

    TC_LOG_DEBUG("network", "WorldSession::HandleQueryInspectAchievements: [{}] inspected Player [{}]", GetPlayer()->GetGUID().ToString(), inspect.Guid.ToString());

    if (!GetPlayer()->IsWithinDistInMap(player, INSPECT_DISTANCE, false))
        return;

    if (GetPlayer()->IsValidAttackTarget(player))
        return;

    player->SendRespondInspectAchievements(GetPlayer());
}

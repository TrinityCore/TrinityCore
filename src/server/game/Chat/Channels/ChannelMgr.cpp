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

#include "ChannelMgr.h"
#include "Channel.h"
#include "ChannelPackets.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "Log.h"
#include "Player.h"
#include "RealmList.h"
#include "World.h"
#include "WorldSession.h"

AreaTableEntry const* ChannelMgr::SpecialLinkedArea;

ChannelMgr::~ChannelMgr()
{
    for (auto itr = _channels.begin(); itr != _channels.end(); ++itr)
        delete itr->second;

    for (auto itr = _customChannels.begin(); itr != _customChannels.end(); ++itr)
        delete itr->second;
}

/*static*/ void ChannelMgr::LoadFromDB()
{
    SpecialLinkedArea = sAreaTableStore.AssertEntry(3459);
    ASSERT(SpecialLinkedArea->GetFlags().HasFlag(AreaFlags::LinkedChatSpecialArea));

    if (!sWorld->getBoolConfig(CONFIG_PRESERVE_CUSTOM_CHANNELS))
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 custom chat channels. Custom channel saving is disabled.");
        return;
    }

    uint32 oldMSTime = getMSTime();
    if (uint32 days = sWorld->getIntConfig(CONFIG_PRESERVE_CUSTOM_CHANNEL_DURATION))
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_OLD_CHANNELS);
        stmt->setUInt32(0, days * DAY);
        CharacterDatabase.Execute(stmt);
    }

    QueryResult result = CharacterDatabase.Query("SELECT name, team, announce, ownership, password, bannedList FROM channels");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 custom chat channels. DB table `channels` is empty.");
        return;
    }

    std::vector<std::pair<std::string, uint32>> toDelete;
    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();
        std::string dbName = fields[0].GetString();
        Team team = Team(fields[1].GetUInt32());
        bool dbAnnounce = fields[2].GetBool();
        bool dbOwnership = fields[3].GetBool();
        std::string dbPass = fields[4].GetString();
        std::string dbBanned = fields[5].GetString();

        std::wstring channelName;
        if (!Utf8toWStr(dbName, channelName))
        {
            TC_LOG_ERROR("server.loading", "Failed to load custom chat channel '{}' from database - invalid utf8 sequence? Deleted.", dbName);
            toDelete.push_back({ dbName, team });
            continue;
        }

        ChannelMgr* mgr = ForTeam(team);
        if (!mgr)
        {
            TC_LOG_ERROR("server.loading", "Failed to load custom chat channel '{}' from database - invalid team {}. Deleted.", dbName, team);
            toDelete.push_back({ dbName, team });
            continue;
        }

        Channel* channel = new Channel(mgr->CreateCustomChannelGuid(), dbName, team, dbBanned);
        channel->SetAnnounce(dbAnnounce);
        channel->SetOwnership(dbOwnership);
        channel->SetPassword(dbPass);
        mgr->_customChannels.emplace(channelName, channel);

        ++count;
    } while (result->NextRow());

    for (std::pair<std::string, uint32> const& pair : toDelete)
    {
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHANNEL);
        stmt->setString(0, pair.first);
        stmt->setUInt32(1, pair.second);
        CharacterDatabase.Execute(stmt);
    }

    TC_LOG_INFO("server.loading", ">> Loaded {} custom chat channels in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

/*static*/ ChannelMgr* ChannelMgr::ForTeam(Team team)
{
    static ChannelMgr allianceChannelMgr(ALLIANCE);
    static ChannelMgr hordeChannelMgr(HORDE);
    static ChannelMgr neutralChannelMgr(PANDARIA_NEUTRAL);

    if (sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL))
        return &neutralChannelMgr;         // cross-faction

    switch (team)
    {
        case HORDE:
            return &hordeChannelMgr;
        case ALLIANCE:
            return &allianceChannelMgr;
        case PANDARIA_NEUTRAL:
            return &neutralChannelMgr;
        default:
            break;
    }

    return nullptr;
}

Channel* ChannelMgr::GetChannelForPlayerByNamePart(std::string const& namePart, Player* playerSearcher)
{
    std::wstring channelNamePart;
    if (!Utf8toWStr(namePart, channelNamePart))
        return nullptr;

    wstrToLower(channelNamePart);
    for (Channel* channel : playerSearcher->GetJoinedChannels())
    {
        std::string chanName = channel->GetName(playerSearcher->GetSession()->GetSessionDbcLocale());

        std::wstring channelNameW;
        if (!Utf8toWStr(chanName, channelNameW))
            continue;

        wstrToLower(channelNameW);
        if (!channelNameW.compare(0, channelNamePart.size(), channelNamePart))
            return channel;
    }

    return nullptr;
}

void ChannelMgr::SaveToDB()
{
    for (auto pair : _customChannels)
        pair.second->UpdateChannelInDB();
}

Channel* ChannelMgr::GetChannelForPlayerByGuid(ObjectGuid channelGuid, Player* playerSearcher)
{
    for (Channel* channel : playerSearcher->GetJoinedChannels())
        if (channel->GetGUID() == channelGuid)
            return channel;

    return nullptr;
}

Channel* ChannelMgr::GetSystemChannel(uint32 channelId, AreaTableEntry const* zoneEntry /* = nullptr */)
{
    ObjectGuid channelGuid = CreateBuiltinChannelGuid(channelId, zoneEntry);
    auto itr = _channels.find(channelGuid);
    if (itr != _channels.end())
        return itr->second;

    Channel* newChannel = new Channel(channelGuid, channelId, _team, zoneEntry);
    _channels[channelGuid] = newChannel;
    return newChannel;
}

Channel* ChannelMgr::CreateCustomChannel(std::string const& name)
{
    std::wstring channelName;
    if (!Utf8toWStr(name, channelName))
        return nullptr;

    wstrToLower(channelName);

    Channel*& c = _customChannels[channelName];
    if (c)
        return nullptr;

    Channel* newChannel = new Channel(CreateCustomChannelGuid(), name, _team);
    newChannel->SetDirty();

    c = newChannel;
    return newChannel;
}

Channel* ChannelMgr::GetCustomChannel(std::string const& name) const
{
    std::wstring channelName;
    if (!Utf8toWStr(name, channelName))
        return nullptr;

    wstrToLower(channelName);
    auto itr = _customChannels.find(channelName);
    if (itr != _customChannels.end())
        return itr->second;

    return nullptr;
}

Channel* ChannelMgr::GetChannel(uint32 channelId, std::string const& name, Player* player, bool notify /*= true*/, AreaTableEntry const* zoneEntry /*= nullptr*/) const
{
    Channel* result = nullptr;
    if (channelId) // builtin
    {
        auto itr = _channels.find(CreateBuiltinChannelGuid(channelId, zoneEntry));
        if (itr != _channels.end())
            result = itr->second;
    }
    else // custom
    {
        std::wstring channelName;
        if (!Utf8toWStr(name, channelName))
            return nullptr;

        wstrToLower(channelName);

        auto itr = _customChannels.find(channelName);
        if (itr != _customChannels.end())
            result = itr->second;
    }

    if (!result && notify)
    {
        std::string channelName = name;
        Channel::GetChannelName(channelName, channelId, player->GetSession()->GetSessionDbcLocale(), zoneEntry);

        SendNotOnChannelNotify(player, channelName);
    }

    return result;
}

void ChannelMgr::LeftChannel(uint32 channelId, AreaTableEntry const* zoneEntry)
{
    auto itr = _channels.find(CreateBuiltinChannelGuid(channelId, zoneEntry));
    if (itr == _channels.end())
        return;

    Channel* channel = itr->second;
    if (!channel->GetNumPlayers())
    {
        _channels.erase(itr);
        delete channel;
    }
}

void ChannelMgr::SendNotOnChannelNotify(Player const* player, std::string const& name)
{
    WorldPackets::Channel::ChannelNotify notify;
    notify.Type = CHAT_NOT_MEMBER_NOTICE;
    notify._Channel = name;
    player->SendDirectMessage(notify.Write());
}

ObjectGuid ChannelMgr::CreateCustomChannelGuid()
{
    return ObjectGuid::Create<HighGuid::ChatChannel>(false, false, 0, _team == ALLIANCE ? 3 : 5, _guidGenerator.Generate());
}

ObjectGuid ChannelMgr::CreateBuiltinChannelGuid(uint32 channelId, AreaTableEntry const* zoneEntry /*= nullptr*/) const
{
    ChatChannelsEntry const* channelEntry = sChatChannelsStore.AssertEntry(channelId);
    uint32 zoneId = 0;
    if (zoneEntry && channelEntry->GetFlags().HasFlag(ChatChannelFlags::ZoneBased) && !channelEntry->GetFlags().HasFlag(ChatChannelFlags::LinkedChannel))
        zoneId = zoneEntry->ID;

    if (channelEntry->GetFlags().HasFlag(ChatChannelFlags::GlobalForTournament))
        if (std::shared_ptr<Realm const> currentRealm = sRealmList->GetCurrentRealm())
            if (Cfg_CategoriesEntry const* category = sCfgCategoriesStore.LookupEntry(currentRealm->Timezone))
                if (category->GetFlags().HasFlag(CfgCategoriesFlags::Tournament))
                    zoneId = 0;

    return ObjectGuid::Create<HighGuid::ChatChannel>(true, channelEntry->GetFlags().HasFlag(ChatChannelFlags::LinkedChannel), zoneId, _team == ALLIANCE ? 3 : 5, channelId);
}

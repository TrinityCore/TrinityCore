/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Channel.h"
#include "Chat.h"
#include "ObjectMgr.h"
#include "SocialMgr.h"
#include "World.h"
#include "DatabaseEnv.h"
#include "AccountMgr.h"
#include "Player.h"

Channel::Channel(std::string const& name, uint32 channelId, uint32 team):
    _announce(true),
    _ownership(true),
    _IsSaved(false),
    _flags(0),
    _channelId(channelId),
    _Team(team),
    _ownerGUID(0),
    _name(name),
    _password("")
{
    // set special flags if built-in channel
    if (ChatChannelsEntry const* ch = sChatChannelsStore.LookupEntry(channelId)) // check whether it's a built-in channel
    {
        _announce = false;                                 // no join/leave announces
        _ownership = false;                                // no ownership handout

        _flags |= CHANNEL_FLAG_GENERAL;                    // for all built-in channels

        if (ch->flags & CHANNEL_DBC_FLAG_TRADE)             // for trade channel
            _flags |= CHANNEL_FLAG_TRADE;

        if (ch->flags & CHANNEL_DBC_FLAG_CITY_ONLY2)        // for city only channels
            _flags |= CHANNEL_FLAG_CITY;

        if (ch->flags & CHANNEL_DBC_FLAG_LFG)               // for LFG channel
            _flags |= CHANNEL_FLAG_LFG;
        else                                                // for all other channels
            _flags |= CHANNEL_FLAG_NOT_LFG;
    }
    else                                                    // it's custom channel
    {
        _flags |= CHANNEL_FLAG_CUSTOM;

        // If storing custom channels in the db is enabled either load or save the channel
        if (sWorld->getBoolConfig(CONFIG_PRESERVE_CUSTOM_CHANNELS))
        {
            PreparedStatement *stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHANNEL);
            stmt->setString(0, name);
            stmt->setUInt32(1, _Team);
            PreparedQueryResult result = CharacterDatabase.Query(stmt);

            if (result) //load
            {
                Field* fields = result->Fetch();
                _announce = fields[0].GetBool();
                _ownership = fields[1].GetBool();
                _password  = fields[2].GetString();
                const char* db_BannedList = fields[3].GetCString();

                if (db_BannedList)
                {
                    Tokenizer tokens(db_BannedList, ' ');
                    for (Tokenizer::const_iterator i = tokens.begin(); i != tokens.end(); ++i)
                    {
                        uint64 banned_guid = atol(*i);
                        if (banned_guid)
                        {
                            sLog->outDebug(LOG_FILTER_CHATSYS, "Channel(%s) loaded bannedStore guid:" UI64FMTD "", name.c_str(), banned_guid);
                            bannedStore.insert(banned_guid);
                        }
                    }
                }
            }
            else // save
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHANNEL);
                stmt->setString(0, name);
                stmt->setUInt32(1, _Team);
                CharacterDatabase.Execute(stmt);
                sLog->outDebug(LOG_FILTER_CHATSYS, "Channel(%s) saved in database", name.c_str());
            }

            _IsSaved = true;
        }
    }
}

void Channel::UpdateChannelInDB() const
{
    if (_IsSaved)
    {
        std::ostringstream banlist;
        BannedContainer::const_iterator iter;
        for (iter = bannedStore.begin(); iter != bannedStore.end(); ++iter)
            banlist << (*iter) << ' ';

        std::string banListStr = banlist.str();

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHANNEL);
        stmt->setBool(0, _announce);
        stmt->setBool(1, _ownership);
        stmt->setString(2, _password);
        stmt->setString(3, banListStr);
        stmt->setString(4, _name);
        stmt->setUInt32(5, _Team);
        CharacterDatabase.Execute(stmt);

        sLog->outDebug(LOG_FILTER_CHATSYS, "Channel(%s) updated in database", _name.c_str());
    }
}

void Channel::UpdateChannelUseageInDB() const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHANNEL_USAGE);
    stmt->setString(0, _name);
    stmt->setUInt32(1, _Team);
    CharacterDatabase.Execute(stmt);
}

void Channel::CleanOldChannelsInDB()
{
    if (sWorld->getIntConfig(CONFIG_PRESERVE_CUSTOM_CHANNEL_DURATION) > 0)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_OLD_CHANNELS);
        stmt->setUInt32(0, sWorld->getIntConfig(CONFIG_PRESERVE_CUSTOM_CHANNEL_DURATION) * DAY);
        CharacterDatabase.Execute(stmt);

        sLog->outDebug(LOG_FILTER_CHATSYS, "Cleaned out unused custom chat channels.");
    }
}

void Channel::JoinChannel(Player* player, std::string const& pass)
{
    uint64 guid = player->GetGUID();
    if (IsOn(guid))
    {
        // Do not send error message for built-in channels
        if (!IsConstant())
        {
            WorldPacket data;
            MakePlayerAlreadyMember(&data, guid);
            SendToOne(&data, guid);
        }
        return;
    }

    if (IsBanned(guid))
    {
        WorldPacket data;
        MakeBanned(&data);
        SendToOne(&data, guid);
        return;
    }

    if (!_password.empty() && pass != _password)
    {
        WorldPacket data;
        MakeWrongPassword(&data);
        SendToOne(&data, guid);
        return;
    }

    if (HasFlag(CHANNEL_FLAG_LFG) &&
        sWorld->getBoolConfig(CONFIG_RESTRICTED_LFG_CHANNEL) &&
        AccountMgr::IsPlayerAccount(player->GetSession()->GetSecurity()) &&
        player->GetGroup())
    {
        WorldPacket data;
        MakeNotInLfg(&data);
        SendToOne(&data, guid);
        return;
    }

    player->JoinedChannel(this);

    if (_announce && (!AccountMgr::IsGMAccount(player->GetSession()->GetSecurity()) ||
                       !sWorld->getBoolConfig(CONFIG_SILENTLY_GM_JOIN_TO_CHANNEL)))
    {
        WorldPacket data;
        MakeJoined(&data, guid);
        SendToAll(&data);
    }

    PlayerInfo pinfo;
    pinfo.player = guid;
    pinfo.flags = MEMBER_FLAG_NONE;
    playersStore[guid] = pinfo;

    WorldPacket data;
    MakeYouJoined(&data);
    SendToOne(&data, guid);

    JoinNotify(guid);

    // Custom channel handling
    if (!IsConstant())
    {
        // Update last_used timestamp in db
        if (!playersStore.empty())
            UpdateChannelUseageInDB();

        // If the channel has no owner yet and ownership is allowed, set the new owner.
        if (!_ownerGUID && _ownership)
        {
            SetOwner(guid, playersStore.size() > 1);
            playersStore[guid].SetModerator(true);
        }
    }
}

void Channel::LeaveChannel(Player* player, bool send)
{
    uint64 guid = player->GetGUID();
    if (!IsOn(guid))
    {
        if (send)
        {
            WorldPacket data;
            MakeNotMember(&data);
            SendToOne(&data, guid);
        }
        return;
    }

    if (send)
    {
        WorldPacket data;
        MakeYouLeft(&data);
        SendToOne(&data, guid);
        player->LeftChannel(this);
        data.clear();
    }

    bool changeowner = playersStore[guid].IsOwner();

    playersStore.erase(guid);
    if (_announce && (!AccountMgr::IsGMAccount(player->GetSession()->GetSecurity()) ||
                       !sWorld->getBoolConfig(CONFIG_SILENTLY_GM_JOIN_TO_CHANNEL)))
    {
        WorldPacket data;
        MakeLeft(&data, guid);
        SendToAll(&data);
    }

    LeaveNotify(guid);

    if (!IsConstant())
    {
        // Update last_used timestamp in db
        UpdateChannelUseageInDB();

        // If the channel owner left and there are still playersStore inside, pick a new owner
        if (changeowner && _ownership && !playersStore.empty())
        {
            uint64 newowner = playersStore.begin()->second.player;
            playersStore[newowner].SetModerator(true);
            SetOwner(newowner);
        }
    }
}

void Channel::KickOrBan(Player const* player, std::string const& badname, bool ban)
{
    AccountTypes sec = player->GetSession()->GetSecurity();
    uint64 good = player->GetGUID();

    if (!IsOn(good))
    {
        WorldPacket data;
        MakeNotMember(&data);
        SendToOne(&data, good);
        return;
    }

    if (!playersStore[good].IsModerator() && !AccountMgr::IsGMAccount(sec))
    {
        WorldPacket data;
        MakeNotModerator(&data);
        SendToOne(&data, good);
        return;
    }

    Player* bad = sObjectAccessor->FindPlayerByName(badname);
    uint64 victim = bad ? bad->GetGUID() : 0;
    if (!victim || !IsOn(victim))
    {
        WorldPacket data;
        MakePlayerNotFound(&data, badname);
        SendToOne(&data, good);
        return;
    }

    bool changeowner = _ownerGUID == victim;

    if (!AccountMgr::IsGMAccount(sec) && changeowner && good != _ownerGUID)
    {
        WorldPacket data;
        MakeNotOwner(&data);
        SendToOne(&data, good);
        return;
    }

    bool notify = !(AccountMgr::IsGMAccount(sec) && sWorld->getBoolConfig(CONFIG_SILENTLY_GM_JOIN_TO_CHANNEL));

    if (ban && !IsBanned(victim))
    {
        bannedStore.insert(victim);
        UpdateChannelInDB();

        if (notify)
        {
            WorldPacket data;
            MakePlayerBanned(&data, victim, good);
            SendToAll(&data);
        }
    }
    else if (notify)
    {
        WorldPacket data;
        MakePlayerKicked(&data, victim, good);
        SendToAll(&data);
    }

    playersStore.erase(victim);
    bad->LeftChannel(this);

    if (changeowner && _ownership && !playersStore.empty())
    {
        uint64 newowner = good;
        playersStore[newowner].SetModerator(true);
        SetOwner(newowner);
    }
}

void Channel::UnBan(Player const* player, std::string const& badname)
{
    uint32 sec = player->GetSession()->GetSecurity();
    uint64 good = player->GetGUID();

    if (!IsOn(good))
    {
        WorldPacket data;
        MakeNotMember(&data);
        SendToOne(&data, good);
        return;
    }

    if (!playersStore[good].IsModerator() && !AccountMgr::IsGMAccount(sec))
    {
        WorldPacket data;
        MakeNotModerator(&data);
        SendToOne(&data, good);
        return;
    }

    Player* bad = sObjectAccessor->FindPlayerByName(badname);
    uint64 victim = bad ? bad->GetGUID(): 0;

    if (!victim || !IsBanned(victim))
    {
        WorldPacket data;
        MakePlayerNotFound(&data, badname);
        SendToOne(&data, good);
        return;
    }

    bannedStore.erase(victim);

    WorldPacket data;
    MakePlayerUnbanned(&data, victim, good);
    SendToAll(&data);

    UpdateChannelInDB();
}

void Channel::Password(Player const* player, std::string const& pass)
{
    uint64 guid = player->GetGUID();

    ChatHandler chat(player->GetSession());
    if (!IsOn(guid))
    {
        WorldPacket data;
        MakeNotMember(&data);
        SendToOne(&data, guid);
        return;
    }

    if (!playersStore[guid].IsModerator() && !AccountMgr::IsGMAccount(player->GetSession()->GetSecurity()))
    {
        WorldPacket data;
        MakeNotModerator(&data);
        SendToOne(&data, guid);
        return;
    }

    _password = pass;

    WorldPacket data;
    MakePasswordChanged(&data, guid);
    SendToAll(&data);

    UpdateChannelInDB();
}

void Channel::SetMode(Player const* player, std::string const& p2n, bool mod, bool set)
{
    uint64 guid = player->GetGUID();
    uint32 sec = player->GetSession()->GetSecurity();

    if (!IsOn(guid))
    {
        WorldPacket data;
        MakeNotMember(&data);
        SendToOne(&data, guid);
        return;
    }

    if (!playersStore[guid].IsModerator() && !AccountMgr::IsGMAccount(sec))
    {
        WorldPacket data;
        MakeNotModerator(&data);
        SendToOne(&data, guid);
        return;
    }

    if (guid == _ownerGUID && std::string(p2n) == player->GetName() && mod)
        return;

    Player* newp = sObjectAccessor->FindPlayerByName(p2n);
    uint64 victim = newp ? newp->GetGUID() : 0;

    if (!victim || !IsOn(victim) ||
        // allow make moderator from another team only if both is GMs
        // at this moment this only way to show channel post for GM from another team
        ((!AccountMgr::IsGMAccount(sec) || !AccountMgr::IsGMAccount(newp->GetSession()->GetSecurity())) &&
         player->GetTeam() != newp->GetTeam() && !sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL)))
    {
        WorldPacket data;
        MakePlayerNotFound(&data, p2n);
        SendToOne(&data, guid);
        return;
    }

    if (_ownerGUID == victim && _ownerGUID != guid)
    {
        WorldPacket data;
        MakeNotOwner(&data);
        SendToOne(&data, guid);
        return;
    }

    if (mod)
        SetModerator(newp->GetGUID(), set);
    else
        SetMute(newp->GetGUID(), set);
}

void Channel::SetOwner(Player const* player, std::string const& newname)
{
    uint64 guid = player->GetGUID();
    uint32 sec = player->GetSession()->GetSecurity();

    if (!IsOn(guid))
    {
        WorldPacket data;
        MakeNotMember(&data);
        SendToOne(&data, guid);
        return;
    }

    if (!AccountMgr::IsGMAccount(sec) && guid != _ownerGUID)
    {
        WorldPacket data;
        MakeNotOwner(&data);
        SendToOne(&data, guid);
        return;
    }

    Player* newp = sObjectAccessor->FindPlayerByName(newname);
    uint64 victim = newp ? newp->GetGUID() : 0;

    if (!victim || !IsOn(victim) ||
        (newp->GetTeam() != player->GetTeam() && !sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL)))
    {
        WorldPacket data;
        MakePlayerNotFound(&data, newname);
        SendToOne(&data, guid);
        return;
    }

    playersStore[victim].SetModerator(true);
    SetOwner(victim);
}

void Channel::SendWhoOwner(uint64 guid)
{
    WorldPacket data;
    if (IsOn(guid))
        MakeChannelOwner(&data);
    else
        MakeNotMember(&data);
    SendToOne(&data, guid);
}

void Channel::List(Player const* player)
{
    uint64 guid = player->GetGUID();

    if (!IsOn(guid))
    {
        WorldPacket data;
        MakeNotMember(&data);
        SendToOne(&data, guid);
        return;
    }

    sLog->outDebug(LOG_FILTER_CHATSYS, "SMSG_CHANNEL_LIST %s Channel: %s",
        player->GetSession()->GetPlayerInfo().c_str(), GetName().c_str());

    WorldPacket data(SMSG_CHANNEL_LIST, 1+(GetName().size()+1)+1+4+playersStore.size()*(8+1));
    data << uint8(1);                                   // channel type?
    data << GetName();                                  // channel name
    data << uint8(GetFlags());                          // channel flags?

    size_t pos = data.wpos();
    data << uint32(0);                                  // size of list, placeholder

    uint32 gmLevelInWhoList = sWorld->getIntConfig(CONFIG_GM_LEVEL_IN_WHO_LIST);

    uint32 count  = 0;
    for (PlayerContainer::const_iterator i = playersStore.begin(); i != playersStore.end(); ++i)
    {
        Player* member = ObjectAccessor::FindPlayer(i->first);

        // PLAYER can't see MODERATOR, GAME MASTER, ADMINISTRATOR characters
        // MODERATOR, GAME MASTER, ADMINISTRATOR can see all
        if (member && (!AccountMgr::IsPlayerAccount(player->GetSession()->GetSecurity()) || member->GetSession()->GetSecurity() <= AccountTypes(gmLevelInWhoList)) &&
            member->IsVisibleGloballyFor(player))
        {
            data << uint64(i->first);
            data << uint8(i->second.flags);             // flags seems to be changed...
            ++count;
        }
    }

    data.put<uint32>(pos, count);

    SendToOne(&data, guid);
}

void Channel::Announce(Player const* player)
{
    uint64 guid = player->GetGUID();
    uint32 sec = player->GetSession()->GetSecurity();

    if (!IsOn(guid))
    {
        WorldPacket data;
        MakeNotMember(&data);
        SendToOne(&data, guid);
        return;
    }

    if (!playersStore[guid].IsModerator() && !AccountMgr::IsGMAccount(sec))
    {
        WorldPacket data;
        MakeNotModerator(&data);
        SendToOne(&data, guid);
        return;
    }

    _announce = !_announce;

    WorldPacket data;
    if (_announce)
        MakeAnnouncementsOn(&data, guid);
    else
        MakeAnnouncementsOff(&data, guid);
    SendToAll(&data);

    UpdateChannelInDB();
}

void Channel::Say(uint64 guid, std::string const& what, uint32 lang)
{
    if (what.empty())
        return;

    if (sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL))
        lang = LANG_UNIVERSAL;

    if (!IsOn(guid))
    {
        WorldPacket data;
        MakeNotMember(&data);
        SendToOne(&data, guid);
        return;
    }

    if (playersStore[guid].IsMuted())
    {
        WorldPacket data;
        MakeMuted(&data);
        SendToOne(&data, guid);
        return;
    }

    WorldPacket data(SMSG_MESSAGECHAT, 1 + 4 + 8 + 4 + _name.size() + 8 + 4 + what.size() + 1);
    data << uint8(CHAT_MSG_CHANNEL);
    data << uint32(lang);
    data << uint64(guid);
    data << uint32(0);
    data << _name;
    data << uint64(guid);
    data << uint32(what.size() + 1);
    data << what;
    Player* player = ObjectAccessor::FindPlayer(guid);
    data << uint8(player ? player->GetChatTag() : 0);

    SendToAll(&data, !playersStore[guid].IsModerator() ? guid : false);
}

void Channel::Invite(Player const* player, std::string const& newname)
{
    uint64 guid = player->GetGUID();

    if (!IsOn(guid))
    {
        WorldPacket data;
        MakeNotMember(&data);
        SendToOne(&data, guid);
        return;
    }

    Player* newp = sObjectAccessor->FindPlayerByName(newname);
    if (!newp || !newp->isGMVisible())
    {
        WorldPacket data;
        MakePlayerNotFound(&data, newname);
        SendToOne(&data, guid);
        return;
    }

    if (IsBanned(newp->GetGUID()))
    {
        WorldPacket data;
        MakePlayerInviteBanned(&data, newname);
        SendToOne(&data, guid);
        return;
    }

    if (newp->GetTeam() != player->GetTeam() && !sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL))
    {
        WorldPacket data;
        MakeInviteWrongFaction(&data);
        SendToOne(&data, guid);
        return;
    }

    if (IsOn(newp->GetGUID()))
    {
        WorldPacket data;
        MakePlayerAlreadyMember(&data, newp->GetGUID());
        SendToOne(&data, guid);
        return;
    }

    if (!newp->GetSocial()->HasIgnore(GUID_LOPART(guid)))
    {
        WorldPacket data;
        MakeInvite(&data, guid);
        SendToOne(&data, newp->GetGUID());
        data.clear();
    }

    WorldPacket data;
    MakePlayerInvited(&data, newp->GetName());
    SendToOne(&data, guid);
}

void Channel::SetOwner(uint64 guid, bool exclaim)
{
    if (_ownerGUID)
    {
        // [] will re-add player after it possible removed
        PlayerContainer::iterator p_itr = playersStore.find(_ownerGUID);
        if (p_itr != playersStore.end())
            p_itr->second.SetOwner(false);
    }

    _ownerGUID = guid;
    if (_ownerGUID)
    {
        uint8 oldFlag = GetPlayerFlags(_ownerGUID);
        playersStore[_ownerGUID].SetModerator(true);
        playersStore[_ownerGUID].SetOwner(true);

        WorldPacket data;
        MakeModeChange(&data, _ownerGUID, oldFlag);
        SendToAll(&data);

        if (exclaim)
        {
            MakeOwnerChanged(&data, _ownerGUID);
            SendToAll(&data);
        }

        UpdateChannelInDB();
    }
}

void Channel::SendToAll(WorldPacket* data, uint64 guid)
{
    for (PlayerContainer::const_iterator i = playersStore.begin(); i != playersStore.end(); ++i)
        if (Player* player = ObjectAccessor::FindPlayer(i->first))
            if (!guid || !player->GetSocial()->HasIgnore(GUID_LOPART(guid)))
                player->GetSession()->SendPacket(data);
}

void Channel::SendToAllButOne(WorldPacket* data, uint64 who)
{
    for (PlayerContainer::const_iterator i = playersStore.begin(); i != playersStore.end(); ++i)
        if (i->first != who)
            if (Player* player = ObjectAccessor::FindPlayer(i->first))
                player->GetSession()->SendPacket(data);
}

void Channel::SendToOne(WorldPacket* data, uint64 who)
{
    if (Player* player = ObjectAccessor::FindPlayer(who))
        player->GetSession()->SendPacket(data);
}

void Channel::Voice(uint64 /*guid1*/, uint64 /*guid2*/)
{

}

void Channel::DeVoice(uint64 /*guid1*/, uint64 /*guid2*/)
{

}

void Channel::MakeNotifyPacket(WorldPacket* data, uint8 notify_type)
{
    data->Initialize(SMSG_CHANNEL_NOTIFY, 1 + _name.size());
    *data << uint8(notify_type);
    *data << _name;
}

void Channel::MakeJoined(WorldPacket* data, uint64 guid)
{
    MakeNotifyPacket(data, CHAT_JOINED_NOTICE);
    *data << uint64(guid);
}

void Channel::MakeLeft(WorldPacket* data, uint64 guid)
{
    MakeNotifyPacket(data, CHAT_LEFT_NOTICE);
    *data << uint64(guid);
}

void Channel::MakeYouJoined(WorldPacket* data)
{
    MakeNotifyPacket(data, CHAT_YOU_JOINED_NOTICE);
    *data << uint8(GetFlags());
    *data << uint32(GetChannelId());
    *data << uint32(0);
}

void Channel::MakeYouLeft(WorldPacket* data)
{
    MakeNotifyPacket(data, CHAT_YOU_LEFT_NOTICE);
    *data << uint32(GetChannelId());
    *data << uint8(IsConstant());
}

void Channel::MakeWrongPassword(WorldPacket* data)
{
    MakeNotifyPacket(data, CHAT_WRONG_PASSWORD_NOTICE);
}

void Channel::MakeNotMember(WorldPacket* data)
{
    MakeNotifyPacket(data, CHAT_NOT_MEMBER_NOTICE);
}

void Channel::MakeNotModerator(WorldPacket* data)
{
    MakeNotifyPacket(data, CHAT_NOT_MODERATOR_NOTICE);
}

void Channel::MakePasswordChanged(WorldPacket* data, uint64 guid)
{
    MakeNotifyPacket(data, CHAT_PASSWORD_CHANGED_NOTICE);
    *data << uint64(guid);
}

void Channel::MakeOwnerChanged(WorldPacket* data, uint64 guid)
{
    MakeNotifyPacket(data, CHAT_OWNER_CHANGED_NOTICE);
    *data << uint64(guid);
}

void Channel::MakePlayerNotFound(WorldPacket* data, std::string const& name)
{
    MakeNotifyPacket(data, CHAT_PLAYER_NOT_FOUND_NOTICE);
    *data << name;
}

void Channel::MakeNotOwner(WorldPacket* data)
{
    MakeNotifyPacket(data, CHAT_NOT_OWNER_NOTICE);
}

void Channel::MakeChannelOwner(WorldPacket* data)
{
    std::string name = "";

    if (!sObjectMgr->GetPlayerNameByGUID(_ownerGUID, name) || name.empty())
        name = "PLAYER_NOT_FOUND";

    MakeNotifyPacket(data, CHAT_CHANNEL_OWNER_NOTICE);
    *data << ((IsConstant() || !_ownerGUID) ? "Nobody" : name);
}

void Channel::MakeModeChange(WorldPacket* data, uint64 guid, uint8 oldflags)
{
    MakeNotifyPacket(data, CHAT_MODE_CHANGE_NOTICE);
    *data << uint64(guid);
    *data << uint8(oldflags);
    *data << uint8(GetPlayerFlags(guid));
}

void Channel::MakeAnnouncementsOn(WorldPacket* data, uint64 guid)
{
    MakeNotifyPacket(data, CHAT_ANNOUNCEMENTS_ON_NOTICE);
    *data << uint64(guid);
}

void Channel::MakeAnnouncementsOff(WorldPacket* data, uint64 guid)
{
    MakeNotifyPacket(data, CHAT_ANNOUNCEMENTS_OFF_NOTICE);
    *data << uint64(guid);
}

void Channel::MakeMuted(WorldPacket* data)
{
    MakeNotifyPacket(data, CHAT_MUTED_NOTICE);
}

void Channel::MakePlayerKicked(WorldPacket* data, uint64 bad, uint64 good)
{
    MakeNotifyPacket(data, CHAT_PLAYER_KICKED_NOTICE);
    *data << uint64(bad);
    *data << uint64(good);
}

void Channel::MakeBanned(WorldPacket* data)
{
    MakeNotifyPacket(data, CHAT_BANNED_NOTICE);
}

void Channel::MakePlayerBanned(WorldPacket* data, uint64 bad, uint64 good)
{
    MakeNotifyPacket(data, CHAT_PLAYER_BANNED_NOTICE);
    *data << uint64(bad);
    *data << uint64(good);
}

void Channel::MakePlayerUnbanned(WorldPacket* data, uint64 bad, uint64 good)
{
    MakeNotifyPacket(data, CHAT_PLAYER_UNBANNED_NOTICE);
    *data << uint64(bad);
    *data << uint64(good);
}

void Channel::MakePlayerNotBanned(WorldPacket* data, const std::string &name)
{
    MakeNotifyPacket(data, CHAT_PLAYER_NOT_BANNED_NOTICE);
    *data << name;
}

void Channel::MakePlayerAlreadyMember(WorldPacket* data, uint64 guid)
{
    MakeNotifyPacket(data, CHAT_PLAYER_ALREADY_MEMBER_NOTICE);
    *data << uint64(guid);
}

void Channel::MakeInvite(WorldPacket* data, uint64 guid)
{
    MakeNotifyPacket(data, CHAT_INVITE_NOTICE);
    *data << uint64(guid);
}

void Channel::MakeInviteWrongFaction(WorldPacket* data)
{
    MakeNotifyPacket(data, CHAT_INVITE_WRONG_FACTION_NOTICE);
}

void Channel::MakeWrongFaction(WorldPacket* data)
{
    MakeNotifyPacket(data, CHAT_WRONG_FACTION_NOTICE);
}

void Channel::MakeInvalidName(WorldPacket* data)
{
    MakeNotifyPacket(data, CHAT_INVALID_NAME_NOTICE);
}

void Channel::MakeNotModerated(WorldPacket* data)
{
    MakeNotifyPacket(data, CHAT_NOT_MODERATED_NOTICE);
}

void Channel::MakePlayerInvited(WorldPacket* data, const std::string& name)
{
    MakeNotifyPacket(data, CHAT_PLAYER_INVITED_NOTICE);
    *data << name;
}

void Channel::MakePlayerInviteBanned(WorldPacket* data, const std::string& name)
{
    MakeNotifyPacket(data, CHAT_PLAYER_INVITE_BANNED_NOTICE);
    *data << name;
}

void Channel::MakeThrottled(WorldPacket* data)
{
    MakeNotifyPacket(data, CHAT_THROTTLED_NOTICE);
}

void Channel::MakeNotInArea(WorldPacket* data)
{
    MakeNotifyPacket(data, CHAT_NOT_IN_AREA_NOTICE);
}

void Channel::MakeNotInLfg(WorldPacket* data)
{
    MakeNotifyPacket(data, CHAT_NOT_IN_LFG_NOTICE);
}

void Channel::MakeVoiceOn(WorldPacket* data, uint64 guid)
{
    MakeNotifyPacket(data, CHAT_VOICE_ON_NOTICE);
    *data << uint64(guid);
}

void Channel::MakeVoiceOff(WorldPacket* data, uint64 guid)
{
    MakeNotifyPacket(data, CHAT_VOICE_OFF_NOTICE);
    *data << uint64(guid);
}

void Channel::JoinNotify(uint64 guid)
{
    WorldPacket data(IsConstant() ? SMSG_USERLIST_ADD : SMSG_USERLIST_UPDATE, 8 + 1 + 1 + 4 + GetName().size());
    data << uint64(guid);
    data << uint8(GetPlayerFlags(guid));
    data << uint8(GetFlags());
    data << uint32(GetNumPlayers());
    data << GetName();

    if (IsConstant())
        SendToAllButOne(&data, guid);
    else
        SendToAll(&data);
}

void Channel::LeaveNotify(uint64 guid)
{
    WorldPacket data(SMSG_USERLIST_REMOVE, 8 + 1 + 4 + GetName().size());
    data << uint64(guid);
    data << uint8(GetFlags());
    data << uint32(GetNumPlayers());
    data << GetName();

    if (IsConstant())
        SendToAllButOne(&data, guid);
    else
        SendToAll(&data);
}

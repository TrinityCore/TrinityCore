/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
    _team(team),
    _name(name)
{
    // set special flags if built-in channel
    if (ChatChannelsEntry const* ch = sChatChannelsStore.LookupEntry(channelId)) // check whether it's a built-in channel
    {
        _announce = false;                                  // no join/leave announces
        _ownership = false;                                 // no ownership handout

        _flags |= CHANNEL_FLAG_GENERAL;                     // for all built-in channels

        if (ch->Flags & CHANNEL_DBC_FLAG_TRADE)             // for trade channel
            _flags |= CHANNEL_FLAG_TRADE;

        if (ch->Flags & CHANNEL_DBC_FLAG_CITY_ONLY2)        // for city only channels
            _flags |= CHANNEL_FLAG_CITY;

        if (ch->Flags & CHANNEL_DBC_FLAG_LFG)               // for LFG channel
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
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_CHANNEL);
            stmt->setString(0, _name);
            stmt->setUInt32(1, _team);
            PreparedQueryResult result = CharacterDatabase.Query(stmt);

            if (result) // load
            {
                Field* fields = result->Fetch();
                _announce = fields[0].GetBool();
                _ownership = fields[1].GetBool();
                _password  = fields[2].GetString();
                std::string bannedList = fields[3].GetString();

                if (!bannedList.empty())
                {
                    Tokenizer tokens(bannedList, ' ');
                    for (Tokenizer::const_iterator i = tokens.begin(); i != tokens.end(); ++i)
                    {
                        std::string bannedGuidStr(*i);
                        ObjectGuid bannedGuid;
                        bannedGuid.SetRawValue(uint64(strtoull(bannedGuidStr.substr(0, 16).c_str(), nullptr, 16)), uint64(strtoull(bannedGuidStr.substr(16).c_str(), nullptr, 16)));
                        if (!bannedGuid.IsEmpty())
                        {
                            TC_LOG_DEBUG("chat.system", "Channel (%s) loaded bannedStore %s", _name.c_str(), bannedGuid.ToString().c_str());
                            _bannedStore.insert(bannedGuid);
                        }
                    }
                }
            }
            else // save
            {
                stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHANNEL);
                stmt->setString(0, _name);
                stmt->setUInt32(1, _team);
                CharacterDatabase.Execute(stmt);
                TC_LOG_DEBUG("chat.system", "Channel (%s) saved in database", _name.c_str());
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
        for (ObjectGuid const& guid : _bannedStore)
            banlist << guid << ' ';

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHANNEL);
        stmt->setBool(0, _announce);
        stmt->setBool(1, _ownership);
        stmt->setString(2, _password);
        stmt->setString(3, banlist.str());
        stmt->setString(4, _name);
        stmt->setUInt32(5, _team);
        CharacterDatabase.Execute(stmt);

        TC_LOG_DEBUG("chat.system", "Channel (%s) updated in database", _name.c_str());
    }
}

void Channel::UpdateChannelUseageInDB() const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHANNEL_USAGE);
    stmt->setString(0, _name);
    stmt->setUInt32(1, _team);
    CharacterDatabase.Execute(stmt);
}

void Channel::CleanOldChannelsInDB()
{
    if (sWorld->getIntConfig(CONFIG_PRESERVE_CUSTOM_CHANNEL_DURATION) > 0)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_OLD_CHANNELS);
        stmt->setUInt32(0, sWorld->getIntConfig(CONFIG_PRESERVE_CUSTOM_CHANNEL_DURATION) * DAY);
        CharacterDatabase.Execute(stmt);

        TC_LOG_DEBUG("chat.system", "Cleaned out unused custom chat channels.");
    }
}

void Channel::JoinChannel(Player* player, std::string const& pass)
{
    ObjectGuid const& guid = player->GetGUID();
    if (IsOn(guid))
    {
        // Do not send error message for built-in channels
        if (!IsConstant())
        {
            WorldPackets::Channel::ChannelNotify notify;
            MakePlayerAlreadyMember(notify, guid);
            player->SendDirectMessage(notify.Write());
        }
        return;
    }

    if (IsBanned(guid))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeBanned(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    if (!_password.empty() && pass != _password)
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeWrongPassword(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    if (HasFlag(CHANNEL_FLAG_LFG) &&
        sWorld->getBoolConfig(CONFIG_RESTRICTED_LFG_CHANNEL) &&
        AccountMgr::IsPlayerAccount(player->GetSession()->GetSecurity()) && //FIXME: Move to RBAC
        player->GetGroup())
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotInLfg(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    player->JoinedChannel(this);

    if (_announce && !player->GetSession()->HasPermission(rbac::RBAC_PERM_SILENTLY_JOIN_CHANNEL))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeJoined(notify, guid);
        SendToAll(notify.Write());
    }

    PlayerInfo playerInfo;
    playerInfo.PlayerGuid = guid;
    _playersStore[guid] = playerInfo;

    /*
    WorldPackets::Channel::ChannelNotify notify;
    MakeYouJoined(notify);
    player->SendDirectMessage(notify.Write());
    */

    WorldPackets::Channel::ChannelNotifyJoined notify;
    //notify.ChannelWelcomeMsg = "";
    notify.ChatChannelID = _channelId;
    //notify.InstanceID = 0;
    notify.ChannelFlags = _flags;
    notify.Channel = _name;
    player->SendDirectMessage(notify.Write());

    JoinNotify(player);

    // Custom channel handling
    if (!IsConstant())
    {
        // Update last_used timestamp in db
        if (!_playersStore.empty())
            UpdateChannelUseageInDB();

        // If the channel has no owner yet and ownership is allowed, set the new owner.
        if (_ownerGUID.IsEmpty() && _ownership)
        {
            SetOwner(guid, _playersStore.size() > 1);
            _playersStore[guid].SetModerator(true);
        }
    }
}

void Channel::LeaveChannel(Player* player, bool send)
{
    ObjectGuid const& guid = player->GetGUID();
    if (!IsOn(guid))
    {
        if (send)
        {
            WorldPackets::Channel::ChannelNotify notify;
            MakeNotMember(notify);
            player->SendDirectMessage(notify.Write());
        }
        return;
    }

    player->LeftChannel(this);

    if (send)
    {
        /*
        WorldPackets::Channel::ChannelNotify notify;
        MakeYouLeft(notify);
        player->SendDirectMessage(notify.Write());
        */

        WorldPackets::Channel::ChannelNotifyLeft notify;
        notify.Channel = _name;
        notify.ChatChannelID = 0;
        //notify.Suspended = false;
        player->SendDirectMessage(notify.Write());
    }

    bool changeowner = _playersStore[guid].IsOwner();

    _playersStore.erase(guid);

    if (_announce && !player->GetSession()->HasPermission(rbac::RBAC_PERM_SILENTLY_JOIN_CHANNEL))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeLeft(notify, guid);
        SendToAll(notify.Write());
    }

    LeaveNotify(player);

    if (!IsConstant())
    {
        // Update last_used timestamp in db
        UpdateChannelUseageInDB();

        // If the channel owner left and there are still playersStore inside, pick a new owner
        if (changeowner && _ownership && !_playersStore.empty())
        {
            ObjectGuid const& newowner = _playersStore.begin()->second.PlayerGuid;
            _playersStore[newowner].SetModerator(true);
            SetOwner(newowner);
        }
    }
}

void Channel::KickOrBan(Player const* player, std::string const& badname, bool ban)
{
    ObjectGuid const& good = player->GetGUID();

    if (!IsOn(good))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotMember(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    if (!_playersStore[good].IsModerator() && !player->GetSession()->HasPermission(rbac::RBAC_PERM_CHANGE_CHANNEL_NOT_MODERATOR))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotModerator(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    Player* bad = ObjectAccessor::FindConnectedPlayerByName(badname);
    ObjectGuid victim = bad ? bad->GetGUID() : ObjectGuid::Empty;
    if (!victim || !IsOn(victim))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakePlayerNotFound(notify, badname);
        player->SendDirectMessage(notify.Write());
        return;
    }

    bool changeowner = _ownerGUID == victim;

    if (!player->GetSession()->HasPermission(rbac::RBAC_PERM_CHANGE_CHANNEL_NOT_MODERATOR) && changeowner && good != _ownerGUID)
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotOwner(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    if (ban && !IsBanned(victim))
    {
        _bannedStore.insert(victim);
        UpdateChannelInDB();

        if (!player->GetSession()->HasPermission(rbac::RBAC_PERM_SILENTLY_JOIN_CHANNEL))
        {
            WorldPackets::Channel::ChannelNotify notify;
            MakePlayerBanned(notify, victim, good);
            SendToAll(notify.Write());
        }
    }
    else if (!player->GetSession()->HasPermission(rbac::RBAC_PERM_SILENTLY_JOIN_CHANNEL))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakePlayerKicked(notify, victim, good);
        SendToAll(notify.Write());
    }

    _playersStore.erase(victim);
    bad->LeftChannel(this);

    if (changeowner && _ownership && !_playersStore.empty())
    {
        _playersStore[good].SetModerator(true);
        SetOwner(good);
    }
}

void Channel::UnBan(Player const* player, std::string const& badname)
{
    ObjectGuid const& good = player->GetGUID();

    if (!IsOn(good))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotMember(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    if (!_playersStore[good].IsModerator() && !player->GetSession()->HasPermission(rbac::RBAC_PERM_CHANGE_CHANNEL_NOT_MODERATOR))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotModerator(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    Player* bad = ObjectAccessor::FindConnectedPlayerByName(badname);
    ObjectGuid victim = bad ? bad->GetGUID() : ObjectGuid::Empty;

    if (victim.IsEmpty() || !IsBanned(victim))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakePlayerNotFound(notify, badname);
        player->SendDirectMessage(notify.Write());
        return;
    }

    _bannedStore.erase(victim);

    WorldPackets::Channel::ChannelNotify notify;
    MakePlayerUnbanned(notify, victim, good);
    SendToAll(notify.Write());

    UpdateChannelInDB();
}

void Channel::Password(Player const* player, std::string const& pass)
{
    ObjectGuid const& guid = player->GetGUID();

    if (!IsOn(guid))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotMember(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    if (!_playersStore[guid].IsModerator() && !player->GetSession()->HasPermission(rbac::RBAC_PERM_CHANGE_CHANNEL_NOT_MODERATOR))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotModerator(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    _password = pass;

    WorldPackets::Channel::ChannelNotify notify;
    MakePasswordChanged(notify, guid);
    SendToAll(notify.Write());

    UpdateChannelInDB();
}

void Channel::SetMode(Player const* player, std::string const& p2n, bool mod, bool set)
{
    ObjectGuid const& guid = player->GetGUID();

    if (!IsOn(guid))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotMember(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    if (!_playersStore[guid].IsModerator() && !player->GetSession()->HasPermission(rbac::RBAC_PERM_CHANGE_CHANNEL_NOT_MODERATOR))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotModerator(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    if (guid == _ownerGUID && p2n == player->GetName() && mod)
        return;

    Player* newp = ObjectAccessor::FindConnectedPlayerByName(p2n);
    ObjectGuid victim = newp ? newp->GetGUID() : ObjectGuid::Empty;

    if (victim.IsEmpty() || !IsOn(victim) ||
        (player->GetTeam() != newp->GetTeam() &&
        (!player->GetSession()->HasPermission(rbac::RBAC_PERM_TWO_SIDE_INTERACTION_CHANNEL) ||
        !newp->GetSession()->HasPermission(rbac::RBAC_PERM_TWO_SIDE_INTERACTION_CHANNEL))))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakePlayerNotFound(notify, p2n);
        player->SendDirectMessage(notify.Write());
        return;
    }

    if (_ownerGUID == victim && _ownerGUID != guid)
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotOwner(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    if (mod)
        SetModerator(newp->GetGUID(), set);
    else
        SetMute(newp->GetGUID(), set);
}

void Channel::SetOwner(Player const* player, std::string const& newname)
{
    ObjectGuid const& guid = player->GetGUID();

    if (!IsOn(guid))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotMember(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    if (!player->GetSession()->HasPermission(rbac::RBAC_PERM_CHANGE_CHANNEL_NOT_MODERATOR) && guid != _ownerGUID)
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotOwner(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    Player* newp = ObjectAccessor::FindConnectedPlayerByName(newname);
    ObjectGuid victim = newp ? newp->GetGUID() : ObjectGuid::Empty;

    if (!victim || !IsOn(victim) ||
        (player->GetTeam() != newp->GetTeam() &&
        (!player->GetSession()->HasPermission(rbac::RBAC_PERM_TWO_SIDE_INTERACTION_CHANNEL) ||
        !newp->GetSession()->HasPermission(rbac::RBAC_PERM_TWO_SIDE_INTERACTION_CHANNEL))))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakePlayerNotFound(notify, newname);
        player->SendDirectMessage(notify.Write());
        return;
    }

    _playersStore[victim].SetModerator(true);
    SetOwner(victim);
}

void Channel::SendWhoOwner(Player const* player)
{
    WorldPackets::Channel::ChannelNotify notify;
    if (IsOn(player->GetGUID()))
        MakeChannelOwner(notify);
    else
        MakeNotMember(notify);
    player->SendDirectMessage(notify.Write());
}

void Channel::List(Player const* player)
{
    if (!IsOn(player->GetGUID()))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotMember(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    TC_LOG_DEBUG("chat.system", "SMSG_CHANNEL_LIST %s Channel: %s",
        player->GetSession()->GetPlayerInfo().c_str(), GetName().c_str());

    WorldPackets::Channel::ChannelListResponse list;
    list.Display = true; /// always true?
    list.Channel = GetName();
    list.ChannelFlags = GetFlags();

    uint32 gmLevelInWhoList = sWorld->getIntConfig(CONFIG_GM_LEVEL_IN_WHO_LIST);

    for (PlayerContainer::value_type const& i : _playersStore)
    {
        Player* member = ObjectAccessor::FindConnectedPlayer(i.first);

        // PLAYER can't see MODERATOR, GAME MASTER, ADMINISTRATOR characters
        // MODERATOR, GAME MASTER, ADMINISTRATOR can see all
        if (member &&
            (player->GetSession()->HasPermission(rbac::RBAC_PERM_WHO_SEE_ALL_SEC_LEVELS) ||
             member->GetSession()->GetSecurity() <= AccountTypes(gmLevelInWhoList)) &&
            member->IsVisibleGloballyFor(player))
        {
            list.Members.emplace_back(i.second.PlayerGuid, GetVirtualRealmAddress(), i.second.GetFlags());
        }
    }

    player->SendDirectMessage(list.Write());
}

void Channel::Announce(Player const* player)
{
    ObjectGuid const& guid = player->GetGUID();

    if (!IsOn(guid))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotMember(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    if (!_playersStore[guid].IsModerator() && !player->GetSession()->HasPermission(rbac::RBAC_PERM_CHANGE_CHANNEL_NOT_MODERATOR))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotModerator(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    _announce = !_announce;

    WorldPackets::Channel::ChannelNotify notify;
    if (_announce)
        MakeAnnouncementsOn(notify, guid);
    else
        MakeAnnouncementsOff(notify, guid);
    SendToAll(notify.Write());

    UpdateChannelInDB();
}

void Channel::Say(ObjectGuid const& guid, std::string const& what, uint32 lang)
{
    if (what.empty())
        return;

    // TODO: Add proper RBAC check
    if (sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL))
        lang = LANG_UNIVERSAL;

    if (!IsOn(guid))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotMember(notify);
        SendToOne(notify.Write(), guid);
        return;
    }

    if (_playersStore[guid].IsMuted())
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeMuted(notify);
        SendToOne(notify.Write(), guid);
        return;
    }

    WorldPackets::Chat::Chat packet;
    if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
        ChatHandler::BuildChatPacket(&packet, CHAT_MSG_CHANNEL, Language(lang), player, player, what, 0, _name);
    else
    {
        ChatHandler::BuildChatPacket(&packet, CHAT_MSG_CHANNEL, Language(lang), NULL, NULL, what, 0,  _name);
        packet.SenderGUID = guid;
        packet.TargetGUID = guid;
    }

    SendToAll(packet.Write(), !_playersStore[guid].IsModerator() ? guid : ObjectGuid::Empty);
}

void Channel::Invite(Player const* player, std::string const& newname)
{
    ObjectGuid const& guid = player->GetGUID();

    if (!IsOn(guid))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeNotMember(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    Player* newp = ObjectAccessor::FindConnectedPlayerByName(newname);
    if (!newp || !newp->isGMVisible())
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakePlayerNotFound(notify, newname);
        player->SendDirectMessage(notify.Write());
        return;
    }

    if (IsBanned(newp->GetGUID()))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakePlayerInviteBanned(notify, newname);
        player->SendDirectMessage(notify.Write());
        return;
    }

    if (newp->GetTeam() != player->GetTeam() &&
        (!player->GetSession()->HasPermission(rbac::RBAC_PERM_TWO_SIDE_INTERACTION_CHANNEL) ||
        !newp->GetSession()->HasPermission(rbac::RBAC_PERM_TWO_SIDE_INTERACTION_CHANNEL)))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeInviteWrongFaction(notify);
        player->SendDirectMessage(notify.Write());
        return;
    }

    if (IsOn(newp->GetGUID()))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakePlayerAlreadyMember(notify, newp->GetGUID());
        player->SendDirectMessage(notify.Write());
        return;
    }

    if (!newp->GetSocial()->HasIgnore(guid))
    {
        WorldPackets::Channel::ChannelNotify notify;
        MakeInvite(notify, guid);
        newp->SendDirectMessage(notify.Write());
    }

    WorldPackets::Channel::ChannelNotify notify;
    MakePlayerInvited(notify, newp->GetName());
    player->SendDirectMessage(notify.Write());
}

void Channel::SetOwner(ObjectGuid const& guid, bool exclaim)
{
    if (!_ownerGUID.IsEmpty())
    {
        // [] will re-add player after it possible removed
        PlayerContainer::iterator itr = _playersStore.find(_ownerGUID);
        if (itr != _playersStore.end())
            itr->second.SetOwner(false);
    }

    _ownerGUID = guid;
    if (!_ownerGUID.IsEmpty())
    {
        uint8 oldFlag = _playersStore[_ownerGUID].GetFlags();
        _playersStore[_ownerGUID].SetModerator(true);
        _playersStore[_ownerGUID].SetOwner(true);

        WorldPackets::Channel::ChannelNotify notify;
        MakeModeChange(notify, _ownerGUID, oldFlag, _playersStore[_ownerGUID].GetFlags());
        SendToAll(notify.Write());

        if (exclaim)
        {
            MakeOwnerChanged(notify, _ownerGUID);
            SendToAll(notify.Write());
        }

        UpdateChannelInDB();
    }
}

void Channel::SendToAll(WorldPacket const* data, ObjectGuid const& guid)
{
    for (PlayerContainer::value_type const& i : _playersStore)
        if (Player* player = ObjectAccessor::FindConnectedPlayer(i.first))
            if (guid.IsEmpty() || !player->GetSocial()->HasIgnore(guid))
                player->SendDirectMessage(data);
}

void Channel::SendToAllButOne(WorldPacket const* data, ObjectGuid const& who)
{
    for (PlayerContainer::value_type const& i : _playersStore)
        if (i.first != who)
            if (Player* player = ObjectAccessor::FindConnectedPlayer(i.first))
                player->SendDirectMessage(data);
}

void Channel::SendToOne(WorldPacket const* data, ObjectGuid const& who)
{
    if (Player* player = ObjectAccessor::FindConnectedPlayer(who))
        player->SendDirectMessage(data);
}

void Channel::Voice(ObjectGuid const& /*guid1*/, ObjectGuid const& /*guid2*/)
{

}

void Channel::DeVoice(ObjectGuid const& /*guid1*/, ObjectGuid const& /*guid2*/)
{

}

void Channel::MakeNotifyPacket(WorldPackets::Channel::ChannelNotify& data, uint8 notifyType)
{
    data.Type = notifyType;
    data.Channel = _name;
}

void Channel::MakeJoined(WorldPackets::Channel::ChannelNotify& data, ObjectGuid const& guid)
{
    MakeNotifyPacket(data, CHAT_JOINED_NOTICE);
    data.SenderGuid = guid;
}

void Channel::MakeLeft(WorldPackets::Channel::ChannelNotify& data, ObjectGuid const& guid)
{
    MakeNotifyPacket(data, CHAT_LEFT_NOTICE);
    data.SenderGuid = guid;
}

void Channel::MakeYouJoined(WorldPackets::Channel::ChannelNotify& data)
{
    MakeNotifyPacket(data, CHAT_YOU_JOINED_NOTICE);
    //*data << uint8(GetFlags());
    data.ChatChannelID = GetChannelId();
    //*data << uint32(0);
}

void Channel::MakeYouLeft(WorldPackets::Channel::ChannelNotify& data)
{
    MakeNotifyPacket(data, CHAT_YOU_LEFT_NOTICE);
    data.ChatChannelID = GetChannelId();
    //*data << uint8(IsConstant());
}

void Channel::MakeWrongPassword(WorldPackets::Channel::ChannelNotify& data)
{
    MakeNotifyPacket(data, CHAT_WRONG_PASSWORD_NOTICE);
}

void Channel::MakeNotMember(WorldPackets::Channel::ChannelNotify& data)
{
    MakeNotifyPacket(data, CHAT_NOT_MEMBER_NOTICE);
}

void Channel::MakeNotModerator(WorldPackets::Channel::ChannelNotify& data)
{
    MakeNotifyPacket(data, CHAT_NOT_MODERATOR_NOTICE);
}

void Channel::MakePasswordChanged(WorldPackets::Channel::ChannelNotify& data, ObjectGuid const& guid)
{
    MakeNotifyPacket(data, CHAT_PASSWORD_CHANGED_NOTICE);
    data.SenderGuid = guid;
}

void Channel::MakeOwnerChanged(WorldPackets::Channel::ChannelNotify& data, ObjectGuid const& guid)
{
    MakeNotifyPacket(data, CHAT_OWNER_CHANGED_NOTICE);
    data.SenderGuid = guid;
}

void Channel::MakePlayerNotFound(WorldPackets::Channel::ChannelNotify& data, std::string const& name)
{
    MakeNotifyPacket(data, CHAT_PLAYER_NOT_FOUND_NOTICE);
    data.Sender = name;
}

void Channel::MakeNotOwner(WorldPackets::Channel::ChannelNotify& data)
{
    MakeNotifyPacket(data, CHAT_NOT_OWNER_NOTICE);
}

void Channel::MakeChannelOwner(WorldPackets::Channel::ChannelNotify& data)
{
    std::string name;

    if (!ObjectMgr::GetPlayerNameByGUID(_ownerGUID, name) || name.empty())
        name = "PLAYER_NOT_FOUND";

    MakeNotifyPacket(data, CHAT_CHANNEL_OWNER_NOTICE);
    data.Sender = ((IsConstant() || !_ownerGUID) ? "Nobody" : name);
}

void Channel::MakeModeChange(WorldPackets::Channel::ChannelNotify& data, ObjectGuid const& guid, uint8 oldFlags, uint8 newFlags)
{
    MakeNotifyPacket(data, CHAT_MODE_CHANGE_NOTICE);
    data.SenderGuid = guid;
    data.OldFlags = oldFlags;
    data.NewFlags = newFlags;
}

void Channel::MakeAnnouncementsOn(WorldPackets::Channel::ChannelNotify& data, ObjectGuid const& guid)
{
    MakeNotifyPacket(data, CHAT_ANNOUNCEMENTS_ON_NOTICE);
    data.SenderGuid = guid;
}

void Channel::MakeAnnouncementsOff(WorldPackets::Channel::ChannelNotify& data, ObjectGuid const& guid)
{
    MakeNotifyPacket(data, CHAT_ANNOUNCEMENTS_OFF_NOTICE);
    data.SenderGuid = guid;
}

void Channel::MakeMuted(WorldPackets::Channel::ChannelNotify& data)
{
    MakeNotifyPacket(data, CHAT_MUTED_NOTICE);
}

void Channel::MakePlayerKicked(WorldPackets::Channel::ChannelNotify& data, ObjectGuid const& bad, ObjectGuid const& good)
{
    MakeNotifyPacket(data, CHAT_PLAYER_KICKED_NOTICE);
    data.SenderGuid = good;
    data.TargetGuid = bad;
}

void Channel::MakeBanned(WorldPackets::Channel::ChannelNotify& data)
{
    MakeNotifyPacket(data, CHAT_BANNED_NOTICE);
}

void Channel::MakePlayerBanned(WorldPackets::Channel::ChannelNotify& data, ObjectGuid const& bad, ObjectGuid const& good)
{
    MakeNotifyPacket(data, CHAT_PLAYER_BANNED_NOTICE);
    data.SenderGuid = good;
    data.TargetGuid = bad;
}

void Channel::MakePlayerUnbanned(WorldPackets::Channel::ChannelNotify& data, ObjectGuid const& bad, ObjectGuid const& good)
{
    MakeNotifyPacket(data, CHAT_PLAYER_UNBANNED_NOTICE);
    data.SenderGuid = good;
    data.TargetGuid = bad;
}

void Channel::MakePlayerNotBanned(WorldPackets::Channel::ChannelNotify& data, std::string const& name)
{
    MakeNotifyPacket(data, CHAT_PLAYER_NOT_BANNED_NOTICE);
    data.Sender = name;
}

void Channel::MakePlayerAlreadyMember(WorldPackets::Channel::ChannelNotify& data, ObjectGuid const& guid)
{
    MakeNotifyPacket(data, CHAT_PLAYER_ALREADY_MEMBER_NOTICE);
    data.SenderGuid = guid;
}

void Channel::MakeInvite(WorldPackets::Channel::ChannelNotify& data, ObjectGuid const& guid)
{
    MakeNotifyPacket(data, CHAT_INVITE_NOTICE);
    data.SenderGuid = guid;
}

void Channel::MakeInviteWrongFaction(WorldPackets::Channel::ChannelNotify& data)
{
    MakeNotifyPacket(data, CHAT_INVITE_WRONG_FACTION_NOTICE);
}

void Channel::MakeWrongFaction(WorldPackets::Channel::ChannelNotify& data)
{
    MakeNotifyPacket(data, CHAT_WRONG_FACTION_NOTICE);
}

void Channel::MakeInvalidName(WorldPackets::Channel::ChannelNotify& data)
{
    MakeNotifyPacket(data, CHAT_INVALID_NAME_NOTICE);
}

void Channel::MakeNotModerated(WorldPackets::Channel::ChannelNotify& data)
{
    MakeNotifyPacket(data, CHAT_NOT_MODERATED_NOTICE);
}

void Channel::MakePlayerInvited(WorldPackets::Channel::ChannelNotify& data, std::string const& name)
{
    MakeNotifyPacket(data, CHAT_PLAYER_INVITED_NOTICE);
    data.Sender = name;
}

void Channel::MakePlayerInviteBanned(WorldPackets::Channel::ChannelNotify& data, std::string const& name)
{
    MakeNotifyPacket(data, CHAT_PLAYER_INVITE_BANNED_NOTICE);
    data.Sender = name;
}

void Channel::MakeThrottled(WorldPackets::Channel::ChannelNotify& data)
{
    MakeNotifyPacket(data, CHAT_THROTTLED_NOTICE);
}

void Channel::MakeNotInArea(WorldPackets::Channel::ChannelNotify& data)
{
    MakeNotifyPacket(data, CHAT_NOT_IN_AREA_NOTICE);
}

void Channel::MakeNotInLfg(WorldPackets::Channel::ChannelNotify& data)
{
    MakeNotifyPacket(data, CHAT_NOT_IN_LFG_NOTICE);
}

void Channel::MakeVoiceOn(WorldPackets::Channel::ChannelNotify& data, ObjectGuid const& guid)
{
    MakeNotifyPacket(data, CHAT_VOICE_ON_NOTICE);
    data.SenderGuid = guid;
}

void Channel::MakeVoiceOff(WorldPackets::Channel::ChannelNotify& data, ObjectGuid const& guid)
{
    MakeNotifyPacket(data, CHAT_VOICE_OFF_NOTICE);
    data.SenderGuid = guid;
}

void Channel::JoinNotify(Player const* player)
{
    ObjectGuid const& guid = player->GetGUID();
    WorldPacket data(IsConstant() ? SMSG_USERLIST_ADD : SMSG_USERLIST_UPDATE, 8 + 1 + 1 + 4 + GetName().size());
    data << guid;
    data << uint8(GetPlayerFlags(guid));
    data << uint8(GetFlags());
    data << uint32(GetNumPlayers());
    data << GetName();

    if (IsConstant())
        SendToAllButOne(&data, guid);
    else
        SendToAll(&data);
}

void Channel::LeaveNotify(Player const* player)
{
    ObjectGuid const& guid = player->GetGUID();
    WorldPacket data(SMSG_USERLIST_REMOVE, 8 + 1 + 4 + GetName().size());
    data << guid;
    data << uint8(GetFlags());
    data << uint32(GetNumPlayers());
    data << GetName();

    if (IsConstant())
        SendToAllButOne(&data, guid);
    else
        SendToAll(&data);
}

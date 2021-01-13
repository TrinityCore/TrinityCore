/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#include "TSChannel.h"
#include "Channel.h"
#include "Player.h"

TSChannel::TSChannel(Channel *channel)
{
    this->channel = channel;
}

TSChannel::TSChannel()
{
    this->channel = nullptr;
}

TSString TSChannel::GetName(uint32 locale)
{
    return TSString(channel->GetName(LocaleConstant(locale)));
}

uint32 TSChannel::GetID()
{
    return channel->GetChannelId();
}

bool TSChannel::IsConstant() { return channel->IsConstant(); }
bool TSChannel::IsLFG() { return channel->IsLFG(); }
bool TSChannel::IsAnnounce(){ return channel->IsAnnounce(); }
void TSChannel::SetAnnounce(bool announce) { channel->SetAnnounce(announce); }
void TSChannel::SetDirty() { channel->SetDirty(); }
void TSChannel::SetPassword(TSString password) { channel->SetPassword(password.std_str()); }
bool TSChannel::CheckPassword(TSString password) { return channel->CheckPassword(password.std_str()); }
uint32 TSChannel::GetNumPlayers() { return channel->GetNumPlayers(); }
uint8 TSChannel::GetFlags() { return channel->GetFlags(); }
bool TSChannel::HasFlag(uint8 flag) { return channel->HasFlag(flag); }
void TSChannel::JoinChannel(TSPlayer player, TSString password) 
{
    channel->JoinChannel(player->player, password.std_str()); 
}

void TSChannel::LeaveChannel(TSPlayer player, bool send)
{
    channel->LeaveChannel(player->player,send);
}

void TSChannel::SetInvisible(TSPlayer player, bool on)
{
    channel->SetInvisible(player->player,on);
}

void TSChannel::SetOwner(uint64 guid, bool exclaim)
{
    channel->SetOwner(ObjectGuid(guid),exclaim);
}

void TSChannel::Say(uint64 guid, TSString what, uint32 lang)
{
    channel->Say(ObjectGuid(guid),what,LocaleConstant(lang));
}
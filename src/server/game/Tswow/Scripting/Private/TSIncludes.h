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
#pragma once
#define CORE_NAME               "TrinityCore"
#define CORE_VERSION            (GitRevision::GetDate())
#define eWorld                  (sWorld)
#define eMapMgr                 (sMapMgr)
#define eConfigMgr              (sConfigMgr)
#define eGuildMgr               (sGuildMgr)
#define eObjectMgr              (sObjectMgr)
#define eAccountMgr             (sAccountMgr)
#define eAuctionMgr             (sAuctionMgr)
#define eGameEventMgr           (sGameEventMgr)
#define eObjectAccessor()       ObjectAccessor::
#define REGEN_TIME_FULL

#define HIGHGUID_PLAYER         HighGuid::Player
#define HIGHGUID_UNIT           HighGuid::Unit
#define HIGHGUID_ITEM           HighGuid::Item
#define HIGHGUID_GAMEOBJECT     HighGuid::GameObject
#define HIGHGUID_PET            HighGuid::Pet
#define HIGHGUID_TRANSPORT      HighGuid::Transport
#define HIGHGUID_VEHICLE        HighGuid::Vehicle
#define HIGHGUID_CONTAINER      HighGuid::Container
#define HIGHGUID_DYNAMICOBJECT  HighGuid::DynamicObject
#define HIGHGUID_CORPSE         HighGuid::Corpse
#define HIGHGUID_MO_TRANSPORT   HighGuid::Mo_Transport
#define HIGHGUID_INSTANCE       HighGuid::Instance
#define HIGHGUID_GROUP          HighGuid::Group

#define MAKE_NEW_GUID(l, e, h)  ObjectGuid(h, e, l)
#define GUID_ENPART(guid)       ObjectGuid(guid).GetEntry()
#define GUID_LOPART(guid)       ObjectGuid(guid).GetCounter()
#define GUID_HIPART(guid)       ObjectGuid(guid).GetHigh()
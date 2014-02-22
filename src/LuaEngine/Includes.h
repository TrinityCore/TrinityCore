/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef INCLUDES_H
#define INCLUDES_H

// #define MANGOS
// #define TBC

#ifndef NOINCLUDE

// Required
#include "AccountMgr.h"
#include "ArenaTeam.h"
#include "AuctionHouseMgr.h"
#include "Cell.h"
#include "CellImpl.h"
#include "Chat.h"
#include "Channel.h"
#include "DBCStores.h"
#include "GossipDef.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Language.h"
#include "Mail.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "Pet.h"
#include "ReputationMgr.h"
#include "revision.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#ifdef MANGOS
#include "ReactorAI.h"
#include "revision_nr.h"
#else
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "WeatherMgr.h"
#endif
#ifndef TBC
#include "Vehicle.h"
#endif

typedef std::set<std::string> LoadedScripts;

#define ELUNA_GUARD() \
    ACE_Guard< ACE_Thread_Mutex > ELUNA_GUARD_OBJECT (sEluna->lock);

#ifdef MANGOS
#undef  sWorld
#undef  sMapMgr
#undef  sGuildMgr
#undef  sObjectMgr
#undef  sAccountMgr
#undef  sObjectAccessor
#define sWorld                  (&MaNGOS::Singleton<World>::Instance())
#define sMapMgr                 (&MapManager::Instance())
#define sGuildMgr               (&MaNGOS::Singleton<GuildMgr>::Instance())
#define sObjectMgr              (&MaNGOS::Singleton<ObjectMgr>::Instance())
#define sAccountMgr             (&MaNGOS::Singleton<AccountMgr>::Instance())
#define sObjectAccessor         (&ObjectAccessor::Instance())
#define MAKE_NEW_GUID(l, e, h)  ObjectGuid(h, e, l)
#define GUID_TYPE               ObjectGuid
#define GET_GUID                GetObjectGuid
#define GetGameObjectTemplate   GetGameObjectInfo
#define GetItemTemplate         GetItemPrototype
#define TC_LOG_INFO(L, F, ...)  { sLog.outString(F, __VA_ARGS__); }
#define TC_LOG_ERROR(L, F, ...) { sLog.outErrorEluna(F, __VA_ARGS__); }
#define TC_LOG_DEBUG(L, F, ...) { sLog.outDebug(F, __VA_ARGS__); }
#define CORE_VERSION            REVISION_NR
#define CORE_NAME               "MaNGOS"
#define SERVER_MSG_STRING       SERVER_MSG_CUSTOM
#define MAX_LOCALES             MAX_LOCALE
#define OVERRIDE                override
#define DIALOG_STATUS_SCRIPTED_NO_STATUS    DIALOG_STATUS_UNDEFINED
#define TempSummon              TemporarySummon
#define PLAYER_FIELD_LIFETIME_HONORABLE_KILLS   PLAYER_FIELD_LIFETIME_HONORBALE_KILLS
#define MAX_TALENT_SPECS        MAX_TALENT_SPEC_COUNT
#define Vehicle                 VehicleInfo
#define GUID_ENPART(guid)       ObjectGuid(guid).GetEntry()
#define GUID_LOPART(guid)       ObjectGuid(guid).GetCounter()
#define GUID_HIPART(guid)       ObjectGuid(guid).GetHigh()
enum SelectAggroTarget
{
    SELECT_TARGET_RANDOM = 0,                               // Just selects a random target
    SELECT_TARGET_TOPAGGRO,                                 // Selects targes from top aggro to bottom
    SELECT_TARGET_BOTTOMAGGRO,                              // Selects targets from bottom aggro to top
    SELECT_TARGET_NEAREST,
    SELECT_TARGET_FARTHEST
};
#ifdef TBC
#define SPELL_AURA_MOD_KILL_XP_PCT  SPELL_AURA_MOD_XP_PCT
#endif
#else
#define GUID_TYPE               uint64
#define GET_GUID                GetGUID
#define CORE_VERSION            _DATE
#define CORE_NAME               "TrinityCore"
#define REGEN_TIME_FULL
#define ThreatList              ThreatContainer::StorageType
#endif

#endif
#endif
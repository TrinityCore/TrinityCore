/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef _ELUNA_INCLUDES_H
#define _ELUNA_INCLUDES_H

// Required
#include "AccountMgr.h"
#include "AuctionHouseMgr.h"
#include "Cell.h"
#include "CellImpl.h"
#include "Chat.h"
#include "Channel.h"
#include "DBCStores.h"
#include "GameEventMgr.h"
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
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "WorldPacket.h"
#include "WorldSession.h"

#if defined TRINITY
#include "GitRevision.h"
#include "SpellHistory.h"
#endif

#if defined TRINITY || defined AZEROTHCORE
#include "Config.h"
#include "GameEventMgr.h"
#include "GroupMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "WeatherMgr.h"
#include "Battleground.h"
#include "MotionMaster.h"
#include "DatabaseEnv.h"
#include "Bag.h"
#else
#include "Config/Config.h"
#ifdef CMANGOS
#include "AI/AggressorAI.h"
#else
#include "AggressorAI.h"
#endif
#include "BattleGroundMgr.h"
#include "SQLStorages.h"
#include "revision.h"
#endif

#if (!defined(TBC) && !defined(CLASSIC))
#include "Vehicle.h"
#endif

#ifndef CLASSIC
#include "ArenaTeam.h"
#endif

#ifndef CLASSIC
typedef Opcodes                 OpcodesList;
#endif

/*
 * Note: if you add or change a CORE_NAME or CORE_VERSION #define,
 *   please update LuaGlobalFunctions::GetCoreName or LuaGlobalFunctions::GetCoreVersion documentation example string.
 */
#ifdef MANGOS
#define CORE_NAME               "MaNGOS"
#define CORE_VERSION            REVISION_NR
#endif

#ifdef CMANGOS
#define CORE_NAME               "cMaNGOS"
#define CORE_VERSION            REVISION_DATE " " REVISION_TIME
#endif

#ifdef TRINITY
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

#ifdef CATA
#define NUM_MSG_TYPES           NUM_OPCODE_HANDLERS
#endif
#endif

#ifdef AZEROTHCORE
#define CORE_NAME               "AzerothCore"
#define CORE_VERSION            ""
#define eWorld                  (sWorld)
#define eMapMgr                 (sMapMgr)
#define eConfigMgr              (sConfigMgr)
#define eGuildMgr               (sGuildMgr)
#define eObjectMgr              (sObjectMgr)
#define eAccountMgr             (sAccountMgr)
#define eAuctionMgr             (sAuctionMgr)
#define eGameEventMgr           (sGameEventMgr)
#define eObjectAccessor()       ObjectAccessor::
#endif

#if !defined TRINITY && !AZEROTHCORE
#define eWorld                  (&sWorld)
#define eMapMgr                 (&sMapMgr)
#define eConfigMgr              (&sConfig)
#define eGuildMgr               (&sGuildMgr)
#define eObjectMgr              (&sObjectMgr)
#define eAccountMgr             (&sAccountMgr)
#define eAuctionMgr             (&sAuctionMgr)
#define eGameEventMgr           (&sGameEventMgr)
#define eObjectAccessor()       sObjectAccessor.
#define SERVER_MSG_STRING       SERVER_MSG_CUSTOM
#define TOTAL_LOCALES           MAX_LOCALE
#define TARGETICONCOUNT         TARGET_ICON_COUNT
#define MAX_TALENT_SPECS        MAX_TALENT_SPEC_COUNT
#define TEAM_NEUTRAL            TEAM_INDEX_NEUTRAL

#if defined(TBC) || defined(WOTLK) || defined(CATA)
#define PLAYER_FIELD_LIFETIME_HONORABLE_KILLS   PLAYER_FIELD_LIFETIME_HONORBALE_KILLS
#endif

#ifdef TBC
#define SPELL_AURA_MOD_KILL_XP_PCT  SPELL_AURA_MOD_XP_PCT
#endif

#if defined(CATA) || defined(MISTS) || (defined(WOTLK) && !defined(MANGOS))
#define UNIT_BYTE2_FLAG_SANCTUARY   UNIT_BYTE2_FLAG_SUPPORTABLE
#endif

typedef TemporarySummon TempSummon;
typedef SpellEntry SpellInfo;
#endif // TRINITY

#endif // _ELUNA_INCLUDES_H

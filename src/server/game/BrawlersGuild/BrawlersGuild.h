/*
 * Copyright 2023 AzgathCore
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

#ifndef _BRAWLERS_GUILD_H
#define _BRAWLERS_GUILD_H

#include "Common.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

class Player;

#define MAX_BRAWLERS_RANK 8
#define BOSS_PER_RANK 4
#define REPUTATION_PER_RANK 250
#define MAX_BRAWLERS_REPUTATION 10000

enum BrawlersSpells
{
    SPELL_QUEUED_FOR_BRAWL      = 132639,
    SPELL_ARENA_TELEPORTATION   = 105315,
    SPELL_ARENA_FORCE_REACTION  = 132633,

    SPELL_EXPLOSION_0           = 87706,
    SPELL_EXPLOSION_1           = 87708,
    SPELL_EXPLOSION_2           = 87711,
    SPELL_EXPLOSION_3           = 87705,

    SPELL_ALLIANCE_SOUND        = 136144,
    SPELL_HORDE_SOUND           = 136143,
    
    SPELL_MOVE_FORWARD          = 229882, // for master
};

enum BrawlersSounds
{
    VICTORY,
    DEFEAT,

    MAX_BRAWLERS_SOUNDS
};

enum BrawlersAchievement
{
    ACHIEVEMENT_FIRST_RULE_A    = 7947,
    ACHIEVEMENT_FIRST_RULE_H    = 7948,
    ACHIEVEMENT_WIN_BRAWL_A     = 7937,
    ACHIEVEMENT_WIN_BRAWL_H     = 8020,
    ACHIEVEMENT_RANK_FOUR_A     = 11563,
    ACHIEVEMENT_RANK_FOUR_H     = 11564,
    ACHIEVEMENT_RANK_EIGHT_A    = 11565,
    ACHIEVEMENT_RANK_EIGHT_H    = 11566,
    
};

enum BrawlersGuilds
{
    ALLIANCE_GUILD,
    HORDE_GUILD,

    MAX_BRAWLERS_GUILDS
};

enum BrawlersStates
{
    BRAWL_STATE_NONE,
    BRAWL_STATE_WAITING,
    BRAWL_STATE_PREPARE_COMBAT,
    BRAWL_STATE_COMBAT,
    BRAWL_STATE_TRANSITION
};

enum BrawlersBosses
{
    //! 1 rank
    NPC_OOLISS          = 117133,
    NPC_GRANDPA         = 70678,
    NPC_OSO             = 117753,
    NPC_ULRICH          = 115292,
    // adds for Ulrich
    NPC_ALTOR           = 115294,
    NPC_ARSTAD          = 115295,
    
    //! 2 rank
    NPC_DIPPY           = 68255,
    NPC_BILL_THE_JANITOR = 117077,
    NPC_SANORIAK        = 67268,
    NPC_MASTER_PAKU     = 115645,
  
    //! 3 rank
    NPC_DOOMFLIPPER     = 117145,
    NPC_SPLAT           = 70736,
    NPC_SHADOWMASTER    = 116743,
    NPC_JOHNNY          = 115058,
    //! 4 rank 
    NPC_BURNSTACHIO     = 115023,
    NPC_MEATBALL        = 67573,
    NPC_STITCHES        = 117275,
    NPC_MAX_MEHABLAST   = 67488,
    // ADD FOR MAX
    NPC_BO_BOBBLE       = 67487,
    
    //! 5 rank
    NPC_BLACKMANGE      = 114902,
    NPC_RAZORGRIN       = 71086,  
    NPC_THWACK_U        = 115432,
    //< add for thwack
    NPC_SONNY           = 114944,
    NPC_WES             = 114945,
    //>`
    NPC_FIVE_GNOMES     = 67509,
    // gnomes
    NPC_FLEASY          = 67515,
    NPC_GREAZY          = 67514,
    NPC_SLEAZY          = 67513,
    NPC_WHEEZY          = 67516,
    NPC_QUEAZY          = 67511,
    
    //! 6 rank
    NPC_TOPPS           = 116539,
    NPC_MILLIE          = 67591,
    NPC_CARL            = 115233,
    NPC_OGREWATCH       = 115796,
    // add for ogrewatch
    NPC_HUDSON          = 114951,
    NPC_DUPREE          = 114955,
    NPC_STUFFSHREW      = 114941,
    
    //! 7 rank
    NPC_NIBBLEH         = 70656,
    NPC_SERPENT         = 116692,
    NPC_EPICUS          = 67490,
    NPC_RAYD            = 115040,
    
    //! 8 rank
    //...
    
};

class TC_GAME_API BrawlersGuild
{
public:
    explicit BrawlersGuild(uint32 id, Map* map);
    ~BrawlersGuild();

    void Update(uint32 diff);

    void AddPlayer(Player* player);

    void RemovePlayer(Player* player);
    void RemovePlayer(ObjectGuid guid);

    void BossReport(ObjectGuid guid, bool win);

    bool IsPlayerInBrawl(Player* player);

    void SetAnnouncer(ObjectGuid guid);

    uint32 GetPlayerPosition(Player* player);

private:
    static void UpdateAura(Player* player, uint32 rank);
    void UpdateAllAuras();

    void RemovePlayers();

    void UpdateBrawl(uint32 diff);

    void EndCombat(bool win, bool time = false);

    static uint32 GetPlayerRank(Player* player);
    static uint32 GetPlayerSubRank(Player* player);
    static uint32 GetBossForPlayer(Player* player);

    void SetBrawlState(uint32 state);
   // void PlayFightSound(bool play, uint32 boss = 0);
    void SendCongratulations(Player* player);
    
    std::list<ObjectGuid> _waitList;
    std::list<ObjectGuid> _removeList;
    ObjectGuid _current;
    ObjectGuid _announcer;
    ObjectGuid _boss;
    uint32 _ID;
    uint32 _brawlState;
    IntervalTimer _prepareCombatTimer;
    IntervalTimer _combatTimer;
    IntervalTimer _transitionTimer;
    Map* m_map;
};

#endif

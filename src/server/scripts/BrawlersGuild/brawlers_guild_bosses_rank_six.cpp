/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "AchievementMgr.h"
#include "AreaTriggerAI.h"
#include "brawlers_guild.h"

enum eSpells
{
    // topps
    SPELL_CHARGE            = 232252,
    SPELL_STUN              = 232285,  
    SPELL_FAKE_STUN         = 234501,

    // mille
    SPELL_PHOTOPLASM_BUSTER_RAY =133357,
    SPELL_ELECTRIC_DYNAMITE = 133363,
    SPELL_TRANSFORM         = 133362,
    
    // carl
    SPELL_LAVA_SPIT         = 229398,
    SPELL_TELEPORT          = 229358,
    SPELL_LAVA_AT           = 229269,
    SPELL_LAVA_WAVES        = 229328,
    
    // hudson
    SPELL_PROTECT_SHIELD    = 230366, 
    SPELL_PROTECT_SHIELD_BUFF = 229893,
    SPELL_JUMP_PACK         = 230373,
    SPELL_JUMP_PACK_DMG     = 230374,
    SPELL_TESLA_GUN         = 230372,

    // dupree
    SPELL_HIGH_NOON         = 229154,

    //stuffshrew
    SPELL_FRAG_LAUNCHER     = 234683,
    SPELL_MANICAL_LAUGH     = 229998,
};


void AddSC_the_brawlers_guild_bosses_rank_six()
{
    //new boss_brawguild_topps();
    //new boss_brawguild_millie();
    //new boss_brawguild_carl();
    //new npc_brawguild_ogrewatch_controller();
    //new boss_brawguild_ogrewatch();
};

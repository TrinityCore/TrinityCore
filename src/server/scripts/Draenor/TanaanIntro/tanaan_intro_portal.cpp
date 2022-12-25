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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GameObject.h"
#include "Player.h"
#include "tanaan_intro.h"
#include "TemporarySummon.h"

enum eCreatures
{
    // Company
    NPC_KHADGAR                 = 78558,
    NPC_OLIN                    = 79315,
    NPC_THAELIN                 = 78568,
    NPC_HANSEL                  = 78569,

    // Ennemy
    NPC_IRON_GRUNT              = 78883,
    NPC_SHADOWMOON_RITUALIST    = 81711,

    // Ally
    NPC_VANGUARD_MUMPER         = 82188, // Escalier
    NPC_VANGUARD_MORICCALAS     = 81990, // Escalier

    NPC_VANGUARD_ARNOLD         = 79062,
    NPC_VANGUARD_RACY           = 82082,
    NPC_VANGUARD_ASTRYLIAN      = 81993,
    NPC_VANGUARD_CORSELLE       = 81994,
    NPC_VANGUARD_MAELGWYN       = 81995,
    NPC_VANGUARD_TURKINA        = 81996,
    NPC_VANGUARD_ROAGUE         = 81997,
    NPC_VANGUARD_ANRUIN         = 81998,
    NPC_VANGUARD_NEVO           = 81999,
    NPC_VANGUARD_ELAYNEA        = 82000,
    NPC_VANGUARD_MONISHOT       = 82001,
    NPC_VANGUARD_ALYA           = 82002, // Enemy : Shadowmoon Ritualist
    NPC_VANGUARD_ED             = 82003,
    NPC_VANGUARD_SALTY          = 82004,
    NPC_VANGUARD_CHALLE         = 82005,
    NPC_VANGUARD_PAZO           = 82006,
    NPC_VANGUARD_TORE           = 82007,
    NPC_VANGUARD_MALOTHAS       = 82008,
    NPC_VANGUARD_BARBERY        = 82009,
    NPC_VANGUARD_BONESAW        = 82010,
    NPC_VANGUARD_NORTHPAUL      = 82011,
    NPC_VANGUARD_KENGTUS        = 82012,
    NPC_VANGUARD_DARRAGH        = 82013,
    NPC_VANGUARD_ARCHON         = 82014, // Enemy : Shadowmoon Ritualist
    NPC_VANGUARD_MOONALLI       = 82015,
    NPC_VANGUARD_DURPHORN       = 82016,
    NPC_VANGUARD_MISERAIN       = 82017,
    NPC_VANGUARD_YOORI          = 82025,
    NPC_VANGUARD_RYII           = 82075,
    NPC_VANGUARD_ETUBRUTE       = 82187,
    NPC_VANGUARD_LUPAS          = 82189,
    NPC_VANGUARD_SHOJU          = 82191,
    NPC_VANGUARD_RAINIARA       = 82260,
    NPC_VANGUARD_AGIOS          = 82263,
    NPC_VANGUARD_JOHNNY         = 82264
};

enum eEvents
{
    EVENT_AGGRO     = 1
};

enum eKillCredits
{
    CREDIT_DARK_PORTAL_KILL      = 78419,
    CREDIT_STATIS_RUNE_DESTROYED = 78333,
    CREDIT_ENTER_GULDAN_PRISON   = 82573
};

void AddSC_tanaan_intro_portal()
{
   
}

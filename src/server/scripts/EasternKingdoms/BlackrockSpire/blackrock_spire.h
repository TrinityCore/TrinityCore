/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_BLACKROCK_SPIRE_H
#define DEF_BLACKROCK_SPIRE_H

enum Data
{
    DATA_OMOKK,
    DATA_SHADOW_HUNTER_VOSHGAJIN,
    DATA_WARMASTER_VOONE,
    DATA_MOTHER_SMOLDERWEB,
    DATA_UROK_DOOMHOWL,                       // not scripted
    DATA_QUARTERMASTER_ZIGRIS,
    DATA_GIZRUL_THE_SLAVENER,                 // not scripted
    DATA_HALYCON ,
    DATA_OVERLORD_WYRMTHALAK,
    DATA_PYROGAURD_EMBERSEER,
    DATA_WARCHIEF_REND_BLACKHAND,
    DATA_GYTH,
    DATA_THE_BEAST,
    DATA_GENERAL_DRAKKISATH
};
enum Npc
{
    NPC_OMOKK                       = 9196,
    NPC_SHADOW_HUNTER_VOSHGAJIN     = 9236,
    NPC_WARMASTER_VOONE             = 9237,
    NPC_MOTHER_SMOLDERWEB           = 10596,
    NPC_UROK_DOOMHOWL               = 10584,
    NPC_QUARTERMASTER_ZIGRIS        = 9736,
    NPC_GIZRUL_THE_SLAVENER         = 10268,
    NPC_HALYCON                     = 10220,
    NPC_OVERLORD_WYRMTHALAK         = 9568,
    NPC_PYROGAURD_EMBERSEER         = 9816,
    NPC_WARCHIEF_REND_BLACKHAND     = 10429,
    NPC_GYTH                        = 10339,
    NPC_THE_BEAST                   = 10430,
    NPC_GENERAL_DRAKKISATH          = 10363,
};

enum AdditionalData
{
    SPELL_SUMMON_ROOKERY_WHELP      = 15745,
    MAX_ENCOUNTER                   = 14,
};

enum GameObjects
{
    GO_WHELP_SPAWNER                = 175622, //trap spawned by go id 175124
};

#endif


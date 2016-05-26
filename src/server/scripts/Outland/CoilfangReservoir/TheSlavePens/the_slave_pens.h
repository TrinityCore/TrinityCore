/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef SLAVE_PENS_H
#define SLAVE_PENS_H

uint32 const EncounterCount               = 3;

#define SPScriptName "instance_the_slave_pens"
#define DataHeader "SP"

enum DataTypes
{
    DATA_MENNU_THE_BETRAYER               = 1,
    DATA_ROKMAR_THE_CRACKLER              = 2,
    DATA_QUAGMIRRAN                       = 3,
    DATA_AHUNE                            = 4,
    DATA_AHUNE_BUNNY                      = 5,
    DATA_FROZEN_CORE                      = 6,
    DATA_FLAMECALLER_000                  = 7,
    DATA_FLAMECALLER_001                  = 8,
    DATA_FLAMECALLER_002                  = 9,
    DATA_BONFIRE_BUNNY_000                = 10,
    DATA_BONFIRE_BUNNY_001                = 11,
    DATA_BONFIRE_BUNNY_002                = 12,
    DATA_BEAM_BUNNY_000                   = 13,
    DATA_BEAM_BUNNY_001                   = 14,
    DATA_BEAM_BUNNY_002                   = 15,
    DATA_LUMA_SKYMOTHER                   = 16
};

enum CreaturesIds
{
    NPC_AHUNE                            = 25740,
    NPC_FROZEN_CORE                      = 25865,
    NPC_LUMA_SKYMOTHER                   = 25697,
    NPC_AHUNE_LOC_BUNNY                  = 25745,
    NPC_EARTHEN_RING_FLAMECALLER         = 25754,
    NPC_SHAMAN_BONFIRE_BUNNY_000         = 25971,
    NPC_SHAMAN_BONFIRE_BUNNY_001         = 25972,
    NPC_SHAMAN_BONFIRE_BUNNY_002         = 25973,
    NPC_SHAMAN_BEAM_BUNNY_000            = 25964,
    NPC_SHAMAN_BEAM_BUNNY_001            = 25965,
    NPC_SHAMAN_BEAM_BUNNY_002            = 25966,
    NPC_WHISP_DEST_BUNNY                 = 26120,
    NPC_WHISP_SOURCE_BUNNY               = 26121
};

enum GameObjectIds
{
    GO_ICE_SPEAR                         = 188077,
    GO_ICE_STONE                         = 187882
};

#endif // SLAVE_PENS_H

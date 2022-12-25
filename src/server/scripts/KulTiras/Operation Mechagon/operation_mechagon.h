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

#ifndef OPERATION_MECHAGON_H
#define OPERATION_MECHAGON_H

#define DataHeader "OM"

uint32 const EncounterCount = 8;

enum EncounterData
{
    DATA_KING_GOBBAMAK = 1,
    DATA_GUNKER,
    DATA_TRIXIE_NAENO,
    DATA_HK8,
    DATA_TUSSLE_TONKS,
    DATA_KUJO,
    DATA_HEAD_MACHINIST_SPARKFLUX,
    DATA_KING_MECHAGON
};

enum Conversations
{
    CONVERSATION_OPERATION_MECHAGON_INTRO = 11775
};

enum Creatures
{
    NPC_KING_GOBBAMAK = 150159,
    NPC_SCRAPBONE_GRUNTER = 158871,
    NPC_STOLEN_SCRAPBOT = 153172,
    NPC_STOLEN_SHOCK_COIL = 153245,
    NPC_GUNKER = 150222,
    NPC_TRIXIE = 150712,
    NPC_NAENO = 153755,
    NPC_MECHACYCLE = 153756,
    NPC_JUMP_POINT_STALKER = 153886,
    NPC_SMOKE_CLOUD_STALKER = 153761,
    NPC_HK_8_AERIAL_OPPRESION_UNIT = 150190,
    NPC_TANK_BUSTER_MK1= 150295,
    NPC_WALKIE_SHOCKIE_X1 = 163746,    
    NPC_HK8_CENTER_ARENA_STALKER = 152272,
    NPC_HK8_TARGET_SELECTOR = 500519,
    NPC_TANK_BUSTER_MK2 = 155760, //hardmode
    NPC_OVERCHARGE_STATION = 152138,
    NPC_BUZZ_SAW = 145312,
    NPC_STALKER_ROBODROME_ARENA = 500520,
    NPC_PLATINUM_PUMMELER = 144244,
    NPC_GNOMERCY = 145185,
    NPC_KUJO = 144246,
    NPC_FLYING_CLAW = 150442,
    NPC_WENDY_COGSWORTH = 150694,
    NPC_MACHINISTS_GARDEN = 144248,
    NPC_KING_MECHAGON = 150397,
    NPC_AERIEL_UNIT = 144248,
    NPC_PLASMA_ORB = 150485,
    NPC_OMEGA_BUSTER = 144249,
    NPC_SQUIRT_BOT = 154746
};

enum Gameobjects
{

};

#endif // OPERATION_H

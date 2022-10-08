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

#ifndef ATAL_DAZAR_H
#define ATAL_DAZAR_H

#define DataHeader "AD"


enum EncounterData
{
    DATA_PRIESTESS_ALUNZA,
    DATA_VOLKAAL,
    DATA_REZAN,
    DATA_YAZMA,
    DATA_ACHIEVEMENT_COUNT = 0,
    DATA_MAX_ENCOUNTERS,
};

enum CreatureIds
{
    NPC_PRIESTESS_ALUNZA        = 122967,
    NPC_VOLKAAL                 = 122965,
    NPC_REZAN                   = 122963,
    NPC_YAZMA                   = 122968,
};

enum AtalDazarAchievements
{
    ACHIEVEMENT_ATAL_DAZAR_COMPLETED = 12824,
    ACHIEVEMENT_ATAL_DAZAR_COMPLETED_HEROIC = 12825,
    ACHIEVEMENT_ATAL_DAZAR_COMPLETED_MYTHIC = 12826,
    ACHIEVEMENT_BRINGING_HEXY_BACK = 12270,
    ACHIEVEMENT_GOLD_FEVER = 12272,
    ACHIEVEMENT_ITS_LIT = 12273,
};

enum AtalDazarGO
{
    GO_GATE_001 = 288204,
    GO_GATE_002 = 288205,
    GO_GATE_003 = 288202,
    GO_GATE_004 = 288203,
    GO_GATE_005 = 292402,
    GO_GATE_006 = 292399,
    GO_GATE_007 = 292400,
    GO_GATE_008 = 292401,
    GO_GATE_009 = 292397,
    GO_GATE_010 = 292398,

    GO_COLLISION_WALL = 278820,
    GO_WATERFALL_STAIRS = 278422,
    GO_ANCIENT_SWITCH01 = 288478,
    GO_ANCIENT_SWITCH02 = 288477,
};

enum AtalDazarSpells
{
    SPELL_UNSTABLE_HEX = 252781,
};

//int8 achievementCont = 0;
#endif // ATAL_DAZAR_H

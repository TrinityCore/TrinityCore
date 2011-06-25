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

#ifndef DEF_NAXXRAMAS_H
#define DEF_NAXXRAMAS_H

enum Encounter
{
    BOSS_ANUBREKHAN,
    BOSS_FAERLINA,
    BOSS_MAEXXNA,
    BOSS_NOTH,
    BOSS_HEIGAN,
    BOSS_LOATHEB,
    BOSS_PATCHWERK,
    BOSS_GROBBULUS,
    BOSS_GLUTH,
    BOSS_THADDIUS,
    BOSS_RAZUVIOUS,
    BOSS_GOTHIK,
    BOSS_HORSEMEN,
    BOSS_SAPPHIRON,
    BOSS_KELTHUZAD,
    MAX_BOSS_NUMBER,
    NPC_KELTHUZAD        = 300000,
    NPC_LICHKING         = 37181
};

enum Text
{
    SAY_KELTHUZAD_TAUNT1        = -1533090,
    SAY_KELTHUZAD_TAUNT2        = -1533091,
    SAY_KELTHUZAD_TAUNT3        = -1533092,
    SAY_KELTHUZAD_TAUNT4        = -1533093,
    SAY_CAT_DIED                = -1533089,
    SAY_SAPP_DIALOG1            = -1533084, 
    SAY_SAPP_DIALOG2_LICH       = -1533085, 
    SAY_SAPP_DIALOG3            = -1533086, 
    SAY_SAPP_DIALOG4_LICH       = -1533087, 
    SAY_SAPP_DIALOG5            = -1533088
};

enum Data
{
    DATA_HEIGAN_ERUPT = 0,
    DATA_GOTHIK_GATE = 1,
    DATA_SAPPHIRON_BIRTH = 2,

    DATA_HORSEMEN0 = 3,
    DATA_HORSEMEN1 = 4,
    DATA_HORSEMEN2 = 5,
    DATA_HORSEMEN3 = 6,

    DATA_GO_ROOM_HEIGAN = 14,
    DATA_GO_PASSAGE_HEIGAN = 15,

    DATA_PLAYER_DEATHS = 16,
    DATA_HEIGAN_PLAYER_DEATHS = 17,                  
};

enum Data64
{
    DATA_FAERLINA,
    DATA_THANE,
    DATA_LADY,
    DATA_BARON,
    DATA_SIR,
    DATA_THADDIUS,
    DATA_FEUGEN,
    DATA_STALAGG,
    DATA_KELTHUZAD,
    DATA_KELTHUZAD_PORTAL01,
    DATA_KELTHUZAD_PORTAL02,
    DATA_KELTHUZAD_PORTAL03,
    DATA_KELTHUZAD_PORTAL04,
    DATA_KELTHUZAD_TRIGGER,
    DATA_KELTHUZAD_2=18,
};

#define GO_BIRTH                181356

#endif

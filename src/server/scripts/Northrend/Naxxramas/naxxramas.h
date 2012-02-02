/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

uint32 const EncounterCount = 15;

enum Nax_Text /* not added yet */
{
    SAY_CAT_DIED                = 0,
    SAY_SAPP_DIALOG1            = -1533084, 
    SAY_SAPP_DIALOG2_LICH       = -1533085, 
    SAY_SAPP_DIALOG3            = -1533086, 
    SAY_SAPP_DIALOG4_LICH       = -1533087, 
    SAY_SAPP_DIALOG5            = -1533088,
    SAY_KELTHUZAD_TAUNT1        = -1533090,
    SAY_KELTHUZAD_TAUNT2        = -1533091,
    SAY_KELTHUZAD_TAUNT3        = -1533092,
    SAY_KELTHUZAD_TAUNT4        = -1533093,
};

enum Nax_Data
{
    // Encounter States/Boss GUIDs
    BOSS_FAERLINA = 0,
    BOSS_GOTHIK = 1,
    BOSS_THADDIUS = 2,
    BOSS_HEIGAN = 3,
    BOSS_RAZUVIOUS = 4,
    BOSS_GROBBULUS = 5,
    BOSS_GLUTH = 6,
    BOSS_HORSEMEN = 7,
    BOSS_ANUBREKHAN = 8,
    BOSS_MAEXXNA = 9,
    BOSS_NOTH = 10,
    BOSS_LOATHEB = 11,
    BOSS_PATCHWERK = 12,
    BOSS_SAPPHIRON = 13,
    BOSS_KELTHUZAD = 14,

    // Additional data	
    DATA_THANE = 15,
    DATA_LADY = 16,
    DATA_BARON = 17,
    DATA_SIR = 18,
    DATA_KELTHUZAD_PORTAL01 = 19,
    DATA_KELTHUZAD_PORTAL02 = 20,
    DATA_KELTHUZAD_PORTAL03 = 21,
    DATA_KELTHUZAD_PORTAL04 = 22,
    DATA_KELTHUZAD_TRIGGER = 23,
    DATA_KELTHUZAD_SPEAKER = 24,
    DATA_LICHKING = 25,
    DATA_HEIGAN_ERUPT = 26,
    DATA_GOTHIK_GATE = 27,
    DATA_SAPPHIRON_BIRTH = 28,
    DATA_HORSEMEN0 = 29,
    DATA_HORSEMEN1 = 30,
    DATA_HORSEMEN2 = 31,
    DATA_HORSEMEN3 = 32,
    DATA_FEUGEN = 33,
    DATA_STALAGG = 34,
    DATA_GO_ROOM_HEIGAN = 35,
    DATA_GO_PASSAGE_HEIGAN = 36,
    DATA_PLAYER_DEATHS = 37,
    DATA_HEIGAN_PLAYER_DEATHS = 38,
    DATA_ABOMINATION_KILLED = 39,
};

enum Naxx_GO
{
    GO_HORSEMEN_CHEST_HERO  = 193426,
    GO_HORSEMEN_CHEST       = 181366,
    GO_GOTHIK_GATE          = 181170,
    GO_KELTHUZAD_PORTAL01   = 181402,
    GO_KELTHUZAD_PORTAL02   = 181403,
    GO_KELTHUZAD_PORTAL03   = 181404,
    GO_KELTHUZAD_PORTAL04   = 181405,
    GO_KELTHUZAD_TRIGGER    = 181444,

    GO_ROOM_ANUBREKHAN      = 181126,
    GO_PASSAGE_ANUBREKHAN   = 181195,
    GO_PASSAGE_FAERLINA     = 194022,
    GO_ROOM_MAEXXNA         = 181209,
    GO_ROOM_NOTH            = 181200,
    GO_PASSAGE_NOTH         = 181201,
    GO_ROOM_HEIGAN          = 181202,
    GO_PASSAGE_HEIGAN       = 181203,
    GO_ROOM_LOATHEB         = 181241,
    GO_ROOM_GROBBULUS       = 181123,
    GO_PASSAGE_GLUTH        = 181120,
    GO_ROOM_THADDIUS        = 181121,
    GO_ROOM_GOTHIK          = 181124,
    GO_PASSAGE_GOTHIK       = 181125,
    GO_ROOM_HORSEMEN        = 181119,
    GO_PASSAGE_SAPPHIRON    = 181225,
    GO_ROOM_KELTHUZAD       = 181228,
    GO_ARAC_PORTAL          = 181575,
    GO_PLAG_PORTAL          = 181577,
    GO_MILI_PORTAL          = 181578,
    GO_CONS_PORTAL          = 181576,

    SPELL_ERUPTION          = 29371,
    SPELL_SLIME             = 28801
};

enum Nax_Creatures
{
    NPC_SAPPHIRON           = 15989,
    NPC_FAERLINA            = 15953,
    NPC_THANE               = 16064,
    NPC_LADY                = 16065,
    NPC_BARON               = 30549,
    NPC_SIR                 = 16063,
    NPC_THADDIUS            = 15928,
    NPC_HEIGAN              = 15936,
    NPC_FEUGEN              = 15930,
    NPC_STALAGG             = 15929,
    NPC_KELTHUZAD           = 15990,
    NPC_MR_BIGGLESWORTH     = 16998,
};


#define GO_BIRTH                181356

#endif


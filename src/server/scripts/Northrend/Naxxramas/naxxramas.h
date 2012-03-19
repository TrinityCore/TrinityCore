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

enum Nax_Text
{
    SAY_CAT_DIED                = 10,
    SAY_KELTHUZAD_TAUNT         = 11,
    SAY_SAPP_DIALOG1            = 12, 
    SAY_SAPP_DIALOG2_LICH       = 1, 
    SAY_SAPP_DIALOG3            = 13, 
    SAY_SAPP_DIALOG4_LICH       = 2, 
    SAY_SAPP_DIALOG5            = 14,
    SAY_HORSEMEN_1              = 5,
    SAY_HORSEMEN_2              = 5, 
    SAY_HORSEMEN_3              = 5, 
    SAY_HORSEMEN_4              = 6, 
    SAY_HORSEMEN_5              = 6, 
    SAY_HORSEMEN_6              = 5,
    SAY_HORSEMEN_7              = 6,


};

enum Nax_Data
{
    // Encounter States/Boss GUIDs
    BOSS_FAERLINA = 1,
    BOSS_GOTHIK,
    BOSS_THADDIUS,
    BOSS_HEIGAN,
    BOSS_RAZUVIOUS,
    BOSS_GROBBULUS,
    BOSS_GLUTH,
    BOSS_HORSEMEN,
    BOSS_ANUBREKHAN,
    BOSS_MAEXXNA,
    BOSS_NOTH,
    BOSS_LOATHEB,
    BOSS_PATCHWERK,
    BOSS_SAPPHIRON,
    BOSS_KELTHUZAD,

    // Additional data	
    DATA_THANE,
    DATA_LADY,
    DATA_BARON,
    DATA_SIR,
    DATA_KELTHUZAD_PORTAL01,
    DATA_KELTHUZAD_PORTAL02,
    DATA_KELTHUZAD_PORTAL03,
    DATA_KELTHUZAD_PORTAL04,
    DATA_KELTHUZAD_TRIGGER,
    DATA_HEIGAN_ERUPT,
    DATA_GOTHIK_GATE,
    DATA_SAPPHIRON_BIRTH,
    DATA_HORSEMEN0,
    DATA_HORSEMEN1,
    DATA_HORSEMEN2,
    DATA_HORSEMEN3,
    DATA_FEUGEN,
    DATA_STALAGG,
    DATA_GO_ROOM_HEIGAN,
    DATA_GO_PASSAGE_HEIGAN,
    DATA_ABOMINATION_KILLED,
    DATA_HUNDRED_CLUB,
    DATA_LICHKING,
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
    NPC_LICH_KING           = 16980,
    NPC_ZOMBIE              = 16360,
};

#define GO_BIRTH                181356

#endif


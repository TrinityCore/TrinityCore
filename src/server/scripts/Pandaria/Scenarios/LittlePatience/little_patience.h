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

#ifndef LITTLE_PATIENCE_H_
#define LITTLE_PATIENCE_H_

const Position varianTablePos  = { -1074.90f, 1155.35f, 16.60f, 5.38f };
const Position varianOuterPos  = { -1621.39f, 1053.91f, 14.20f, 3.13f };
const Position tyrandeOuterPos = { -1626.27f, 1039.74f, 14.20f, 2.18f };

const Position chiJiTemplePath[5]=
{
    { -1615.16f, 1075.36f, 13.82f, 0.0f },
    { -1638.47f, 1055.28f, 14.20f, 0.0f },
    { -1663.32f, 1053.72f, 14.05f, 0.0f },
    { -1684.03f, 1053.28f, 29.23f, 0.0f },
    { -1695.51f, 1053.28f, 29.51f, 0.0f },
};

enum Data
{
    DATA_PREPARE_CONSTRUCTS,
    DATA_SCARGASH_DEFEAT,

    // Misc
    DATA_CONSTRUCTION_COUNT,
    DATA_MASSIVE_ATTACK,
    FACTION_DATA,
};

enum Creatures
{
    NPC_KING_VARIAN_WRYNN           = 69026,
    NPC_TYRANDE_WHISPERWIND         = 68842,
    NPC_COMMANDER_SCARGASH          = 68474,
    NPC_CHI_JI                      = 67761,

    // Our Helpers
    NPC_ELDER_ADLER                 = 67569,
    NPC_ROSEY_AXLEROD               = 67883,
    NPC_FERA_PEARL                  = 68599,
    NPC_DUFF_MCSTRUM                = 68057,
    NPC_MASTER_BROWNSTONE           = 68240,
    NPC_NIGHT_ELF_LABORER           = 68597,
    NPC_FALLSONG_LABORER            = 67568,
    NPC_GNOME_LABORER               = 67888,
    NPC_DWARF_LABORER               = 68058,
    NPC_PANDAREN_LABORER            = 68246,

    // Our Enemy & Vermins
    NPC_KORKRON_COMMANDO            = 67688,
    NPC_MUCKMAW_CROCOLISK           = 67922,
    NPC_RIVERBLADE_MARAUDER         = 68775,
    NPC_BOGROT                      = 67974,
    NPC_WAKENED_MOGU                = 68102,
    NPC_JUNGLE_STOMPER              = 68351,
    NPC_RIVERBLADE_SCAVENGER        = 68409,
    NPC_KORKRON_ELITE               = 68739,
    NPC_KORKRON_ASSAILANT           = 67818,

    // Misc
    NPC_MOUND_OF_SOIL               = 68709,
    NPC_SAPLING                     = 68704,
    NPC_BURGEONING_SAPLING          = 68699,
    NPC_GLAIVE_THROWER              = 68788,
    NPC_WATER_BUCKET                = 68706,
    NPC_GLAIVETHOWER                = 68673,
    NPC_FOOD                        = 68672,
    NPC_WORK_COMPLETE               = 68213,
    NPC_WOODPILE                    = 68419,
    NPC_NOURSIHMENT                 = 68423,
    NPC_KORKRON_PARATROOPER_TRIGGER = 67708,
    NPC_KORKRON_COMMANDO_TRIGGER    = 67688,
    NPC_NIGHT_ELF_CONSTRUCTION_SITE = 68896,
    NPC_JINYU_CONSTRUCTION_SITE     = 68898,
    NPC_SPECIAL_ATTACK_MANAGER      = 67687,
    NPC_CANNON                      = 68135,
    NPC_CANNON_BARREL               = 68100,
    NPC_CANNON_BALLS                = 68112,
    NPC_WOODPILE_2                  = 68089,
    NPC_ANCIENT_DEFENDER            = 68787,
    NPC_KRASARI_IRON_SUPPLY         = 68343,
    NPC_BUBBLE_SPIKE                = 68422,
    NPC_CNAKE_OIL_BOILER            = 68478,
    NPC_SNACKS                      = 68481,
    NPC_GNOME_CONSTRUCTION_SITE     = 68899,
    NPC_SUSTENANCE                  = 68082,
    NPC_PANDAREN_KEG                = 68269,
    NPC_VITTLES                     = 68270,
    NPC_PANDAREN_CONSTRUCTION_SITE  = 68895,
    NPC_WOODPILE_3                  = 68273,
    NPC_BLAST_BREW_CAULDRON         = 68271,
    NPC_BLAST_BREW_KEG              = 68366,
    NPC_GNOMISH_TRANSFORMER         = 68495,
    NPC_GNOME_CONSTRUCTION_SITE_2   = 68900,
    NPC_DWARF_CONSTRUCTION_SITE     = 68901,
    NPC_SWARM_GAS                   = 68816,
    NPC_SPIRIT_BOMB                 = 68296,
};

enum Yells
{
    TALK_INTRO,
    TALK_SPECIAL_1,
    TALK_SPECIAL_2,
    TALK_SPECIAL_3,
    TALK_SPECIAL_4,
    TALK_SPECIAL_5,
    TALK_SPECIAL_6,
    TALK_SPECIAL_7,
    TALK_SPECIAL_8,
    TALK_SPECIAL_9,
    TALK_SPECIAL_10,
    TALK_SPECIAL_11,
    TALK_SPECIAL_12,
    TALK_SPECIAL_13,
    TALK_SPECIAL_14,
    TALK_SPECIAL_15,
    TALK_SPECIAL_16,
    TALK_SPECIAL_17,
    TALK_SPECIAL_18,
    TALK_SPECIAL_19,
    TALK_SPECIAL_20,
    TALK_SPECIAL_21,
    TALK_SPECIAL_22,
    TALK_SPECIAL_23,
    TALK_SPECIAL_24,
    TALK_SPECIAL_25,
    TALK_SPECIAL_26,
    TALK_SPECIAL_27,
    TALK_SPECIAL_28,
    TALK_SPECIAL_29,
    TALK_SPECIAL_30,
    TALK_SPECIAL_31,
    TALK_SPECIAL_32,
    TALK_SPECIAL_33,
};

enum AssaultType
{
    TYPE_GNOME,
    TYPE_DWARF,
    TYPE_NIGHT_ELF,
    TYPE_JYUIN,
    TYPE_PANDAREN,

    TYPE_PROGRESS_BAR_ENTRY,
    TYPE_PROGRESS_BAR_VALUE,
    TYPE_ASSAULT_IDX,
};

const std::vector<uint32> assaulters =
{
    NPC_RIVERBLADE_MARAUDER,
    NPC_BOGROT,
    NPC_WAKENED_MOGU,
};

enum MiscSpells
{
    SPELL_PERIODIC_CONSTRUCTION_CHECK = 133850,
    SPELL_INSPIRED_NIGHT_ELF          = 135414,
    SPELL_INSPIRED_GNOME_EFF          = 133928,
    SPELL_INSPIRED_JYNUI              = 133461,
    SPELL_INSPIRED_DWARF              = 134116,
};

const std::map<uint32, Position> invAssaultType =
{
    { TYPE_GNOME,     { -1508.53f, 1220.52f, 14.76f, 4.74f } },
    { TYPE_DWARF,     { -1458.48f, 785.17f,  18.93f, 0.06f } },
    { TYPE_NIGHT_ELF, { -1624.22f, 1319.20f, 14.39f, 0.77f } },
    { TYPE_JYUIN,     { -1559.70f, 1061.08f, 13.12f, 6.21f } },
    { TYPE_PANDAREN,  { -1250.81f, 881.71f,  15.28f, 0.28f } },
};

const std::map<uint32, std::array<uint32, 3>> invAssaultBindType =
{
    { TYPE_GNOME,     { NPC_ROSEY_AXLEROD, NPC_GNOME_LABORER, SPELL_INSPIRED_GNOME_EFF } },
    { TYPE_DWARF,     { NPC_DUFF_MCSTRUM, NPC_DWARF_LABORER, SPELL_INSPIRED_DWARF } },
    { TYPE_NIGHT_ELF, { NPC_FERA_PEARL, NPC_FALLSONG_LABORER, SPELL_INSPIRED_NIGHT_ELF } },
    { TYPE_JYUIN,     { NPC_ELDER_ADLER, NPC_FALLSONG_LABORER, SPELL_INSPIRED_JYNUI } },
    { TYPE_PANDAREN,  { NPC_MASTER_BROWNSTONE, NPC_GNOME_LABORER, 0 } },
};

const std::map<uint32, Position> invFactionLeadersType =
{
    { NPC_ELDER_ADLER,        { -1515.03f, 1042.22f, 14.38f, 3.41f } },
    { NPC_ROSEY_AXLEROD,      { -1508.33f, 1216.82f, 14.86f, 4.73f } },
    { NPC_FERA_PEARL,         { -1574.04f, 1323.81f, 17.32f, 3.36f } },
    { NPC_DUFF_MCSTRUM,       { -1445.18f, 795.48f,  18.08f, 5.22f } },
    { NPC_MASTER_BROWNSTONE,  { -1247.59f, 837.25f,  29.99f, 5.99f } },
};

const std::list<uint32> customAnnouce = 
{
    TALK_SPECIAL_1,
    TALK_SPECIAL_3,
    TALK_SPECIAL_4,
    TALK_SPECIAL_7,
};

enum Actions
{
    ACTION_START_INTRO,
    ACTION_FORCE_ASSAULT_TEMPLE,
    ACTION_SCARGASH_SLAIN,
};

enum Criterias
{
    CRTITERIA_DEFENSES_CONSTRUCTED = 22517,
    CRITERIA_SCARGASH_SLAIN        = 22461,

    SCENE_LITTLE_PATIENCE          = 316,
};

enum LFGTypes
{
    LFG_LITTLE_PATIENCE_H = 619,
    LFG_LITTLE_PATIENCE_A = 589,
};

#endif // LITTLE_PATIENCE_H_
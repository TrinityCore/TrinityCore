/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#define MAX_ENCOUNTERS 15
#define NaxxScriptName "instance_naxxramas"

enum DataTypes
{
    // Encounters
    DATA_ANUBREKHAN         = 1,
    DATA_FAERLINA           = 2,
    DATA_MAEXXNA            = 3,
    DATA_NOTH               = 4,
    DATA_HEIGAN             = 5,
    DATA_LOATHEB            = 6,
    DATA_PATCHWERK          = 7,
    DATA_GROBBULUS          = 8,
    DATA_GLUTH              = 9,
    DATA_THADDIUS           = 10,
    DATA_RAZUVIOUS          = 11,
    DATA_GOTHIK             = 12,
    DATA_HORSEMEN           = 13,
    DATA_SAPPHIRON          = 14,
    DATA_KELTHUZAD          = 15,

    DATA_HEIGAN_ERUPT       = 16,
    DATA_GOTHIK_GATE        = 17,
    DATA_SAPPHIRON_BIRTH    = 18,

    DATA_HORSEMEN0          = 19,
    DATA_HORSEMEN1          = 20,
    DATA_HORSEMEN2          = 21,
    DATA_HORSEMEN3          = 22,
    DATA_ABOMINATION_KILLED = 23,

    DATA_THANE              = 24,
    DATA_LADY               = 25,
    DATA_BARON              = 26,
    DATA_SIR                = 27,

    DATA_STALAGG            = 28,
    DATA_FEUGEN             = 29,

    DATA_KELTHUZAD_PORTAL01 = 30,
    DATA_KELTHUZAD_PORTAL02 = 31,
    DATA_KELTHUZAD_PORTAL03 = 32,
    DATA_KELTHUZAD_PORTAL04 = 33,
    DATA_KELTHUZAD_TRIGGER  = 34,
    DATA_TESLA_FEUGEN       = 35,
    DATA_TESLA_STALAG       = 36,
    DATA_TESLA_TRIGGER      = 37,

};

enum TextIds
{
    SAY_SAPP_DIALOG2_LICH       = 1,
    SAY_SAPP_DIALOG4_LICH       = 3,
    SAY_CAT_DIED                = 0,
    SAY_TAUNT1                  = 1,
    SAY_TAUNT2                  = 2,
    SAY_TAUNT3                  = 3,
    SAY_TAUNT4                  = 4,
    SAY_SAPP_DIALOG1            = 5, 
    SAY_SAPP_DIALOG3            = 6,
    SAY_SAPP_DIALOG5            = 7,
    SAY_HORSEMEN_1              = 5,
    SAY_HORSEMEN_2              = 5, 
    SAY_HORSEMEN_3              = 5, 
    SAY_HORSEMEN_4              = 6, 
    SAY_HORSEMEN_5              = 6, 
    SAY_HORSEMEN_6              = 5,
    SAY_HORSEMEN_7              = 6,
    SAY_KORT_TAUNT1             = 1,
};

enum CreaturesIds
{
    // Bosses
    BOSS_ANUBREKHAN         = 15956,
    BOSS_FAERLINA           = 15953,
    BOSS_MAEXXNA            = 15952,
    BOSS_NOTH               = 15954,
    BOSS_HEIGAN             = 15936,
    BOSS_LOATHEB            = 16011,
    BOSS_PATCHWERK          = 16028,
    BOSS_GROBBULUS          = 15931,
    BOSS_GLUTH              = 15932,
    BOSS_THADDIUS           = 15928,
    BOSS_RAZUVIOUS          = 16061,
    BOSS_GOTHIK             = 16060,
    BOSS_THANE              = 16064,
    BOSS_LADY               = 16065,
    BOSS_BARON              = 30549,
    BOSS_SIR                = 16063,
    BOSS_SAPPHIRON          = 15989,
    BOSS_KELTHUZAD          = 15990,

    // Mini bosses
    BOSS_FEUGEN             = 15930,
    BOSS_STALAGG            = 15929,

    // Creatures
    NPC_CRYPT_GUARD         = 16573,
    NPC_CORPSE_SCARAB       = 16698,
    NPC_TESLA               = 16218,
    NPC_BIGGLESWORTH        = 16998,
};

enum GameObjectsIds
{
    GO_HORSEMEN_CHEST_HERO  = 193426,
    GO_HORSEMEN_CHEST       = 181366,
    GO_GOTHIK_GATE          = 181170,
    GO_KELTHUZAD_PORTAL01   = 181402,
    GO_KELTHUZAD_PORTAL02   = 181403,
    GO_KELTHUZAD_PORTAL03   = 181404,
    GO_KELTHUZAD_PORTAL04   = 181405,
    GO_KELTHUZAD_TRIGGER    = 181444,
    GO_ARAC_PORTAL          = 181575,
    GO_PLAG_PORTAL          = 181577,
    GO_MILI_PORTAL          = 181578,
    GO_CONS_PORTAL          = 181576,
    GO_BIRTH                = 181356,

    GO_ANUBREKHAN_DOOR      = 181126,
    GO_ANUBREKHAN_ESCAPE    = 181195,
    GO_FEARLINA_DOOR_1      = 194022,
    GO_MAEXXNA_DOOR         = 181209,
    GO_NOTH_ENTRANCE        = 181200,
    GO_NOTH_ESCAPE          = 181201,
    GO_HEIGAN_ENTRANCE      = 181202,
    GO_HEIGAN_ESCAPE        = 181203,
    GO_LOATHEB_DOOR         = 181241,
    GO_GROBBULUS_DOOR       = 181123,
    GO_GLUTH_ESCAPE         = 181120,
    GO_THADDIUS_DOOR        = 181121,
    GO_GOTHIK_ENTRANCE      = 181124,
    GO_GOTHIK_ESCAPE        = 181125,
    GO_HORSEMEN_DOOR        = 181119,
    GO_SAPPHIRON_ESCAPE     = 181225,
    GO_KELTHUZAD_DOOR       = 181228,

    GO_PLAGUE_WING_PORTAL   = 181211,
    GO_DEATHKNIGHT_PORTAL   = 181210,
    GO_SPIDER_PORTAL        = 181212,
    GO_CONSTRUCTION_PORTAL  = 181213,
    GO_TESLA_FEUGEN         = 181477,
    GO_TESLA_STALAG         = 181478,
};

enum SpellIds
{
    SPELL_ERUPTION          = 29371,
    SPELL_PORTAL            = 28444,
    SPELL_ORB_TELEPORT_1    = 72617,
    SPELL_ORB_TELEPORT_2    = 72613,
};

template<class AI>
CreatureAI* GetNaxxramasAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId(NaxxScriptName))
                return new AI(creature);
    return NULL;
}

#endif


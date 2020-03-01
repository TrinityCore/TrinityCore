/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef DEF_STRATHOLME_H
#define DEF_STRATHOLME_H

#include "CreatureAIImpl.h"

#define StratholmeScriptName "instance_stratholme"
#define DataHeader "STR"

enum STRDataTypes
{
    TYPE_BARON_RUN = 1,
    TYPE_BARONESS = 2,
    TYPE_NERUB = 3,
    TYPE_PALLID = 4,
    TYPE_RAMSTEIN = 5,
    TYPE_BARON = 6,

    TYPE_MALOWN = 7,

    DATA_BARON = 10,
    DATA_YSIDA_TRIGGER = 11,

    TYPE_SH_QUEST = 20,
    TYPE_SH_CATHELA = 21,
    TYPE_SH_GREGOR = 22,
    TYPE_SH_NEMAS = 23,
    TYPE_SH_VICAR = 24,
    TYPE_SH_AELMAR = 25,
};

enum STRCreatureIds
{
    NPC_CRYSTAL                         = 10415, // ziggurat crystal
    NPC_BARON                           = 10440, // ziggurat crystal
    NPC_YSIDA_TRIGGER                   = 16100, // ziggurat crystal

    NPC_RAMSTEIN                        = 10439,
    NPC_ABOM_BILE                       = 10416,
    NPC_ABOM_VENOM                      = 10417,
    NPC_BLACK_GUARD                     = 10394,
    NPC_YSIDA                           = 16031,

    // Scarlet side creatures
    NPC_CRIMSON_GUARDSMAN               = 10418,
    NPC_CRIMSON_CONJUROR                = 10419,
    NPC_CRIMSON_INITATE                 = 10420,
    NPC_CRIMSON_GALLANT                 = 10424,

    NPC_TIMMY_THE_CRUEL                 = 10808,

    NPC_MANGLED_CADAVER = 10382,
    NPC_BROKEN_CADAVER = 10383,

    NPC_THUZADIN_ACOLYTE = 10399,

    NPC_AURIUS = 10917,
};

enum STRATHOLME_NPC_SPAWN_ID
{
    NPC_SPAWN_ID_CRIMSON_GUARDSMAN_0 = 54052,
    NPC_SPAWN_ID_CRIMSON_GUARDSMAN_1 = 54056,
    NPC_SPAWN_ID_CRIMSON_GUARDSMAN_2 = 54055,

    NPC_SPAWN_ID_ASHARI_CRYSTAL_0 = 53955,
    NPC_SPAWN_ID_ASHARI_CRYSTAL_1 = 53963,
    NPC_SPAWN_ID_ASHARI_CRYSTAL_2 = 53968,

    NPC_SPAWN_ID_THUZADIN_ACOLYTE_0_0 = 53268,
    NPC_SPAWN_ID_THUZADIN_ACOLYTE_0_1 = 53271,
    NPC_SPAWN_ID_THUZADIN_ACOLYTE_0_2 = 53270,
    NPC_SPAWN_ID_THUZADIN_ACOLYTE_0_3 = 53269,
    NPC_SPAWN_ID_THUZADIN_ACOLYTE_0_4 = 53272,

    NPC_SPAWN_ID_THUZADIN_ACOLYTE_1_0 = 53257,
    NPC_SPAWN_ID_THUZADIN_ACOLYTE_1_1 = 53260,
    NPC_SPAWN_ID_THUZADIN_ACOLYTE_1_2 = 53261,
    NPC_SPAWN_ID_THUZADIN_ACOLYTE_1_3 = 53258,
    NPC_SPAWN_ID_THUZADIN_ACOLYTE_1_4 = 53259,

    NPC_SPAWN_ID_THUZADIN_ACOLYTE_2_0 = 53265,
    NPC_SPAWN_ID_THUZADIN_ACOLYTE_2_1 = 53266,
    NPC_SPAWN_ID_THUZADIN_ACOLYTE_2_2 = 53264,
    NPC_SPAWN_ID_THUZADIN_ACOLYTE_2_3 = 53262,
    NPC_SPAWN_ID_THUZADIN_ACOLYTE_2_4 = 53263,
};

enum STRATHOLME_LINE_CRIMSON_GUARDSMAN
{
    LINE_CRIMSON_GUARDSMAN_0 = 0,
    LINE_CRIMSON_GUARDSMAN_1 = 1,
    LINE_CRIMSON_GUARDSMAN_2 = 2,
};

enum STRATHOLME_LINE_CRIMSON_GALLANT
{
    LINE_CRIMSON_GALLANT_0 = 0,    
};

enum STRATHOLME_LINE_THUZADIN_ACOLYTE
{
    LINE_THUZADIN_ACOLYTE_0 = 0,
    LINE_THUZADIN_ACOLYTE_1 = 1,
    LINE_THUZADIN_ACOLYTE_2 = 2,
};

enum STRATHOLME_LINE_BARON_RIVENDARE
{
    LINE_BARON_RIVENDARE_0 = 0,
    LINE_BARON_RIVENDARE_1 = 1,
    LINE_BARON_RIVENDARE_2 = 2,
    LINE_BARON_RIVENDARE_3 = 3,
    LINE_BARON_RIVENDARE_4 = 4,
    LINE_BARON_RIVENDARE_5 = 5,
};

enum STRATHOLME_LINE_RAMSTEIN
{
    LINE_RAMSTEIN_0 = 0,
};

enum STRATHOLME_LINE_AURIUS
{
    LINE_AURIUS_0 = 0,
    LINE_AURIUS_1 = 1,
};

enum STRATHOLME_QUEST
{
    QUEST_THE_MEDALLION_OF_FAITH = 5122,
};

enum STRGameobjectIds
{
    GO_DOOR_HALAZZI = 186303,
    GO_SERVICE_ENTRANCE = 175368,
    GO_GAUNTLET_GATE1 = 175357,
    GO_GAUNTLET_GATE2 = 175356,
    GO_ZIGGURAT1 = 175380,  // baroness
    GO_ZIGGURAT2 = 175379,  // nerub'enkan
    GO_ZIGGURAT3 = 175381,  // maleki
    GO_ZIGGURAT4 = 175405,  // rammstein
    GO_ZIGGURAT5 = 175796,  // baron
    GO_PORT_GAUNTLET = 175374,  // port from gauntlet to slaugther
    GO_PORT_SLAUGTHER = 175373,  // port at slaugther
    GO_PORT_ELDERS = 175377,  // port at elders square
    GO_YSIDA_CAGE = 181071
};

enum STRQuestIds
{
    QUEST_DEAD_MAN_PLEA                 = 8945
};

enum STRSpellIds
{
    SPELL_BARON_ULTIMATUM = 27861,
    SPELL_PERM_FEIGN_DEATH = 29266,
    SPELL_YSIDA_SAVED = 31912,
    SPELL_YSIDA_CREDIT_EFFECT = 31913,

    SPELL_AURIUS_CRUSADER_STRIKE = 14517,
    SPELL_AURIUS_EXORCISM = 17149,
    SPELL_AURIUS_HOLY_LIGHT = 13952,
    SPELL_AURIUS_DIVINE_SHIELD = 13874,
};

enum AURIUS_EVENT
{
    EVENT_CRUSADER_STRIKE = 1,
    EVENT_EXORCISM = 2,
    EVENT_HOLY_LIGHT = 3,
    EVENT_DIVINE_SHIELD = 4,
};

enum STRMisc
{
    //! amount of crusade monsters required to be killed in order for timmy the cruel to spawn
    TIMMY_THE_CRUEL_CRUSADERS_REQUIRED  = 15,
    MAX_ENCOUNTER                       = 6
};

template <class AI, class T>
inline AI* GetStratholmeAI(T* obj)
{
    return GetInstanceAI<AI>(obj, StratholmeScriptName);
}

#define RegisterStratholmeCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetStratholmeAI)

#endif

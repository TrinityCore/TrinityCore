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

enum STRBossIds
{
    BOSS_HEARTHSINGER_FORRESTEN = 0,
    BOSS_TIMMY_THE_CRUEL        = 1,
    BOSS_COMMANDER_MALOR        = 2,
    BOSS_WILLEY_HOPEBREAKER     = 3,
    BOSS_INSTRUCTOR_GALFORD     = 4,
    BOSS_BALNAZZAR              = 5,
    BOSS_THE_UNFORGIVEN         = 6,
    BOSS_BARONESS_ANASTARI      = 7,
    BOSS_NERUB_ENKAN            = 8,
    BOSS_MALEKI_THE_PALLID      = 9,
    BOSS_MAGISTRATE_BARTHILAS   = 10,
    BOSS_RAMSTEIN_THE_GORGER    = 11,
    BOSS_RIVENDARE              = 12,
    BOSS_POSTMASTER_MALOWN      = 13,

    MAX_ENCOUNTER
};

enum STRDataTypes
{
    TYPE_BARON_RUN                      = 1,
    TYPE_BARONESS                       = 2,
    TYPE_NERUB                          = 3,
    TYPE_PALLID                         = 4,
    TYPE_RAMSTEIN                       = 5,
    TYPE_BARON                          = 6,

    DATA_BARON                          = 10,
    DATA_YSIDA_TRIGGER                  = 11,

    TYPE_SH_QUEST                       = 20,
    TYPE_SH_CATHELA                     = 21,
    TYPE_SH_GREGOR                      = 22,
    TYPE_SH_NEMAS                       = 23,
    TYPE_SH_VICAR                       = 24,
    TYPE_SH_AELMAR                      = 25
};

enum STRCreatureIds
{
    NPC_HEARTHSINGER_FORRESTEN          = 10558,
    NPC_COMMANDER_MALOR                 = 11032,
    NPC_INSTRUCTOR_GALFORD              = 10811,
    NPC_THE_UNFORGIVEN                  = 10516,

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

    NPC_TIMMY_THE_CRUEL                 = 10808
};

enum STRGameobjectIds
{
    GO_DOOR_HALAZZI                     = 186303,
    GO_SERVICE_ENTRANCE                 = 175368,
    GO_GAUNTLET_GATE1                   = 175357,
    GO_ZIGGURAT1                        = 175380,  // baroness
    GO_ZIGGURAT2                        = 175379,  // nerub'enkan
    GO_ZIGGURAT3                        = 175381,  // maleki
    GO_ZIGGURAT4                        = 175405,  // rammstein
    GO_ZIGGURAT5                        = 175796,  // baron
    GO_PORT_GAUNTLET                    = 175374,  // port from gauntlet to slaugther
    GO_PORT_SLAUGTHER                   = 175373,  // port at slaugther
    GO_PORT_ELDERS                      = 175377,  // port at elders square
    GO_YSIDA_CAGE                       = 181071
};

enum STRQuestIds
{
    QUEST_DEAD_MAN_PLEA                 = 8945
};

enum STRSpellIds
{
    SPELL_BARON_ULTIMATUM               = 27861,
    SPELL_PERM_FEIGN_DEATH              = 29266,
    SPELL_YSIDA_SAVED                   = 31912,
    SPELL_YSIDA_CREDIT_EFFECT           = 31913
};

enum STRMisc
{
    //! amount of crusade monsters required to be killed in order for timmy the cruel to spawn
    TIMMY_THE_CRUEL_CRUSADERS_REQUIRED  = 15,
};

template <class AI, class T>
inline AI* GetStratholmeAI(T* obj)
{
    return GetInstanceAI<AI>(obj, StratholmeScriptName);
}

#define RegisterStratholmeCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetStratholmeAI)

#endif

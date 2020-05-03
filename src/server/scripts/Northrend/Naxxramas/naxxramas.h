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

#ifndef DEF_NAXXRAMAS_H
#define DEF_NAXXRAMAS_H

#include "CreatureAIImpl.h"

#define NaxxramasScriptName "instance_naxxramas"
#define DataHeader "NAX"

uint32 const EncounterCount     = 15;

enum NAXEncounter
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
    BOSS_KELTHUZAD
};

enum NAXData
{
    DATA_GOTHIK_GATE,
    DATA_HAD_ANUBREKHAN_GREET,
    DATA_HAD_FAERLINA_GREET,
    DATA_HAD_THADDIUS_GREET,
    DATA_HAD_SAPPHIRON_BIRTH,

    DATA_HORSEMEN_CHECK_ACHIEVEMENT_CREDIT,

    DATA_NAXX_PORTAL_ARACHNID,
    DATA_NAXX_PORTAL_CONSTRUCT,
    DATA_NAXX_PORTAL_PLAGUE,
    DATA_NAXX_PORTAL_MILITARY,
    DATA_KELTHUZAD_THRONE
};

enum NAXData64
{
    DATA_ANUBREKHAN,
    DATA_FAERLINA,
    DATA_RAZUVIOUS,
    DATA_GOTHIK,
    DATA_THANE,
    DATA_LADY,
    DATA_BARON,
    DATA_SIR,
    DATA_GLUTH,
    DATA_THADDIUS,
    DATA_HEIGAN,
    DATA_FEUGEN,
    DATA_STALAGG,
    DATA_SAPPHIRON,
    DATA_KELTHUZAD,
    DATA_KELTHUZAD_PORTAL01,
    DATA_KELTHUZAD_PORTAL02,
    DATA_KELTHUZAD_PORTAL03,
    DATA_KELTHUZAD_PORTAL04,
    DATA_KELTHUZAD_TRIGGER,
    DATA_LICH_KING
};

enum NAXCreaturesIds
{
    NPC_ANUBREKHAN              = 15956,
    NPC_FAERLINA                = 15953,
    NPC_RAZUVIOUS               = 16061,
    NPC_GOTHIK                  = 16060,
    NPC_THANE                   = 16064,
    NPC_LADY                    = 16065,
    NPC_BARON                   = 30549,
    NPC_SIR                     = 16063,
    NPC_GLUTH                   = 15932,
    NPC_HEIGAN                  = 15936,
    NPC_THADDIUS                = 15928,
    NPC_FEUGEN                  = 15930,
    NPC_STALAGG                 = 15929,
    NPC_TESLA                   = 16218,
    NPC_SAPPHIRON               = 15989,
    NPC_KEL_THUZAD              = 15990,
    NPC_CRYPT_GUARD             = 16573,
    NPC_NAXXRAMAS_FOLLOWER      = 16505,
    NPC_FOLLOWER_WORSHIPPER     = 16506,
    NPC_DK_UNDERSTUDY           = 16803,
    NPC_BIGGLESWORTH            = 16998,
    NPC_LICH_KING               = 16980,
    NPC_OLD_WORLD_TRIGGER       = 15384,
    NPC_FROGGER                 = 16027
};

enum NAXGameObjectsIds
{
    GO_HORSEMEN_CHEST_HERO      = 193426,
    GO_HORSEMEN_CHEST           = 181366,
    GO_GOTHIK_GATE              = 181170,
    GO_KELTHUZAD_PORTAL01       = 181402,
    GO_KELTHUZAD_PORTAL02       = 181403,
    GO_KELTHUZAD_PORTAL03       = 181404,
    GO_KELTHUZAD_PORTAL04       = 181405,
    GO_KELTHUZAD_TRIGGER        = 181444,
    GO_KELTHUZAD_THRONE         = 181640,
    GO_ROOM_ANUBREKHAN          = 181126,
    GO_PASSAGE_ANUBREKHAN       = 181195,
    GO_PASSAGE_FAERLINA         = 194022,
    GO_ROOM_MAEXXNA             = 181209,
    GO_ROOM_NOTH                = 181200,
    GO_PASSAGE_NOTH             = 181201,
    GO_ROOM_HEIGAN              = 181202,
    GO_PASSAGE_HEIGAN           = 181203,
    GO_ROOM_LOATHEB             = 181241,
    GO_ROOM_GROBBULUS           = 181123,
    GO_PASSAGE_GLUTH            = 181120,
    GO_ROOM_THADDIUS            = 181121,
    GO_ROOM_GOTHIK              = 181124,
    GO_PASSAGE_GOTHIK           = 181125,
    GO_ROOM_HORSEMEN            = 181119,
    GO_PASSAGE_SAPPHIRON        = 181225,
    GO_ROOM_KELTHUZAD           = 181228,

    // End of wing portals
    GO_ARAC_PORTAL              = 181575,
    GO_PLAG_PORTAL              = 181577,
    GO_MILI_PORTAL              = 181578,
    GO_CONS_PORTAL              = 181576,

    // "Glow" effect on center-side portal
    GO_ARAC_EYE_RAMP            = 181212,
    GO_PLAG_EYE_RAMP            = 181211,
    GO_MILI_EYE_RAMP            = 181210,
    GO_CONS_EYE_RAMP            = 181213,

    // "Glow" effect on boss-side portal
    GO_ARAC_EYE_RAMP_BOSS       = 181233,
    GO_PLAG_EYE_RAMP_BOSS       = 181231,
    GO_MILI_EYE_RAMP_BOSS       = 181230,
    GO_CONS_EYE_RAMP_BOSS       = 181232,
    GO_CONS_NOX_TESLA_FEUGEN    = 181477,
    GO_CONS_NOX_TESLA_STALAGG   = 181478,
    GO_BIRTH                    = 181356,

    // Teleporting pads spawned by the end of every quarter.
    GO_NAXX_PORTAL_ARACHNID     = 181575,
    GO_NAXX_PORTAL_CONSTRUCT    = 181576,
    GO_NAXX_PORTAL_PLAGUE       = 181577,
    GO_NAXX_PORTAL_MILITARY     = 181578
};

enum NAXInstanceEvents
{
    // Dialogue that happens after Gothik's death.
    EVENT_DIALOGUE_GOTHIK_KORTHAZZ = 1,
    EVENT_DIALOGUE_GOTHIK_ZELIEK,
    EVENT_DIALOGUE_GOTHIK_BLAUMEUX,
    EVENT_DIALOGUE_GOTHIK_RIVENDARE,
    EVENT_DIALOGUE_GOTHIK_BLAUMEUX2,
    EVENT_DIALOGUE_GOTHIK_ZELIEK2,
    EVENT_DIALOGUE_GOTHIK_KORTHAZZ2,
    EVENT_DIALOGUE_GOTHIK_RIVENDARE2,

    // Dialogue that happens after each wing.
    EVENT_KELTHUZAD_WING_TAUNT,

    // Periodic Frogger summon
    EVENT_SUMMON_FROGGER_WAVE,

    // Dialogue that happens after Sapphiron's death.
    EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD,
    EVENT_DIALOGUE_SAPPHIRON_LICHKING,
    EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD2,
    EVENT_DIALOGUE_SAPPHIRON_LICHKING2,
    EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD3,
    EVENT_DIALOGUE_SAPPHIRON_KELTHUZAD4
};

enum NAXInstanceTexts
{
    // The Four Horsemen
    SAY_DIALOGUE_GOTHIK_HORSEMAN      = 5,
    SAY_DIALOGUE_GOTHIK_HORSEMAN2     = 6,

    // Kel'Thuzad
    SAY_DIALOGUE_SAPPHIRON_KELTHUZAD  = 0,
    SAY_DIALOGUE_SAPPHIRON_KELTHUZAD2 = 2,
    SAY_DIALOGUE_SAPPHIRON_KELTHUZAD3 = 4,
    SAY_DIALOGUE_SAPPHIRON_KELTHUZAD4 = 20,

    SAY_KELTHUZAD_CAT_DIED            = 5,
    SAY_KELTHUZAD_FIRST_WING_TAUNT    = 16,

    // Lich King
    SAY_DIALOGUE_SAPPHIRON_LICH_KING  = 1,
    SAY_DIALOGUE_SAPPHIRON_LICH_KING2 = 2
};

template<typename AI, typename T>
inline AI* GetNaxxramasAI(T* obj)
{
    return GetInstanceAI<AI>(obj, NaxxramasScriptName);
}
#define RegisterNaxxramasCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetNaxxramasAI)

#endif

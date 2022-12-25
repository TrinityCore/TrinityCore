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

#include "AreaTriggerAI.h"
#include "halls_of_valor.h"
#include "ScriptedGossip.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_RAGNAROK = 1,
    SAY_RAGNAROK_EMOTE = 2,
    SAY_EGIDA = 3,
    SAY_DEATH = 4,
};

enum Spells
{
    SPELL_ZERO_REGEN = 78725,
    SPELL_CONVERSATION = 193975, //Skovald Intro 

    SPELL_FELBLAZE_RUSH = 193658,
    SPELL_RAGNAROK = 193826,
    SPELL_RAGNAROK_DMG = 193827,
    SPELL_RAGNAROK_MOD = 202494,
    SPELL_AEGIS_SPAWN = 193940,
    SPELL_CLAIM_THE_AEGIS = 194112,
    SPELL_SAVAGE_BLADE = 193668,
    SPELL_INFERNAL_FLAMES_AURA = 193983,
    SPELL_INFERNAL_FLAMES_FIND_N = 194222, //Filter normal
    SPELL_INFERNAL_FLAMES_FIND_H = 207510, //Filter heroic+
    SPELL_INFERNAL_FLAMES_TRIG_AT = 193705,
    SPELL_INFERNAL_FLAMES_AT = 193704,
    SPELL_INFERNAL_FLAMES_TRIG_SUM = 207509,

    //Aegis
    SPELL_AEGIS_VISUAL_SHIELD = 193769,
    SPELL_AEGIS_OVERRIDE = 193783,

    //Kings
    SPELL_CALL_ANCESTOR = 200969,
    SPELL_WICKED_DAGGER = 199674,
    SPELL_UNRULY_YELL = 199726,
    SPELL_SEVER = 199652,
};

enum eEvents
{
    EVENT_INTRO_COMPLETE = 1,
    EVENT_FELBLAZE_RUSH = 2,
    EVENT_RAGNAROK = 3,
    EVENT_PICK_AEGIS = 4,
    EVENT_SAVAGE_BLADE = 5,

    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4,
};

Position const kingsPos[4] =
{
    {2387.87f, 506.50f, 749.30f, 0.57f}, //NPC_KING_HALDOR  95843
    {2388.01f, 551.16f, 749.30f, 5.67f}, //NPC_KING_BJORN   97081
    {2409.10f, 490.69f, 749.30f, 1.16f}, //NPC_KING_RANULF  97083
    {2408.56f, 568.34f, 749.30f, 5.11f}, //NPC_KING_TOR     97084
};

uint32 OdynKings[4] =
{
    NPC_KING_HALDOR,
    NPC_KING_BJORN,
    NPC_KING_RANULF,
    NPC_KING_TOR
};

enum Actions
{
    ACTION_1 = 1,
    ACTION_2,
};

void AddSC_boss_godking_skovald()
{
   
}

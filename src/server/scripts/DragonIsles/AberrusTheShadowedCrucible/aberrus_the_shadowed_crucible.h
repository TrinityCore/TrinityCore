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

#ifndef DEF_ABERRUS_THE_SHADOWED_CRUCIBLE_H_
#define DEF_ABERRUS_THE_SHADOWED_CRUCIBLE_H_

#include "CreatureAIImpl.h"

#define ATSCScriptName "instance_aberrus_the_shadowed_crucible"
#define DataHeader "Aberrus"

uint32 const EncounterCount = 9;

enum AberrusDataTypes
{
    // Encounters
    DATA_KAZZARA_THE_HELLFORGED         = 0,
    DATA_THE_AMALGAMATION_CHAMBER       = 1,
    DATA_THE_FORGOTTEN_EXPERIMENTS      = 2,
    DATA_ASSAULT_OF_THE_ZAQALI          = 3,
    DATA_RASHOK_THE_ELDER               = 4,
    DATA_ZSKARN_THE_VIGILANT_STEWARD    = 5,
    DATA_MAGMORAX                       = 6,
    DATA_ECHO_OF_NELTHARION             = 7,
    DATA_SCALECOMMANDER_SARKARETH       = 8,

    // Creatures
    DATA_SARKARETH_AT_KAZZARA,

    // Gameobjects
    DATA_KAZZARA_GATE,

    // Misc
    DATA_KAZZARA_INTRO_STATE
};

enum AberrusCreatureIds
{
    // Bosses
    BOSS_KAZZARA_THE_HELLFORGED         = 201261,

    BOSS_ETERNAL_BLAZE                  = 201773,
    BOSS_ESSENCE_OF_SHADOW              = 201774,
    BOSS_SHADOWFLAME_AMALGAMATION       = 201934,

    BOSS_NELDRIS                        = 200912,
    BOSS_THADRION                       = 200913,
    BOSS_RIONTHUS                       = 200918,

    BOSS_WARLORD_KAGNI                  = 199659,
    BOSS_RASHOK_THE_ELDER               = 201320,
    BOSS_ZSKARN_THE_VIGILANT_STEWARD    = 202637,
    BOSS_MAGMORAX                       = 201579,
    BOSS_ECHO_OF_NELTHARION             = 204223,
    BOSS_SCALECOMMANDER_SARKARETH       = 205319,

    // Kazzara Trash
    NPC_SCALECOMMANDER_SARKARETH_AT_KAZZARA = 202416,
    NPC_SUNDERED_DEVASTATOR             = 198869,
    NPC_SUNDERED_SCALEGUARD             = 198871,
    NPC_SUNDERED_MANAWEAVER             = 198872,
    NPC_SUNDERED_EDGELORD               = 198873,

    // Misc
    NPC_SABELLIAN_AT_ABERRUS_ENTRANCE   = 201575
};

enum AberrusGameObjectIds
{
    GO_KAZZARA_DOOR                     = 398742,
    GO_KAZZARA_GATE                     = 397996,
    GO_INVISIBLE_DOOR                   = 398588
};

enum AberrusSharedActions
{
    ACTION_START_KAZZARA_INTRO = 0,
};

template <class AI, class T>
inline AI* GetAberrusTheShadowedCrucibleAI(T* obj)
{
    return GetInstanceAI<AI>(obj, ATSCScriptName);
}

#define RegisterAberrusTheShadowedCrucibleCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetAberrusTheShadowedCrucibleAI)

#endif

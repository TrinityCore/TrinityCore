/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef GATE_OF_THE_SETTING_SUN_H_
#define GATE_OF_THE_SETTING_SUN_H_

#define GSSScriptName "instance_gate_of_the_setting_sun"
#define DataHeader    "GSS"

uint32 const EncounterCount = 4;

enum GSSDataTypes
{
    // Encounter States/Boss GUIDs
    DATA_KIPTILAK               = 0,
    DATA_GADOK                  = 1,
    DATA_RIMOK                  = 2,
    DATA_RAIGONN                = 3,

    // Additional Data
    DATA_IN_FIGHT               = 4,
    DATA_OPEN_FIRST_DOOR        = 5,
    DATA_BRASIER_CLICKED        = 6,
    DATA_RANDOM_BOMBARDER       = 7,
    DATA_RANDOM_BOMB_STALKER    = 8,
};

enum GSSCreatureIds
{
    NPC_KIPTILAK                = 56906,
    NPC_GADOK                   = 56589,
    NPC_RIMOK                   = 56636,
    NPC_RAIGONN                 = 56877,

    NPC_KRITHUK_BOMBARDER       = 56706,
    NPC_BOMB_STALKER            = 56709,

    // Kip'Tilak
    NPC_STABLE_MUNITION         = 56917,

    NPC_EXPLOSION_BUNNY_N_M     = 56911,
    NPC_EXPLOSION_BUNNY_S_M     = 56918,
    NPC_EXPLOSION_BUNNY_E_M     = 56919,
    NPC_EXPLOSION_BUNNY_W_M     = 56920,

    NPC_EXPLOSION_BUNNY_N_P     = 59205,
    NPC_EXPLOSION_BUNNY_S_P     = 59206,
    NPC_EXPLOSION_BUNNY_E_P     = 59207,
    NPC_EXPLOSION_BUNNY_W_P     = 59208,

    // Gadok
    NPC_STALKER_NORTH_SOUTH     = 56932,
    NPC_STALKER_WEST_EAST       = 56913,

    NPC_KRIKTHIK_STRIKER        = 59778, // Appear on Gadok bombardment
    NPC_KRIKTHIK_DISRUPTOR      = 59794, // Bombard tower when Gadok is in fight

    // Rimok
    NPC_ADD_GENERATOR           = 59834,

    NPC_KRIKTHIK_SWARMER        = 59835,
    NPC_KRIKTHIK_SABOTEUR       = 60447,

    // Raingonn
    NPC_WEAK_SPOT               = 56895,

    NPC_KRIKTHIK_PROTECTORAT    = 56929,
    NPC_KRIKTHIK_ENGULFER       = 56912,
    NPC_KRIKTHIK_SWARM_BRINGER  = 56930,

    NPC_ARTILLERY               = 59819
};

enum GSSGameObjectIds
{
    GO_KIPTILAK_ENTRANCE_DOOR   = 212982,
    GO_KIPTILAK_WALLS           = 214629,
    GO_KIPTILAK_MANTID_BOMBS    = 215757,
    GO_KIPTILAK_EXIT_DOOR       = 212983,

    GO_SIGNAL_FIRE              = 213507,

    GO_RIMAK_AFTER_DOOR         = 212985,

    GO_RAIGONN_DOOR             = 212986,
    GO_RAIGONN_AFTER_DOOR       = 214261,

    GO_GREATDOOR_SECOND_DOOR    = 214888,
    GO_WALL_C                   = 213198,

    GO_PORTAL_TEMP_CORDE        = 400001,
    GO_PORTAL_TEMP_GADOK        = 400002
};

enum GSSMisc
{
    CINEMATIC_SETTING_SUN       = 265
};

template<typename AI, typename T>
inline AI* GetGateOfTheSettingSunAI(T* obj)
{
    return GetInstanceAI<AI>(obj, GSSScriptName);
}
#define RegisterGateOfTheSettingSunCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetGateOfTheSettingSunAI)

#endif // GATE_OF_THE_SETTING_SUN_H_

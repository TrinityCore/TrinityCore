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

#ifndef DEF_VIOLET_HOLD_BROKEN_ISLES_H
#define DEF_VIOLET_HOLD_BROKEN_ISLES_H

#include "CreatureAIImpl.h"

#define SCScriptName "instance_violet_hold_broken_isles"
#define DataHeader "VHBI"

uint32 const EncounterCount = 8;

extern Position const DefenseSystemLocation;
uint8 constexpr PortalIntroCount = 3;
extern Position const PortalIntroPositions[];

/* Violet Hold encounters:
0 - Festerface               0% Done
1 - Shivermaw                0% Done
2 - Blood-Princess Thal'ena  0% Done
3 - Mindflayer Haahrj        0% Done
4 - Millificent Manastorm    0% Done
5 - Anub'esset               0% Done
6 - Sael'orn                 0% Done
7 - Fel Lord Betrug          0% Done
*/

enum VHBIData
{
    // Main encounters
    // Bosses
    DATA_FESTERFACE            = 0,
    DATA_SHIVERMAW             = 1,
    DATA_BLOOD_PRINCE_THAL_ENA = 2,
    DATA_MINDFLAYER_HAAHRJ     = 3,
    DATA_MILLIFICENT_MANASTORM = 4,
    DATA_ANUB_ESSET            = 5,
    DATA_SAEL_ORN              = 6,
    DATA_FEL_LORD_BETRUG       = 7,

    // Misc
    DATA_MAIN_EVENT_STATE,
    DATA_WAVE_COUNT,
    DATA_DOOR_INTEGRITY,
    DATA_PORTAL_LOCATION,
    DATA_START_BOSS_ENCOUNTER,
    DATA_DEFENSELESS,

    // Cells
    DATA_FESTERFACE_CELL,
    DATA_SHIVERMAW_CELL,
    DATA_BLOOD_PRINCE_THAL_ENA_CELL,
    DATA_MINDFLAYER_HAAHRJ_CELL,
    DATA_MILLIFICENT_MANASTORM_CELL,
    DATA_ANUB_ESSET_CELL,
    DATA_SAEL_ORN_CELL,
    DATA_FEL_LORD_BETRUG_CELL,

    // Misc
    DATA_MAIN_DOOR,
    DATA_SINCLARI,
    DATA_SINCLARI_TRIGGER,
    DATA_HANDLE_CELLS
};

enum VHBICreatures
{
    NPC_TELEPORTATION_PORTAL         = 102279,
    //NPC_TELEPORTATION_PORTAL_ELITE = 32174,
    NPC_TELEPORTATION_PORTAL_INTRO   = 102267,
    NPC_PORTAL_GUARDIAN              = 102337,
    NPC_PORTAL_KEEPER                = 102336,

    NPC_FESTERFACE                   = 101995,
    NPC_SHIVERMAW                    = 101951,
    NPC_BLOOD_PRINCE_THAL_ENA        = 102431,
    NPC_MINDFLAYER_HAAHRJ            = 101950,
    NPC_MILLIFICENT_MANASTORM        = 101976,
    NPC_ANUB_ESSET                   = 102246,
    NPC_SAEL_ORN                     = 102387,
    NPC_FEL_LORD_BETRUG              = 102446,

    //NPC_DUMMY_XEVOZZ               = 32231,
    //NPC_DUMMY_LAVANTHOR            = 32237,
    //NPC_DUMMY_ICHORON              = 32234,
    //NPC_DUMMY_ZURAMAT              = 32230,
    //NPC_DUMMY_EREKEM               = 32226,
    //NPC_DUMMY_EREKEM_GUARD         = 32228,
    //NPC_DUMMY_MORAGG               = 32235,

    NPC_SINCLARI                     = 102278,
    //NPC_SINCLARI_TRIGGER           = 32204,
    NPC_VIOLET_HOLD_GUARD            = 174272,
    NPC_DEFENSE_SYSTEM               = 30837
};

enum VHBIGameObjectIds
{
    GO_MAIN_DOOR                  = 247544,
    GO_FESTERFACE_DOOR            = 0,
    GO_SHIVERMAW_DOOR             = 0,
    GO_BLOOD_PRINCE_THAL_ENA_DOOR = 0,
    GO_MINDFLAYER_HAAHRJ_DOOR     = 0,
    GO_MILLIFICENT_MANASTORM_DOOR = 0,
    GO_ANUB_ESSET_DOOR            = 0,
    GO_SAEL_ORN_DOOR              = 0,
    GO_FEL_LORD_BETRUG_DOOR       = 0,
    GO_ACTIVATION_CRYSTAL         = 193611,
    GO_INTRO_ACTIVATION_CRYSTAL   = 193615,
    GO_PLASMATIC_LASR_BOLT        = 249733
};

enum VHBIWorldStateIds
{
    WORLD_STATE_VH_SHOW = 3816,
    WORLD_STATE_VH_PRISON_STATE = 3815,
    WORLD_STATE_VH_WAVE_COUNT = 3810,
};

enum VHBIEvents
{
    EVENT_ACTIVATE_CRYSTAL = 20001
};

enum VHBIInstanceMisc
{
    ACTION_SINCLARI_OUTRO = 1,
    POINT_INTRO = 1
};

template <class AI, class T>
inline AI* GetVioletHolBrokenIslesAI(T* obj)
{
    return GetInstanceAI<AI>(obj, VioletHoldBrokenIslesScriptName);
}

#define RegisterVioletHoldBrokenIslesCreatureAI(ai_name) RegisterCreatureAIWithFactory(ai_name, GetVioletHolBrokenIslesAI)
#define RegisterVioletHoldBrokenIslesGameObjectAI(ai_name) RegisterGameObjectAIWithFactory(ai_name, GetVioletHolBrokenIslesAI)

#endif // DEF_VIOLET_HOLD_BROKEN_ISLES_H

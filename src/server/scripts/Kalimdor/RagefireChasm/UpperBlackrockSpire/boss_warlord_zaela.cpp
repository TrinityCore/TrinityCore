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

#include "upper_blackrock_spire.h"
#include "VehicleDefines.h"

#define MIN_X -0.5f
#define MAX_X 42.92f
#define MIN_Y -139.73f   
#define MAX_Y -101.40f

enum Says
{
    SAY_INTRO           = 0,
    SAY_AGGRO           = 1,
    SAY_DEATH           = 6
};

enum Spells
{
    SPELL_BURNING_BRIDGE        = 166685,
    SPELL_BURNING_BRIDGE_AT     = 166721,
    SPELL_DESTRUCTIVE_SMITE     = 155673,
    SPELL_BLACK_IRON_CYCLONE    = 155720,
    SPELL_REBOUNDING_BLADE      = 155705,
    SPELL_RIDE_VEHICLE          = 46598,

    SPELL_BURNING_BREATH        = 166040
};

enum eEvents
{
    EVENT_DESTRUCTIVE_SMITE     = 1,
    EVENT_BLACK_IRON_CYCLONE    = 2,
    EVENT_REBOUNDING_BLADE      = 3,
    EVENT_DRAKE_ATTACK          = 4,

    EVENT_DRAKE_BURNING_BREATH  = 1,
    EVENT_DRAKE_MOVE_BACK       = 2
};

enum eActions
{
    ACTION_DRAKE_INTRO      = 1,

    ACTION_REMOVE_VEHICLE   = 1
};

Position const fireBridgePos[11] = 
{
    {24.26f, -141.72f, 97.55f},
    {23.47f, -147.01f, 97.50f},
    {22.55f, -154.03f, 97.51f},
    {20.71f, -159.56f, 97.81f},
    {18.25f, -164.55f, 98.32f},
    {15.71f, -169.47f, 98.78f},
    {13.29f, -174.33f, 99.15f},
    {11.23f, -179.76f, 99.72f},
    {10.00f, -184.17f, 100.2f},
    {8.860f, -189.42f, 100.8f},
    {7.769f, -194.11f, 101.4f}
};

Position const drakePos[6] = 
{
    {11.44f, -110.48f,  97.75f, 4.78f}, // Intro drake spawn
    {33.64f, -109.21f,  97.75f, 4.78f},
    {68.62f,    0.98f, 129.01f},        // Drake despawn pos
    {19.71f, -186.19f,  29.51f},        // Matron spawn
    {4.49f,  -123.23f,  97.46f},        // Zaela run to matron point
    {21.88f, -112.88f, 122.49f}         // Centr platform pos
};

enum ePhase
{
    PHASE_BATTLE    = 1,
    PHASE_FLY       = 2
};

void AddSC_boss_warlord_zaela()
{
   
}

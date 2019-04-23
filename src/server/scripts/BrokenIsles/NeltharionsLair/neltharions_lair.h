/*
* Copyright (C) 2008-2018 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DEF_NELTHARIONS_LAIR_H
#define DEF_NELTHARIONS_LAIR_H
#define DataHeader "NL"

uint32 const EncounterCount = 4;

enum eData
{
    DATA_ENTRANCE_START_DIALOG     = 0,
    DATA_SPIRITWALKER              = 1,
    DATA_NAVARROGG_ROKMORA_STARTER = 2,
    DATA_ULAROGG_ROKMORA_STARTER   = 3,
    DATA_ROKMORA_START_DIALOG      = 4,
    DATA_ROKMORA                   = 5,
    DATA_MYSTIC_BARRIER            = 6,
    DATA_GO_NAVARROGG_OBSTRUCTION  = 7,
    DATA_BARRELS_EVENT             = 8,
    DATA_ULAROGG_CRAGSHAPER        = 9,
    DATA_NARAXAS                   = 10,
    DATA_RIGHT_IDOL                = 11,
    DATA_LEFT_IDOL                 = 12,
    DATA_CENTER_IDOL               = 13,
    DATA_BACK_IDOL                 = 14,
    DATA_FRONT_IDOL                = 15,
    DATA_CENTER_IDOL_KILLED        = 16,
    DATA_BARRIER_ULAROGG           = 17,
    DATA_BARRIER_NARAXAS           = 18,
    DATA_NARAXAS_LOOT              = 19,
    DATA_DARGRUL                   = 20,
    MAX_DATA
};

enum eNavarroggMisc
{
    SPELL_NAVARROGG_JUMP           = 184483,
    SPELL_2                        = 209517,
    GO_NAVARROGG_OBSTRUCTION       = 254854,
    SPELL_NAVARROGG_INSTAKILL      = 225785
};

enum eGameObjects
{
    GO_MYSTIC_BARRIER              = 248871,
    GO_BARRIER_ULAROGG             = 248765,
    GO_BARRIER_NARAXAS             = 248851,
    GO_NARAXAS_LOOT                = 251482,
};

enum eCreaturesInstance
{
    NPC_VILESHARD_CRAWLER                   = 96247,
    NPC_MBERSHARD_SCORPION                  = 98406,
    NPC_ROCKBACK_GNASHER                    = 91006,
    NPC_VILESHARD_CHUNK                     = 101438,
    NPC_UNDERSTONE_DRUDGE                   = 92350,
    NPC_TARSPITTER_LURKER                   = 91001,
    NPC_NAVARROGG_ROKMORA_STARTER           = 100700,
    NPC_ULAROGG_ROKMORA_STARTER             = 105300,
    NPC_ROKMORA                             = 91003,
    NPC_SPIRITWALKER                        = 100701,
    NPC_BLIGHTSHARD_SKITTER                 = 97720,
    NPC_BELLOWING_IDOL_M_STANCE             = 100818,
    NPC_WORMSPEACKER_DEVOUT                 = 101075,
    NPC_NARAXAS                             = 91005,
    NPC_DARGRUL                             = 91007,
    NPC_CRYSTALL_SPIKE                      = 101593,
};

enum eSpellsInstance
{
    SPELL_FALLING_VISUAL                  = 209888,
};

enum Misc
{
    TAXI_NODE_FALLING_START_POINT           = 1911,
    TAXI_NODE_FALLING_END_POINT             = 1910,
    TAXI_NODE_BARREL_START_POINT            = 1909,
    TAXI_NODE_BARREL_END_POINT              = 1908
};

Position const startFallingPos = { 2948.911865f, 1014.381287f, 320.373932f, 0.567054f };
Position const navaroggRokmoraPos = { 2959.87f , 1390.53f, 53.5284f };
Position const navaroggRokmoraJumpPos = { 2920.548828f, 1401.56f, -2.403572f, 2.744223f };
Position const ularoggAwayPos = { 2847.9978f, 1363.296997f, -0.553441f, 3.599185f };
Position const navaroggObstructionPos = { 2821.666f, 1353.644165f, 3.036326f, 2.85959f };
Position const spiritwalkerBarrelPos = { 2840.433594f, 1338.372f, -2.381463f, 1.773655f };

Position const ularoggJumpPos = { 2838.01416f, 1668.135986f, -40.652294f, 0.465261f };

Position const ularoggRightIdolStartPos = { 2831.75f, 1671.662598f, -40.619526f, 4.238316f };
Position const ularoggLeftIdolStartPos = { 2843.78418f, 1661.64856f, -40.742912f, 3.492187f };
Position const ularoggBackIdolStartPos = { 2829.3559f, 1667.85144f, -40.824234f, 0.067f };
Position const ularoggFrontIdolStartPos = { 2844.95f, 1669.667f, -40.585f, 0.243764f };

float const ularoggIdolsPositions[18][3] =
{
    { 2852.457773f, 1672.428589f, -40.824554f },
    { 2819.2f, 1668.4271f, -40.8596f },
    { 2847.351318f, 1678.2517f, -40.824554f },
    { 2837.3283f, 1650.5891f, -40.8341f },
    { 2849.5f, 1653.1f, -40.8263f },
    { 2856.76f, 1661.8317f, -40.8263f },
    { 2846.8f, 1667.824f, -40.8242f },
    { 2835.324f, 1658.68f, -40.852f },
    { 2829.397f, 1681.5772f, -40.8246f },
    { 2841.8f, 1687.719f, -40.8246f },
    { 2826.849f, 1672.85f, -40.8246f },
    { 2836.9467f, 1681.3924f, -40.824833f },
    { 2827.5f, 1652.2945f, -40.94f },
    { 2823.03f, 1659.981f, -41.0309f },
    { 2843.105f, 1656.638f, -40.826f },
    { 2849.3f, 1660.841f, -40.826f },
    { 2846.741f, 1683.984f, -40.826f },
    { 2824.643f, 1666.382f, -40.855f },
};

float const WormspeakerDevoutPositions[2][4]
{
    { 3035.41674f, 1781.331f, -61.256599f, 3.393305f },
    { 3027.4677f, 1799.203f, -61.256599f, 3.683903f },    
};
#endif

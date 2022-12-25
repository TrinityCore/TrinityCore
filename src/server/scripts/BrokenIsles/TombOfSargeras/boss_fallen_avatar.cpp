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

#include "tomb_of_sargeras.h"
#include "GameObject.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_CHAOS = 1,
    SAY_BLADES = 2,
    SAY_RUPTURE_1 = 3,
    SAY_RUPTURE_2 = 4,
    SAY_ANNIHILANT = 5,
    SAY_DEATH = 6,
};

enum Spells
{
    SPELL_UNBOUND_CHAOS = 234057, //
    SPELL_DESOLATE = 236494, //
    SPELL_SHADOWY_BLADES = 236573, //
    SPELL_RUPTURE_REALISTIC = 239132, //

    SPELL_ACTIVATE_PILONES = 240614, //
    SPELL_RIPPLE_OF_DARKNESS = 236528, //

    // second phase
    SPELL_CONSUME = 240594, //

    SPELL_ANNIHILATION = 235597, //
    SPELL_JUMP = 235613, //

    SPELL_SPARK_SECOND_PHASE = 239309, // ?
    SPELL_SEAR = 234179, // 
    SPELL_DARK_MARK = 239825, //
    SPELL_RUPTURE_REALISTIC_2 = 235572, //

    SPELL_AURA_WITHOUT_BLOCK = 110470,
    SPELL_AURA_PROC = 239830,
    SPELL_VISUAL_SWORD = 235582,


    // heroic
    SPELL_TOUCH_OF_SARGERAS_DMG = 239058,
    SPELL_TOUCH_OF_SARGERAS_NOT_CLOSE = 239287,
    SPELL_TOUCH_OF_SARGERAS_SUM = 239057, // 3 / 5
    SPELL_TOUCH_OF_SARGERAS_AT = 240827,
    SPELL_TOUCH_OF_SARGERAS_VIS = 240834,
    SPELL_TOUCH_OF_SARGERAS_CAST = 239207,

    SPELL_BLACK_WIND_TICKS = 239417,
    SPELL_BLACK_WIND_DMG = 242017,
    SPELL_BLACK_WIND_VIS = 241988,
    SPELL_BLACK_WIND_AT = 239418,

    SPELL_FEL_INFUSION = 236682,
    SPELL_FEL_INFUSION_BUFF = 236684,


    // add
    SPELL_CORRUPTED_BLADE = 236571, //  236604
    SPELL_CORRUPTED_BLADE_1 = 237666,
    SPELL_CORRUPTED_BLADE_REMOVE = 236593, //

    // maiden
    SPELL_CLEANING_PROTOCOL = 233856, //
    SPELL_CLEANING_PROTOCOL_ABSORB = 241008, // 
    SPELL_MALFUNCTION = 233739, //

    // pilones
    SPELL_BEAM_ON_BOSS = 238244, //
    SPELL_BEAM_ON_MAIDEN = 238335, //
    SPELL_BEAM_COND = 233878, //
    SPELL_PILONE_ACTIVATE = 233556, //
    SPELL_SPARK_OF_THE_DARK_TITAN = 234873, //

    SPELL_FEL_PILONE_ACTIVATE = 240623,
    SPELL_BEAM_ON_PLAYER_FEL = 240631, //  (aura)
    SPELL_BEAM_ON_PLAYER = 240746,

    SPELL_BEAM_ON_MAIDEN_FEL = 240758,
    SPELL_BEAM_ON_BOSS_FEL_VIS = 240630,
    SPELL_BEAM_ON_BOSS_FEL = 240675,
    SPELL_TAINTED_ESSENCE = 240728,
    SPELL_TAINTED_ESSENCE_KILL = 242081,

    SPELL_REMOVE_BEAMS = 238407, //

    SPELL_RAIN_OF_THE_DESTROYER_VIS = 241040,
    SPELL_RAIN_OF_THE_DESTROYER_AT = 241039,
    SPELL_RAIN_OF_THE_DESTROYER_SUM = 241036,
    SPELL_RAIN_OF_THE_DESTROYER_AOE = 240396,
    SPELL_RAIN_OF_THE_DESTROYER_CLOSE = 234417,
    // 236674


    // khadhar 241084 + 235582  + dmg (241123, 241122, 241128)
    // velen 241078  + dmg (241470, 241463, heal(241466))
    // illidan 57764 + dmg (241268, 241484)
    SPELL_CONVERS_EVENT_1 = 241103, //++ 4955

    SPELL_BONUS = 240659,
};

enum eEvents
{
    EVENT_SHADOWY_BLADES = 1,
    EVENT_CHECK_ENERGY,
    EVENT_RUPTURE_REALISTIC,
    EVENT_UNBOUND_CHAOS,
    EVENT_DESOLATE,
    EVENT_SELECT_PILONE,
    EVENT_RUPTURE_REALISTIC_AND_ENERGY,
    EVENT_DARK_MARK,

    EVENT_TOUCH_OF_SARGERAS,
    EVENT_SELECT_PILONE_FEL,
    EVENT_RAIN,

    EVENT_FORCE_SECOND_PHASE,
};

Position const pilonesPos[5]
{
    {6547.43f, -760.646f,	1662.98f,	5.75959f },
    {6538.19f, -795.174f,	1662.98f,	0       },
    {6547.38f, -829.529f,	1662.98f,	0.523599f},
    {6572.73f, -854.656f,	1662.98f,	1.0472f  },
    {6572.56f, -735.365f,	1662.98f,	5.23599f }
};

std::map<uint32, Position> floorBlocks
{
    { 267700, {6600.41f, -794.17f, 1510.0f, 0}},
    { 267701, {6560.08f, -775.08f, 1510.0f, 0}},
    { 267702, {6600.47f, -774.19f, 1510.0f, 0}},
    { 267703, {6635.91f, -761.15f, 1510.0f, 0}},
    { 267704, {6579.87f, -774.42f, 1510.0f, 0}},
    { 267705, {6642.12f, -795.31f, 1510.0f, 0}},
    { 267706, {6642.62f, -777.85f, 1510.0f, 0}},
    { 267707, {6561.22f, -794.48f, 1510.0f, 0}},
    { 267708, {6581.60f, -794.47f, 1510.0f, 0}},
    { 267709, {6560.60f, -757.41f, 1510.0f, 0}},
    { 267710, {6620.75f, -794.93f, 1510.0f, 0}},
    { 267711, {6597.75f, -753.93f, 1510.0f, 0}},
    { 267712, {6578.06f, -754.54f, 1510.0f, 0}},
    { 267713, {6620.22f, -775.04f, 1510.0f, 0}},
    { 267714, {6617.95f, -756.67f, 1510.0f, 0}},
    { 267715, {6600.41f, -836.14f, 1510.0f, 0}},
    { 267716, {6581.68f, -814.19f, 1510.0f, 0}},
    { 267717, {6614.62f, -836.08f, 1510.0f, 0}},
    { 267718, {6619.10f, -814.93f, 1510.0f, 0}},
    { 267719, {6638.89f, -814.43f, 1510.0f, 0}},
    { 267720, {6631.49f, -830.53f, 1510.0f, 0}},
    { 267721, {6600.83f, -814.48f, 1510.0f, 0}},
    { 267722, {6567.33f, -828.77f, 1510.0f, 0}},
    { 267723, {6582.95f, -832.97f, 1510.0f, 0}},
    { 267724, {6563.81f, -814.08f, 1510.0f, 0}}
};

std::map<uint32, std::pair<Position, Position>> perephaseEvent
{
    {121171, {{6515.72f, -809.69f, 1663.67f, 0.0f}, {6712.24f, -770.72f, 1519.62f}}},
    {121170, {{6615.99f, -797.28f, 1663.67f, 0.0f}, {6705.52f, -800.44f, 1513.50f}}},
    {121169, {{6514.16f, -785.14f, 1663.67f, 0.0f}, {6708.47f, -782.25f, 1517.22f}}}
};

Position const bladesPositions[7]
{
    {6594.51f, -806.92f, 1663.58f, 0.0f},
    {6589.36f, -794.80f, 1663.58f, 0.0f},
    {6597.37f, -779.48f, 1663.58f, 0.0f},

    {6551.39f, -737.23f, 1663.58f, 0.0f},
    {6529.41f, -771.28f, 1663.58f, 0.0f},
    {6530.16f, -812.10f, 1663.58f, 0.0f},
    {6541.95f, -839.76f, 1663.58f, 0.0f},
};

std::vector<Position> sargerasPositions
{
    {6551.96f, -805.34f, 1663.58f, 0.0f},
    {6573.08f, -756.50f, 1663.58f, 0.0f},
    {6578.23f, -779.93f, 1663.58f, 0.0f},
    {6578.44f, -832.90f, 1663.58f, 0.0f},
    {6583.62f, -812.65f, 1663.58f, 0.0f},
    {6562.11f, -794.26f, 1663.58f, 0.0f},
    {6554.01f, -767.29f, 1663.58f, 0.0f},
    {6589.62f, -756.13f, 1663.58f, 0.0f},

};

std::vector<Position> windsPos
{
    { 6538.00f, -754.95f, 1509.91f, 0.0f },
    { 6538.00f, -774.61f, 1509.91f, 0.0f },
    { 6538.00f, -795.38f, 1509.91f, 0.0f },
    { 6538.00f, -814.43f, 1509.91f, 0.0f },
    { 6538.00f, -831.60f, 1509.91f, 0.0f }, // + 118 by x

    { 6642.00f, -741.01f, 1509.91f, 0.0f },
    { 6620.33f, -737.82f, 1509.91f, 0.0f },
    { 6596.41f, -737.06f, 1509.91f, 0.0f },
    { 6577.08f, -736.97f, 1509.91f, 0.0f },
    { 6557.97f, -736.97f, 1509.91f, 0.0f } // -118 by y
};

enum Misc
{
    EVENT_1 = 1,
    EVENT_2,
};

void AddSC_boss_fallen_avatar()
{
    
}

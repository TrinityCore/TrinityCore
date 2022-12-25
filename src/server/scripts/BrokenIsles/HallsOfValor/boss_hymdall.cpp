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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "halls_of_valor.h"

enum Says
{
    SAY_AGGRO = 0,
    SAY_HORN = 1,
    SAY_HORN_EMOTE = 2,
    SAY_BLOODLETTING = 3,
    SAY_DEATH = 4,
};

enum Spells
{
    SPELL_HORN_OF_VALOR = 191284,
    SPELL_DANCING_BLADE = 193235,
    SPELL_DANCING_BLADE_AT = 193214,
    SPELL_BLOODLETTING_SWEEP = 193092,

    //Heroic
    SPELL_BALL_LIGHTNING_AT_FRONT = 193240,
    SPELL_BALL_LIGHTNING_AT_BACK = 188405,

    //Drake
    SPELL_STORM_BREATH_VIS = 188404,
    SPELL_STORM_BREATH_AT = 192959,
};

enum eEvents
{
    EVENT_HORN_OF_VALOR = 1,
    EVENT_SUM_S_DRAKE = 2,
    EVENT_DANCING_BLADE = 3,
    EVENT_BLOODLETTING_SWEEP = 4,

    EVENT_1,
    EVENT_2,
};

Position const drakePos[6] =
{
    {3566.12f, 675.0f,  626.44f, 4.67f},
    {3566.12f, 383.00f, 626.44f, 1.60f},
    {3534.45f, 675.02f, 626.44f, 4.67f},
    {3534.45f, 383.00f, 626.44f, 1.60f},
    {3502.45f, 675.04f, 626.44f, 4.67f},
    {3502.45f, 383.00f, 626.44f, 1.60f}
};

void AddSC_boss_hymdall()
{
    
}

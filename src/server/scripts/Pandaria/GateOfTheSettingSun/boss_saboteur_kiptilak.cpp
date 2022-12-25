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
#include "gate_setting_sun.h"

enum eSpells
{
    SPELL_PLANT_EXPLOSIVE = 107187,

    SPELL_SABOTAGE = 107268,
    SPELL_SABOTAGE_EXPLOSION = 113645,

    SPELL_PLAYER_EXPLOSION = 113654,

    SPELL_MUNITION_STABLE = 109987,
    SPELL_MUNITION_EXPLOSION = 107153,
    SPELL_MUNITION_EXPLOSION_AURA = 120551
};

enum eEvents
{
    EVENT_EXPLOSIVES = 1,
    EVENT_SABOTAGE = 2
};

enum eWorldInFlames
{
    WIF_NONE = 0,
    WIF_70 = 1,
    WIF_30 = 2
};

void AddSC_boss_saboteur_kiptilak()
{
   
}
